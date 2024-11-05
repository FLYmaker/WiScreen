/*
 * Hardware_GPIO.cpp
 *
 *  Created on: 2024年8月5日
 *      Author: 10589
 */
#include "Hardware_GPIO.h"
#include "utils/GpioHelper.h"
#include <vector>
#include <string.h>
#include "utils/Log.h"

extern void gcode_send(std::string godes,bool move,bool is_Calibration,bool is_Send_directly);
std::vector<Customize_buttons> Customize_button;



bool GPIO::readyToRun() {
    GpioHelper::initPinMap(138, 1, 1);

    return true;
}

bool GPIO::threadLoop() {
    if (exitPending()) {
        return false;
    }

	for(int i=0; i< (int)Customize_button.size(); i++){
		 if(Customize_button[i].Gpio != "null")
		 {
			 LOGD("按钮:%s",Customize_button[i].Gpio.c_str());
			 int state = GpioHelper::input(Customize_button[i].Gpio.c_str());

			 if(state == 0){
				 usleep(1000 * 100);
				 state = GpioHelper::input(Customize_button[i].Gpio.c_str());
				 //触发后，等200ms还在触发状态说明是在触发，防抖
				 if(state == 0){
					 gcode_send(Customize_button[i].gcode,false,false,false);
				 	 while(GpioHelper::input(Customize_button[i].Gpio.c_str()) == 0);//简单实现，只能单通道输入，不能多个按钮同时按下
				 }
			 }
		 }
	}




    usleep(1000 * 100);
    return true;
}

