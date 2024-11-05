// Scan_Print.cpp

#include "Scan_Print.h"  // 假设你已经定义了 Scan_Print 类
#include <iostream>
#include <cstring>
#include <sstream>
#include "json/json.h"
#include "restclient-cpp/restclient.h"
#include "restclient-cpp/connection.h"
#include "curl/curl.h"
#include <cmath>
#include "utils/Log.h"
#include <vector>
#include <string.h>
#include "Print_save.h"
#include "net/net.h"


int ip = 0;
int ip1 = 13;
int ip2 = 25;
int ip3 = 37;
int ip4 = 50;
int ip5 = 63;
int ip6 = 76;
int ip7 = 89;
int ip8 = 102;
int ip9 = 115;
int ip10 = 128;
int ip11 = 141;
int ip12 = 154;
int ip13 = 167;
int ip14 = 180;
int ip15 = 193;
int ip16 = 206;
int ip17 = 219;
int ip18 = 232;
int ip19 = 245;
extern std::vector<std::string> Slave_Print_ip;
//url编码
extern std::string encode_url(const std::string& text);
// 全局变量声明

bool Thread_Completion_Flag0 = true;
bool Thread_Completion_Flag1 = true;
bool Thread_Completion_Flag2 = true;
bool Thread_Completion_Flag3 = true;
bool Thread_Completion_Flag4 = true;
bool Thread_Scan_Print_udp_Flag = true;
string Thread_ip0;
string Thread_ip1;
string Thread_ip2;
string Thread_ip3;
string Thread_ip4;
std::string line_Commad;//单个命令


Print_send_commd0 send_commd0;
Print_send_commd1 send_commd1;
Print_send_commd2 send_commd2;
Print_send_commd3 send_commd3;
Print_send_commd4 send_commd4;


bool Scan_Print_udp::readyToRun() {
	udp_print_Info.clear();
	Thread_Scan_Print_udp_Flag = true;

    return true;
}

bool Scan_Print_udp::threadLoop() {
    if (exitPending()) {
        return false;
    }

	if(Thread_Scan_Print_udp_Flag == true)
	{

		Udp_print_Info _print;
		Thread_Scan_Print_udp_Flag = false;
		//使用以udp协议连接IP:192.168.1.100 的8080端口
		net::Conn* conn = net::Dial("udp", "239.255.255.250:1900");
		if (conn)
		{
		  byte buf[2048] = {0};
		  const char* req =
					"M-SEARCH * HTTP/1.1\r\n"
					"HOST: 239.255.255.250:1900\r\n"
					"MAN: \"ssdp:discover\"\r\n"
					"MX: 1\r\n"
					"ST: ssdp:all\r\n"
					"USER-AGENT: Fly_lcd\r\n"
					"\r\n";
		  conn->Write((byte*)req, strlen(req));
		  while (true) {
			//读取，超时1000毫秒
			int n = conn->Read(buf, sizeof(buf) - 1, 1000);
			if (n > 0) {
			  buf[n] = 0;
	//	      LOGD("读取 %d字节： %s", n, buf);
			  //是Moonraker服务
			  if(strstr((char*)buf,"Moonraker"))
			  {
				  string data = (char*)buf;
				  _print.print_ip = data.substr(data.find("LOCATION: http://") + 10,
										  data.find("/server/zeroconf/ssdp") - (data.find("LOCATION: http://") + 10));

				  //去除7125的显示，避免客户使用7125端口浏览器访问
				  std::string::size_type pos = _print.print_ip.find(":7125");
				  if (pos != std::string::npos)
				  {
					  _print.print_ip = _print.print_ip.substr(0,pos);
				  }

				  _print.print_uuid = data.substr(data.find("USN: uuid:") + 10,
													  data.find("::upnp:") - (data.find("USN: uuid:") + 10));

				  //把单项添加到总相列表
				  udp_print_Info.push_back(_print);
			  }

			} else if (n == 0) {
//			  LOGD("连接正常断开");
			  break;
			} else if (n == net::E_TIMEOUT) {
//			  LOGD("读取超时");
			  //这里设置超时就退出
			  break;
			} else {
//			  LOGD("出错");
			  break;
			}
		  }
		  //关闭连接
//		  conn->Close();
		  //释放内存
//		  delete conn;
//		  conn = NULL;
		}


	}else
    	return false;

    usleep(1000 * 10);
    return true;
}



bool Scan_Print::readyToRun() {
	ip = 0;
    return true;
}

bool Scan_Print::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip < 13) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip);
        std::string url = "http://192.168.6.";
        url += buf;
        ip++;
        std::string url2 = url;
        //LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print1::readyToRun() {
	ip1 = 13;
    return true;
}

bool Scan_Print1::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip1 < 25) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip1);
        std::string url = "http://192.168.6.";
        url += buf;
        ip1++;
        std::string url2 = url;
       // LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print2::readyToRun() {
	ip2 = 25;
    return true;
}

bool Scan_Print2::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip2 < 37) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip2);
        std::string url = "http://192.168.6.";
        url += buf;
        ip2++;
        std::string url2 = url;
       // LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print3::readyToRun() {
	ip3 = 37;
    return true;
}

bool Scan_Print3::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip3 < 50) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip3);
        std::string url = "http://192.168.6.";
        url += buf;
        ip3++;
        std::string url2 = url;
        //LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print4::readyToRun() {
	ip4 = 50;
    return true;
}

bool Scan_Print4::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip4 < 63) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip4);
        std::string url = "http://192.168.6.";
        url += buf;
        ip4++;
        std::string url2 = url;
        //LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print5::readyToRun() {
	ip5 = 63;
    return true;
}

bool Scan_Print5::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip5 < 76) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip5);
        std::string url = "http://192.168.6.";
        url += buf;
        ip5++;
        std::string url2 = url;
        //LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print6::readyToRun() {
	ip6 = 76;
    return true;
}

bool Scan_Print6::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip6 < 89) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip6);
        std::string url = "http://192.168.6.";
        url += buf;
        ip6++;
        std::string url2 = url;
        //LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print7::readyToRun() {
	ip7 = 89;
    return true;
}

bool Scan_Print7::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip7 < 102) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip7);
        std::string url = "http://192.168.6.";
        url += buf;
        ip7++;
        std::string url2 = url;
        //LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print8::readyToRun() {
	ip8 = 102;
    return true;
}

bool Scan_Print8::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip8 < 115) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip8);
        std::string url = "http://192.168.6.";
        url += buf;
        ip8++;
        std::string url2 = url;
       // LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print9::readyToRun() {
	ip9 = 115;
    return true;
}

bool Scan_Print9::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip9 < 128) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip9);
        std::string url = "http://192.168.6.";
        url += buf;
        ip9++;
        std::string url2 = url;
        //LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);

                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}




bool Scan_Print10::readyToRun() {
	ip10 = 128;
    return true;
}

bool Scan_Print10::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip10 < 141) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip10);
        std::string url = "http://192.168.6.";
        url += buf;
        ip10++;
        std::string url2 = url;
        //LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print11::readyToRun() {
	ip11 = 141;
    return true;
}

bool Scan_Print11::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip11 < 154) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip11);
        std::string url = "http://192.168.6.";
        url += buf;
        ip11++;
        std::string url2 = url;
       // LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print12::readyToRun() {
	ip12 = 154;
    return true;
}

bool Scan_Print12::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip12 < 167) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip12);
        std::string url = "http://192.168.6.";
        url += buf;
        ip12++;
        std::string url2 = url;
       // LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print13::readyToRun() {
	ip13 = 167;
    return true;
}

bool Scan_Print13::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip13 < 180) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip13);
        std::string url = "http://192.168.6.";
        url += buf;
        ip13++;
        std::string url2 = url;
        //LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print14::readyToRun() {
	ip14 = 180;
    return true;
}

bool Scan_Print14::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip14 < 193) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip14);
        std::string url = "http://192.168.6.";
        url += buf;
        ip14++;
        std::string url2 = url;
        //LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print15::readyToRun() {
	ip15 = 193;
    return true;
}

bool Scan_Print15::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip15 < 206) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip15);
        std::string url = "http://192.168.6.";
        url += buf;
        ip15++;
        std::string url2 = url;
        //LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print16::readyToRun() {
	ip16 = 206;
    return true;
}

bool Scan_Print16::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip16 < 219) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip16);
        std::string url = "http://192.168.6.";
        url += buf;
        ip16++;
        std::string url2 = url;
        //LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print17::readyToRun() {
	ip17 = 219;
    return true;
}

bool Scan_Print17::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip17 < 232) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip17);
        std::string url = "http://192.168.6.";
        url += buf;
        ip17++;
        std::string url2 = url;
        //LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print18::readyToRun() {
	ip18 = 232;
    return true;
}

bool Scan_Print18::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip18 < 245) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip18);
        std::string url = "http://192.168.6.";
        url += buf;
        ip18++;
        std::string url2 = url;
       // LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);
                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}

bool Scan_Print19::readyToRun() {
	ip19 = 245;
    return true;
}

bool Scan_Print19::threadLoop() {
    if (exitPending()) {
        return false;
    }

    if (ip19 < 256) {
        char buf[10];
        snprintf(buf, sizeof(buf), "%d", ip19);
        std::string url = "http://192.168.6.";
        url += buf;
        ip19++;
        std::string url2 = url;
        //LOGD("ip:%s", url.c_str());

        RestClient::Connection conn(url);

        RestClient::HeaderFields headers;
        headers["Content-Type"] = "application/x-www-form-urlencoded";
        conn.SetHeaders(headers);

        conn.FollowRedirects(true);
        conn.SetTimeout(2000);

        url = "/machine/system_info";
        RestClient::Response r = conn.get(url);
        System_Info newInfo;
        Json::Reader reader;
        Json::Value root;
            // 解析 JSON 字符串
            if (reader.parse(r.body, root, false)) {

                // 访问 JSON 中的字段
                if (root.isMember("result")) {
                    Json::Value result = root["result"];

                    if (result.isMember("system_info")) {
                        Json::Value system_info = result["system_info"];

                        if (system_info.isMember("network")) {
                            Json::Value network = system_info["network"];
                            newInfo.print_ip = url2;
                            if (network.isMember("wlan0")) {
                            	Json::Value wlan0 = network["wlan0"];
                                if (wlan0.isMember("mac_address")) {

                                	newInfo.print_mac = wlan0["mac_address"].asString().c_str();
                                }

                            }else if (network.isMember("eth0")) {
                            	Json::Value eth0 = network["eth0"];
                            	if (eth0.isMember("mac_address")) {
                                	newInfo.print_mac = eth0["mac_address"].asString().c_str();
                            	}
                            }
                            System_info.push_back(newInfo);

                        }
                    }
                }
            }
    }
    else
    	return false;

    usleep(1000 * 10);
    return true;
}


















bool Scan_Print_mac::readyToRun() {
    return true;
}

bool Scan_Print_mac::threadLoop() {
    if (exitPending()) {
        return false;
    }

        size_t size = Print_info.size();

        for (int i = 0; i < (int)size; ++i)
        {
        	//主线程删除了ip列表
        	if(Print_info_size_ch == true){
        		Print_info_size_ch = false;
        		usleep(1000 * 100);
        		break;
        	}
            std::string url = Print_info[i].ip;
            RestClient::Connection conn(url);

            RestClient::HeaderFields headers;
            headers["Content-Type"] = "application/x-www-form-urlencoded";
            conn.SetHeaders(headers);

            conn.FollowRedirects(true);
            conn.SetTimeout(2000);

            url = "/printer/objects/query?print_stats=state";
            RestClient::Response r = conn.get(url);

            Json::Reader reader;
             Json::Value root;
                 // 解析 JSON 字符串
                 if (reader.parse(r.body, root, false)) {

                     // 访问 JSON 中的字段
                     if (root.isMember("result"))
                     {
                         Json::Value result = root["result"];

                         if (result.isMember("status"))
                         {
                             Json::Value status = result["status"];

                             if (status.isMember("print_stats"))
                             {
                                 Json::Value print_stats = status["print_stats"];
                                 	if (print_stats.isMember("state"))
                                 	{
                                 		//LOGD("zt:%s",print_stats["state"].asString().c_str());
                                    	//主线程删除了ip列表
                                    	if(Print_info_size_ch == true){
                                    		Print_info_size_ch = false;
                                    		usleep(1000 * 100);
                                    		break;
                                    	}
                                 		Print_info[i].state = print_stats["state"].asString().c_str();

                                 	 }

                              }
                          }


                        }
                   }else{
                   	//主线程删除了ip列表
                   	if(Print_info_size_ch == true){
                   		Print_info_size_ch = false;
                   		usleep(1000 * 100);
                   		break;
                   	}
                	   Print_info[i].state = "disconnect";
                   }
           }




    usleep(1000 * 10);
    return true;
}


bool Scan_Print_send_commd::readyToRun() {
    return true;
}

bool Scan_Print_send_commd::threadLoop() {
    if (exitPending()) {
        return false;
    }



	     int posEnter = Commad.find("\n");
	     // 已经找到\n，进行处理

		if(posEnter > 0)
		{


			line_Commad = Commad.substr(0, posEnter).c_str();
//			LOGD("COMM:%s",line_Commad.c_str());
//			while(1){

			//每个IP轮询分配给空闲的线程
			size_t size = Slave_Print_ip.size();

			for (int i = 0; i < (int)size; ++i)
			{
				//如果线程空闲就让它干活
				if(Thread_Completion_Flag0 == true)
				{
//					LOGD("aaaa");
					Thread_Completion_Flag0 = false;//完成标志重置，避免多次运行
					Thread_ip0 = Slave_Print_ip[i];//分配这个线程的ip
					//线程没开起来就开起来
					if(send_commd0.isRunning() == false)
					{
						send_commd0.run();
					}
				}else if(Thread_Completion_Flag1 == true)//如果线程空闲就让它干活
				{
//					LOGD("bbbb");
					Thread_Completion_Flag1 = false;//完成标志重置，避免多次运行
					Thread_ip1 = Slave_Print_ip[i];//分配这个线程的ip
					//线程没开起来就开起来
					if(send_commd1.isRunning() == false)
					{
						send_commd1.run();
					}
				}else if(Thread_Completion_Flag2 == true)//如果线程空闲就让它干活
				{
//					LOGD("cccc");
					Thread_Completion_Flag2 = false;//完成标志重置，避免多次运行
					Thread_ip2 = Slave_Print_ip[i];//分配这个线程的ip
					//线程没开起来就开起来
					if(send_commd2.isRunning() == false)
					{
						send_commd2.run();
					}
				}else if(Thread_Completion_Flag3 == true)//如果线程空闲就让它干活
				{
//					LOGD("dddd");
					Thread_Completion_Flag3 = false;//完成标志重置，避免多次运行
					Thread_ip3 = Slave_Print_ip[i];//分配这个线程的ip
					//线程没开起来就开起来
					if(send_commd3.isRunning() == false)
					{
						send_commd3.run();
					}
				}else if(Thread_Completion_Flag4 == true)//如果线程空闲就让它干活
				{
//					LOGD("eeeee");
					Thread_Completion_Flag4 = false;//完成标志重置，避免多次运行
					Thread_ip4 = Slave_Print_ip[i];//分配这个线程的ip
					//线程没开起来就开起来
					if(send_commd4.isRunning() == false)
					{
						send_commd4.run();
					}
				}

				//如果所有线程都忙，我们就不进行下一个IP发送
				while(Thread_Completion_Flag0 == false && Thread_Completion_Flag1 == false &&
						Thread_Completion_Flag2 == false && Thread_Completion_Flag3 == false && Thread_Completion_Flag4 == false )
				{
					usleep(1000 * 10);
				}
//				LOGD("OK");
			}


		    Commad =  Commad.erase(0, posEnter+1);		// 删除\n以前的数据和\n本身


		}

    usleep(1000 * 10);
    return true;
}



bool Print_send_commd0::readyToRun() {
    return true;
}

bool Print_send_commd0::threadLoop() {
    if (exitPending()) {
        return false;
    }

	if(Thread_Completion_Flag0 == false)
	{

		std::string url = Thread_ip0;
//		LOGD("aurl:%s",url.c_str());

		RestClient::Connection conn(url);

		RestClient::HeaderFields headers;
		headers["Content-Type"] = "application/x-www-form-urlencoded";
		conn.SetHeaders(headers);

		conn.FollowRedirects(true);
		conn.SetTimeout(2000);

		url = "/printer/gcode/script?script=" + line_Commad;
	   // LOGD("url:%s",url.c_str());

		RestClient::Response r = conn.post(encode_url(url)  ,"");
//		LOGD("POST:%s",r.body.c_str());
		Thread_Completion_Flag0 = true;

	}


    usleep(1000 * 500);
    return true;
}


bool Print_send_commd1::readyToRun() {
    return true;
}

bool Print_send_commd1::threadLoop() {
    if (exitPending()) {
        return false;
    }

	if(Thread_Completion_Flag1 == false)
	{

		std::string url = Thread_ip1;
//		LOGD("aurl:%s",url.c_str());

		RestClient::Connection conn(url);

		RestClient::HeaderFields headers;
		headers["Content-Type"] = "application/x-www-form-urlencoded";
		conn.SetHeaders(headers);

		conn.FollowRedirects(true);
		conn.SetTimeout(2000);

		url = "/printer/gcode/script?script=" + line_Commad;
	   // LOGD("url:%s",url.c_str());

		RestClient::Response r = conn.post(encode_url(url)  ,"");
//		LOGD("POST:%s",r.body.c_str());
		Thread_Completion_Flag1 = true;

	}


    usleep(1000 * 500);
    return true;
}



bool Print_send_commd2::readyToRun() {
    return true;
}

bool Print_send_commd2::threadLoop() {
    if (exitPending()) {
        return false;
    }

	if(Thread_Completion_Flag2 == false)
	{

		std::string url = Thread_ip2;
//		LOGD("aurl:%s",url.c_str());

		RestClient::Connection conn(url);

		RestClient::HeaderFields headers;
		headers["Content-Type"] = "application/x-www-form-urlencoded";
		conn.SetHeaders(headers);

		conn.FollowRedirects(true);
		conn.SetTimeout(2000);

		url = "/printer/gcode/script?script=" + line_Commad;
	   // LOGD("url:%s",url.c_str());

		RestClient::Response r = conn.post(encode_url(url)  ,"");
//		LOGD("POST:%s",r.body.c_str());
		Thread_Completion_Flag2 = true;

	}


    usleep(1000 * 500);
    return true;
}



bool Print_send_commd3::readyToRun() {
    return true;
}

bool Print_send_commd3::threadLoop() {
    if (exitPending()) {
        return false;
    }

	if(Thread_Completion_Flag3 == false)
	{

		std::string url = Thread_ip3;
//		LOGD("aurl:%s",url.c_str());

		RestClient::Connection conn(url);

		RestClient::HeaderFields headers;
		headers["Content-Type"] = "application/x-www-form-urlencoded";
		conn.SetHeaders(headers);

		conn.FollowRedirects(true);
		conn.SetTimeout(2000);

		url = "/printer/gcode/script?script=" + line_Commad;
	   // LOGD("url:%s",url.c_str());

		RestClient::Response r = conn.post(encode_url(url)  ,"");
//		LOGD("POST:%s",r.body.c_str());
		Thread_Completion_Flag3 = true;

	}


    usleep(1000 * 500);
    return true;
}



bool Print_send_commd4::readyToRun() {
    return true;
}

bool Print_send_commd4::threadLoop() {
    if (exitPending()) {
        return false;
    }

	if(Thread_Completion_Flag4 == false)
	{

		std::string url = Thread_ip4;
//		LOGD("aurl:%s",url.c_str());

		RestClient::Connection conn(url);

		RestClient::HeaderFields headers;
		headers["Content-Type"] = "application/x-www-form-urlencoded";
		conn.SetHeaders(headers);

		conn.FollowRedirects(true);
		conn.SetTimeout(2000);

		url = "/printer/gcode/script?script=" + line_Commad;
	   // LOGD("url:%s",url.c_str());

		RestClient::Response r = conn.post(encode_url(url)  ,"");
//		LOGD("POST:%s",r.body.c_str());
		Thread_Completion_Flag4 = true;

	}


    usleep(1000 * 500);
    return true;
}




