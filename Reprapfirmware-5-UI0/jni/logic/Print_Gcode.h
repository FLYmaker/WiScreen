/*
 * Marlin_serial_data.h
 *
 *  Created on: 2024年7月11日
 *      Author: 10589
 */

#ifndef JNI_LOGIC_PRINT_GCODE_H_
#define JNI_LOGIC_PRINT_GCODE_H_


#include <system/Thread.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <cstring>
#include <sstream>

void printGCode(std::string file, int index) ;
bool find_Preheat_temp(std::string file, int index);

void sendLine();

#endif /* JNI_LOGIC_PRINT_GCODE_H_ */
