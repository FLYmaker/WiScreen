/*
 * Marlin_serial_data.h
 *
 *  Created on: 2024年7月11日
 *      Author: 10589
 */

#ifndef JNI_LOGIC_MARLIN_SERIAL_DATA_H_
#define JNI_LOGIC_MARLIN_SERIAL_DATA_H_


#include <system/Thread.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <cstring>
#include <sstream>

class Serial_Data_Parsing : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};




extern int Fan0_Speed;
extern int Fan1_Speed;
extern int Fan2_Speed;

extern void Send_serial_commands();

#endif /* JNI_LOGIC_MARLIN_SERIAL_DATA_H_ */
