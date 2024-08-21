/*
 * Hardware_GPIO.h
 *
 *  Created on: 2024年8月5日
 *      Author: 10589
 */

#ifndef JNI_LOGIC_HARDWARE_GPIO_H_
#define JNI_LOGIC_HARDWARE_GPIO_H_


#include <string.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <system/Thread.h>

class GPIO : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

struct Customize_buttons {
	std::string name;//自定义按钮名字
	std::string type;//gcode/moon api
	std::string gcode;//gcode或者moon api内容
	std::string Gpio;//绑定物理引脚按钮
};
extern std::vector<Customize_buttons> Customize_button;
static GPIO gPIO;



#endif /* JNI_LOGIC_HARDWARE_GPIO_H_ */
