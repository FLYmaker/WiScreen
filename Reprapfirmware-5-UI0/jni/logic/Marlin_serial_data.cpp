/*
 * Marlin_serial_data.cpp
 *
 *  Created on: 2024年7月11日
 *      Author: 10589
 */
#include "Marlin_serial_data.h"
#include <string.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include "utils/Log.h"
#include <vector>
#include <string.h>
#include "uart/UartContext.h"
#include "Print_Gcode.h"
#include "json/json.h"
#include "mainLogic.h"



extern bool make_RRF_print_big_Thumbnail_sure;
extern int cur_print_file_size;
extern int cur_file_size;
std::string CUR_Print_fileName;
extern std::string fileName;
extern std::string currentDirectory;
extern std::vector<FileInfo> fileInfos;
extern std::vector<std::string> gcodes_message;
std::vector<std::string> Plus;//m92
std::vector<std::string> Max_feed;//m203 Max feedrates
std::vector<std::string> Max_Acc;//m201
std::vector<std::string> Acceleration;//m204
std::vector<std::string> Advanced;//m205
std::vector<std::string> Hotend_PID;//m301
std::vector<std::string> Driver_current;//m906
extern bool CA_Hotend ;//校准喷头PID标志
extern bool CA_Hotbed ;//校准热床PID标志
extern bool CA_mesh ;//校准调平标志
extern bool Calibration_sw;
extern int Cur_Calibration_term;
extern int Calibration_yes_no[10];
extern std::vector<std::string> Calibration_term;
extern void Print_ok();
extern void RRF_make_Thumbnail(std::string base64_data,std::string fileName);
bool is_G91 = false;//相对模式
bool is_M83 = false;//E相对模式

bool Refresh_list_num = false;//刷新设置列表数值

void processPrinterCodeLine(std::string data);
extern std::string Serial_data;
extern std::string send_gcode_buff;
extern std::string send_gcode_buff2;

extern void run_next_Calibration();
extern void notify_open_close(bool sw_layer);
//通知消息储存
extern std::vector<std::string>Notify_message_list;
extern std::vector<std::string>Calibration_error;
extern bool can_send;
extern void init_sys_reboot();
extern std::string print_state;
std::vector<std::string> tempItems;
std::vector<std::string> xyze_pos;
std::string FR;


extern bool make_RRF_big_Thumbnail;
extern bool make_RRF_big_Thumbnail_sure;
//记录最后打印文件的xyz坐标
std::string file_x_pos;
std::string file_y_pos;
std::string file_z_pos;
std::string file_e_pos;
std::string file_speed;
void send(std::string j_gcodes);
void Send_serial_commands();

int Fan0_Speed = 0;
int Fan1_Speed = 0;
int Fan2_Speed = 0;
std::string RRF_base64_data;




//查找指定字母后面的数值
int extractSValue(char c,const std::string& gcode) {
    size_t s_pos = gcode.find(c);
    if (s_pos != std::string::npos) {
        std::string s_value_str = gcode.substr(s_pos + 1);
        std::stringstream ss(s_value_str);
        int s_value;
        ss >> s_value;
        return s_value;
    }
    return 0;  // 如果没有找到 'p'，返回 0 表示未找到
}

//从文件列表中找到文件，发送M36获取文件缩略图信息
void get_next_Thumbnail(){

	static int cur_num = 0;
	if(cur_num + 1 > (int)fileInfos.size()){
		cur_num = 0;
		return;
	}

	while(fileInfos[cur_num].fileType == E_FILETYPE_FOLDER){
		cur_num ++;
	}
	send_gcode_buff += "M36 " + currentDirectory;
	send_gcode_buff += fileInfos[cur_num].fileName;
	send_gcode_buff += "\r\n";
//	LOGD("NANANAN:%d,%s",cur_num,fileInfos[cur_num].fileName.c_str());
	cur_num ++;
	Send_serial_commands();
}



bool Serial_Data_Parsing::readyToRun() {

    return true;
}

bool Serial_Data_Parsing::threadLoop() {
    if (exitPending()) {
        return false;
    }

     	int posEnter = Serial_data.find("\n");
     	while (posEnter >= 0) {						// 已经找到\n，进行处理

     		if(posEnter > 0)
     			processPrinterCodeLine(Serial_data.substr(0, posEnter));
     			// LOGD("wart:%s",Serial_data.c_str());
     		Serial_data = Serial_data.erase(0, posEnter + 1);		// 删除\n以前的数据和\n本身
     		posEnter = Serial_data.find("\n");
     	}

    usleep(1000 * 10);
    return true;
}

static int back_ok_num = 0;
static int M105_num = 0;





void processPrinterCodeLine(std::string data){

	char buf[64];

//	 if(!strstr(data.c_str(),"heaters") && !strstr(data.c_str(),"axes"))
//	 {
		 LOGD("DATA:%s",data.c_str());

//	 }

	Send_serial_commands();


		 Json::Reader reader;
		 Json::Value Numerical;

		 if (reader.parse(data, Numerical, false))
		 {
			 	 Json::Value result = Numerical["result"];

			 	if (result.isMember("status")) {
			 		if(strstr(result["status"].asString().c_str(),"paused")){
			 			print_state = "pause";
			 		}else if(strstr(result["status"].asString().c_str(),"processing")){
			 			print_state = "printing";
			 		}else{
			 			print_state = "idel";
			 		}
			 	}else if (result.isMember("filePosition")) {
			 		if (result.isMember("file")){
			 			 Json::Value file = result["file"];
			 			 cur_print_file_size = file["size"].asInt();
			 			 fileName =  file["fileName"].asString().erase(0,3);//移除0:/
			 			CUR_Print_fileName = fileName;
			 		}
			 		cur_file_size = result["filePosition"].asInt();
			 		//下载大的缩略图
					make_RRF_big_Thumbnail = true;
					send_gcode_buff += "M36 ";
					send_gcode_buff += fileName;
					send_gcode_buff += "\r\n";
					Send_serial_commands();
			 	}else if (result.isMember("heaters")) {

			    		  Json::Value heaters = result["heaters"];
			    		  std::vector<std::string> temp;
			    		  temp.push_back("0");
			    		  temp.push_back("0");
			    		  if(heaters.isArray()){
			    		      for (Json::ArrayIndex i = 0; i < heaters.size(); ++i) {
			    		        snprintf(buf, sizeof(buf), "%0.0f", atof(heaters[i]["current"].asString().c_str()));
			    		        temp.push_back(buf);
			    		        snprintf(buf, sizeof(buf), "%0.0f", atof(heaters[i]["standby"].asString().c_str()));
			    		        temp.push_back(buf);
			    		      }
			    		      tempItems = temp;
			    		  }
			      }else if (result.isMember("axes")) {
			    		  Json::Value axes = result["axes"];
			    		  std::vector<std::string> _axes;
			    		  if(axes.isArray()){
			    		        for (Json::ArrayIndex i = 0; i < axes.size(); ++i) {
			    		        	snprintf(buf, sizeof(buf), "%0.2f", atof(axes[i]["machinePosition"].asString().c_str()));
			    		        	_axes.push_back(buf);
			    		        }
			    		        xyze_pos = _axes;
			    		  }
			      }else if (Numerical.isMember("files")) {

			    	  fileInfos.clear();
			    	  FileInfo _file;
				      Json::Value obj = Numerical["files"];
				      if (obj.isArray()) {

				        for (Json::ArrayIndex i = 0; i < obj.size(); ++i) {

				        	if(obj[i].asString()[0] == '*'){//文件夹
				        		_file.fileType = E_FILETYPE_FOLDER;
				        		_file.fileName = obj[i].asString().c_str() + 1 ;
				        	}else{
				        		_file.fileType = E_FILETYPE_FILE;
				        		_file.fileName = obj[i].asString().c_str();
				        	}
				        	fileInfos.push_back(_file);
				        }
			        	//获取文件缩略图信息
			        	get_next_Thumbnail();
				      }
				}else if (Numerical.isMember("fileName") && Numerical.isMember("thumbnails")) {
					RRF_base64_data.clear();
					Json::Value thumbnails = Numerical["thumbnails"];

					if(!thumbnails.empty() && thumbnails.isArray()){
//						for (Json::ArrayIndex i = 0; i < thumbnails.size(); ++i) {
							if(strstr(thumbnails[thumbnails.size() - 1]["format"].asString().c_str(), "png") ){
								std::string _path =  "/tmp/" + Numerical["fileName"].asString() + ".png";
								if(access(_path.c_str(), F_OK) == -1 || make_RRF_big_Thumbnail == true){
									send_gcode_buff += "M36.1 P\"";
									send_gcode_buff += Numerical["fileName"].asString();
									snprintf(buf,sizeof(buf),"\" S%d\r\n",thumbnails[thumbnails.size() - 1]["offset"].asInt());
									send_gcode_buff += buf;
								}else{
						        	//已储存当前文件缩略图，获取下一个文件缩略图信息
						        	get_next_Thumbnail();
								}
							}
//						}
					}else{
			        	//当前文件没有缩略图，获取下一个文件缩略图信息
			        	get_next_Thumbnail();
					}

				}else if (Numerical.isMember("thumbnail")) {
					Json::Value thumbnail = Numerical["thumbnail"];

					RRF_base64_data += thumbnail["data"].asString();
					if(thumbnail["next"].asInt() != 0){
						send_gcode_buff += "M36.1 P\"";
						send_gcode_buff += thumbnail["fileName"].asString();
						snprintf(buf,sizeof(buf),"\" S%d\r\n",thumbnail["next"].asInt());
						send_gcode_buff += buf;
						Send_serial_commands();
					}else{
						if(make_RRF_big_Thumbnail == false){
							std::string _name = thumbnail["fileName"].asString();
							_name =  _name.erase(0, currentDirectory.size());
							LOGD("NAME:%s",_name.c_str());
							RRF_make_Thumbnail(RRF_base64_data,_name);
						}else{
							if(CUR_Print_fileName == thumbnail["fileName"].asString()){
								RRF_make_Thumbnail(RRF_base64_data,"big_Thumbnail_Print");
								make_RRF_print_big_Thumbnail_sure = true;
							}else{
								RRF_make_Thumbnail(RRF_base64_data,"big_Thumbnail");
							}
							make_RRF_big_Thumbnail = false;
							make_RRF_big_Thumbnail_sure = true;
							return;
						}
						get_next_Thumbnail();
					}
				}else if(Numerical.isMember("resp")){
					std::string resp = Numerical["resp"].asString();
					gcodes_message.push_back(resp);

					if(strstr(resp.c_str(),"Error")){

						if(strstr(resp.c_str(),"insufficient axes homed"))
						{
							Notify_message_list.push_back("plase home");
							notify_open_close(true);
						}
					}
				}



		 }




















     if( data == "ok" || strstr(data.c_str(),"ok T:")|| data == "wait" )
     {

    	 if(can_send == true){//在打印文件，就发送下一行

    		 if(M105_num <= 0){
    			 sendLine();
    		 }else
    			 M105_num --;
    		 //在打印状态下，没发送16条命令我们就发送温度命令，以确认当前温度
    		 back_ok_num ++;
    		 if(back_ok_num >= 16){
    			 back_ok_num = 0;
    			 send_gcode_buff += "M105\r\n";
    			 M105_num ++;
    		 }

    	 }
    	 Send_serial_commands();
     }



    //单独一个喷头         ok T:-15.00 /0.00 @:0
    //两个喷头                 ok T:-15.00 /0.00 T0:-15.00 /0.00 T1:-15.00 /0.00 @:0 @0:0 @1:0
    //一个喷头 	一个热床 ok T:-15.00 /0.00 B:26.16 /0.00 @:59 B@:0
    //  ok T:-15.00 /0.00 B:-15.00 /0.00 T0:-15.00 /0.00 T1:-15.00 /0.00 T2:-15.00 /0.00 @:0 B@:0 @0:0 @1:0 @2:0
    //                    0     1        2     3         4     5         6     7
    //       1     2        3     4         5     6         7     8
    //换色                          ok T:-15.00 /0.00 @:0
    //混色                          ok T:-15.00 /0.00 @:0

     if (strstr(data.c_str(), "T:")) {
         std::string codes = data;
         tempItems.clear();
         const char* tokena = strstr(codes.c_str(), "T:") + 2;
         tokena = strtok(const_cast<char*>(tokena), " ");
         if (tokena == nullptr) return;
         snprintf(buf, sizeof(buf), "%0.0f", atof(tokena)); // 消除小数点后面值
         tempItems.push_back(buf);

         while (true) {
             tokena = strtok(NULL, " ");
             if (!tokena) break;

             if (strstr(tokena, "@")) {
                 break;
             } else if (strstr(tokena, "/")) {
                 tokena += 1;
             } else if (strstr(tokena, "B:")) {
                 tokena += 2;
             } else if (strstr(tokena, "T0:")) {
                 tokena += 3;
             } else if (strstr(tokena, "T1:")) {
                 tokena += 3;
             } else if (strstr(tokena, "T2:")) {
                 tokena += 3;
             } else if (strstr(tokena, "T3:")) {
                 tokena += 3;
             } else if (strstr(tokena, "T4:")) {
                 tokena += 3;
             }
             snprintf(buf, sizeof(buf), "%0.0f", atof(tokena)); // 消除小数点后面值
             tempItems.push_back(buf);
         }

         // 以下代码是将数组始终保持为 {当前喷头温度, 当前喷头温度, 热床温度, 热床温度, t0, t0, t1, t1}
         if (!strstr(data.c_str(), "B:")) { // 如果不含有热床温度，为了方便显示出机器温度，将热床温度以0的方式插入
             tempItems.insert(tempItems.begin() + 2, "0");
             tempItems.insert(tempItems.begin() + 3, "0");
         }

         if (!strstr(data.c_str(), "T0:")) {
             if (tempItems.size() < 6) {
                 tempItems.push_back(tempItems[0]);
                 tempItems.push_back(tempItems[1]);
             } else {
                 tempItems.insert(tempItems.begin() + 4, tempItems[0]);
                 tempItems.insert(tempItems.begin() + 5, tempItems[1]);
             }
         }
     }//温度解析完成

	//获取当前坐标    X:0.00 Y:223.00 Z:0.00 E:0.00 Count X:0 Y:17840 Z:0
	else if(strstr(data.c_str(),"Count X:"))
	{
		xyze_pos.clear();
		char* tokena =  strstr(data.c_str(),"X");
		tokena = strtok(tokena, " ");
		xyze_pos.push_back(tokena + 2);
		while(tokena){

			tokena = strtok(NULL, " ");
			if(strstr(tokena,"Count"))
				break;
			else
				xyze_pos.push_back(tokena + 2);
		}

		return;
	}//获取坐标结束


     //读取打印速度百分比
	else if(strstr(data.c_str(),"FR:"))
	{
		FR = strstr(data.c_str(),"FR:") + 3;
		return;
	}

	//系统重启
	else if(strstr(data.c_str(),"External Reset"))
	{
		 init_sys_reboot();
		 return;
	}


//	std::vector<std::string> Plus;//m92
//	std::vector<std::string> Max_feed;//m203 Max feedrates
//	std::vector<std::string> Max_Acc;//m201
//	std::vector<std::string> Acceleration;//m204
//	std::vector<std::string> Advanced;//m205
//	std::vector<std::string> Hotend_PID;//m301
//	std::vector<std::string> Driver_current;//m906

//解析marlin脉冲等参数
	else if(strstr(data.c_str(),"M92"))
	{
		LOGD("DADASDASD:%s",data.c_str());
		Plus.clear();
		char* tokena =  strstr(data.c_str(),"X");
		tokena = strtok(tokena, " ");
		Plus.push_back(tokena);

		while(tokena){

			tokena = strtok(NULL, " ");
	    	if (!tokena)
	        	break;
			else
				Plus.push_back(tokena);
		}

	}else if(strstr(data.c_str(),"M203"))
	{
		Max_feed.clear();
		char* tokena =  strstr(data.c_str(),"X");
		tokena = strtok(tokena, " ");
		Max_feed.push_back(tokena);

		while(tokena){

			tokena = strtok(NULL, " ");
	    	if (!tokena)
	        	break;
			else
				Max_feed.push_back(tokena);
		}
	}else if(strstr(data.c_str(),"M201"))
	{
		Max_Acc.clear();
		char* tokena =  strstr(data.c_str(),"X");
		tokena = strtok(tokena, " ");
		Max_Acc.push_back(tokena);

		while(tokena){

			tokena = strtok(NULL, " ");
	    	if (!tokena)
	        	break;
			else
				Max_Acc.push_back(tokena);
		}
	}else if(strstr(data.c_str(),"M204"))
	{
		Acceleration.clear();
		char* tokena =  strstr(data.c_str(),"P");
		tokena = strtok(tokena, " ");
		Acceleration.push_back(tokena);

		while(tokena){

			tokena = strtok(NULL, " ");
	    	if (!tokena)
	        	break;
			else
				Acceleration.push_back(tokena);
		}
	}else if(strstr(data.c_str(),"M205"))
	{
		Advanced.clear();
		char* tokena =  strstr(data.c_str(),"B");
		tokena = strtok(tokena, " ");
		Advanced.push_back(tokena);

		while(tokena){

			tokena = strtok(NULL, " ");
	    	if (!tokena)
	        	break;
			else
				Advanced.push_back(tokena);
		}
	}else if(strstr(data.c_str(),"M301"))
	{
		Hotend_PID.clear();
		char* tokena =  strstr(data.c_str(),"P");
		tokena = strtok(tokena, " ");
		Hotend_PID.push_back(tokena);

		while(tokena){

			tokena = strtok(NULL, " ");
	    	if (!tokena)
	        	break;
			else
				Hotend_PID.push_back(tokena);
		}
	}else if(strstr(data.c_str(),"M906 X"))
	{
		Driver_current.clear();
		char* tokena =  strstr(data.c_str(),"X");
		tokena = strtok(tokena, " ");
		Driver_current.push_back(tokena);

		while(tokena){

			tokena = strtok(NULL, " ");
	    	if (!tokena)
	        	break;
			else
				Driver_current.push_back(tokena);
		}
	}else if(strstr(data.c_str(),"M906 T"))
	{
		char* tokena =  strstr(data.c_str(),"E");
		tokena = strtok(tokena, " ");
		Driver_current.push_back(tokena);
		Refresh_list_num = true;
	}

	//PID调整完成
	else if(strstr(data.c_str(),"#define DEFAULT_Kp ")){
		std::string pid ;
		//检查是喷嘴还是热床
		if(strstr(Calibration_term[Cur_Calibration_term].c_str(),"E0"))
		{
			pid = "M301 P";
		}else{
			pid = "M304 P";
		}
		pid += strstr(data.c_str(),"Kp ")+3;
		pid +="\r\n";
		send_gcode_buff += pid;
	}
	else if(strstr(data.c_str(),"#define DEFAULT_Ki ")){
		std::string pid ;
		//检查是喷嘴还是热床
		if(strstr(Calibration_term[Cur_Calibration_term].c_str(),"E0"))
		{
			pid = "M301 I";
		}else{
			pid = "M304 I";
		}
		pid += strstr(data.c_str(),"Ki ")+3;
		pid +="\r\n";
		send_gcode_buff += pid;
	}
	else if(strstr(data.c_str(),"#define DEFAULT_Kd ")){
		std::string pid ;
		//检查是喷嘴还是热床
		if(strstr(Calibration_term[Cur_Calibration_term].c_str(),"E0"))
		{
			pid = "M301 D";
		}else{
			pid = "M304 D";
		}
		pid += strstr(data.c_str(),"Kd ")+3;
		pid +="\r\n";
		send_gcode_buff += pid;
		send_gcode_buff += "M500\r\n";
		Calibration_yes_no[Cur_Calibration_term] = 1;
	    run_next_Calibration();
	}
	else if(strstr(data.c_str(),"echo:Bed Leveling")){
			Calibration_yes_no[Cur_Calibration_term] = 1;
		    run_next_Calibration();
		}
	else if(strstr(data.c_str(),"echo:Bed Leveling")){
			Calibration_yes_no[Cur_Calibration_term] = 1;
		    run_next_Calibration();
		}
	//下面的都是系统报错，进行数据储存
	else if(strstr(data.c_str(),"echo:Unknown command: \"G29\""))
	{
		Calibration_yes_no[Cur_Calibration_term] = 2;
	    run_next_Calibration();
	}
	//最小温度触发
	else if(strstr(data.c_str(),"MINTEMP triggered") && strstr(data.c_str(),"Heater_ID: E"))
	{
		Notify_message_list.push_back("MINTEMP triggered E");
		notify_open_close(true);
	}
	//最小温度触发
	else if(strstr(data.c_str(),"MINTEMP triggered") && strstr(data.c_str(),"Heater_ID: bed"))
	{
		Notify_message_list.push_back("MINTEMP triggered bed");
		notify_open_close(true);
	}
	//最大温度触发
	else if(strstr(data.c_str(),"MAXTEMP triggered") && strstr(data.c_str(),"Heater_ID: E"))
	{
		Notify_message_list.push_back("MAXTEMP triggered E");
		notify_open_close(true);
	}
	//最大温度触发
	else if(strstr(data.c_str(),"MAXTEMP triggered") && strstr(data.c_str(),"Heater_ID: bed"))
	{
		Notify_message_list.push_back("MAXTEMP triggered bed");
		notify_open_close(true);
	}
	//加热失败
	else if(strstr(data.c_str(),"Heating failed") && strstr(data.c_str(),"Heater_ID: E"))
	{
		Notify_message_list.push_back("Heating failed E");
		notify_open_close(true);
	}
	//加热失败
	else if(strstr(data.c_str(),"Heating failed") && strstr(data.c_str(),"Heater_ID: bed"))
	{
		Notify_message_list.push_back("Heating failed bed");
		notify_open_close(true);
	}

	//调平使能失败
	else if(strstr(data.c_str(),"Failed to enable Bed Leveling"))
	{
		Notify_message_list.push_back("Failed to enable Bed Leveling");
		notify_open_close(true);
	}

	else if(strstr(data.c_str(),"PID Autotune failed! Bad heater id"))
	{
		Calibration_error.push_back(data);
		Notify_message_list.push_back("PID Autotune failed! Bad heater id");
		notify_open_close(true);
		Calibration_yes_no[Cur_Calibration_term] = 2;
	    run_next_Calibration();
	}
	else if(strstr(data.c_str(),"Unknown command:") && !strstr(data.c_str(),"M25") && !strstr(data.c_str(),"M24"))
	{

		if(strstr(data.c_str(),"M290")){
			Notify_message_list.push_back("M290");
			notify_open_close(true);
		}else{
			Notify_message_list.push_back(data);
			notify_open_close(true);
		}


	}



}




void Send_serial_commands(){


     int posEnter = send_gcode_buff.find("\n");
     // 已经找到\n，进行处理

	if(posEnter > 0)
	{

	    send(send_gcode_buff.substr(0, posEnter+1));//将数据从串口发送出去

	    send_gcode_buff =  send_gcode_buff.erase(0, posEnter+1);		// 删除\n以前的数据和\n本身
	}
	else
		return;





}



void send(std::string send_gcodes){
char buf[64];
//    //断电续打文件中的文件名字
//	if(strstr(send_gcodes.c_str(),"flie_size") ){
//		//LOGD("文件%s",j_gcodes.c_str());
//
//		send_gcodes = send_gcodes.substr(0, strlen(send_gcodes.c_str())-2);
//
//		char* back_filesize = strstr(send_gcodes.c_str(),"ze:")+3;
//		char* back_filename = strstr(send_gcodes.c_str(),"/mnt");
//		char* tokena = strtok(back_filesize, ":");
//		int back_Filesize = atoi(tokena) ;
//
//		 remove("/mnt/extsd/sys/power_back.txt");
//		return;
//	}
//	//校准喷头PID标志
//	if(strstr(send_gcodes.c_str(),"M303 E0") ){
//		CA_Hotend = true;
//	}
//	//校准热床PID标志
//	if(strstr(send_gcodes.c_str(),"M303 E-1") ){
//		CA_Hotbed = true;
//	}
//	//校准热床PID标志
//	if(strstr(send_gcodes.c_str(),"G29") ){
//		CA_mesh = true;
//	}

	 if(strstr(send_gcodes.c_str(),"printok" ) ) {
		 Print_ok();
		 return;
	 }



	 if( print_state == "pause"  && strstr(send_gcodes.c_str(),"M24" )  )
	{
		 can_send = true;
		 send_gcode_buff += send_gcode_buff2;

		 send_gcode_buff2.clear();
		 print_state = "printing";
//		 Send_serial_commands();
	}
	 else if( can_send  && strstr(send_gcodes.c_str(),"M25" )  )
	{
		 can_send = false;
		 //提前设置好恢复打印的坐标
		 send_gcode_buff2 += "G90\r\n";
		 send_gcode_buff2 += "G90\r\n";
		 snprintf(buf,sizeof(buf),"G1 X%0.3f Y%0.3f F4000\r\n",atof(file_x_pos.c_str()),atof(file_y_pos.c_str()));
		 send_gcode_buff2 += buf;
		 snprintf(buf,sizeof(buf),"G1 Z%0.3f F600\r\n",atof(file_z_pos.c_str()));
		 send_gcode_buff2 += buf;
		 snprintf(buf,sizeof(buf),"G1 F%d\r\n",atoi(file_speed.c_str()));
		 send_gcode_buff2 += buf;

		 if(is_M83)
		 {
			 send_gcode_buff2 += "M83\r\n";
			 snprintf(buf,sizeof(buf),"G1 E1\r\n");
			 send_gcode_buff2 += buf;
		 }else{
			 snprintf(buf,sizeof(buf),"G1 E%0.5f\r\n",atof(file_e_pos.c_str()) + 1);
			 send_gcode_buff2 += buf;
			 snprintf(buf,sizeof(buf),"G92 E%0.5f\r\n",atof(file_e_pos.c_str()));
			 send_gcode_buff2 += buf;
		 }
		 if(is_G91)
		 {
			 send_gcode_buff2 += "G91\r\n";
		 }

		 send_gcode_buff2 += send_gcode_buff.substr(5);//M25还没发送删除，这里避免M25再次保存
		 send_gcode_buff.clear();
		 //提前设置好恢复打印的坐标结束；

		 //暂停位置坐标
		 send_gcode_buff += "G90\r\n";
		 send_gcode_buff += "G90\r\n";
		 snprintf(buf,sizeof(buf),"G1 Z%0.3f F600\r\n",atof(file_z_pos.c_str()) + 5);
		 send_gcode_buff += buf;
		 send_gcode_buff += "G1 X0 Y0 F4000\r\n";
		 print_state = "pause";
	}
	 else if( can_send  && strstr(send_gcodes.c_str(),"G90" )  )
	{
		 is_G91 = false;
	}else if( can_send  && strstr(send_gcodes.c_str(),"G91" )  )
	{
		 is_G91 = true;
	}else if( can_send  && strstr(send_gcodes.c_str(),"M82" )  )
	{
		 is_M83 = false;
	} else if( can_send  && strstr(send_gcodes.c_str(),"M83" )  )
	{
		 is_M83 = true;
	}else if( can_send  && (strstr(send_gcodes.c_str(),"G0" ) || strstr(send_gcodes.c_str(),"G1" ) ) )
	{
         std::string posxyze = send_gcodes.c_str();

		char* tokena = strtok((char*)posxyze.c_str(), " ");

		while(1)
		{
		  tokena = strtok(NULL, " ");

	    	if (!tokena)
	        	break;


			else if ( strstr(tokena,"X") )
				file_x_pos = tokena+1;

			else if ( strstr(tokena,"Y") )
				file_y_pos = tokena+1;

			else if ( strstr(tokena,"Z") && !strstr(send_gcodes.c_str(),"F1234")){//排除暂停抬升高度
				file_z_pos = tokena+1;
					  LOGD("Az:%s",file_z_pos.c_str());
			}
			else if ( strstr(tokena,"E") && is_G91 == false && is_M83 == false){
				file_e_pos = tokena+1;
			}
			else if ( strstr(tokena,"F") )
				file_speed = tokena+1;



//		else if ( strstr(tokena,"E") && can_config_emode)
//		{
//		          curr_e_pos = tokena+1;//这行用作于断电续打一类的
//		          break;
//		}

       }
	}else if( strstr(send_gcodes.c_str(),"M106") ){

		if(strstr(send_gcodes.c_str(),"_M")){//这个是屏幕上发送的风扇命令，避免和文件发送的冲突
			send_gcodes.erase(0, 1); // 删除第一个字符
		}else{
			int P = extractSValue('P',send_gcodes);
			int S = extractSValue('S',send_gcodes);

			switch(P){
			case 0:
				Fan0_Speed = static_cast<float>(S) * 100 / 255 ;
	//			LOGD("FAN:%d",fan0_speed);
				break;
			case 1:
				Fan1_Speed = static_cast<float>(S) / 255 * 100;
				break;
			case 2:
				Fan2_Speed = static_cast<float>(S) / 255 * 100;
				break;
			}

		}


	}

	UARTCONTEXT->send((const unsigned char*)send_gcodes.c_str(), strlen(send_gcodes.c_str()));
		LOGD("发送了:%s",send_gcodes.c_str());
}
