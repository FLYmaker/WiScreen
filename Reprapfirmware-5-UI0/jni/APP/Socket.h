/*
 * Socket.h
 *
 *  Created on: 2021年11月23日
 *      Author: 23398
 */

#ifndef JNI_APP_SOCKET_H_
#define JNI_APP_SOCKET_H_


#include "app/Activity.h"
#include "entry/EasyUIContext.h"

#include "uart/ProtocolData.h"
#include "uart/ProtocolParser.h"

#include "utils/Log.h"
#include "control/ZKDigitalClock.h"
#include "control/ZKButton.h"
#include "control/ZKCircleBar.h"
#include "control/ZKDiagram.h"
#include "control/ZKListView.h"
#include "control/ZKPointer.h"
#include "control/ZKQRCode.h"
#include "control/ZKTextView.h"
#include "control/ZKSeekBar.h"
#include "control/ZKEditText.h"
#include "control/ZKVideoView.h"
#include "window/ZKSlideWindow.h"
#include "uart/ProtocolSender.h"
#include "json/json.h"

#include "curl/curl.h"

#include "easywsclient/easywsclient.hpp"

#include <assert.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>

#include <system/Thread.h>
#include "restclient-cpp/restclient.h"


using easywsclient::WebSocket;
static WebSocket::pointer WS = NULL;

void HttpErr();
void Start_WebSocket(string ip,string port,string token);
void Close();
#endif /* JNI_APP_SOCKET_H_ */
