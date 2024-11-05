/*
 * Marlin_serial_data.cpp
 *
 *  Created on: 2024年7月11日
 *      Author: 10589
 */
#include "Print_Gcode.h"

#include <string.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include "utils/Log.h"
#include <vector>
#include <string.h>
#include "uart/UartContext.h"
extern FILE* f;
extern std::string send_gcode_buff;
extern bool can_send;
extern void Send_serial_commands();

int cur_print_file_size = 0;
int cur_file_size = 0;


//void processPrinterCodeLine(std::string data);
//extern std::string Serial_data;
//extern std::string send_gcode_buff;
//
//std::vector<std::string> tempItems;
//std::vector<std::string> xyze_pos;
//
//void send(std::string j_gcodes);
//void Send_serial_commands();

// 发送一行
void sendLine() {
 	if(!f){
 		LOGD("打开失败");
 		return;
 	}


 	//canSend = true;
 	char buf[1024];
 	char* rslt = NULL;
 	do {

 		rslt = fgets(buf, sizeof(buf), f);
 		cur_file_size = ftell(f);
 		// 发送完成
 		if(rslt == NULL)
 		{	// 文件读完了

 			can_send = false;
			fflush(f);
			fclose(f);
			sync();
			f = NULL;
 		    send_gcode_buff += "printok\r\n";

            return;
 		}

 		// 消除前导空格
 		int len = strlen(rslt);
 		for(int i = 0; i < len; i++) {
 			if(*rslt == ' ')
 				rslt ++;
 			else
 				break;
 		}

 		// 查找分号
 		char* pos = strstr(rslt, ";");
 		if(pos != NULL) {
 			if(rslt[0] == ';')
 				*pos = 0;
 			else {
 				*pos ++ = '\r';
 				*pos ++ = '\n';
 				*pos = NULL;
 			}
 		}
 		if((rslt[0] == '\r') || (rslt[0] == '\n'))
 			rslt[0] = 0;

        // 检查这一行是否以 exclude_prefix 开头
        if (strncmp(buf, "EXCLUDE_OBJECT", 14) == 0) {
        	//这一行没超过1024个
        	if(strchr(buf, '\n'))
        	{
        	  sendLine();
        	  return;
        	}
            // 如果这一行数据超过了 1023 个字符，需要继续读取直到这一行结束
            while(1){
            	rslt = fgets(buf, sizeof(buf), f);
            	if(strchr(buf, '\n'))
            	{
            		sendLine();
            		return;
            	}
            }
        }


 	} while(rslt[0] == 0);

 	//排除打印那些不发送
 	if(strstr(rslt, "M105")
 			|| strstr(rslt, "EXCLUDE_OBJECT")
 			|| strstr(rslt, "POLYGON")
			|| strstr(rslt, "PRINT_START")
			|| strstr(rslt, "SET_VELOCITY")) {
 		sendLine();

 		return;
 	}

 	send_gcode_buff += rslt ;
//LOGD("neirong:%s",send_gcode_buff.c_str());

 	cur_file_size = ftell(f);
//	LOGD("大小:%d",cur_file_size);

// 	LOGD("大小:%d",send_gcode_buff.size());
//





 }



void printGCode(std::string file, int index) {
 	fseek(f,0,SEEK_END);//把文件指针放到文件末尾的位置
 	cur_print_file_size = ftell(f);//得到文件大小，以字节为单位
// 	LOGD("大小a:%d",cur_print_file_size);
 	fseek(f,0,SEEK_SET);//把文件指针放到文件开始的位置

	can_send = true;
//    	printinit();

	sendLine();
	Send_serial_commands();
 }


bool find_Preheat_temp(std::string file, int index) {
	if(!f){
 		LOGD("打开失败");
 		return false;
 	}
	bool find_heat = false;
	bool find_bed = false;

 	while(1){


 	char buf[1024];
 	char* rslt = NULL;
 	do {

 		rslt = fgets(buf, sizeof(buf), f);
 		cur_file_size = ftell(f);
 		// 发送完成
 		if(rslt == NULL)
 		{	// 文件读完了

			fflush(f);
			fclose(f);
			sync();
			f = NULL;

            return false;
 		}

 		// 消除前导空格
 		int len = strlen(rslt);
 		for(int i = 0; i < len; i++) {
 			if(*rslt == ' ')
 				rslt ++;
 			else
 				break;
 		}

 		// 查找分号
 		char* pos = strstr(rslt, ";");
 		if(pos != NULL) {
 			if(rslt[0] == ';')
 				*pos = 0;
 			else {
 				*pos ++ = '\r';
 				*pos ++ = '\n';
 				*pos = NULL;
 			}
 		}
 		if((rslt[0] == '\r') || (rslt[0] == '\n'))
 			rslt[0] = 0;


 	} while(rslt[0] == 0);


	if(strstr(rslt,"M190")){

		send_gcode_buff += "M140 ";
		send_gcode_buff += strstr(rslt,"S");
		find_bed = true;
	}
	if(strstr(rslt,"M109")){

		send_gcode_buff += "M104 ";
		send_gcode_buff += strstr(rslt,"S");
		find_heat = true;
	}

	if(find_heat && find_bed){
		fflush(f);
		fclose(f);
		sync();
		f = NULL;
		return true;
	}

 }

}

