/*
 * Util.h
 *
 *  Created on: 2021年11月25日
 *      Author: 23398
 */
#include "app/Activity.h"
#include "entry/EasyUIContext.h"

#include "uart/ProtocolSender.h"
#include "storage/StoragePreferences.h"
#include <assert.h>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cstring>

#ifndef JNI_APP_UTIL_H_
#define JNI_APP_UTIL_H_

class Util {
public:

	static void HttpErr();
	static void SetIp(char* ip);
	static void SetIp(string ip);
	static string GetIp();

	static void SetPort(char* port);
	static void SetPort(string port);
	static string GetPort();

	static string GetToken();
	static string GetToken_Auth();
	static string GetToken_Refr();
};

#endif /* JNI_APP_UTIL_H_ */
