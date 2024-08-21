#include <iostream>
#include <cstring>
#include <sstream>
#include "json/json.h"
#include "utils/Log.h"
#include <vector>
#include <string.h>
#include "storage/StoragePreferences.h"
#include "Print_save.h"
#include "Scan_Print.h"
#include "json/json.h"
#include "restclient-cpp/restclient.h"
#include "restclient-cpp/connection.h"
#include "curl/curl.h"
std::vector<Print_Info> Print_info;
/*
 *
 *
 */
void Init_print_info(){

	Print_info.clear();

	std::string print_list = StoragePreferences::getString("print_list", "");
//	LOGD("print_list:%s", print_list.c_str());
    Json::Reader reader;
    Json::Value root;
	if (reader.parse(print_list, root, false)) {
	//处理文件
	if (root.isMember("print_list"))
	{

		Json::Value list = root["print_list"];
		if(list.isArray())
		{
	           // 遍历 "result" 数组
	         for (Json::ArrayIndex i = 0; i < list.size(); ++i)
	         {
				  const Json::Value& item = list[i];

				  Print_Info _cu;

				  _cu.ip = 	item["ip"].asString();
				  _cu.name = item["name"].asString();
				  _cu.mac = 	item["mac"].asString();
				  _cu.img = 	item["img"].asString();
				  _cu.uuid = item["uuid"].asString();
				  Print_info.push_back(_cu);
	         }
		}

	}

}

	//下面是从旧的存储方法读取列表信息，已经弃用，为了兼容才放到这里
	std::string mac_addr = StoragePreferences::getString("mac_addr", "");
	//解析mac——addr中的每一个mac
	if (mac_addr != "")
	{
		Json::Reader reader;
		Json::Value root2;
		std::vector<std::string> Print_info_ip;
		//std::string mac_addr_string = root.toStyledString();
		if (reader.parse(mac_addr, root2, false))
		{
			  if (root2.isMember("mac")) {
			    Json::Value obj = root2["mac"];
			    if (obj.isArray()) {
			      for (Json::ArrayIndex i = 0; i < obj.size(); ++i) {
			    	  Print_info_ip.push_back(obj[i].asString().c_str());
			    	//  LOGD("array: %s", obj[i].asString().c_str());
			      }
			    }
			  }
		}

		//读取每个mac的参数
		for (const auto& info : Print_info_ip)
		{
			Print_Info print;
			std::string infoa = StoragePreferences::getString(info, "");
			//LOGD("infoa: %s", infoa.c_str());
			print.mac = info;
			if (infoa != "")
			{

				if (reader.parse(infoa, root2, false))
				{
					  //LOGD("解析成功");
					  //解析json时，一定要多多检查输入的合法性，避免非法输入造成程序崩溃。
					  if (root2.isMember("name"))
					  {
						  print.name = root2["name"].asString().c_str();
						//  LOGD("name = %s", root2["name"].asString().c_str());
					  }
					  if (root2.isMember("ip"))
					  {
						  print.ip = root2["ip"].asString().c_str();
						//  LOGD("IP = %s", root2["ip"].asString().c_str());
					  }
					  if (root2.isMember("img"))
					  {
						  print.img = root2["img"].asString().c_str();
						//  LOGD("ime = %s", root2["img"].asString().c_str());
					  }

				}

			}
			Print_info.push_back(print);

		}
	}


}


////udp扫描出来的ip与，http扫描的ip先进性合并
void updateSystemInfoWithUdpPrintInfo() {


    for (const auto& udp_info : udp_print_Info) {
        bool found = false;
        for (auto& sys_info : System_info) {
        	//udp扫描出来的ip带7125端口，所以不使用==验证

            if (sys_info.print_ip == udp_info.print_ip) {
                sys_info.print_uuid = udp_info.print_uuid; // 更新 UUID
                found = true;
                break;
            }
        }
        if (!found) {
            System_Info new_info;
            new_info.print_ip = udp_info.print_ip;
            new_info.print_uuid = udp_info.print_uuid;
            // 如果有其他字段需要初始化，添加相应的初始化代码
            System_info.push_back(new_info); // 增加新的 IP 和 UUID
        }
    }
    //清理掉储存
    udp_print_Info.clear();

}

// 将合并的wifi列表，检测有没有存在储存列表，没有就合并，有就检测ip是否变化，有变化就修改ip
void updatePrintInfoWithSystemInfo() {
    for (const auto& sys_info : System_info) {

        bool found = false;
        for (auto& print_info : Print_info) {
        	//如果新添加的ip与已经储存的ip相同，说明旧的ip已经被新设备替换
        	if(print_info.ip ==  sys_info.print_ip)
        	{
        		print_info.ip = sys_info.print_ip;
        		if(!sys_info.print_uuid.empty()){
        			print_info.uuid = sys_info.print_uuid;
        		}
        		if(!sys_info.print_mac.empty()){
        			print_info.mac = sys_info.print_mac;
        		}
        	}
        	//mac地址不为空且相同
            if (print_info.mac == sys_info.print_mac && !print_info.mac.empty() && !sys_info.print_mac.empty()) {
                found = true;
                if (print_info.ip != sys_info.print_ip) {
                    print_info.ip = sys_info.print_ip; // 更新 IP
                }
                if(!sys_info.print_uuid.empty())
                {
                	print_info.uuid = sys_info.print_uuid;
                }
                break;
            }else if(print_info.uuid == sys_info.print_uuid && !print_info.uuid.empty() && !sys_info.print_uuid.empty()) {
                found = true;
                if (print_info.ip != sys_info.print_ip) {
                    print_info.ip = sys_info.print_ip; // 更新 IP
                }
                if(!sys_info.print_mac.empty())
                {
                	print_info.mac = sys_info.print_mac;
                }

                break;
            }
        }
        if (!found) {
            Print_Info new_print_info;
            new_print_info.mac = sys_info.print_mac;
            new_print_info.ip = sys_info.print_ip;
            new_print_info.uuid = sys_info.print_uuid;
            // 可以初始化其他字段为默认值
            new_print_info.name = "";
            new_print_info.img = "";
            new_print_info.state = "";
            Print_info.push_back(new_print_info); // 增加新的打印机信息
        }
    }

    //清理掉储存
    System_info.clear();
}

//清理旧的零散储存打印机列表
void clear_old_save()
{
	std::string mac_addr = StoragePreferences::getString("mac_addr", "");

	if (mac_addr != "")
	{
		Json::Reader reader;
		Json::Value root2;
		std::vector<std::string> Print_info_ip;

		if (reader.parse(mac_addr, root2, false))
		{
			  if (root2.isMember("mac")) {
			    Json::Value obj = root2["mac"];
			    if (obj.isArray()) {
			      for (Json::ArrayIndex i = 0; i < obj.size(); ++i) {
			    	  Print_info_ip.push_back(obj[i].asString().c_str());
			      }
			    }
			  }
		}

	    for (const auto& info : Print_info_ip)
	    {
	    	StoragePreferences::remove(info);
	    }
	    StoragePreferences::remove("mac_addr");
	}

}



void Save_all_print_info(){


	//清理旧的零散储存打印机列表,主要为了兼容旧程序
	clear_old_save();

	//udp扫描出来的ip与，http扫描的ip先进性合并
	updateSystemInfoWithUdpPrintInfo();

	//将合并后的wifi列表，与已储存的wifi列表进行合并
	updatePrintInfoWithSystemInfo();


	//生成json格式进行储存
    Json::Value root;
    //添加数组
    Json::Value array;
    //json的嵌套
    Json::Value sub;

    for (const auto& info : Print_info)
    {
    	//储存mac前我们先检测当前的MAC是否已被储存
    	sub["ip"] = info.ip;
        sub["name"] = info.name;
        sub["mac"] = info.mac;
        sub["img"] = info.img;
        sub["uuid"] = info.uuid;
        array.append(sub);

    }
    root["print_list"] = array;
    LOGD("root: %s", root.toStyledString().c_str());
    StoragePreferences::putString("print_list", root.toStyledString());

}
