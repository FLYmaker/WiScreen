/*
 * Socket.cpp
 *
 *  Created on: 2021年11月23日
 *      Author: 23398
 */
#include "Socket.h"

#include "../activity/mainActivity.h"

class Socket_Thread: public Thread {
public:
	virtual bool readyToRun() {
		return true;
	}
	virtual bool threadLoop() {
		if (exitPending()) {
			return false;
		}
		/*
		 //解析json
		 Json::Reader reader;
		 Json::Value root;
		 if (reader.parse(r.body, root, false)) {
		 LOGD("解析成功");
		 //解析json时，一定要多多检查输入的合法性，避免非法输入造成程序崩溃。
		 if (root.isMember("result")) {
		 //连接WebSocket
		 //LOGD("ws://192.168.3.188/websocket?token=%s",
		 //		root["result"].asString().c_str());

		 WS = WebSocket::from_url(
		 "ws://192.168.3.188/websocket?token="
		 + root["result"].asString(),
		 "http://192.168.3.188");
		 assert(WS);
		 LOGD("WebSocket连接");
		 //mTextView1Ptr->setText("WebSocket连接");
		 //WS->send("goodbye");
		 WS->send(
		 "{\"id\":38166,\"method\":\"server.info\",\"jsonrpc\":\"2.0\"}");
		 while (WS->getReadyState() != WebSocket::CLOSED) {
		 WS->poll();
		 WS->dispatch(handle_message);
		 }
		 LOGD("WebSocket断开");
		 //mTextView1Ptr->setText("WebSocket断开");
		 delete WS;
		 }
		 }
		 */
		//返回真，继续下次线程循
		return true;
	}
};
static Socket_Thread socket_thread;

mainActivity mact;
void handle_message(const std::string & message) {
	//printf(">>> %s\n", message.c_str());
	//LOGD("%s", message.c_str());

}



void Close(){
	WS->close();
}
void HttpErr() {

}
