/*
 * Scan_Print.h
 *
 *  Created on: 2024年1月9日
 *      Author: Fly
 */

#ifndef JNI_LOGIC_SCAN_PRINT_H_
#define JNI_LOGIC_SCAN_PRINT_H_


// Scan_Print.h

#pragma once
#include <APP/Socket.h>

#include <system/Thread.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <cstring>
#include <sstream>

class Scan_Print_udp : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};



class Scan_Print : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};


class Scan_Print1 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print2 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print3 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print4 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print5 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print6 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print7 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print8 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print9 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};
class Scan_Print10 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};


class Scan_Print11 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print12 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print13 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print14 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print15 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print16 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print17 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print18 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Scan_Print19 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};
class Scan_Print_mac : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};


class Scan_Print_send_commd : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Print_send_commd0 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};


class Print_send_commd1 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Print_send_commd2 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Print_send_commd3 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Print_send_commd4 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};

class Print_send_commd5 : public Thread {
public:
    virtual bool readyToRun();
    virtual bool threadLoop();
};



struct System_Info {
    std::string print_ip;
    std::string print_mac;
    std::string print_uuid;
//    std::string print_eth0_ip;
//    std::string print_eth0_mac;
};
extern std::vector<System_Info> System_info;

struct Udp_print_Info {
    std::string print_ip;
    std::string print_uuid;

};
extern std::vector<Udp_print_Info> udp_print_Info;



//群控命令集合
extern std::string Commad;

#endif /* JNI_LOGIC_SCAN_PRINT_H_ */
