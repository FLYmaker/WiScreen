/*
 * Print_save.h
 *
 *  Created on: 2024年2月27日
 *      Author: Fly
 */

#ifndef JNI_LOGIC_PRINT_SAVE_H_
#define JNI_LOGIC_PRINT_SAVE_H_

extern void Save_all_print_info();

extern void Init_print_info();
struct Print_Info {
	std::string mac;
    std::string name;
    std::string ip;
    std::string img;
    std::string uuid;
    std::string state;//0失联 黑，1空闲 白色，2打印 蓝色，3暂停 黄色，4打完 绿色
};
extern std::vector<Print_Info> Print_info;

extern bool Print_info_size_ch ;
#endif /* JNI_LOGIC_PRINT_SAVE_H_ */
