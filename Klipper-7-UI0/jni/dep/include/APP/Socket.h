/*
 * Socket.h
 *
 *  Created on: 2021年11月23日
 *      Author: 23398
 */

#ifndef SRC_APP_SOCKET_H_
#define SRC_APP_SOCKET_H_


#include <assert.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>

#include "curl/curl.h"
#include "easywsclient/easywsclient.hpp"
#include "app/Activity.h"
#include "control/ZKButton.h"
#include "control/ZKCircleBar.h"
#include "control/ZKDiagram.h"
#include "control/ZKDigitalClock.h"
#include "control/ZKEditText.h"
#include "control/ZKListView.h"
#include "control/ZKPointer.h"
#include "control/ZKQRCode.h"
#include "control/ZKSeekBar.h"
#include "control/ZKTextView.h"
#include "control/ZKVideoView.h"
#include "entry/EasyUIContext.h"
#include "json/json.h"
#include "system/Thread.h"
#include "utils/Log.h"
#include "window/ZKSlideWindow.h"
#include "restclient-cpp/restclient.h"
#include "uart/ProtocolData.h"
#include "uart/ProtocolParser.h"
#include "uart/ProtocolSender.h"


using easywsclient::WebSocket;
static WebSocket::pointer WS = NULL;

void HttpErr();
void Start_WebSocket(string ip,string port,string token);
void Close();
#endif /* SRC_APP_SOCKET_H_ */
