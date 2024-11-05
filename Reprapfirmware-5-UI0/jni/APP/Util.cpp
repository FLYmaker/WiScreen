/*
 * Util.cpp
 *
 *  Created on: 2021年11月25日
 *      Author: 23398
 */

#include "Util.h"

void Util::HttpErr() {

}

void Util::SetIp(char* ip) {
	StoragePreferences::putString("ip", ip);
}

void Util::SetIp(string ip) {
	StoragePreferences::putString("ip", ip);
}

string Util::GetIp(){
	return StoragePreferences::getString("ip", "");
}

void Util::SetPort(char* port) {
	StoragePreferences::putString("port", port);
}

void Util::SetPort(string port) {
	StoragePreferences::putString("port", port);
}

string Util::GetPort(){
	return StoragePreferences::getString("port", "");
}

/////////////////////////////

string Util::GetToken(){
	return StoragePreferences::getString("token", "");
}
string Util::GetToken_Auth(){
	return StoragePreferences::getString("token_auth", "");
}
string Util::GetToken_Refr(){
	return StoragePreferences::getString("token_refr", "");
}
