/*
 * gcodeLogic.h
 *
 *  Created on: 2024年2月24日
 *      Author: Fly
 */

#ifndef JNI_LOGIC_GCODELOGIC_H_
#define JNI_LOGIC_GCODELOGIC_H_


typedef struct {
	uint32_t color;
} ERCF_COLOR;
static ERCF_COLOR ercf_color[] = {

		{0xFFB22222},
		{0xFFFF0000},
		{0xFFFF4500},
		{0xFFFA8072},

		{0xFFFF6100},
		{0xFFFF8000},
		{0xFFFFD700},
		{0xFFFFE384},

		{0xFF6A5ACD},
		{0xFF4169E1},
		{0xFF87CEEB},
		{0xFF00FFFF},

		{0xFF385E0F},
		{0xFF228B22},
		{0xFF00FF00},
		{0xFFBDFCC9},

		{0xFF8A2BE2},
		{0xFFA020F0},
		{0xFFA066D3},
		{0xFFDA70D6},

		{0xFF802A2A},
		{0xFF8A360F},
		{0xFFD2691E},
		{0xFFD2B48C},

		{0xFF000000},
		{0xFF292421},
		{0xFF808069},
		{0xFFC0C0C0},

		{0xFFFFFFFF},
		{0xFFFAEBD7},
};

int ERCF_GATE_SW_index[32];




typedef struct {
	const char* mainText;
} Print_set;
static Print_set print_set[] = {
		{"name"},
		{"picture"},
		{"ip addr"},
		//{"同步主机的配置"},
		{"delete"},
		{"close"},
};



int cur_print_set_num = 0;

//同步文件时下载文件路径
std::string Sync_file_name;

void notify_open_close(bool sw_layer);
//通知消息储存
vector<string>Notify_message_list;
//上传文件进度列表
vector<string>upload_progress_list;
//上传文件速度列表
vector<string>upload_speed_list;
////上传文件当前第几项

//群控命令集合
std::string Commad;

void temp_layer_ch(int layer);

//检查有没有安装u盘或者sd卡
bool udesk = false;
bool sdcard = false;
bool up_download_sw = false;
bool up_file_and_print = false;
//static double total_downloaded;
double up_download_speed = 0;
double up_speed = 0;

double up_download_time = 0;

extern double total_to_download;
//struct UP_FILE_Info {
//    double up_progress;
//    std::string print_ip;
//
//};
//extern std::vector<UP_FILE_Info> UP_file_Info;
bool ws_closs = false;

//文件列表文件夹
vector<string>file_dir;
//每点击一次文件夹就记录一次
std::string cur_file_dir;
int cur_selected_file_index = 0;

struct WIFI_Info {
	bool use;
	std::string bssid;
    std::string ssid;
    int signal;
    std::string security;
    int freq;
};
// 声明一个 vector，其中存储 GcodeFileInfo 对象
std::vector<WIFI_Info> WiFi_Info;

struct WIFI_Devices_Info {
	string name;
	string type;
	string state;
	string connection;
};
// 声明一个 vector，其中存储 GcodeFileInfo 对象
std::vector<WIFI_Devices_Info> WIFI_devices_Info;

struct Devices_Info {
	string connection;
	string ip_address;
};
// 声明一个 vector，其中存储 GcodeFileInfo 对象
std::vector<Devices_Info> devices_Info;

struct Recorded_Wifi {
	string uuid;
	string ssid;
};
// 声明一个 vector，其中存储 GcodeFileInfo 对象
std::vector<Recorded_Wifi> Recorded_wifi;



bool Start_connect_wifi = false;//在线程里连接wifi
bool Disconnect_wifi = false;//在线程里断开wifi
bool Forget_wifi = false;//在线程里忘记wifi

//记录当前Z偏移值，如果不为0打印状态发生变化就保存；
float cur_zoffset = 0;

//用于再download线程里要下载哪个
bool Download_thumbnail = false;
bool Download_file_thumbnail = false;
bool Download_graph_mesh = false;//热床3d图

bool open_cam = false;//打开摄像头
//bool Download_obj = false;

//透明窗口的一些内容
bool down_menu_sw = false;
bool down_menu_close_sw = false;
int down_menu_y_Pos = 0;
int down_menu_Alpha = 0;


int del_Customize_num = 0;


int cur_Place_pos = 1;

float zoffset_size = 0.005;


typedef struct {
	const char* mainText;
	string num;
} Print_speed_info;
static Print_speed_info speed_info[] = {
	{ "Request speed",  "100mm/s" },
	{ "Move speed",  "100%" },
	{ "Extrusion flow",  "100%"  },
	{ "Pressure compensation",  "0.04s" },
	{ "Smoothing time",   "0.04s" },
	{ "Maximum speed",   "5000mm/s" },
	{ "Cornering speed",  "5mm/s" },
	{ "Acceleration",   "10000mm/s²" },
};

string fan1_name;
string fan2_name;
std::vector<string> Host_Macros_list;


typedef struct {
	string mainText;
	string gpio;
} Gpio_list;
static Gpio_list gpio_list[] = {
	{ "Unbound GPIO","null"},
	{ "PE8","GPIO_136"},		//128+8
	{ "PE10","GPIO_138"},		//128+10
	{ "PG8","GPIO_200"},		//192+8
	{ "PG9","GPIO_201"},		//192+9
	{ "PG10","GPIO_202"},		//192+10
	{ "PG11","GPIO_203"},		//192+11
};
string Selected_gpio = "null";

//取消/暂停打印，后5秒内不进行状态更新，以免关闭了打印界面，http刷新，再重复打开，影响体验
bool print_cancel_state = false;
bool print_pause_state = false;

#endif /* JNI_LOGIC_GCODELOGIC_H_ */
