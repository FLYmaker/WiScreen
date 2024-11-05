#pragma once
#include "uart/ProtocolSender.h"
#include "storage/StoragePreferences.h"
#include "uart/UartContext.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include "security/SecurityManager.h"
#include "include/control/ZKTextView.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include "utils/BrightnessHelper.h"
#include "entry/EasyUIContext.h"
#include "manager/ConfigManager.h"
#include "os/MountMonitor.h"
#include <iostream>
#include <fstream>
#include "manager/ConfigManager.h"
#include <iomanip>
#include <cctype>
#include <sstream>

#include <iostream>
#include <vector>

#include <cstring>

#include "Scan_Print.h"
#include "Print_save.h"

#include <APP/Version.h>
#include <APP/Socket.h>
#include <APP/Util.h>

#include "gcodeLogic.h"
#include "manager/LanguageManager.h"
#include "sys/sysinfo.h"
#include "net/NetManager.h"
#include <system/Thread.h>

#include "shttpd/shttpd.h"

#include "json/json.h"
#include "curl/curl.h"
#include <cmath>

#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "upfile/upfile.h"

#include <entry/EasyUIContext.h>


#include <cerrno>

#include "screenconfig.h"

#include <sys/reboot.h>

#include "../dep/include/restclient-cpp/connection.h"
#include "../dep/include/restclient-cpp/restclient.h"
#include "Hardware_GPIO.h"
#include "utils/GpioHelper.h"

#include<unistd.h>
#include<sys/reboot.h>

string http_objects;
string HTTP_data_request;//http模式下，所有数据请求都存到这里
bool HTTP_is_Connection = false;


bool file_progress_lise_ref = false;
extern double file_progress;
extern double upload_progress;

std::string IMETexT ;
namespace { //匿名命名空间

 class IMETextUpdateListener: public IMEContext::IIMETextUpdateListener {
 public:
   virtual void onIMETextUpdate(const std::string &text) {
	   IMETexT = text;
   }

 };

 //定义实例
 static IMETextUpdateListener ime_text_update_listener;
 }

void Subscription_status();
void get_file(std::string gcode_path);
void get_Host_Macros_list();
//对象排除信息储存
struct Exclude_Object {
	vector<float> button_pos;
	float button_xpos;
	float button_ypos;
	float button_height;
	float button_Width;
	float button_mid_x;
	float button_mid_y;

    std::string name;

};
// 声明一个 vector，其中存储 Exclude_object 对象
std::vector<Exclude_Object> exclude_object;
int exclude_object_id = 0;
void init_exclude_obj();

void printJsonValue(const Json::Value& value, Exclude_Object& object);
//储存缩略图文件路径
string Save_Path = "/tmp/";

std::string sw_id ;

void New_Sw_id() {
    // 设置随机数种子
    char buf[12];
    // 生成随机数
	int id = std::rand() % 999999 + 1000;
    snprintf(buf,sizeof(buf),"%d",id);
    sw_id = buf;


}
#define  WIFIMANAGER    NETMANAGER->getWifiManager()
#define  ETHMANAGER    NETMANAGER->getEthernetManager()
int window_cur_mid_xpos = 400;
int window_cur_mid_ypos = 300;
bool layer_open = false;
bool move_button = false;//任意一个移动按钮按下后将记录按下状态，以便抬起时切换图片

int speed_factor = 100;

bool Print_info_size_ch = false;
std::vector<Udp_print_Info> udp_print_Info; // 全局变量的定义
std::vector<System_Info> System_info; // 全局变量的定义
//PID校准温度设置
std::string Pid_ext_temp = "210";
std::string Pid_bed_temp = "60";

//设置需要弹起键盘按钮的id,点击确认时已此id辨别
int AJ_id = 0;
int yes_no_id = 0;
//兔子切换头全局变量
int ERCF_GATE = 0;
//设置风扇速度
int Fan0_Speed = 0,Fan1_Speed = 0,Fan2_Speed = 0;

//打印界面显示
std::string Print_Filename;
int total_layer = 0;
int current_layer = 0;

std::string Select_Filename;

bool start_scan_print_ip = false;

void gcode_send(std::string godes,bool move,bool is_Calibration,bool is_Send_directly);
void gcode_send2(std::string method,std::string params);
//用于储存需要校准哪些项
void run_next_Calibration();
vector<string> Calibration_term;
vector<string> Calibration_error;
bool Calibration_sw = false;
bool Calibration_Break_ok = false;
bool Calibration_send_Z_TILT = false;
bool Calibration_wait_reboot = false;
std::string Cur_Calibration_id;
int Cur_Calibration_term = 0;
int Calibration_yes_no[10];

std::vector<string> gcodes_message;
//
std::string file_sw_id;

//vector<string> File_Gcodes;//储存文件或者宏文件名称及文件夹
struct GcodeFileInfo {
	int estimated_time;
	int filament_total;
    std::string path;
    double modified;
    std::string slicer;
    int size;
    float first_layer_extr_temp;
    float first_layer_bed_temp;
//    std::string permissions;
    std::string thumbnail_path_smail;
    std::string thumbnail_path_big;
};
// 声明一个 vector，其中存储 GcodeFileInfo 对象
std::vector<GcodeFileInfo> File_Gcodes;
// 自定义比较函数，用于排序
bool compareByModified(const GcodeFileInfo& a, const GcodeFileInfo& b) {
    return a.modified > b.modified;
}




struct Current_file_information {
	float object_height;//模型高度
	int estimated_time;//剩余时间
	float layer_height;//层高
	float first_layer_height;//首层高度
	float filament_total;//耗材长度

	//print_stats
	float filament_used;//打印了的耗材长度
	std::string filename;//打印的文件名
	float print_duration;//打印时间
	std::string state;//打印状态

	//virtual_sdcard
	float progress;//打印进度
	string slicer;

};
Current_file_information current_file_information;

struct MMU {
	int cur_tool_num;//当前工具头
	int all_tool_num;//一共多少个头

};
MMU mmu;


int start_print_button_x = 0;
int end_print_button_x = 0;

//超时时间
int time_out = 0;

typedef struct {
	const char* mainText;
	bool bOn;
} more_time;
static more_time moretime[] = {
	{ "Never",  false },
	{ "10S",    false },
	{ "30S",    false  },
	{ "1minute",   false },
	{ "2minute",   false },
	{ "5minute",   false },
	{ "30minute",  false },
	{ "1hour",   false },

};

typedef struct {
	const char* mainText;
	bool bOn;
} Lanugage;
static Lanugage lanugage[] = {
	{ "中文",  false },
	{ "English",    false },
};


/*
*此文件由GUI工具生成
*文件功能：用于处理用户的逻辑相应代码
*功能说明：
*========================onButtonClick_XXXX
当页面中的按键按下后系统会调用对应的函数，XXX代表GUI工具里面的[ID值]名称，
如Button1,当返回值为false的时候系统将不再处理这个按键，返回true的时候系统将会继续处理此按键。比如SYS_BACK.
*========================onSlideWindowItemClick_XXXX(int index) 
当页面中存在滑动窗口并且用户点击了滑动窗口的图标后系统会调用此函数,XXX代表GUI工具里面的[ID值]名称，
如slideWindow1;index 代表按下图标的偏移值
*========================onSeekBarChange_XXXX(int progress) 
当页面中存在滑动条并且用户改变了进度后系统会调用此函数,XXX代表GUI工具里面的[ID值]名称，
如SeekBar1;progress 代表当前的进度值
*========================ogetListItemCount_XXXX() 
当页面中存在滑动列表的时候，更新的时候系统会调用此接口获取列表的总数目,XXX代表GUI工具里面的[ID值]名称，
如List1;返回值为当前列表的总条数
*========================oobtainListItemData_XXXX(ZKListView::ZKListItem *pListItem, int index)
 当页面中存在滑动列表的时候，更新的时候系统会调用此接口获取列表当前条目下的内容信息,XXX代表GUI工具里面的[ID值]名称，
如List1;pListItem 是贴图中的单条目对象，index是列表总目的偏移量。具体见函数说明
*========================常用接口===============
*LOGD(...)  打印调试信息的接口
*mTextXXXPtr->setText("****") 在控件TextXXX上显示文字****
*mButton1Ptr->setSelected(true); 将控件mButton1设置为选中模式，图片会切换成选中图片，按钮文字会切换为选中后的颜色
*mSeekBarPtr->setProgress(12) 在控件mSeekBar上将进度调整到12
*mListView1Ptr->refreshListView() 让mListView1 重新刷新，当列表数据变化后调用
*mDashbroadView1Ptr->setTargetAngle(120) 在控件mDashbroadView1上指针显示角度调整到120度
*
* 在Eclipse编辑器中  使用 “alt + /”  快捷键可以打开智能提示
*/
//网页的json设置
std::string master_print_ip = "192.168.1.100";
std::vector<std::string> Slave_Print_ip;
RestClient::Connection* conn = nullptr;//HTTP连接
RestClient::Connection* http_ca_conn = nullptr;//HTTP连接

std::string xz_print_ip;

Scan_Print_udp scan_Print_udp;
Scan_Print scan_print;
Scan_Print1 scan_print1;
Scan_Print2 scan_print2;
Scan_Print3 scan_print3;
Scan_Print4 scan_print4;
Scan_Print5 scan_print5;
Scan_Print6 scan_print6;
Scan_Print7 scan_print7;
Scan_Print8 scan_print8;
Scan_Print9 scan_print9;
Scan_Print10 scan_print10;
Scan_Print11 scan_print11;
Scan_Print12 scan_print12;
Scan_Print13 scan_print13;
Scan_Print14 scan_print14;
Scan_Print15 scan_print15;
Scan_Print16 scan_print16;
Scan_Print17 scan_print17;
Scan_Print18 scan_print18;
Scan_Print19 scan_print19;
Scan_Print_mac scan_Print_mac;
Scan_Print_send_commd scan_Print_send_commd;



void layer_ch(int layer);


int Machine_state = 0;//0:idle 1:printing 2:prusa  3;打完状态
bool canSend = false;
string curr_tool;
bool can_running = false;
//发送命令的缓存
//string send_gcode_buff;
//string send_gcode_buff2;

static std::string sContentStr;//键盘相关设置
static void delOneChar();
static void addOneChar(char ch) {
	cur_Place_pos ++;//位置符增加
	sContentStr += ch;
	//sContentStr += "|"
	mTextView22Ptr->setText(sContentStr);
	if(mAJ1Ptr->isVisible())
		mTextView46Ptr->setText(sContentStr);
	if(mlockPtr->isVisible())
		mButton18Ptr->setText(sContentStr);
}

static void delOneChar() {
	cur_Place_pos --;//位置符减小
	if (!sContentStr.empty()) {
		sContentStr.erase(sContentStr.length() - 1, 1);

		mTextView22Ptr->setText(sContentStr);
		if(mAJ1Ptr->isVisible())
			mTextView46Ptr->setText(sContentStr);
		if(mlockPtr->isVisible())
			mButton18Ptr->setText(sContentStr);
	}
}
//复制文件到指定目录

void copyFile(const std::string& sourcePath, const std::string& destinationPath) {
    std::ifstream sourceFile(sourcePath.c_str(), std::ios::binary | ifstream::in);
    std::ofstream destinationFile(destinationPath.c_str(), std::ios::binary | std::ios::out);

    if (sourceFile && destinationFile) {
        destinationFile << sourceFile.rdbuf();
        LOGD("File copied successfully.");
    } else {
        LOGD("Error copying file. Source file open:%d,%d " , sourceFile.is_open() ,destinationFile.is_open());
    }
//    // 以二进制模式打开源文件进行读取
//    std::ifstream sourceFile(sourcePath.c_str(), std::ios::binary | std::ifstream::in);
//
//    // 检查源文件是否打开成功
//    if (sourceFile.is_open()) {
//        // 以二进制模式打开目标文件进行写入
//
//
//        FILE* destinationFile = fopen(destinationPath.c_str(), "wb");
//
//        // 检查目标文件是否打开成功
//        if (destinationFile) {
//            // 使用 fread 和 fwrite 读取和写入数据
//            size_t bufferSize = 4096;
//            char buffer[bufferSize];
//            while (!sourceFile.eof()) {
//                sourceFile.read(buffer, bufferSize);
//                size_t bytesRead = sourceFile.gcount();
//                if (bytesRead > 0) {
//                    fwrite(buffer, 1, bytesRead, destinationFile);
//                }
//            }
//
//            // 关闭目标文件
//            fclose(destinationFile);
//        } else {
//            // 处理目标文件打开失败的情况
//        	LOGD("文件打开失败");
//        }
//
//        // 关闭源文件
//        sourceFile.close();
//    } else {
//    	LOGD("路径打开失败");
//        // 处理源文件打开失败的情况
//    }
}




string currentDirectory;
string fileName;
enum FileType { E_FILETYPE_HOME, E_FILETYPE_BACK, E_FILETYPE_FOLDER, E_FILETYPE_FILE, E_FILETYE_MAX };

struct FileInfo {
	string fileName;
	FileType fileType;
	long datetime;
};
vector<FileInfo> fileInfos;
bool compare(const FileInfo& inf1, const FileInfo& inf2) {
	return inf1.datetime > inf2.datetime;
}
// 列出TF卡中的文件夹
void listFiles(string folder, string subFolder,bool img) {
	// /mnt/extsd就是顶级目录

	if((folder == "/mnt") && (subFolder == ".."))
		return;

	fileInfos.clear();
//	fileInfos.push_back({"返回主目录", E_FILETYPE_HOME});
//	fileInfos.push_back({"返回上级目录", E_FILETYPE_BACK});

	if(subFolder == "..") {			// 上一级目录
		for(int len = folder.length(); len > 0; len --) {
			if(folder[len - 1] == '/') {
				currentDirectory = folder.substr(0, len);
				//LOGD("%d",len);
				break;
		}
		}
	} else {
		currentDirectory = folder + "/" + subFolder;
	}

    DIR *d;
    struct dirent *file;
    if(!(d = opendir(currentDirectory.c_str())))  {
        LOGE("无法打开目录 %s!!!\n",currentDirectory.c_str());
    	Notify_message_list.push_back("Please create img directory and add pictures");
    	notify_open_close(true);
        if(img == true)
        {
        	mPrint_img_ListViewPtr->refreshListView();
        }else{
        	mFileListPtr->refreshListView();

        }

        return;
    }

//     while((file = readdir(d)) != NULL) {
//         if(strncmp(file->d_name, ".", 1) == 0)
//             continue;
//
//         if(file->d_type == DT_REG )
//         	fileInfos.push_back({file->d_name, E_FILETYPE_FILE});
//         else if(file->d_type == DT_DIR)
//         	fileInfos.push_back({file->d_name, E_FILETYPE_FOLDER});
//     }

    while ((file = readdir(d)) != NULL) {
    		if (strncmp(file->d_name, ".", 1) == 0)
    			continue;

    		struct stat file_stat;
    		stat((currentDirectory + "/" + file->d_name).c_str(), &file_stat);

    		if (file->d_type == DT_REG) {
    	        if(img == true)
    	        {
        			if((strstr(file->d_name, ".png")||(strstr(file->d_name, ".jpg")) ||(strstr(file->d_name, ".bmp"))) != NULL) {
        				FileInfo inf = { file->d_name, E_FILETYPE_FILE, file_stat.st_mtime };
        				fileInfos.push_back(inf);
        			}
    	        }else{
        			if((strstr(file->d_name, "gcode")||(strstr(file->d_name, "fly"))) != NULL) {
        				FileInfo inf = { file->d_name, E_FILETYPE_FILE, file_stat.st_mtime };
        				fileInfos.push_back(inf);
        			}
    	        }


    		} else if (file->d_type == DT_DIR) {
    			FileInfo inf = { file->d_name, E_FILETYPE_FOLDER, file_stat.st_mtime };
    			fileInfos.push_back( inf);
    		}
    	}
    	closedir(d);

    	std::stable_sort(fileInfos.begin() + 2, fileInfos.end(), compare);
        if(img == true)
        {
        	mPrint_img_ListViewPtr->refreshListView();
        }else{
        	mFileListPtr->refreshListView();

        }

}



namespace { // 加个匿名作用域，防止多个源文件定义相同类名，运行时冲突

//实现长按监听接口
class LongClickListener : public ZKBase::ILongClickListener {

         virtual void onLongClick(ZKBase *pBase) {

        	 if(pBase == mButton167Ptr)
        	 {
        		 delOneChar();
        	 }
         }
};

}
static LongClickListener longButtonClickListener;





void updata_perint_img(std::string path)
{

	FILE *fp;
	long siz;

	std::string Path = path + "print.png";

	if(!(fp=fopen(Path.c_str(),"rb"))==NULL)
	{
	      fseek(fp, 0, SEEK_END);
	      siz = ftell(fp);
	      fclose(fp);
	  	if(siz <= 1024 * 45){
	  		copyFile(Path, "/data/print.png");
	  		mTextView6Ptr->setBackgroundPic("/data/print.png");
	  	}
	}

//加载小图片
	Path = path +"print_smail.png";
	if(!(fp=fopen(Path.c_str(),"rb"))==NULL)
	{
	      fseek(fp, 0, SEEK_END);
	      siz = ftell(fp);
	      fclose(fp);
	  	if(siz <= 1024 * 45){
	  		copyFile(Path, "/data/print_smail.png");
	  		mTextView4Ptr->setBackgroundPic("/data/print_smail.png");
	  	}
	}



//	else
//
//	LOGD("该图片大小为 %ld kb\n",siz);

}

class MyMountListener : public MountMonitor::IMountListener {
public:
    virtual void notify(int what, int status, const char *msg) {
        switch (status) {
        case MountMonitor::E_MOUNT_STATUS_MOUNTED:    // 插入
            // msg 为挂载路径
            LOGD("mount path: %s\n", msg);
           // mMountTextviewPtr->setText("TF卡已插入");
            if (strcmp(msg, "/mnt/usb1") == 0) {
            	LOGD("usb插入");
            	udesk = true;
            	FILE *fp;
            	if(!(fp=fopen("/mnt/usb1/print.png","rb"))==NULL)
            	{
            		mTextView18Ptr->setTextTr("Confirm load images?");
            		yes_no_id = 2;
            		myes_no_WindowPtr->setVisible(true);

            	}


            } else if (strcmp(msg, "/mnt/extsd") == 0) {
            	sdcard = true;
            	FILE *fp;
            	if(!(fp=fopen("/mnt/extsd/print.png","rb"))==NULL)
            	{
            		mTextView18Ptr->setTextTr("Confirm load images?");
            		yes_no_id = 3;
            		myes_no_WindowPtr->setVisible(true);

            	}
            }
            break;

        case MountMonitor::E_MOUNT_STATUS_REMOVE:    // 移除

            if (strcmp(msg, "/mnt/usb1") == 0) {
            	LOGD("usb移除");
            	udesk = false;



            } else if (strcmp(msg, "/mnt/extsd") == 0) {
            	LOGD("sdcard移除");
            	sdcard = false;
            }


            break;
        }
    }
};
static MyMountListener sMyMountListener;

int move_button_bg_sw = 0;

//url编码
std::string encode_url(const std::string& text) {
    std::ostringstream encoded_url;

    for (char ch : text) {
        if (std::isalnum(ch)
        || ch == '&'  || ch == '#'  || ch == '$'
        || ch == '!'  || ch == '\\' || ch == '|'
        || ch == '('  || ch == ')'  || ch == '-'
        || ch == '_'  || ch == '.'  || ch == ':'
        || ch == '~'  || ch == '/'  || ch == '='
        || ch == '?'  || ch == '^'  || ch == '*'
        || ch == ';'  || ch == '\'' || ch == '"'
        || ch == '<'  || ch == '>'  || ch == ','
        || ch == '%'
        ) {
            encoded_url << ch;
        } else {
            encoded_url << '%' << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(static_cast<unsigned char>(ch));
        }
    }




    return encoded_url.str();
}
//对\n以及空格进行编码
std::string encode_url2(const std::string &url) {
    CURL *curl = curl_easy_init();
    if (curl) {
        char *output = curl_easy_escape(curl, url.c_str(), url.length());
        if (output) {
            std::string encoded_url = output;
            curl_free(output);
            return encoded_url;
        }
        curl_easy_cleanup(curl);
    }
    return "";
}
std::string replace_newline(const std::string& input);
void sendbuff(){

}
void  excluded_objects_button_cancel(int index){
	switch(index)
	{
		case 0: mobj_B0Ptr->setSelected(true);mobj_B0Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 1: mobj_B1Ptr->setSelected(true);mobj_B1Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 2: mobj_B2Ptr->setSelected(true);mobj_B2Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 3: mobj_B3Ptr->setSelected(true);mobj_B3Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 4: mobj_B4Ptr->setSelected(true);mobj_B4Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 5: mobj_B5Ptr->setSelected(true);mobj_B5Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 6: mobj_B6Ptr->setSelected(true);mobj_B6Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 7: mobj_B7Ptr->setSelected(true);mobj_B7Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 8: mobj_B8Ptr->setSelected(true);mobj_B8Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 9: mobj_B9Ptr->setSelected(true);mobj_B9Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 10: mobj_B10Ptr->setSelected(true);mobj_B10Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 11: mobj_B11Ptr->setSelected(true);mobj_B11Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 12: mobj_B12Ptr->setSelected(true);mobj_B12Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 13: mobj_B13Ptr->setSelected(true);mobj_B13Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 14: mobj_B14Ptr->setSelected(true);mobj_B14Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 15: mobj_B15Ptr->setSelected(true);mobj_B15Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 16: mobj_B16Ptr->setSelected(true);mobj_B16Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 17: mobj_B17Ptr->setSelected(true);mobj_B17Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 18: mobj_B18Ptr->setSelected(true);mobj_B18Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 19: mobj_B19Ptr->setSelected(true);mobj_B19Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 20: mobj_B20Ptr->setSelected(true);mobj_B20Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 21: mobj_B21Ptr->setSelected(true);mobj_B21Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 22: mobj_B22Ptr->setSelected(true);mobj_B22Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 23: mobj_B23Ptr->setSelected(true);mobj_B23Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 24: mobj_B24Ptr->setSelected(true);mobj_B24Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 25: mobj_B25Ptr->setSelected(true);mobj_B25Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 26: mobj_B26Ptr->setSelected(true);mobj_B26Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 27: mobj_B27Ptr->setSelected(true);mobj_B27Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 28: mobj_B28Ptr->setSelected(true);mobj_B28Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 29: mobj_B29Ptr->setSelected(true);mobj_B29Ptr->setBackgroundPic("exclude_object_off.png");break;
		case 30: mobj_B30Ptr->setSelected(true);mobj_B30Ptr->setBackgroundPic("exclude_object_off.png");break;

	}

}



bool create_directory_if_not_exists(const char* path) {
    struct stat st;
    if (stat(path, &st) != 0) {
        // 如果路径不存在
        if (errno == ENOENT) {
            // 尝试创建目录
            if (mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0) {
                return true;
            } else {
               // perror("mkdir");
                return false;
            }
        } else {
            //perror("stat");
            return false;
        }
    } else if (S_ISDIR(st.st_mode)) {
        // 路径已存在且为目录
        return true;
    } else {
       // std::cerr << "Path is not a directory.\n";
        return false;
    }
}

class upfile_Thread: public Thread {
public:
  /**
   * 线程创建成功后会调用该函数，可以在该函数中做一些初始化操作
   * return true   继续线程
   *        false  退出线程
   */
  virtual bool readyToRun() {
		file_progress = 0;
		upload_progress = 0;
		upload_progress_list.clear();
		upload_speed_list.clear();
	//	LOGD("Thread 已经创建完成");
	  file_progress = 0;
    return true;
  }

  /**
   * 线程循环函数
   *
   * return true  继续线程循环
   *        false 推出线程
   */
  virtual bool threadLoop() {
   // LOGD("线程循环函数");

    //检查是否有退出线程的请求，如果有，则返回false，立即退出线程
    if (exitPending()) {
      return false;
    }
    if(file_progress == 0)
    {




    	mdownload_listPtr->setVisible(true);

    	file_progress_lise_ref = true;

    	std::string save_path ;
    	if(mms_file_buttonPtr->isSelected())
    	{

    		//检测是否有u盘/sd卡
    	  if(udesk == true)
    	  {
    		  save_path = "/mnt/usb1/gcodes/" + Sync_file_name;
    		  LOGD("/mnt/usb1/gcodes/");
    	  }else
    	  {
    		  save_path = "/mnt/extsd/gcodes/" + Sync_file_name;
    		  LOGD("/mnt/extsd/gcodes/");
    	  }



		string  url = "http://" + master_print_ip + "/server/files/gcodes/" + Sync_file_name;
		up_download_sw = true;
		RestClient::Response r = RestClient::download(encode_url(url), save_path);
		LOGD("DOLD:%s",r.body.c_str());
    	}else{//sd卡/upan上傳文件
    		save_path = fileName;
    		Slave_Print_ip.push_back("http://" + master_print_ip);

			file_progress = 100;

    	}

		    upfile u;


			for(int i = 0;i <(int)Slave_Print_ip.size();i++)
			{
				//LOGD("FOR:%d",i);
				char buf[6];
				up_download_time = 0;
				int back_num = u.up(Slave_Print_ip[i],save_path);

				//把最后的速度存到列表里
				LOGD("UPSPEED:%0.2f",up_speed);
				snprintf(buf,sizeof(buf),"%f",up_speed);
				upload_speed_list.push_back(buf);


				snprintf(buf,sizeof(buf),"%d",back_num);
				LOGD("buf:%s",buf);
				upload_progress_list.push_back(buf);


			}
			//sd卡上傳文件，我們把主机ip加到最后了，所以上传完把最后的删掉


			file_progress_lise_ref = false;
			up_download_sw = false;
    }else
    {
    	return false;
    }


    //为了方便观察，这里添加休眠500ms
    usleep(1000 * 100);

    //返回真，继续下次线程循环
    return true;
  }
};
static upfile_Thread up_file_Thread;


class up_sd_file_Thread: public Thread {
public:
  /**
   * 线程创建成功后会调用该函数，可以在该函数中做一些初始化操作
   * return true   继续线程
   *        false  退出线程
   */
  virtual bool readyToRun() {

		upload_progress = 0;
    return true;
  }

  /**
   * 线程循环函数
   *
   * return true  继续线程循环
   *        false 推出线程
   */
  virtual bool threadLoop() {
   // LOGD("线程循环函数");

    //检查是否有退出线程的请求，如果有，则返回false，立即退出线程
    if (exitPending()) {
      return false;
    }
    if(upload_progress == 0)
    {
    	mTextView73Ptr->setVisible(true);

    	file_progress_lise_ref = true;
		upfile u;
//		int back_num = u.up(master_print_ip,fileName);
		u.up(master_print_ip,fileName);
		file_progress_lise_ref = false;
		mTextView73Ptr->setVisible(false);

    }else
    {

    	return false;
    }


    //为了方便观察，这里添加休眠500ms
    usleep(1000 * 500);

    //返回真，继续下次线程循环
    return true;
  }
};
static up_sd_file_Thread up_sd_file_thread;


//这个线程用于获取上位机端的wifi列表，屏幕上操作连接上位机wifi
class GET_WIFI_LIST: public Thread {
public:
  /**
   * 线程创建成功后会调用该函数，可以在该函数中做一些初始化操作
   * return true   继续线程
   *        false  退出线程
   */
  virtual bool readyToRun() {


    return true;
  }

  /**
   * 线程循环函数
   *
   * return true  继续线程循环
   *        false 推出线程
   */
  virtual bool threadLoop() {
   // LOGD("线程循环函数");

    //检查是否有退出线程的请求，如果有，则返回false，立即退出线程
    if (exitPending()) {
      return false;
    }
    std::string url = "http://";
    url += master_print_ip;
    RestClient::Connection conn(url);

    RestClient::HeaderFields headers;
    headers["Content-Type"] = "application/x-www-form-urlencoded";
    conn.SetHeaders(headers);

    conn.FollowRedirects(true);
    conn.SetTimeout(600);

    Json::Reader reader;
    Json::Value root;

    RestClient::Response r;

    //连接wifi
    if(Start_connect_wifi == true)
    {
        Json::Value root_wifi;

        root_wifi["ssid"] = mTextSsidPtr->getText();
        root_wifi["password"] = mEdittextPwdPtr->getText();

        if(mButtonautoconnectPtr->isSelected() == false){
        	 root_wifi["autoconnect"] = true;
        }else
        {
        	 root_wifi["autoconnect"] = false;
        }

    	url = "/server/network/wifi/connect";

//    	LOGD("JSON:%s",root_wifi.toStyledString().c_str());
    	headers["Content-Type"] = "application/json";
    	conn.SetHeaders(headers);
        conn.FollowRedirects(true);
        conn.SetTimeout(18000);

    	r = conn.post(url, root_wifi.toStyledString());

//    	LOGD("BODY:%s",r.body.c_str());
    	Start_connect_wifi = false;
    }


    headers["Content-Type"] = "application/x-www-form-urlencoded";
    conn.SetHeaders(headers);

    conn.FollowRedirects(true);
    conn.SetTimeout(2000);

    //断开连接
    if(Disconnect_wifi == true)
    {
    	 url = "/server/network/device/disconnect";
    	 r = conn.post(url,"ifname=wlan0");
//    	 LOGD("CLOSE:%s",r.body.c_str());
    	 Disconnect_wifi = false;

    }
    //忘记wifi
    if(Forget_wifi == true)
    {
		for (const Recorded_Wifi& wifi : Recorded_wifi) {
		    if (wifi.ssid == mTextConnectSsidPtr->getText()) {
		    	url = "/server/network/connect/del";
		    	std::string __uuid;
		    	__uuid += "uuid=";
		    	__uuid += wifi.uuid;
		    	r = conn.post(url,__uuid);
//		       	LOGD("Forget:%s",r.body.c_str());
//		    	LOGD("uuid:%s",__uuid.c_str());
		        }
		    }
    	 Forget_wifi = false;

    }



    url = "/server/network/wifi/scan";
    r = conn.get(url);
//    LOGD("WIFI:%s",r.body.c_str());
        // 解析 JSON 字符串
        if (reader.parse(r.body, root, false)) {
        	WIFI_Info wifi_info;
            // 访问 JSON 中的字段
            if (root.isMember("result")) {
                Json::Value result = root["result"];

                if (result.isMember("list")) {
                    Json::Value wifi_list= result["list"];

                    if(wifi_list.isArray())
                    {
                    	WiFi_Info.clear();
						 for (Json::ArrayIndex i = 0; i < wifi_list.size(); ++i)
						 {
							 wifi_info.use = wifi_list[i]["use"].asBool();
							 wifi_info.bssid = wifi_list[i]["bssid"].asString();
							 wifi_info.ssid = wifi_list[i]["ssid"].asString();
							 wifi_info.signal = wifi_list[i]["signal"].asInt();
							 wifi_info.security = wifi_list[i]["security"].asString();
							 wifi_info.freq = wifi_list[i]["freq"].asInt();

							 WiFi_Info.push_back(wifi_info);
						}
						 mListViewWifiInfoPtr->refreshListView();
                    }



                }
            }

        }


    //获取网卡设备列表
    url = "/server/network/device/list";
    r = conn.get(url);
//    LOGD("aaaBODY:%s",r.body.c_str());
    // 解析 JSON 字符串
    if (reader.parse(r.body, root, false))
    {
    	WIFI_Devices_Info _Info;
        if (root.isMember("result")) {
            Json::Value result = root["result"];

            if (result.isMember("devices")) {
                Json::Value devices_list= result["devices"];
                if(devices_list.isArray())
                {
                	WIFI_devices_Info.clear();
					 for (Json::ArrayIndex i = 0; i < devices_list.size(); ++i)
					 {
						 _Info.name = devices_list[i]["name"].asString();
						 _Info.type = devices_list[i]["type"].asString();
						 _Info.state = devices_list[i]["state"].asString();
						 _Info.connection = devices_list[i]["connection"].asString();
						 if (_Info.type == "wifi") {
//							 LOGD("WIFI:%s,%s,%s,%s",_Info.name.c_str(),_Info.type.c_str(),_Info.state.c_str(),_Info.connection.c_str());
							 WIFI_devices_Info.push_back(_Info);
						 }

					 }
                }
            }
        }
    }

   //如果获取到设备了，我们就扫描这个设备的ip
	if( !WIFI_devices_Info.empty() )
	{

		for (size_t i = 0; i < WIFI_devices_Info.size(); ++i) {

		    //获取网卡详细信息，这里我们只获取连接的wifi，以及ip
		    url = "/server/network/device/info?ifname=" + WIFI_devices_Info[i].name;
//		    LOGD("WIFI:%s",url.c_str());
		    r = conn.get(url);
//		    LOGD("BODY:%s",r.body.c_str());
		    // 解析 JSON 字符串
		    if (reader.parse(r.body, root, false)) {

		        if (root.isMember("result")) {
		            Json::Value result = root["result"];

		            Devices_Info _Info;

		            if (result.isMember("info")) {
		                Json::Value info_list= result["info"];
		                devices_Info.clear();
							_Info.connection = info_list["connection"].asString();
							_Info.ip_address = info_list["ip_address"].asString();
							LOGD("WIFI:%s,%s",_Info.connection.c_str(),_Info.ip_address.c_str());
							devices_Info.push_back(_Info);

		                }
		        }
		    }
		   }
		 WIFI_devices_Info.clear();
		}
    //获取已保存的wifi列表
    url = "/server/network/connect/list";
    r = conn.get(url);
    // 解析 JSON 字符串
       if (reader.parse(r.body, root, false)) {
    	   Recorded_Wifi _info;
           // 访问 JSON 中的字段
           if (root.isMember("result")) {
               Json::Value result = root["result"];

               if (result.isMember("list")) {
                   Json::Value wifi_list= result["list"];

                   if(wifi_list.isArray())
                   {
                	   Recorded_wifi.clear();
						 for (Json::ArrayIndex i = 0; i < wifi_list.size(); ++i)
						 {
							 _info.uuid = wifi_list[i]["uuid"].asString();
							 _info.ssid = wifi_list[i]["ssid"].asString();

							 Recorded_wifi.push_back(_info);
						}
                   }

               }
           }

       }


    //为了方便观察，这里添加休眠500ms
    usleep(1000 * 300);

    //返回真，继续下次线程循环
    return true;
  }
};
static GET_WIFI_LIST GET_WIFI_List;



//主要用于下载缩略图，排除打印背景图
class Downloa_Pic_Thread: public Thread {
public:
  virtual bool readyToRun() {


    return true;
  }

  virtual bool threadLoop() {

    if (exitPending()) {
      return false;
    }




    if(Download_thumbnail == true)
    {
    	Download_thumbnail = false;
		string save_path = Save_Path + "big.png";
		//发起HTTPS GET请求
		string  url = "http://" + master_print_ip + "/server/files/gcodes/" + File_Gcodes[cur_selected_file_index].thumbnail_path_big;
		RestClient::Response r = RestClient::download(encode_url(url), save_path);
		mTextView9Ptr->setBackgroundPic(save_path.c_str());
    }
    //下载文件列表的缩略图
	if(Download_file_thumbnail == true)
	{
		Download_file_thumbnail = false;

	    for (int i = 0; i < (int)File_Gcodes.size(); i++) {

	    	if(!File_Gcodes[i].thumbnail_path_smail.empty())
	    	{
			    string save_path = Save_Path + File_Gcodes[i].path + ".png";
			    string  url = "http://" + master_print_ip + "/server/files/gcodes/" + File_Gcodes[i].thumbnail_path_smail;
			    string  url2 = url;
//
//
//			    LOGD("encode_url:%s",encode_url(url).c_str());
//			    LOGD("encode_url2:%s",encode_url2(url2).c_str());
			    RestClient::Response r = RestClient::download(encode_url(url).c_str(), save_path);
			    mFileListPtr->refreshListView();
	    	}
	    }
	}

    //下载热床平整度图
	if(Download_graph_mesh == true)
	{
		Download_graph_mesh = false;
		string  url = "http://" + master_print_ip + "/server/flylcd/get_bedmesh_pic";
		RestClient::Response r = RestClient::get(url);
		LOGD("R:%s",r.body.c_str());
		string save_path = Save_Path + "graph-mesh.png";
		url = "http://" + master_print_ip + "/server/files/graph-mesh.png";
		r = RestClient::download(url, save_path);
		mCAM_BED_MESHPtr->setBackgroundPic(save_path.c_str());
		std::remove(save_path.c_str());

	}


	//摄像头
	    if(open_cam)
	    {
	        string save_pic = Save_Path + "ca.png";
	    	string  url = "http://" + master_print_ip + "/webcam/?action=snapshot";
	    	RestClient::Response r = RestClient::download(encode_url(url), save_pic);
	    	mCAM_BED_MESHPtr->setBackgroundPic(save_pic.c_str());
	    }
	    if(!mCAM_BED_MESHPtr->isVisible() && open_cam)
	    {
	    	open_cam = false;
	    }

    //为了方便观察，这里添加休眠500ms
    usleep(1000 * 100);

    //返回真，继续下次线程循环
    return true;
  }
};
static Downloa_Pic_Thread Downloa_Pic_thread;

//解析macros
void parseMacrosJson(const Json::Value& status)
{

    if (status.isArray()) {
    	Host_Macros_list.clear();
        for (Json::ArrayIndex i = 0; i < status.size(); ++i) {
            std::string object = status[i].asString();
//            LOGD("object: %s", object.c_str());

            // 检查是否以 "gcode_macro" 开头
            std::string prefix = "gcode_macro ";
            if (object.find(prefix) == 0) {
                std::string macro = object.substr(prefix.length());
                //_开头是隐藏的，屏幕也不显示
                if(macro[0] != '_'){
                	Host_Macros_list.push_back(macro);
//                	LOGD("object: %s", macro.c_str());
                }

            }
        }
        mHost_macros_listPtr->refreshListView();
    }
}

//解析文件夹/打印文件
void parseFileJson(const Json::Value& result)
{

	if (result.isMember("dirs"))
	{
		file_dir.clear();
		//如果进入了下一层我们就把第一个口设置为返回上一层的按钮
		if((int)cur_file_dir.size() > 0 )
		{
			file_dir.push_back("..");
		}


		Json::Value dirs = result["dirs"];
		if(dirs.isArray())
		{
	         for (Json::ArrayIndex i = 0; i < dirs.size(); ++i)
	         {
				  const Json::Value& item = dirs[i];
				  //
				  if(!strstr(item["dirname"].asString().c_str() ,".thumbs") && !strstr(item["dirname"].asString().c_str() ,".bottompic"))
				  {
					  file_dir.push_back(item["dirname"].asString());
					  LOGD("DIR:%s",item["dirname"].asString().c_str());
				  }

	         }

		}

	}
	//处理文件
	if (result.isMember("files"))
	{
		File_Gcodes.clear();
		//LOGD("JIN");
//            		LOGD("AA%s", message.c_str());
		Json::Value files = result["files"];
		if(files.isArray())
		{
	           // 遍历 "result" 数组
	         for (Json::ArrayIndex i = 0; i < files.size(); ++i)
	         {
				  const Json::Value& item = files[i];

				  // 构造 GcodeFileInfo 对象并添加到 vector
				  GcodeFileInfo fileInfo;
				  fileInfo.path = item["filename"].asString();

				  fileInfo.modified = item["modified"].asDouble();
				  fileInfo.size = item["size"].asInt();
				  //切片软件
				  if (item.isMember("slicer"))
				  {
					  fileInfo.slicer = item["slicer"].asString();
				  }

				  //获取文件打印时间。
				  if (item.isMember("estimated_time"))
				  {
					  fileInfo.estimated_time = item["estimated_time"].asInt();
				  }
				  //获取文件使用耗材重量。
				  if (item.isMember("filament_total"))
				  {
					  fileInfo.filament_total = item["filament_total"].asInt();
				  }
				  //获取文件喷头温度。
				  if (item.isMember("first_layer_extr_temp"))
				  {
					  fileInfo.first_layer_extr_temp = item["first_layer_extr_temp"].asFloat();
				  }
				  //获取文件床温。
				  if (item.isMember("first_layer_bed_temp"))
				  {
					  fileInfo.first_layer_bed_temp = item["first_layer_bed_temp"].asFloat();
				  }

				  if (item.isMember("thumbnails"))
				  {
                         const Json::Value& resultArray = item["thumbnails"];
                         // 遍历 "result" 数组
                         for (Json::ArrayIndex j = 0; j < resultArray.size(); ++j) {
                             const Json::Value& thumbnailItem = resultArray[j];

                             // 提取 "thumbnail_path" 字段的值
                             std::string thumbnailPath = thumbnailItem["relative_path"].asString();
                             if(j == 0)
                             {
                             	fileInfo.thumbnail_path_smail = thumbnailPath;
//			                         	    string save_path = Save_Path + fileInfo.path + ".png";
                         	   //LOGD("save_path:%s", save_path.c_str());
                         	    //发起HTTPS GET请求
//			                         	    string  url = "http://" + master_print_ip + "/server/files/gcodes/" + fileInfo.thumbnail_path_smail;
                         	   //LOGD("%s", fileInfo.thumbnail_path_smail.c_str());
//			                         	    RestClient::Response r = RestClient::download(encode_url(url).c_str(), save_path);
                         	   // LOGD("RRR:%s",r.body.c_str());
                             }
                             if(j == 1)
                             {
                             	fileInfo.thumbnail_path_big = thumbnailPath;
                             }
                         }
				  }
				  //LOGD("%s", fileInfo.path.c_str());
				  File_Gcodes.push_back(fileInfo);
				  //缩略图在线程里单独下载
				  Download_file_thumbnail = true;

	         }

	         // 使用自定义比较函数对 vector 进行排序
	         std::stable_sort(File_Gcodes.begin(), File_Gcodes.end(), compareByModified);
	         mFileListPtr->refreshListView();

		}
	}


}

void Updata_Notify_message_list(string param);
//每次连接后我们初始化所有的显示数据为0
void init_ui_data(){


        mlyayer2_nozzle_temp_buttonPtr->setText("0");
        mNozzle_Temp_ViewPtr->setText("/ 0℃");
        mButton101Ptr->setText("0℃");

      //解析热床温度
        mlyayer2_bed_temp_buttonPtr->setText("0");
        mBed_Temp_ViewPtr->setText("/ 0℃");
        mbed_temp_buttonPtr->setText("0℃");
        mButton103Ptr->setText("0");

        mWarehouse_Temperature_ViewPtr->setText("/ 0℃");
        mButton50Ptr->setText("0℃");



		cur_zoffset = 0;
		if(LANGUAGEMANAGER->getCurrentCode() == "zh_CN"){
			mTextView45Ptr->setText("Z偏移:0");
		}else{
			 mTextView45Ptr->setText("Zoffset:0");
		}


		mTextView34Ptr->setText("X:0");
		mTextView35Ptr->setText("Y:0");
		mTextView36Ptr->setText("Z:0");

		mlayer2_speed_buttonPtr->setText("100%");

      	//led
		mButton98Ptr->setSelected(false);

        mFAN0_ViewPtr->setText("0%");
        mFAN1_ViewPtr->setText("0%");
        mFAN2_ViewPtr->setText("0%");
        mFan0_PointerPtr->setTargetAngle(0);
        mFan1_PointerPtr->setTargetAngle(0);
        mFan2_PointerPtr->setTargetAngle(0);
        mFAN1_SW_ButtonPtr->setSelected(false);
        mFAN2_SW_ButtonPtr->setSelected(false);
        mFAN3_SW_ButtonPtr->setSelected(false);
        mFAN1_SW_ButtonPtr->setTextTr("off");
        mFAN2_SW_ButtonPtr->setTextTr("off");
        mFAN3_SW_ButtonPtr->setTextTr("off");

        //文件列表
    	cur_file_dir.clear();
    	file_dir.clear();
    	File_Gcodes.clear();
    	mFileListPtr->refreshListView();


}

void parseStatusJson(const Json::Value& status)
{


    char buf[256];
    if (status.isMember("webhooks")) {
        Json::Value webhooks = status["webhooks"];
        if (webhooks.isMember("state"))
        {
        	std::string _state =webhooks["state"].asString();
//        	LOGD("state:%s",_state.c_str());
        	if(_state == "shutdown" || _state == "error" ||_state == "startup"){
        		mrestart_layerPtr->setVisible(true);
                if (webhooks.isMember("state_message")) {
                	mTextView41Ptr->setText(webhooks["state_message"].asString().c_str());
                }
        	}else{
        		if(mrestart_layerPtr->isVisible() == true){
        			mrestart_layerPtr->setVisible(false);
        		}
        		mTextView41Ptr->setText("");

        		//http下的校准检测是否重启了
        		if(_state == "ready" && mHTTP_WS_BUTTONPtr->isSelected() == true && Calibration_wait_reboot== true)
        		{
        			Calibration_wait_reboot = false;
        			run_next_Calibration();
        		}



        	}
        }
    }
    //解析打印文件json
    if (status.isMember("print_stats"))
    {
        Json::Value Print_stats = status["print_stats"];

                     if (Print_stats.isMember("total_layer")) {
                    	 total_layer = Print_stats["total_layer"].asInt() ;
                     }
                     if (Print_stats.isMember("current_layer")) {
                    	 current_layer = Print_stats["current_layer"].asInt() ;
                     }

        if(Print_stats.isMember("print_duration")) {
      	  	  current_file_information.print_duration = Print_stats["print_duration"].asFloat() ;
				 // 计算小时数
				 int hours = static_cast<int>(current_file_information.print_duration / 3600);
				 // 计算剩余的秒数
				 int remainingSeconds = static_cast<int>(current_file_information.print_duration) % 3600;
				 // 计算分钟数
				 int minutes = remainingSeconds / 60;

				 int seconds = remainingSeconds % 60;
				 if(hours > 0)
				 {
					 snprintf(buf,sizeof(buf),"-%dh %dm %ds",hours,minutes,seconds);
				 }else
				 {
					 snprintf(buf,sizeof(buf),"-%dm %ds",minutes,seconds);
				 }
				 mTextView43Ptr->setText(buf);
				if(current_file_information.print_duration > 0)
				{
					float remainingTime = current_file_information.print_duration / current_file_information.progress - current_file_information.print_duration;
					hours = static_cast<int>(remainingTime / 3600);
					remainingSeconds = static_cast<int>(remainingTime) % 3600;
					minutes = remainingSeconds / 60;
					 if(hours > 0)
					 {
						 snprintf(buf,sizeof(buf),"-%dh %dm %ds",hours,minutes,seconds);
					 }else
					 {
						 snprintf(buf,sizeof(buf),"-%dm %ds",minutes,seconds);
					 }
					 mTextView42Ptr->setText(buf);
				}
				else{
					mTextView42Ptr->setText("-0");
				}
        }

        if(Print_stats.isMember("filament_used")) {
       	 current_file_information.filament_used = Print_stats["filament_used"].asFloat() ;
				 snprintf(buf,sizeof(buf),"%.1fcm",current_file_information.filament_used/10);
				 mTextView17Ptr->setText(buf);
        }

        if(Print_stats.isMember("filename")) {

       	 current_file_information.filename = Print_stats["filename"].asString() ;
        }

        if(Print_stats.isMember("print_duration")) {
       	 current_file_information.print_duration = Print_stats["print_duration"].asFloat() ;
        }

        if(Print_stats.isMember("state") && print_cancel_state == false && print_pause_state == false) {
       	 current_file_information.state = Print_stats["state"].asString() ;

       	 if(  current_file_information.state  == "printing")//打印状态
       	 {

       		 //检测打印时，打印界面有没有弹出来
       		 if(mprintPtr->isVisible() == false)
       		 {
       			mprint_surePtr->setVisible(false);
       			layer_ch(6);
       	     }
       		 //切换暂停按钮状态
      			if(mPause_ButtonPtr->isSelected() == true)
      			{
      				mPause_ButtonPtr->setSelected(false);
      			}

             }else if(current_file_information.state  == "paused")//暂停状态
        	   {
            	 //打印界面没有显示
        		 if(mprintPtr->isVisible() == false)
        		 {
        			 mprint_surePtr->setVisible(false);
        			 layer_ch(6);
        	     }else{//打印界面有显示
         			mprintPtr->setVisible(true);

        	     }
      			//切换暂停按钮状态
      			if(mPause_ButtonPtr->isSelected() == false)
      			{
      				mPause_ButtonPtr->setSelected(true);
      			}
              }else if(current_file_information.state  == "cancelled"){
            	  //如果设置了cur_zoffset，取消打印/打印完成，自动保存这个值
        	    	if(cur_zoffset != 0 )
        	    	{
          	    		Notify_message_list.push_back("Auto-stored the Z offset") ;
          	    		notify_open_close(true);
          	    		gcode_send2("","Z_OFFSET_APPLY_PROBE");
        	    		gcode_send2("","SAVE_CONFIG");
        	    	}
					if(mprintPtr->isVisible() == true)
					{
						mprintPtr->setVisible(false);
						layer_ch(1);
					}

          	  }else if(current_file_information.state  == "standby"){
          		  //删除自动保存Z偏移的提示
          		  Notify_message_list.erase(
          	        std::remove_if(Notify_message_list.begin(), Notify_message_list.end(),
          	                       [](const std::string& str) { return str.find("Auto-stored the Z offset") != std::string::npos; }),
          	        Notify_message_list.end());
          		  	 mNotify_ListViewPtr->refreshListView();
	        	    if( (int)Notify_message_list.size() == 0 )
	        	    {
	        	    	notify_open_close(false);
	        	    }

					 if(mprintPtr->isVisible() == true)
					 {
						mprintPtr->setVisible(false);
						layer_ch(1);
					 }
          	  }else if(current_file_information.state  == "complete")
          	    {

          		  //打印完成提示
					mPause_ButtonPtr->setSelected(false);
					mTextView43Ptr->setTextTr("-0");
					mTextView3Ptr->setTextTr("100%");
					mPrint_SeekBarPtr->setProgress(100);
					yes_no_id = 11;
					myes_no_WindowPtr->setVisible(true);
					mTextView18Ptr->setTextTr("printok?");


          		//如果设置了cur_zoffset，取消打印/打印完成，自动保存这个值
          	    	if(cur_zoffset != 0 )
          	    	{
          	    		Notify_message_list.push_back("Auto-stored the Z offset") ;
          	    		notify_open_close(true);
          	    		gcode_send2("","Z_OFFSET_APPLY_PROBE");
        	    		gcode_send2("","SAVE_CONFIG");
          	    	}
						 if(mprintPtr->isVisible() == true)
						 {
							//mprintPtr->setVisible(false);
						 }


          	    }

        }

    }
//    因为刷新文件列表占用太大，所以我们在展开列表的时候，不进行其它状态的更新。必须更新的内容写到上面
	if(mfilePtr->isVisible() == false || mprint_surePtr->isVisible() == true){

//    if (status.isMember("state"))
//    {
//    	std::string _state =status["state"].asString();
//    	if(_state == "shutdown" || _state == "error"){
//    		mrestart_layerPtr->setVisible(true);
//            if (status.isMember("state_message")) {
//            	mTextView41Ptr->setText(status["state_message"].asString().c_str());
//            }
//    	}else{
//    		if(mrestart_layerPtr->isVisible() == true){
//    			mrestart_layerPtr->setVisible(false);
//    		}
//    		mTextView41Ptr->setText("");
//    	}
//    }



    if (status.isMember("extruder")) {
          Json::Value extruder = status["extruder"];

          if (extruder.isMember("target")) {
           //   std::cout << "extruder target = " << extruder["target"].asDouble() << std::endl;
         	 snprintf(buf,sizeof(buf),"%.0f",extruder["target"].asDouble());
         	 mlyayer2_nozzle_temp_buttonPtr->setText(buf);
          }

          if (extruder.isMember("temperature")) {
              snprintf(buf,sizeof(buf),"/  %.0f℃",extruder["temperature"].asDouble());
              //设置温度显示

              //第二页温度显示
              mNozzle_Temp_ViewPtr->setText(buf);
              //首页温度显示
              snprintf(buf,sizeof(buf),"%.0f℃",extruder["temperature"].asDouble());
              mButton101Ptr->setText(buf);

          }
          //压力提前
          if (extruder.isMember("pressure_advance")) {
            snprintf(buf, sizeof(buf), "%0.3fs", extruder["pressure_advance"].asFloat());
         	speed_info[3].num = buf;
         	mListView1Ptr->refreshListView();
          }
          //平滑时间
          if (extruder.isMember("smooth_time")) {
        	snprintf(buf, sizeof(buf), "%0.3fs", extruder["smooth_time"].asFloat());
         	speed_info[4].num = buf;
         	mListView1Ptr->refreshListView();
          }
      }
      //解析热床温度
      if (status.isMember("heater_bed")) {
          Json::Value heater_bed = status["heater_bed"];

          if (heater_bed.isMember("target")) {
         	 snprintf(buf,sizeof(buf),"%.0f",heater_bed["target"].asDouble());
         	 mlyayer2_bed_temp_buttonPtr->setText(buf);
          }

          if (heater_bed.isMember("temperature")) {
              snprintf(buf,sizeof(buf),"/  %.0f℃",heater_bed["temperature"].asDouble());
              //设置温度显示
              mBed_Temp_ViewPtr->setText(buf);
              snprintf(buf,sizeof(buf),"%.0f℃",heater_bed["temperature"].asDouble());
              mbed_temp_buttonPtr->setText(buf);

          }
      }
      //解析仓温温度
      if (status.isMember("heater_generic warehouse")) {
          Json::Value heater_bed = status["heater_generic warehouse"];

          if (heater_bed.isMember("target")) {
         	 snprintf(buf,sizeof(buf),"%.0f",heater_bed["target"].asDouble());
         	 mButton103Ptr->setText(buf);
          }

          if (heater_bed.isMember("temperature")) {
              snprintf(buf,sizeof(buf),"/  %.0f℃",heater_bed["temperature"].asDouble());
              //设置温度显示
              mWarehouse_Temperature_ViewPtr->setText(buf);
              snprintf(buf,sizeof(buf),"%.0f℃",heater_bed["temperature"].asDouble());
              mButton50Ptr->setText(buf);

          }
      }
      if (status.isMember("gcode_move")) {
				 Json::Value gcode_move = status["gcode_move"];
				 if (gcode_move.isMember("homing_origin")) {
					 Json::Value homing_origin = gcode_move["homing_origin"];
					 if (homing_origin.isArray()) {
						 for (Json::ArrayIndex i = 0; i < homing_origin.size(); ++i) {

							 if(i == 2)
							 {
								 //记录Z偏移值
								 cur_zoffset = homing_origin[i].asFloat();
								 if(LANGUAGEMANAGER->getCurrentCode() == "zh_CN"){
									 snprintf(buf, sizeof(buf), "Z偏移:%.3f",cur_zoffset);
								 }else
								 {
									 snprintf(buf, sizeof(buf), "Zoffset:%.3f", cur_zoffset);
								 }

								 mTextView45Ptr->setText(buf);
							 }

						 }

					 }
				 }
				 if (gcode_move.isMember("position")) {
					 Json::Value position = gcode_move["position"];
					 if (position.isArray()) {
						 for (Json::ArrayIndex i = 0; i < position.size(); ++i) {
							// LOGD("xyz%f",position[i].asDouble());
							// std::cout << position[i].asDouble() << " ";
							 if(i == 0)
							 {
								 snprintf(buf, sizeof(buf), "X:%0.2f", position[i].asFloat());
								 mTextView34Ptr->setText(buf);
							 }
							 if(i == 1)
							 {
								 snprintf(buf, sizeof(buf), "Y:%0.2f", position[i].asFloat());
								 mTextView35Ptr->setText(buf);
							 }
							 if(i == 2)
							 {
								 snprintf(buf, sizeof(buf), "Z:%0.2f", position[i].asFloat());
								 mTextView36Ptr->setText(buf);
							 }

						 }

					 }
				 }


				// 移动倍率
               if (gcode_move.isMember("speed_factor")) {
              	 speed_factor = gcode_move["speed_factor"].asFloat() * 100;
              	 snprintf(buf, sizeof(buf), "%d%%", speed_factor);
              	 speed_info[1].num = buf;
                 //设置温度显示
              	 //设置速度时不刷新
              	 if(!mprint_speed_WindowPtr->isVisible()){
              		 mlayer2_speed_buttonPtr->setText(buf);
              	 }
               }
               //挤出倍率
               if (gcode_move.isMember("extrude_factor")) {
                snprintf(buf, sizeof(buf), "%d%%", gcode_move["extrude_factor"].asInt() * 100);
              	speed_info[2].num = buf;
              	mListView1Ptr->refreshListView();
               }

		}
		 if (status.isMember("led LED")) {

			 Json::Value led_LED = status["led LED"];
			 if(led_LED.isMember("color_data"))
			 {
				 Json::Value color_data = led_LED["color_data"];
				 if (color_data.isArray())
				 {
					// LOGD("aaaJINJINJIN");
					// int on_off =0;
					 if(color_data[0].isArray())
					 {
					 	 for (Json::ArrayIndex i = 0; i < color_data[0].size(); ++i)
					 	 {

					 		//LOGD("ccccJINJINJIN");
					 		//LOGD("dd:%0.1f",color_data[0][i].asFloat());
					 		if(color_data[0][i].asFloat() > 0)
					 		{
					 		//	on_off = 1;
					 			mButton98Ptr->setSelected(true);

					 			break;
					 		}else
					 		{
					 			mButton98Ptr->setSelected(false);
					 		}
					 	 }
					 }
				 	}
			 }
		 }
      //解析风扇json
      if (status.isMember("fan")) {
          Json::Value Fan = status["fan"];

          if (Fan.isMember("speed")) {
         	  Fan0_Speed = static_cast<int>(Fan["speed"].asDouble() * 100);
         	  snprintf(buf, sizeof(buf), "%d%%", Fan0_Speed);
         	  mFAN0_ViewPtr->setText(buf);
         	  mFan0_PointerPtr->setTargetAngle(Fan0_Speed*270/100);
         	  if(Fan0_Speed > 0 && !mFAN1_SW_ButtonPtr->isSelected()){
         		  mFAN1_SW_ButtonPtr->setSelected(true);
         		 mFAN1_SW_ButtonPtr->setTextTr("on");
         	  }
         	  if(Fan0_Speed == 0 && mFAN1_SW_ButtonPtr->isSelected()){
         		  mFAN1_SW_ButtonPtr->setSelected(false);
         		 mFAN1_SW_ButtonPtr->setTextTr("off");
         	  }

          }
      }

      //解析风扇json
      string fan_name = "fan_generic " + fan1_name;
      if (status.isMember(fan_name.c_str())) {
          Json::Value Fan = status[fan_name.c_str()];

          if (Fan.isMember("speed")) {
         	  Fan1_Speed = static_cast<int>(Fan["speed"].asDouble() * 100);
         	  snprintf(buf, sizeof(buf), "%d%%", Fan1_Speed);
         	  mFAN1_ViewPtr->setText(buf);
         	  mFan1_PointerPtr->setTargetAngle(Fan1_Speed*270/100);
         	  if(Fan1_Speed > 0 && !mFAN2_SW_ButtonPtr->isSelected()){
         		  mFAN2_SW_ButtonPtr->setSelected(true);
         		 mFAN2_SW_ButtonPtr->setTextTr("on");

         	  }
         	  if(Fan1_Speed == 0 && mFAN2_SW_ButtonPtr->isSelected()){
         		  mFAN2_SW_ButtonPtr->setSelected(false);
         		 mFAN2_SW_ButtonPtr->setTextTr("off");
         	  }

          }
      }
      //解析风扇json
      fan_name = "fan_generic " + fan2_name;
      if (status.isMember(fan_name.c_str())) {
          Json::Value Fan = status[fan_name.c_str()];

          if (Fan.isMember("speed")) {
         	  Fan2_Speed = static_cast<int>(Fan["speed"].asDouble() * 100);
         	  snprintf(buf, sizeof(buf), "%d%%", Fan2_Speed);
         	  mFAN2_ViewPtr->setText(buf);
         	  mFan2_PointerPtr->setTargetAngle(Fan2_Speed*270/100);
         	  if(Fan2_Speed > 0 && !mFAN3_SW_ButtonPtr->isSelected()){
         		  mFAN3_SW_ButtonPtr->setSelected(true);
         		 mFAN3_SW_ButtonPtr->setTextTr("on");
         	  }
         	  if(Fan2_Speed == 0 && mFAN3_SW_ButtonPtr->isSelected()){
         		  mFAN3_SW_ButtonPtr->setSelected(false);
         		 mFAN3_SW_ButtonPtr->setTextTr("off");
         	  }

          }
      }



//                 if (status.isMember("virtual_sdcard")) {
//                     Json::Value virtual_sdcard = status["virtual_sdcard"];
//                     if(virtual_sdcard.isMember("progress")) {
//                    	 current_file_information.progress = virtual_sdcard["progress"].asFloat() ;
//                    	 snprintf(buf,sizeof(buf),"%d%%",static_cast<int>(rint(current_file_information.progress * 100)));
//                    	 mTextView3Ptr->setText(buf);
//						 mPrint_SeekBarPtr->setProgress(static_cast<int>(rint(current_file_information.progress * 100)));
//                     }
//                 }

      if (status.isMember("display_status")) {
          Json::Value display_status = status["display_status"];
          if(display_status.isMember("progress")) {
         	 current_file_information.progress = display_status["progress"].asFloat() ;
         	// snprintf(buf,sizeof(buf),"%d%%",static_cast<int>(rint(current_file_information.progress * 100)));
         	 snprintf(buf,sizeof(buf),"%.1f%%",rint(current_file_information.progress * 1000)/10);
         	 mTextView3Ptr->setText(buf);
			 mPrint_SeekBarPtr->setProgress(static_cast<int>(rint(current_file_information.progress * 100)));
          }
      }

      if (status.isMember("exclude_object")) {
          Json::Value Exclude_Objecta = status["exclude_object"];

             if (Exclude_Objecta.isMember("objects") && Exclude_Objecta["objects"].isArray() && Exclude_Objecta["objects"].size() > 0) {
            	 Exclude_Object object;
            	 exclude_object.clear();
                 Json::Value objects = Exclude_Objecta["objects"];

                 for (Json::ArrayIndex i = 0; i < objects.size(); ++i) {
                     if (objects[i].isMember("name")) {
                     	object.name = objects[i]["name"].asString();
                     	//LOGD("Object name: %s",objects[i]["name"].asString().c_str());
                     }
                     //中心点
                     if (objects[i].isMember("center") && objects[i]["center"].isArray()) {
                    	 Json::Value center = objects[i]["center"];
                    		 object.button_mid_x = center[0].asFloat();
                    		 object.button_mid_y = center[1].asFloat();
                    		 LOGD("mid:%f,%f",object.button_mid_x,object.button_mid_y);

                     }


                     if (objects[i].isMember("polygon") && objects[i]["polygon"].isArray()) {
                         Json::Value polygon = objects[i]["polygon"];
                         //LOGD( "Object polygon:" );
                         printJsonValue(polygon,object);
                         object.button_xpos = object.button_pos[2];
                         object.button_ypos = object.button_pos[3];
                         object.button_height = object.button_pos[3] - object.button_pos[1];
                         object.button_Width  = object.button_pos[6] - object.button_pos[0];


                     }
                     //LOGD("name：%s,button_xpos:%f,button_ypos:%f, button_length:%f, button_Width:%f",object.name.c_str(),object.button_xpos,object.button_ypos,object.button_height,object.button_Width);
                     exclude_object.push_back(object);
                     object.button_pos.clear();
                 }
                 init_exclude_obj();
             }
			 if (Exclude_Objecta.isMember("excluded_objects"))
			 {
				 Json::Value Excluded_Objects = Exclude_Objecta["excluded_objects"];
				 if (Excluded_Objects.isArray())
				 {
					 for (Json::ArrayIndex i = 0; i < Excluded_Objects.size(); ++i)
					 {

							    // 遍历 exclude_object 向量
							    for (size_t j = 0; j < exclude_object.size(); ++j)
							    {
							        // 检查每个对象的 name 字段
							        if (exclude_object[j].name == Excluded_Objects[i].asString())
							        {
							        	excluded_objects_button_cancel(j);
							            break;  // 找到匹配项，退出循环
							        }
							    }
							    //LOGD("SSS:%s", Excluded_Objects[i].asString().c_str());
//							 snprintf(buf, sizeof(buf), "X:%s", excluded_objects[i].asString().c_str());
//							 mTextView34Ptr->setText(buf);
					 }
				 }
			 }
      }//exclude_object

      ////toolhead
      if (status.isMember("toolhead"))
      {
          Json::Value toolhead = status["toolhead"];

          //最大速度
          if(toolhead.isMember("max_velocity"))
          {
             snprintf(buf, sizeof(buf), "%dmm/s", toolhead["max_velocity"].asInt());
             speed_info[5].num = buf;
             mListView1Ptr->refreshListView();
          }
          //最大加速度
          if(toolhead.isMember("max_accel"))
          {
        	 snprintf(buf, sizeof(buf), "%dmm/s²", toolhead["max_accel"].asInt());
             speed_info[7].num = buf;
             mListView1Ptr->refreshListView();
          }
          //转角速度
          if(toolhead.isMember("square_corner_velocity"))
          {
             snprintf(buf, sizeof(buf), "%dmm/s", toolhead["square_corner_velocity"].asInt());
             speed_info[6].num = buf;
             mListView1Ptr->refreshListView();
          }

      }//toolhead

      //motion_report 查看请求速度
      if (status.isMember("motion_report"))
      {
          Json::Value motion_report = status["motion_report"];
          //请求速度
          if(motion_report.isMember("live_velocity"))
          {
             snprintf(buf, sizeof(buf), "%dmm/s", motion_report["live_velocity"].asInt());
             speed_info[0].num = buf;
             mListView1Ptr->refreshListView();
          }


      }//motion_report查看请求速度


      if (status.isMember("mmu")) {
				 Json::Value Mmu = status["mmu"];
	               if (Mmu.isMember("tool")) {
	              	 mmu.cur_tool_num = Mmu["tool"].asInt();
//	              	 LOGD("cur_tool_num:%d", mmu.cur_tool_num);
	               }
				 if (Mmu.isMember("ttg_map")) {
					 Json::Value ttg_map = Mmu["ttg_map"];

					 if (ttg_map.isArray()) {
						  mmu.all_tool_num =  static_cast<int>(ttg_map.size());
//						  LOGD("all_tool_num:%d", mmu.all_tool_num);
					}
				}
			mERCF_ListViewPtr->refreshListView();

		}//mmu


	}
}

void run_next_Calibration(){

	Cur_Calibration_term ++;
	mListView2Ptr->refreshListView();
	mListView2Ptr->refreshListView();
	mListView3Ptr->refreshListView();

	LOGD("cc:%d,%d",Cur_Calibration_term,(int)Calibration_term.size());
	if(Cur_Calibration_term + 1 > (int)Calibration_term.size()){
		Calibration_sw = false;
		//最后一次运行完才保存
		if(mButton24Ptr->isSelected() == true){
			gcode_send2("","SAVE_CONFIG");//喷头PID
		}
		return;
	}
	if(mHTTP_WS_BUTTONPtr->isSelected() == false){
		gcode_send2("",Calibration_term[Cur_Calibration_term]+ ".is_ca");//喷头PID
	}
}


static void handle_message(const std::string & message) {
	//printf(">>> %s\n", message.c_str());
//	if (message.find("notify_proc_stat_update") != std::string::npos) {
////	    LOGD("检测到");
////	    return;
//	} else {
//		//if(strstr(message.c_str(),"result"))
////		if(strstr(message.c_str(),"print_stats"))
//	    LOGD("AA%s", message.c_str());
//	}
//	mEditText1Ptr->setText(message);
    Json::Reader reader;
    Json::Value root;



    if (reader.parse(message, root, false)) {
       //LOGD("解析成功");

        if (root.isMember("result")) {
//        	LOGD("AA%s", message.c_str());
        	//设置http连接状态
        	if(mHTTP_WS_BUTTONPtr->isSelected() == true && HTTP_is_Connection == false){
        		HTTP_is_Connection = true;
    	        //每次连接后获取下文件列表+上位机宏列表
        		get_file("");
        		get_Host_Macros_list();

        	}

            Json::Value result = root["result"];
            if (result.isObject())
            {
            	if (result.isMember("status"))
            	{
            		Json::Value status = result["status"];
            		parseStatusJson(status);
            	}
            	if (result.isMember("objects"))
            	{
            		Json::Value status = result["objects"];
            		parseMacrosJson(status);
//            		parseStatusJson(status);

//            		LOGD("JINJINJINAAAAAAAAAAAAAAA");
            	}

//            	if (result.isMember("state"))
//            	{
//
//            		if(result["state"].asString() == "error" && mrestart_layerPtr->isVisible() == true)
//            		{
//                       	if (result.isMember("state_message"))
//                        	{
//                               mTextView41Ptr->setText(result["state_message"].asString().c_str());
//                        	}
//            		}
//            	}

            	//显示文件列表文件夹，用于u盘等等
            	parseFileJson(result);


            }else if(result.isArray()){

            }else{

            	//LOGD("bbbbb");
                std::string resultValue = root["result"].asString();
                std::string idValue;
                if(root.isMember("id")){
                	 idValue = root["id"].asString();
                }
                if(Cur_Calibration_id == idValue && resultValue == "ok" && Calibration_sw == true)
                {

                	//反馈OK，也有可能是有问题的，我们在别的地方检测到需要跳过当前OK
                	if(Calibration_Break_ok == true){

                		//多z轴校准有2中，第一种失败后我们不更新，直接尝试第二种。
                		if(strstr(Calibration_term[Cur_Calibration_term].c_str(),"QUAD_GANTRY_LEVEL")
                				&& Calibration_send_Z_TILT == false)
                		{
	                		gcode_send2("","Z_TILT_ADJUST");
            				Calibration_send_Z_TILT = true;
	                		Calibration_Break_ok = false;
	                		mListView2Ptr->refreshListView();
	                		mListView3Ptr->refreshListView();
	                	}else{
	                		Calibration_yes_no[Cur_Calibration_term] = 2;
	                		Calibration_Break_ok = false;
	                		run_next_Calibration();
	                	}



                	}else{
						Calibration_yes_no[Cur_Calibration_term] = 1;
						//每一项单独保存，保存后系统会重启
						if(mButton24Ptr->isSelected() == false){
							Calibration_wait_reboot = true;
							gcode_send2("","SAVE_CONFIG");//喷头PID
							LOGD("自动保存了");
						}else{
							run_next_Calibration();
						}
                	}

                }


            }
            return;
        }else if(root.isMember("error"))
        {
        	//设置http连接状态
        	if(mHTTP_WS_BUTTONPtr->isSelected() == true && HTTP_is_Connection == false){
        		HTTP_is_Connection = true;
    	        //每次连接后获取下文件列表+上位机宏列表
        		get_file("");
        		get_Host_Macros_list();

        	}

        	std::string idValue;
        	Json::Value error = root["error"];
        	 std::string errorMessage;
        	if (error.isMember("message")) {
        	       errorMessage = error["message"].asString();

        	       //只有在http模式下才加入，ws模式下这里和其它处都会报错，所以为了在ws模式下不重复添加
        	      if(mHTTP_WS_BUTTONPtr->isSelected() == true){
           	       Updata_Notify_message_list(errorMessage);
//           	       LOGD("ERR:%s",errorMessage.c_str());
        	      }

        	}
            // 提取 id
            if (root.isMember("id")) {
                idValue = root["id"].asString();

            }

            if(Cur_Calibration_id == idValue && Calibration_sw == true)
            {

            	//错误项
            	Calibration_error.push_back(Calibration_term[Cur_Calibration_term]+":");
            	//详细的错误信息
            	Calibration_error.push_back(errorMessage);
//            	LOGD("AA%s", message.c_str());
            	Calibration_yes_no[Cur_Calibration_term] = 2;
            	run_next_Calibration();

            }else{
            	if(strstr(errorMessage.c_str(),"Shutdown")){
                	mTextView41Ptr->setText(errorMessage);
                	mrestart_layerPtr->setVisible(true);
                	Calibration_sw = false;


            	}

            }


        }else if(root.isMember("method")){
        			//KLIPPER重启启动
        			if(root["method"].asString() == "notify_klippy_ready")
        			{
        				if(mHTTP_WS_BUTTONPtr->isSelected() == false){
        					Subscription_status();
        				}

                    	//系统重启后检测是否需要继续下一项校准
                    	if(Calibration_wait_reboot == true && Calibration_sw == true){
                    		Calibration_wait_reboot = false;
                    		run_next_Calibration();
                    	}

        			}
        			//KLIPPER状态数据更新
        			if(root["method"].asString() == "notify_status_update")
        			{
        				if(root.isMember("params")) {

        				        Json::Value params = root["params"];
        				        if (params.isArray()) {
        				        	for (Json::ArrayIndex i = 0; i < params.size(); ++i) {
        				        	      if (params[i].isObject()) {
        				        	         // 处理嵌套的 JSON 对象
        				        	         Json::Value nestedObject = params[i];
        				        	         parseStatusJson(nestedObject);
        				        	       }else if (params[i].isNumeric()) {
        				        	                        // 处理数字
        				        	                       // LOGD("Numeric value = %f", params[i].asDouble());
        				        	        }
        				        	 }
        				        }
        				      return;
        				 }

        			}
        			//发送的Gcode反馈
        			if(root["method"].asString() == "notify_gcode_response")
        			{
        		        Json::Value params = root["params"];
        		        if (params.isArray()) {
        		            for (Json::ArrayIndex i = 0; i < params.size(); ++i) {
        		            	string param  = params[i].asString();
        		            	Updata_Notify_message_list(param);

        		                //更新控制台
        		            	gcodes_message.push_back(param) ;
        		            	mListView5Ptr->refreshListView();
        		            	mListView5Ptr->setSelection((int)gcodes_message.size()-1);
        		            	if(strstr(param.c_str(),"// Encoder position:")){
        		            	//	char buf[32];
        		            	//	snprintf(buf,sizeof(buf),"%0.1fmm")
        		            	    size_t pos = param.find("\n");
        		            	    if (pos != std::string::npos) {
        		            	        std::string desired_segment = param.substr(0,pos);
        		            	        mencode_viewPtr->setText(desired_segment.c_str());
        		            	    }

        		            	}
        		                //如果当前在校准阶段，检测到反馈错误，我们就跳过返回的OK，以免失败的变成成功的
        		                if( (Calibration_sw == true && strstr(param.c_str(),Calibration_term[Cur_Calibration_term].c_str()) )
        		                		|| strstr(param.c_str(),"Z_TILT"))
        		                {
        		                	//错误项
        		                	Calibration_error.push_back(Calibration_term[Cur_Calibration_term]+":");
        		                	//详细的错误信息
        		                	Calibration_error.push_back(param);
        		                	Calibration_Break_ok = true;

        		                }
        		            }
        		        }
        			}

        		if(root["method"].asString() == "notify_klippy_shutdown")
        		{


        		}
        }


    }


}//列表界面

void Updata_Notify_message_list(string param){

    if(strstr(param.c_str(),"Must home axis first"))
    {
    	Notify_message_list.push_back("plase home");
    	notify_open_close(true);
    }else if(strstr(param.c_str(),"Extrude below minimum temp")){
    	Notify_message_list.push_back("plase heat");
    	notify_open_close(true);
    }else if(strstr(param.c_str(),"Homing failed") || strstr(param.c_str(),"Error during homing move:")){
    	Notify_message_list.push_back("home failed");
    	notify_open_close(true);
    }else if(strstr(param.c_str(),"Probe triggered prior to movement")){
    	Notify_message_list.push_back("triggered prematurely");
    	notify_open_close(true);
    }else if(strstr(param.c_str(),"still triggered")){
    	Notify_message_list.push_back("still triggered");
    	notify_open_close(true);
    }else if(strstr(param.c_str(),"No trigger")){
    	Notify_message_list.push_back("no triggered");
    	notify_open_close(true);
    }else if(strstr(param.c_str(),"The value 'fan1' is not valid for FAN")){
    	Notify_message_list.push_back("define fan1");
    	notify_open_close(true);
    	mFAN2_SW_ButtonPtr->setSelected(false);
    	mFAN2_SW_ButtonPtr->setTextTr("off");
    }else if(strstr(param.c_str(),"The value 'fan2' is not valid for FAN")){
    	Notify_message_list.push_back("define fan2");
    	notify_open_close(true);
    	mFAN3_SW_ButtonPtr->setSelected(false);
    	mFAN3_SW_ButtonPtr->setTextTr("off");
    }else if(strstr(param.c_str(),"Move out of range")){
    	Notify_message_list.push_back("move out");
    	notify_open_close(true);
    }else if(strstr(param.c_str(),"The value 'LED' is not valid for LED")){
    	Notify_message_list.push_back("define led");
    	notify_open_close(true);
    	mButton98Ptr->setSelected(false);
    }else if(strstr(param.c_str(),"!! mcu 'mcu': Unable to connect")){
    	mTextView41Ptr->setTextTr("Unable to connect");
    	mrestart_layerPtr->setVisible(true);
    	Notify_message_list.push_back("Unable to connect");
    	notify_open_close(true);
    	mButton98Ptr->setSelected(false);
    }


}


void Subscription_status(){
	New_Sw_id();
	WS->send("{\"jsonrpc\":\"2.0\","
			"\"method\":\"printer.objects.subscribe\","
			"\"params\": {"
				"\"objects\": {"
					"\"webhooks\":[\"state\",\"state_message\"],"
					"\"extruder\": [\"target\",\"temperature\",\"pressure_advance\",\"smooth_time\"],"//目标温度，当前温度，压力提前，平滑时间
					"\"heater_bed\": [\"target\",\"temperature\"],"
					"\"heater_generic warehouse\": [\"target\",\"temperature\"],"
					"\"gcode_move\": [\"homing_origin\",\"position\",\"speed_factor\",\"extrude_factor\"],"//原点。坐标点，速度，挤出倍率
					"\"fan\": [\"speed\"],"
					"\"print_stats\": [\"filament_used\", \"filename\", \"print_duration\", \"state\"],"
					"\"display_status\": [\"progress\"],"
					"\"exclude_object\": [\"objects\",\"excluded_objects\"],"
					"\"toolhead\": [\"max_velocity\",\"max_accel\",\"square_corner_velocity\"],"//最大速度，最大加速度，转角速度
					"\"mmu\": [\"tool\",\"ttg_map\"],"
					"\"fan_generic "+fan1_name+"\": [\"speed\"],"
					"\"fan_generic "+fan2_name+"\": [\"speed\"],"
					"\"led LED\": [\"color_data\"],"
					"\"motion_report\": [\"live_velocity\"]"//请求速度

			"}},"
			"\"id\":"+ sw_id +"}");
//LOGD("链接完成id%s",sw_id.c_str());
}

void Start_WebSocket(string ip, string port, string token) {

	if(strstr(ip.c_str(),":"))
	{
		WS = WebSocket::from_url("ws://" + ip  + "/websocket?token=" + token,
				"http://" + ip );
	}else{
		WS = WebSocket::from_url("ws://" + ip +":7125" + "/websocket?token=" + token,
				"http://" + ip );
	}


	if (!WS) {
	    return;
	}
	init_ui_data();
	assert(WS);
	Subscription_status();
	get_file("");
	get_Host_Macros_list();


	while (WS->getReadyState() != WebSocket::CLOSED)
	{
		if(Ethernet_mode && !ETHMANAGER->isConnected()){
			LOGD("WebSocketaaa断开aaaa");
			WS->close();
			ws_closs = false;
			sync();
			reboot(RB_AUTOBOOT);
		}

		if(ws_closs == false)
		{
			WS->poll();
			WS->dispatch(handle_message);
		}else
		{
			LOGD("WebSocket断开aaaa");
			WS->close();
			ws_closs = false;
			break;
		}

	}
	LOGD("WebSocket断开");
	delete WS;
	init_ui_data();
}


 class Temp_Thread: public Thread {
 public:
   /**
    * 线程创建成功后会调用该函数，可以在该函数中做一些初始化操作
    * return true   继续线程
    *        false  退出线程
    */
   virtual bool readyToRun() {

     return true;
   }


   virtual bool threadLoop() {

     if (exitPending()) {
       return false;
     }
     //ws模式连接
     if((WIFIMANAGER->isConnected() || ETHMANAGER->isConnected()) && mHTTP_WS_BUTTONPtr->isSelected() == false){


    	 //连上设备以后先初始化一遍wifi
    	 if(Ethernet_mode == true && !GET_WIFI_List.isRunning())
    	 {
    		 GET_WIFI_List.run("");
    	 }

         Start_WebSocket(master_print_ip,"7125","");

     }else{//http请求连接

    	    if (!conn) {
    	    	HTTP_data_request.clear();
    	    	HTTP_is_Connection = false;
    	    	init_ui_data();
    	        std::string url = "http://" + master_print_ip;
    	        conn = new RestClient::Connection(url);

    	        // 设置 HTTP headers
    	        RestClient::HeaderFields headers;
    	        headers["Content-Type"] = "application/x-www-form-urlencoded";
    	        conn->SetHeaders(headers);
    	        // 配置连接参数
    	        conn->FollowRedirects(true);
    	        conn->SetTimeout(5000);


    	    }

    	    string sends;
    	    RestClient::Response r;
      	int posEnter = HTTP_data_request.find("\n");

      		if(posEnter > 0)
      		{
      			sends = HTTP_data_request.substr(0, posEnter);
      			if(strstr(sends.c_str(),"server/files/directory?")){//获取文件列表
      				LOGD("sends:%s",sends.c_str());
      				r = conn->get(encode_url(sends));
      			}else if(strstr(sends.c_str(),"delete_file/server/files/gcodes")){//删除文件
      				sends = sends.substr(12, sends.size());
      				LOGD("DEL:%s",encode_url(sends).c_str());
      				r = conn->del(encode_url(sends));
      			}else{
      				r = conn->post(encode_url(sends),"");
       				//如果控制台打开了，手动发送的命令展示出来反馈
          				if(mGcode_layerPtr->isVisible())
          				{
          					sends = "/server/gcode_store?count=1";
          					r = conn->get(encode_url(sends));
          					LOGD("aPOST:%s",r.body.c_str());
          				    Json::Reader reader;
          				    Json::Value root;
          				   // 解析 JSON 字符串
          				    if (reader.parse(r.body, root, false))
          				    {
          				      std::string _message;
          				      std::string _type;
          				        // 检查 "result" 字段是否存在
          				        if (root.isMember("result"))
          				        {
          				            Json::Value result = root["result"];

          				            if (result.isMember("gcode_store") && result["gcode_store"].isArray()) {
          				                Json::Value gcode_store = result["gcode_store"];

          				                for (Json::ArrayIndex i = 0; i < gcode_store.size(); ++i) {
          				                    Json::Value item = gcode_store[i];

          				                    if (item.isMember("message")) {
          				                    	_message = item["message"].asString();
          				                    }
          				                    if (item.isMember("type")) {
          				                    	_type = item["type"].asString();
          				                    }
          				                }
          				            }
          				        }
      				            if(_type == "response"){
          				            gcodes_message.push_back(_message);
      				            }else{
      				            	gcodes_message.push_back("ok");
      				            }
      				            mListView5Ptr->refreshListView();
          				    }
          				}
      			}

//      			LOGD("sends:%s",sends.c_str());
//      			LOGD("POST:%s",r.body.c_str());
          		HTTP_data_request = HTTP_data_request.erase(0, posEnter + 1);		// 删除\n以前的数据和\n本身
          		posEnter = HTTP_data_request.find("\n");
      		}else{
      			sends = "/printer/objects/query?" + http_objects;
      			r = conn->post(encode_url(sends),"");
      	}
      	handle_message(r.body.c_str());

//      	 LOGD("POST:%s",r.body.c_str());



     }

     usleep(1000 * 100);

     //返回真，继续下次线程循环
     return true;
   }
 };
 static Temp_Thread temp_thread;

//HTTP校准线程
 class CA_Thread: public Thread {
 public:
   /**
    * 线程创建成功后会调用该函数，可以在该函数中做一些初始化操作
    * return true   继续线程
    *        false  退出线程
    */
   virtual bool readyToRun() {

     return true;
   }


   virtual bool threadLoop() {

     if (exitPending()) {
       return false;
     }
     if(!http_ca_conn){
	        std::string url = "http://" + master_print_ip;
	        http_ca_conn = new RestClient::Connection(url);

	        // 设置 HTTP headers
	        RestClient::HeaderFields _headers;
	        _headers["Content-Type"] = "application/x-www-form-urlencoded";
	        http_ca_conn->SetHeaders(_headers);
	        // 配置连接参数
	        http_ca_conn->FollowRedirects(true);
//	        http_ca_conn->SetTimeout(999999999);
     }

     if(Calibration_term.size() > 0 && Calibration_sw == true && Calibration_wait_reboot == false){
 	    string sends;
 	    RestClient::Response r;

 	    sends = Calibration_term[Cur_Calibration_term];
		if(strstr(sends.c_str(),"\\n")){
			sends = replace_newline(sends);
			sends = encode_url2(sends);
		}
 	    sends = "/printer/gcode/script?script="+ sends;

 	    LOGD("sends:%s",sends.c_str());
 	   	Cur_Calibration_id = "12345";

   		r = http_ca_conn->post(encode_url(sends),"");

   		LOGD("CA:%s",r.body.c_str());

   		if(strstr(r.body.c_str(),"\"result\":\"ok\"")){
   			handle_message("{\"jsonrpc\":\"2.0\",\"result\":\"ok\",\"id\":12345}");
   		}else{
   		    Json::Reader reader;
   		    Json::Value root;
   		    if (reader.parse(r.body, root, false)) {
   		        if (root.isMember("error")) {
   		            Json::Value error = root["error"];
   		        	if (error.isMember("message")) {
//   		        		if(strstr(r.body.c_str(),"Z_TILT"))
//   		        		{
//   		        			Calibration_Break_ok = true;
//   		        		}
   		        		handle_message("{\"jsonrpc\":\"2.0\",\"error\":{\"code\":400,\"message\":\"" + error["message"].asString() + "\"},\"id\":12345}");
   		        	}
   		        }
   		    }


   		}
//   		run_next_Calibration();
		if(Cur_Calibration_term + 1 > (int)Calibration_term.size()){
			return false;
		}

     }

     if(Calibration_sw == false){
    	 return false;
     }


     usleep(1000 * 100);

     //返回真，继续下次线程循环
     return true;
   }
 };
 static CA_Thread ca_thread;



 void get_Host_Macros_list(){
		gcode_send2("printer.objects.list","");
 }


void get_file(std::string gcode_path){

		File_Gcodes.clear();
		std::string params = "\"path\": \"gcodes" + gcode_path +"\",\"extended\": true";
		if(mHTTP_WS_BUTTONPtr->isSelected() == false){
			gcode_send2("server.files.get_directory",params);
		}else{
			gcode_send2("server.files.directory?","path=gcodes" + gcode_path +"&extended=true");
		}
}



// 递归打印 JSON Value
void printJsonValue(const Json::Value& value, Exclude_Object& object) {

    	if (value.isArray()) {
        // 遍历数组的每个元素
        for (Json::ArrayIndex i = 0; i < value.size(); ++i) {
            // 打印数组索引，并增加缩进级别
           // LOGD("b%*s[%d]:\n", level, "", i);
            // 递归调用打印该元素的值

            printJsonValue(value[i],object);

        }
    }
    // 如果当前值是其他类型（整数、字符串等）
    else {
        // 直接打印值的字符串表示，并增加缩进级别
        //LOGD("c%f", value.asFloat());
        object.button_pos.push_back(value.asFloat()) ;

    }

}

// 定义结构体
struct WindowData {
    std::string filename;
    int x;
    int y;
//    int width;
//    int height;
};
WindowData windowData;


void init_exclude_Object_button(float scale)
{

	LayoutPosition Obj_button_pos;
	LayoutPosition Obj_button_mid_pos;


	LayoutPosition windou_size_pos = mExclude_Object_window2Ptr->getPosition();



	for(int i = 0 ;i < (int)exclude_object.size();i++)
	{
//		Obj_button_pos.mLeft   = exclude_object[i].button_xpos * scale-10;
//		Obj_button_pos.mTop    = windou_size_pos.mHeight - exclude_object[i].button_ypos * scale-10 ;
//		Obj_button_pos.mWidth  = exclude_object[i].button_Width * scale+20;
//		Obj_button_pos.mHeight = exclude_object[i].button_height * scale+20;

		//由于使用上面的方式会导致cura兼容性较差，所以我们改用现在的模式，
		Obj_button_mid_pos.mWidth  = 20 ;
		Obj_button_mid_pos.mHeight = 20 ;
		Obj_button_mid_pos.mLeft   = exclude_object[i].button_mid_x - 10;
		Obj_button_mid_pos.mTop    = exclude_object[i].button_mid_y + 10;
//		LOGD("win:%d,%d",windou_size_pos.mWidth,windou_size_pos.mHeight);
//		LOGD("POS:%d,%d,%d,%d",Obj_button_mid_pos.mLeft,Obj_button_mid_pos.mTop,Obj_button_mid_pos.mWidth,Obj_button_mid_pos.mHeight);


		Obj_button_pos.mLeft   = Obj_button_mid_pos.mLeft * scale;
		Obj_button_pos.mTop    = windou_size_pos.mHeight - Obj_button_mid_pos.mTop  * scale;
		Obj_button_pos.mWidth  = 20 * scale;
		Obj_button_pos.mHeight = 20 * scale;


		switch(i)
		{
		case 0:

			mobj_B0Ptr->setVisible(true);
			mobj_B0Ptr->setPosition(Obj_button_pos);

			break;

		case 1:

			mobj_B1Ptr->setVisible(true);
			mobj_B1Ptr->setPosition(Obj_button_pos);
			break;

		case 2:

			mobj_B2Ptr->setVisible(true);
			mobj_B2Ptr->setPosition(Obj_button_pos);
			break;

		case 3:

			mobj_B3Ptr->setVisible(true);
			mobj_B3Ptr->setPosition(Obj_button_pos);
			break;

		case 4:

			mobj_B4Ptr->setVisible(true);
			mobj_B4Ptr->setPosition(Obj_button_pos);
			break;

		case 5:

			mobj_B5Ptr->setVisible(true);
			mobj_B5Ptr->setPosition(Obj_button_pos);
			break;

		case 6:
			mobj_B6Ptr->setVisible(true);
			mobj_B6Ptr->setPosition(Obj_button_pos);
			break;

		case 7:
			mobj_B7Ptr->setVisible(true);
			mobj_B7Ptr->setPosition(Obj_button_pos);
			break;

		case 8:
			mobj_B8Ptr->setVisible(true);
			mobj_B8Ptr->setPosition(Obj_button_pos);
			break;

		case 9:
			mobj_B9Ptr->setVisible(true);
			mobj_B9Ptr->setPosition(Obj_button_pos);
			break;

		case 10:
			mobj_B10Ptr->setVisible(true);
			mobj_B10Ptr->setPosition(Obj_button_pos);
			break;

		case 11:
			mobj_B11Ptr->setVisible(true);
			mobj_B11Ptr->setPosition(Obj_button_pos);
			break;

		case 12:
			mobj_B12Ptr->setVisible(true);
			mobj_B12Ptr->setPosition(Obj_button_pos);
			break;

		case 13:
			mobj_B13Ptr->setVisible(true);
			mobj_B13Ptr->setPosition(Obj_button_pos);
			break;

		case 14:
			mobj_B14Ptr->setVisible(true);
			mobj_B14Ptr->setPosition(Obj_button_pos);
			break;

		case 15:
			mobj_B15Ptr->setVisible(true);
			mobj_B15Ptr->setPosition(Obj_button_pos);
			break;

		case 16:
			mobj_B16Ptr->setVisible(true);
			mobj_B16Ptr->setPosition(Obj_button_pos);
			break;

		case 17:
			mobj_B17Ptr->setVisible(true);
			mobj_B17Ptr->setPosition(Obj_button_pos);
			break;

		case 18:
			mobj_B18Ptr->setVisible(true);
			mobj_B18Ptr->setPosition(Obj_button_pos);
			break;

		case 19:
			mobj_B19Ptr->setVisible(true);
			mobj_B19Ptr->setPosition(Obj_button_pos);
			break;

		case 20:
			mobj_B20Ptr->setVisible(true);
			mobj_B20Ptr->setPosition(Obj_button_pos);
			break;

		case 21:
			mobj_B21Ptr->setVisible(true);
			mobj_B21Ptr->setPosition(Obj_button_pos);
			break;

		case 22:
			mobj_B22Ptr->setVisible(true);
			mobj_B22Ptr->setPosition(Obj_button_pos);
			break;

		case 23:
			mobj_B23Ptr->setVisible(true);
			mobj_B23Ptr->setPosition(Obj_button_pos);
			break;

		case 24:
			mobj_B24Ptr->setVisible(true);
			mobj_B24Ptr->setPosition(Obj_button_pos);
			break;

		case 25:
			mobj_B25Ptr->setVisible(true);
			mobj_B25Ptr->setPosition(Obj_button_pos);
			break;

		case 26:
			mobj_B26Ptr->setVisible(true);
			mobj_B26Ptr->setPosition(Obj_button_pos);
			break;

		case 27:
			mobj_B27Ptr->setVisible(true);
			mobj_B27Ptr->setPosition(Obj_button_pos);
			break;

		case 28:
			mobj_B28Ptr->setVisible(true);
			mobj_B28Ptr->setPosition(Obj_button_pos);
			break;

		case 29:
			mobj_B29Ptr->setVisible(true);
			mobj_B29Ptr->setPosition(Obj_button_pos);
			break;

		case 30:
			mobj_B30Ptr->setVisible(true);
			mobj_B30Ptr->setPosition(Obj_button_pos);
			break;


		}
	}


}
//初始化打印界面的缩略图
void init_thumbnail(){

	std::string url = "http://" + master_print_ip + "/server/files/thumbnails?filename=" + current_file_information.filename;
//    LOGD("thumbnail url: %s",url.c_str());

    RestClient::Response thumbnail_json = RestClient::get(encode_url(url));
    //LOGD("thumbnail_json: %s",thumbnail_json.body.c_str());
    // 解析 当前文件是否包含缩略图 JSON 字符串
    Json::Reader thumbnailReader;
    Json::Value thumbnailroot;
    if (thumbnailReader.parse(thumbnail_json.body, thumbnailroot, false)) {

        // 检查是否存在 "result" 字段
        if (thumbnailroot.isMember("result")) {
            const Json::Value& resultArray = thumbnailroot["result"];

            // 遍历 "result" 数组
            for (Json::ArrayIndex j = 0; j < resultArray.size(); ++j) {
                const Json::Value& thumbnailItem = resultArray[j];
                if(j == 1)
                {
            	    string save_path = Save_Path +"xyz.png";
            	    //发起HTTPS GET请求
            	    url = "http://" + master_print_ip + "/server/files/gcodes/" + thumbnailItem["thumbnail_path"].asString();
            	   // LOGD("Thumbnail Path: %s", url.c_str() );

            	    RestClient::Response r = RestClient::download(encode_url(url), save_path);
            	    mthumbnail_pngPtr->setBackgroundPic(save_path.c_str());
//            	    LOGD("save_path: %s", save_path.c_str() );

                }

            }
//            //获得当前文件的切片软件，因为cura的对象排除有问题
//            url = "http://" + master_print_ip + "/server/files/metadata?filename=" + current_file_information.filename;
//            thumbnail_json = RestClient::get(encode_url(url));
//            if (thumbnailReader.parse(thumbnail_json.body, thumbnailroot, false)) {
//
//                   if (thumbnailroot.isMember("result")) {
//                       const Json::Value& result = thumbnailroot["result"];
//                       if(result.isMember("slicer"))
//                    	{
//                    	   current_file_information.slicer = result["slicer"].asString();
//
//                    	}
//
//
//                   }
//            }


        }
    }





}


//获取当前打印文件的首层图片，以及获取每个模型的坐标位置
void init_exclude_obj(){

	mobj_B0Ptr->setVisible(false);
	mobj_B0Ptr->setBackgroundPic("exclude_object.png");
	mobj_B1Ptr->setVisible(false);
	mobj_B1Ptr->setBackgroundPic("exclude_object.png");
	mobj_B2Ptr->setVisible(false);
	mobj_B2Ptr->setBackgroundPic("exclude_object.png");
	mobj_B3Ptr->setVisible(false);
	mobj_B3Ptr->setBackgroundPic("exclude_object.png");
	mobj_B4Ptr->setVisible(false);
	mobj_B4Ptr->setBackgroundPic("exclude_object.png");
	mobj_B5Ptr->setVisible(false);
	mobj_B5Ptr->setBackgroundPic("exclude_object.png");
	mobj_B6Ptr->setVisible(false);
	mobj_B6Ptr->setBackgroundPic("exclude_object.png");
	mobj_B7Ptr->setVisible(false);
	mobj_B7Ptr->setBackgroundPic("exclude_object.png");
	mobj_B8Ptr->setVisible(false);
	mobj_B8Ptr->setBackgroundPic("exclude_object.png");
	mobj_B9Ptr->setVisible(false);
	mobj_B9Ptr->setBackgroundPic("exclude_object.png");
	mobj_B10Ptr->setVisible(false);
	mobj_B10Ptr->setBackgroundPic("exclude_object.png");
	mobj_B11Ptr->setVisible(false);
	mobj_B11Ptr->setBackgroundPic("exclude_object.png");
	mobj_B12Ptr->setVisible(false);
	mobj_B12Ptr->setBackgroundPic("exclude_object.png");
	mobj_B13Ptr->setVisible(false);
	mobj_B13Ptr->setBackgroundPic("exclude_object.png");
	mobj_B14Ptr->setVisible(false);
	mobj_B14Ptr->setBackgroundPic("exclude_object.png");
	mobj_B15Ptr->setVisible(false);
	mobj_B15Ptr->setBackgroundPic("exclude_object.png");
	mobj_B16Ptr->setVisible(false);
	mobj_B16Ptr->setBackgroundPic("exclude_object.png");
	mobj_B17Ptr->setVisible(false);
	mobj_B17Ptr->setBackgroundPic("exclude_object.png");
	mobj_B18Ptr->setVisible(false);
	mobj_B18Ptr->setBackgroundPic("exclude_object.png");
	mobj_B19Ptr->setVisible(false);
	mobj_B19Ptr->setBackgroundPic("exclude_object.png");
	mobj_B20Ptr->setVisible(false);
	mobj_B20Ptr->setBackgroundPic("exclude_object.png");
	mobj_B21Ptr->setVisible(false);
	mobj_B21Ptr->setBackgroundPic("exclude_object.png");
	mobj_B22Ptr->setVisible(false);
	mobj_B22Ptr->setBackgroundPic("exclude_object.png");
	mobj_B23Ptr->setVisible(false);
	mobj_B23Ptr->setBackgroundPic("exclude_object.png");
	mobj_B24Ptr->setVisible(false);
	mobj_B24Ptr->setBackgroundPic("exclude_object.png");
	mobj_B25Ptr->setVisible(false);
	mobj_B25Ptr->setBackgroundPic("exclude_object.png");
	mobj_B26Ptr->setVisible(false);
	mobj_B26Ptr->setBackgroundPic("exclude_object.png");
	mobj_B27Ptr->setVisible(false);
	mobj_B27Ptr->setBackgroundPic("exclude_object.png");
	mobj_B28Ptr->setVisible(false);
	mobj_B28Ptr->setBackgroundPic("exclude_object.png");
	mobj_B29Ptr->setVisible(false);
	mobj_B29Ptr->setBackgroundPic("exclude_object.png");
	mobj_B30Ptr->setVisible(false);
	mobj_B30Ptr->setBackgroundPic("exclude_object.png");

	std::string url = "http://" + master_print_ip + "/printer/objects/query?exclude_object";

	RestClient::Response r;

    Json::Reader reader;
    Json::Value root;

    url = "http://" + master_print_ip + "/server/files/bottompic?filename=" +  current_file_information.filename + "&zoom=3&layer=1";

    //LOGD("aa%s",encode_url(url).c_str());
    r = RestClient::get(encode_url(url));


    if (reader.parse(r.body, root, false)) {
    	LOGD("解析成功1");

        if (root.isMember("result")) {
            Json::Value result = root["result"];

            if (result.isMember("filename")) {
            	windowData.filename = result["filename"].asString();
            	//LOGD("name%s",windowData.filename.c_str());
            }
            if (result.isMember("x")) {
            	windowData.x = result["x"].asInt();
            }
            if (result.isMember("y")) {
            	windowData.y = result["y"].asInt();
            }
//            if (result.isMember("width")) {
//            	windowData.width = result["width"].asInt();
//            }
//            if (result.isMember("height")) {
//            	windowData.height = result["height"].asInt();
//            }
    	    string save_path = Save_Path + "xyza.png";
    	    //发起HTTPS GET请求
    	  url = "http://" + master_print_ip + "/server/files/" + windowData.filename;
    	  //LOGD("%s",url.c_str());
    	  RestClient::Response downloada = RestClient::download(encode_url(url), save_path);

    	    window_cur_mid_xpos = 400;
    	    window_cur_mid_ypos = 300;

		      static LayoutPosition pos(window_cur_mid_xpos - windowData.x * 0.5, window_cur_mid_ypos - windowData.y * 0.5, windowData.x, windowData.y);

		      mExclude_Object_window2Ptr->setPosition(pos);
		      mExclude_Object_window2Ptr->setBackgroundPic(save_path.c_str());


		      int window_end_xpos = window_cur_mid_xpos - windowData.x*(3/2);
		      int window_end_ypos = window_cur_mid_ypos - windowData.y*(3/2);
		      int kaun = windowData.x * 3;
		      int gao = windowData.y * 3;

		      pos.mLeft = window_end_xpos;
		      pos.mTop = window_end_ypos;
		      pos.mWidth = kaun;
		      pos.mHeight = gao;



		  	mExclude_Object_window2Ptr->setPosition(pos);



		      init_exclude_Object_button(3.0);

        }else{
        	LOGD("解a");
        }
    }


}



//开机初始化存的自定义按钮
void init_Customize_button(void)
{
	std::string Customize = StoragePreferences::getString("Customize_buttons", "");
//	LOGD("vvvvv%s", Customize.c_str());
    Json::Reader reader;
    Json::Value root;
	if (reader.parse(Customize, root, false)) {
	//处理文件
	if (root.isMember("Customize_buttons"))
	{
		Customize_button.clear();

		Json::Value _buttons = root["Customize_buttons"];
		if(_buttons.isArray())
		{
	           // 遍历 "result" 数组
	         for (Json::ArrayIndex i = 0; i < _buttons.size(); ++i)
	         {
				  const Json::Value& item = _buttons[i];

				  Customize_buttons _cu;
				  _cu.name = item["name"].asString();
				  _cu.gcode = item["gcode"].asString();
				  _cu.type = item["type"].asString();
				  if(item.isMember("Gpio"))
					  _cu.Gpio = item["Gpio"].asString();
				  else
					  _cu.Gpio = "null";
				  Customize_button.push_back(_cu);
	         }
		}

	}


	}
}




/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	{0,  1000}, //定时器id=0, 时间间隔6秒
	{1,  10},
	{2,  100},
	{3,  500},
};

/**
 * 当界面构造时触发
 */
static void onUI_init(){
	 fan1_name = StoragePreferences::getString("fan1_name", "fan1");
	 mFAN2_ICONPtr->setText(fan1_name);
	 fan2_name = StoragePreferences::getString("fan2_name", "fan2");
	 mFAN3_ICONPtr->setText(fan2_name);

	 http_objects = ""
	 		"webhooks=state,state_message"
	 		"&extruder=target,temperature,pressure_advance,smooth_time"
	 		"&heater_bed=target,temperature"
	 		"&heater_generic warehouse=target,temperature"
	 		"&gcode_move=homing_origin,position,speed_factor,extrude_factor"
	 		"&fan=speed"
	 		"&print_stats=filament_used,filename,print_duration,state"
	 		"&display_status=progress"
//	 		"&exclude_object=objects,excluded_objects"
	 		"&toolhead=max_velocity,max_accel,square_corner_velocity"
	 		"&mmu=tool,ttg_map"
	 		"&fan_generic "+fan1_name+"=speed"
	 		"&fan_generic "+fan2_name+"=speed"
	 		"&led LED=color_data"
	 		"&motion_report=live_velocity";

	//键盘长按监听
	mButton167Ptr->setLongClickListener(&longButtonClickListener);

	//开机后获取z轴是否需要翻转
	bool moto_revers = StoragePreferences::getBool("moto_revers", false);
	mButton_moto_reversPtr->setSelected(moto_revers);
	//开机后获取z偏移按钮z轴是否需要翻转
	bool zoffset_moto_revers = StoragePreferences::getBool("Z_Offset_moto_revers", false);
	mZ_Offset_Reverse_ButtonPtr->setSelected(zoffset_moto_revers);

	//开启以太网连接模式
	if(Ethernet_mode == true)
	{
		master_print_ip = "192.168.251.100";
		mButton73Ptr->setVisible(false);//关闭屏幕设置
		mButton17Ptr->setVisible(false);//关闭调节休眠设置
		mTextView21Ptr->setVisible(false);//关闭调节休眠设置
		mTextView30Ptr->setVisible(false);//关闭设置界面wifi的mac显示设置


		mms_file_buttonPtr->setVisible(false);//关闭上位机文件按钮选项
		mUdesk_buttonPtr->setVisible(false);//关闭屏幕u盘按钮
		mSd_buttonPtr->setVisible(false);//关闭屏幕sd卡按钮

		LayoutPosition pos= mLayer2_ButtonPtr->getPosition();
		if(screen_size == 7)//7寸
		{
			//设置左侧栏按钮位置
			pos.mTop = (600-pos.mHeight)/3 * 1;
			mLayer2_ButtonPtr->setPosition(pos);
			pos.mTop = (600-pos.mHeight)/3 * 2;
			mFile_ButtonPtr->setPosition(pos);
			//设置左侧栏按钮位置结束

		}else//5寸
		{
			pos.mTop = (480-pos.mHeight)/3 * 1;
			mLayer2_ButtonPtr->setPosition(pos);
			pos.mTop = (480-pos.mHeight)/3 * 2;
			mFile_ButtonPtr->setPosition(pos);
		}

		GET_WIFI_List.requestExit();

	}
	bool Http = StoragePreferences::getBool("Http", false);
	mHTTP_WS_BUTTONPtr->setSelected(Http);
	mzoffset0005_ButtonPtr->setSelected(true);//最偏移按钮初始化选中状态
	mButton20Ptr->setSelected(true);
	mtemp_move_ButtonPtr->setSelected(true);
    mms_file_buttonPtr->setSelected(true);
    mUdesk_buttonPtr->setSelected(false);
    mSd_buttonPtr->setSelected(false);

    mButton42Ptr->setSelected(true);
    mButton43Ptr->setSelected(false);
    mPrint_set_buttonPtr->setSelected(false);


	scan_Print_mac.run();
	scan_Print_send_commd.run();
	Init_print_info();
	char buf[64];
	for (int i = 0; i < 32; ++i) {
		snprintf(buf,sizeof(buf),"COLOR%d",i);
	    ERCF_GATE_SW_index[i] = StoragePreferences::getInt(buf, -1);;
	}



 	std::string Print_ip = StoragePreferences::getString("print_ip", "null");

 	if(Print_ip != "null"&& Ethernet_mode == false){
 		master_print_ip = Print_ip;
 		mButton22Ptr->setText(master_print_ip.c_str());
 	}
	FILE *fp;
	if(!(fp=fopen("/data/print.png","rb"))==NULL)
	{
	  	mTextView6Ptr->setBackgroundPic("/data/print.png");
	  	fclose(fp);
	}
	if(!(fp=fopen("/data/print_smail.png","rb"))==NULL)
	{
		mTextView4Ptr->setBackgroundPic("/data/print_smail.png");
		fclose(fp);
	}



	temp_thread.run();
	Downloa_Pic_thread.run();
	MOUNTMONITOR->addMountListener(&sMyMountListener);

	 std::srand(static_cast<unsigned int>(std::time(nullptr)));

	 Pid_ext_temp = StoragePreferences::getString("Pid_ext_temp", "210");
	 Pid_bed_temp = StoragePreferences::getString("Pid_bed_temp", "60");
	 //休眠时间读取
	time_out = StoragePreferences::getInt("cstime", 0);
		switch (time_out)
		{
			case 0:	mTextView21Ptr->setTextTr("time0");break;
			case 10:mTextView21Ptr->setTextTr("time1");  break;
			case 30:mTextView21Ptr->setTextTr("time2");  break;
			case 60:mTextView21Ptr->setTextTr("time3");  break;
			case 120:mTextView21Ptr->setTextTr("time4");  break;
			case 300:mTextView21Ptr->setTextTr("time5");  break;
			case 1800:mTextView21Ptr->setTextTr("time6"); break;
			case 3600:mTextView21Ptr->setTextTr("time7"); break;
		}

	//get_file();

	LayoutPosition pos= mButton98Ptr->getPosition();
	start_print_button_x = pos.mLeft;

	pos = mthumbnail_pngPtr->getPosition();
	int thumbnail_png_x = pos.mLeft;
	int thumbnail_png_Width = pos.mWidth;

	pos = mTextView4Ptr->getPosition();
	int TextView4_x = pos.mLeft;

	pos = mButton98Ptr->getPosition();
	int Button98_Width = pos.mWidth;

	//设置不同尺寸下打印界面的wifi温度按钮的坐标
	if(ui_modo == 1 && screen_size == 7)
	{
		end_print_button_x = 383;
	}else{
		end_print_button_x =	static_cast<int>((TextView4_x - (thumbnail_png_x + thumbnail_png_Width) - Button98_Width)/2) + (thumbnail_png_x + thumbnail_png_Width);
	}



 	std::string key = StoragePreferences::getString("key", "");

 	if(strcmp(key.c_str(),"")==0){

 	}
 	else{
     if(strcmp(key.c_str(),"0")>0){
     mlockPtr->setVisible(true);
     }
 	}


//开机检测有没有u盘/sd卡已经插入了
    FILE* pipe = popen("df", "r");
    if (!pipe) {
       // perror("popen");

    }else{
        char buffer[128];
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL){

    			if(strstr(buffer,"/mnt/usb1"))
    			{
    				udesk = true;
    				//LOGD("usbdeskaaaaaa");
    			}
    			if(strstr(buffer,"/mnt/extsd"))
    			{
    				sdcard = true;

    			}
    			//LOGD("aa%s", buffer);
            }

        }
        pclose(pipe);
    }

	 if(LANGUAGEMANAGER->getCurrentCode() == "zh_CN"){
		 lanugage[0].bOn = true;
	 }else
	 {
		 lanugage[1].bOn = true;
	 }

	 //初始化自定义按钮
	 init_Customize_button();
	 GpioHelper::output("GPIO_138",1);
	 gPIO.run();

//	 mVideoView1Ptr->play("http://192.168.6.139/webcam/?action=stream");
}
/**
 * 当切换到该界面时触发
 */
static void onUI_intent(const Intent *intentPtr) {
    if (intentPtr != NULL) {
        //TODO
    }
}

/*
 * 当界面显示时触发
 */
static void onUI_show() {

if(WIFIMANAGER->isConnected()){
		char buf[64];
		mTextView27Ptr->setText(WIFIMANAGER->getConnectionInfo()->getSsid());
		snprintf(buf,sizeof(buf),"IP:%s",WIFIMANAGER->getIp());
		mTextView28Ptr->setText(buf);
		snprintf(buf,sizeof(buf),"MAC:%s",WIFIMANAGER->getMacAddr());
		mTextView30Ptr->setText(buf);

}

//
	 if(LANGUAGEMANAGER->getCurrentCode() == "zh_CN"){
		 mTextView24Ptr->setText("语言:中文");
	 }
	 else if(LANGUAGEMANAGER->getCurrentCode() == "en_US"){
		 mTextView24Ptr->setText("English");
	 }
	 else if(LANGUAGEMANAGER->getCurrentCode() == "ja_JP"){
		 mTextView24Ptr->setText("Japanese");
	 }

	 //初始化蜂鸣器
	 bool Buzzer = StoragePreferences::getBool("Buzzer", true);
	 if(Buzzer){
		 CONFIGMANAGER->setBeepEnable(true);
		 mBuzz_BUTTONPtr->setSelected(true);
		 mTextView76Ptr->setTextTr("on");
	 }else
	 {
		 CONFIGMANAGER->setBeepEnable(false);
		 mBuzz_BUTTONPtr->setSelected(false);
		 mTextView76Ptr->setTextTr("off");
	 }


}

/*
 * 当界面隐藏时触发
 */
static void onUI_hide() {

}

/*
 * 当界面完全退出时触发
 */
static void onUI_quit() {

}

/**
 * 串口数据回调接口
 */
std::string printerCode;
static void onProtocolDataUpdate(const SProtocolData &data) {
// 	printerCode += data.str;					// 字符串连接起来
//
// 	int posEnter = printerCode.find("\n");
//// 	while (posEnter >= 0) {						// 已经找到\n，进行处理
//
// //		if(posEnter > 0)
// 			LOGD("wart:%s",printerCode.c_str());
//// 		printerCode = printerCode.erase(0, posEnter + 1);		// 删除\n以前的数据和\n本身
//// 		posEnter = printerCode.find("\n");
//// 	}



}

/**
 * 定时器触发函数
 * 不建议在此函数中写耗时操作，否则将影响UI刷新
 * 参数： id
 *         当前所触发定时器的id，与注册时的id相同
 * 返回值: true
 *             继续运行当前定时器
 *         false
 *             停止运行当前定时器
 */
//{0,  1000}, //定时器id=0, 时间间隔6秒
//{1,  10},
//{2,  100},
int TIMES = 0;
static int cstimea = 0;
static bool onUI_Timer(int id){
	switch (id) {

	case 0:
		if(mPrint_Set_WinPtr->isVisible())
		{
			mPrint_ListView1Ptr->refreshListView();
		}



		if(mERCF_SENSOR_WindowPtr->isVisible())
			{
		 	 gcode_send2("","MMU_ENCODER");
			}

//			if(layer_open == true)
//			{
//				TIMES += 1;
//				int window_end_xpos = 577 - static_cast<int>(894*TIMES / 200);
//				int window_end_ypos = 300 - static_cast<int>(600*TIMES / 200);
//				LayoutPosition pos(window_end_xpos, window_end_ypos, 894 * TIMES/100,  600 * TIMES/100);
//				LOGD("x%d,y%d",window_end_xpos,window_end_ypos);
//				mhomePtr->setPosition(pos);
//				mhomePtr->setVisible(true);
//				if(TIMES >= 100)
//				{
//					layer_open = false;
//					TIMES = 0;
//				}
//
//			}
	  	 //连上设备以后先初始化一遍wifi

				//在以太网模式下，开机后连上设备以后会自动开启wifi线程，以便初始化下wifi界面，不要让客户等太久，初始化以后我们退出线程，避免占用系统性能
	    		 if(GET_WIFI_List.isRunning() && mHost_computer_wifiPtr->isVisible() == false)
	    		 {
	    			 GET_WIFI_List.requestExit();
	    		 }


	    	if(scan_Print_udp.isRunning() || scan_print.isRunning() || scan_print1.isRunning() || scan_print2.isRunning() || scan_print3.isRunning() || scan_print4.isRunning() || scan_print5.isRunning() || scan_print6.isRunning() || scan_print7.isRunning() || scan_print8.isRunning() || scan_print9.isRunning()||
	    	   scan_print10.isRunning() || scan_print11.isRunning() || scan_print12.isRunning() || scan_print13.isRunning() || scan_print14.isRunning() || scan_print15.isRunning() || scan_print16.isRunning() || scan_print17.isRunning() || scan_print18.isRunning() || scan_print19.isRunning())
	     	{
				mPrint_ListView1Ptr->refreshListView();
				mTextView78Ptr->setVisible(true);
			}else if(start_scan_print_ip == true)
			{
				mTextView78Ptr->setVisible(false);
				start_scan_print_ip = false;
				Save_all_print_info();
				mPrint_ListView1Ptr->refreshListView();


			}
			if(time_out > 0)
			{

				  cstimea++;
				  if(cstimea > time_out){
					  mAnti_touchPtr->setVisible(true);
					  BRIGHTNESSHELPER->screenOff();
					  cstimea = 0;
				  }
			}
			//取消/打印后按钮/界面保持不变
			if(print_pause_state || print_cancel_state){
				static int _time = 0;
				_time ++;
				if(_time >= 5){
					print_pause_state = false;
					print_cancel_state = false;
				}
			}



			break;
	case 1:


		break;
	case 2:

		if(scan_print.isRunning() || scan_print1.isRunning() || scan_print2.isRunning() || scan_print3.isRunning() || scan_print4.isRunning() || scan_print5.isRunning() || scan_print6.isRunning() || scan_print7.isRunning() || scan_print8.isRunning() || scan_print9.isRunning()){
			static int pic_num =1;
			char buf[16];
			snprintf(buf,sizeof(buf),"layer4/R%d.png",pic_num);
			mTextView78Ptr->setBackgroundPic(buf);
			pic_num ++;
			if(pic_num > 8)
			{
				pic_num = 1;
			}
		}

		if(up_download_sw == true)
		{
			up_download_time +=100;
		}
		if(file_progress_lise_ref == true){
			mdownload_listPtr->refreshListView();
			char buf[64];
			 if(LANGUAGEMANAGER->getCurrentCode() == "zh_CN"){
				 snprintf(buf,sizeof(buf),"文件处理中:%0.2f%%,请稍后",upload_progress);
			 }
			 else{
				 snprintf(buf,sizeof(buf),"File processing:%0.2f%%,please wait",upload_progress);
			 }

			mTextView73Ptr->setText(buf);
		}
		break;

	case 3://刷新键盘的位置符
			if(mAJ1Ptr->isVisible())
			{

				//不含有最后一个|，添加他
				if(!strstr(mTextView46Ptr->getText().c_str(),"|"))
				{
					mTextView46Ptr->setText(sContentStr + "|");
				}else{
					mTextView46Ptr->setText(sContentStr);
				}
			}

			if(mAJPtr->isVisible())
			{
				//不含有最后一个|，添加他
				if(!strstr(mTextView22Ptr->getText().c_str(),"|"))
				{
					mTextView22Ptr->setText(sContentStr + "|");
				}else{
					mTextView22Ptr->setText(sContentStr);
				}
			}
		break;
		default:
			break;
	}


	//这里是检测当前有没有按下异形按钮，避免在定时器里重复刷新按钮背景
		  if(mX_U10_BUTTONPtr->isPressed())
		  {
			  mMove_button_backgroundPtr->setBackgroundPic("layer2/X+10.png");
		      move_button_bg_sw = 1;
		  }else if(mX_U1_BUTTONPtr->isPressed())
		  {
			  mMove_button_backgroundPtr->setBackgroundPic("layer2/X+1.png");
		      move_button_bg_sw = 1;

		  }else if(mX_D10_BUTTONPtr->isPressed())
		  {
			  mMove_button_backgroundPtr->setBackgroundPic("layer2/X-10.png");
		      move_button_bg_sw = 1;

		  }else if(mX_D1_BUTTONPtr->isPressed())
		  {
			  mMove_button_backgroundPtr->setBackgroundPic("layer2/X-1.png");
		      move_button_bg_sw = 1;
		  }else if(mY_U10_BUTTONPtr->isPressed())
		  {
			  mMove_button_backgroundPtr->setBackgroundPic("layer2/Y+10.png");
		      move_button_bg_sw = 1;
		  }else if(mY_U1_BUTTONPtr->isPressed())
		  {
			  mMove_button_backgroundPtr->setBackgroundPic("layer2/Y+1.png");
		      move_button_bg_sw = 1;
		  }else if(mY_D10_BUTTONPtr->isPressed())
		  {
			  mMove_button_backgroundPtr->setBackgroundPic("layer2/Y-10.png");
		      move_button_bg_sw = 1;
		  }else if(mY_D1_BUTTONPtr->isPressed())
		  {
			  mMove_button_backgroundPtr->setBackgroundPic("layer2/Y-1.png");
		      move_button_bg_sw = 1;
		  }else if(mButton_homePtr->isPressed()){
			  mMove_button_backgroundPtr->setBackgroundPic("layer2/home.png");
		      move_button_bg_sw = 1;
		  }

		  else if(!mX_U10_BUTTONPtr->isPressed() && !mX_U1_BUTTONPtr->isPressed() && !mX_D10_BUTTONPtr->isPressed() && !mX_D1_BUTTONPtr->isPressed() &&
				  !mY_U10_BUTTONPtr->isPressed() && !mY_U1_BUTTONPtr->isPressed() && !mY_D10_BUTTONPtr->isPressed() && !mY_D1_BUTTONPtr->isPressed() &&
				  !mButton_homePtr->isPressed() && move_button_bg_sw == 1)
		    {
			  	  mMove_button_backgroundPtr->setBackgroundPic("layer2/XYZ.png");
			  	  move_button_bg_sw = 0;
		    }













    return true;
}

/**
 * 有新的触摸事件时触发
 * 参数：ev
 *         新的触摸事件
 * 返回值：true
 *            表示该触摸事件在此被拦截，系统不再将此触摸事件传递到控件上
 *         false
 *            触摸事件将继续传递到控件上
 */
//LayoutPosition pos(0, 0, 477, 480);
static bool ongcodeActivityTouchEvent(const MotionEvent &ev) {
	static MotionEvent last_ev;
    switch (ev.mActionStatus) {

		case MotionEvent::E_ACTION_DOWN://触摸按下
		{
			  //定时休眠开启屏幕
			  if(time_out > 0){
				 cstimea = 0;
				  if(!BRIGHTNESSHELPER->isScreenOn()){
				   BRIGHTNESSHELPER->screenOn();
				   mAnti_touchPtr->setVisible(false); //抬起后关闭防触摸界面
				   cstimea = 0;
			  }}

			last_ev = ev;

			//下拉栏
			if(ev.mY <= 50 && mDrop_down_menuPtr->isVisible() == false)
			{
				down_menu_sw = true;
				down_menu_y_Pos = ev.mY;
			}
			//关闭下拉栏
			if (mDrop_down_menuPtr->isVisible() == true && (mDrop_down_menuPtr->getPosition().isHit(ev.mX, ev.mY)) && !mCustomize_ListViewPtr->getPosition().isHit(ev.mX, ev.mY) && !mHost_macros_listPtr->getPosition().isHit(ev.mX, ev.mY))
			{
				down_menu_close_sw = true;
				down_menu_y_Pos = ev.mY;
			}





			  if (mGcode_layerPtr->getPosition().isHit(ev.mX-129, ev.mY-80) && mAJ1Ptr->isVisible() == false &&
				(int)gcodes_message.size() <= 13 && mGcode_layerPtr->isVisible() == true && mPrint_Set_WinPtr->isVisible() == true)
			{

				  	mAJ1Ptr->setVisible(true);
				  	delOneChar();
					sContentStr.clear();
					mTextView46Ptr->setText("");
					AJ_id = 0;
			}




		    if (!mAJPtr->getPosition().isHit(ev.mX, ev.mY)
		        && mAJPtr->isWndShow())
		    {
		    	//关闭按键窗口同时关闭温度界面那些按钮
//		    	mTextView16Ptr->setBackgroundPic("layer2/wendu.png");
//		    	mlyayer2_nozzle_temp_buttonPtr->setSelected(false);
//		    	mlyayer2_bed_temp_buttonPtr->setSelected(false);
//		    	mButton103Ptr->setSelected(false);
//		    	mlayer2_speed_buttonPtr->setSelected(false);
//		    	mFan_layer_open_buttonPtr->setSelected(false);
//
		    	if(mTextView16Ptr->isVisible() && ui_modo == 1){
		    		mTextView16Ptr->setVisible(false);
		    	}

		    	mAJPtr->hideWnd();
		        sContentStr.clear();
		        mTextView22Ptr->setText("");
		    }

		}

			//LOGD("时刻 = %ld 坐标  x = %d, y = %d", ev.mEventTime, ev.mX, ev.mY);
			break;
		case MotionEvent::E_ACTION_MOVE://触摸滑动
		{
			//打开下拉栏
			if(down_menu_sw == true )
			{

				if((ev.mY - down_menu_y_Pos) >= 10){
					//计算透明度

					down_menu_Alpha = (ev.mY - down_menu_y_Pos)*2.55;
					if(down_menu_Alpha > 255)
					{
						down_menu_Alpha = 255;
					}
					//设置透明度；
					mDrop_down_menuPtr->setAlpha(down_menu_Alpha);
					mDrop_down_menuPtr->setVisible(true);
				}

			}
//			if (down_menu_close_sw == true && (mDrop_down_menuPtr->getPosition().isHit(ev.mX, ev.mY)) && !mCustomize_ListViewPtr->getPosition().isHit(ev.mX, ev.mY))

			//关闭下拉栏
			if (down_menu_close_sw == true && (mDrop_down_menuPtr->getPosition().isHit(ev.mX, ev.mY)) && mAJ1Ptr->isVisible() == false)
			{
				if((down_menu_y_Pos - ev.mY ) >= 20){
					down_menu_close_sw = false;
					mDrop_down_menuPtr->setVisible(false);
					mCustomize_WindowPtr->setVisible(false);

				}

			}


		    int x_offset = ev.mX - last_ev.mX;
		    int y_offset = ev.mY - last_ev.mY;
		    if ((mAJPtr->getPosition().isHit(ev.mX, ev.mY)
		        && mAJPtr->isWndShow()) || mExclude_Object_window2Ptr->getPosition().isHit(ev.mX, ev.mY) ) {
		      static LayoutPosition pos;
		      pos = mAJPtr->getPosition();
		      pos.mLeft += x_offset;
		      pos.mTop += y_offset;
		      //拟态
		      if(ui_modo == 1)
		      {
		    	  if(!mTextView16Ptr->isVisible() == true )
		    	  {
		    		  mAJPtr->setPosition(pos);
		    	  }

		      }else{//非拟态
		    	  mAJPtr->setPosition(pos);
		      }



		      pos = mExclude_Object_window2Ptr->getPosition();
		      pos.mLeft += x_offset;
		      pos.mTop += y_offset;
		      mExclude_Object_window2Ptr->setPosition(pos);
			 //计算当前窗口XY中心点坐标
				window_cur_mid_xpos = pos.mLeft +  pos.mWidth/2;
				window_cur_mid_ypos = pos.mTop +  pos.mHeight/2;

		    }
		    last_ev = ev;

		}
			break;
		case MotionEvent::E_ACTION_UP:  //触摸抬起
			//	关闭下拉栏的标志；
			down_menu_sw = false;
			down_menu_close_sw = false;

			//如果透明度没有达到100%，客户放弃下拉
			if(down_menu_Alpha < 255)
			{
				mDrop_down_menuPtr->setVisible(false);
			}


			if(move_button == true)
			{
				move_button = false;
				mMove_button_backgroundPtr->setBackgroundPic("layer2/XYZ.png");
			}


			break;
		default:
			break;
	}
	return false;
}

void layer_ch(int layer)
{


	LayoutPosition pos;
	mhomePtr->setVisible(false);
	mmovePtr->setVisible(false);
	mPrint_Set_WinPtr->setVisible(false);
	mfilePtr->setVisible(false);

	mScreen_set_winPtr->setVisible(false);

    mMain_ButtonPtr->setSelected(!false);
    mLayer2_ButtonPtr->setSelected(false);
    mFile_ButtonPtr->setSelected(false);
    mButton73Ptr->setSelected(false);
    mScreen_set_ButtonPtr->setSelected(false);

	if(screen_size == 7)
	{
	    pos.mLeft = 964;
	    pos.mTop = 0;
	    pos.mWidth = 58;
	    pos.mHeight = 44;
	}
	mstop_ButtonPtr->setPosition(pos);


    if(ui_modo == 1)
    {
    	char buf[32];
    	snprintf(buf,sizeof(buf),"%d.png",layer);
    	if(layer == 6){
    		mTextView25Ptr->setBackgroundPic("1.png");
    	}else{
    		mTextView25Ptr->setBackgroundPic(buf);
    	}

    }

	switch(layer){

	case 1:	mhomePtr->setVisible(true);
			mMain_ButtonPtr->setSelected(false);

			//打印界面没显示，也就是没在打印
			if(!mprintPtr->isVisible())
			{

				pos = mButton98Ptr->getPosition();
				pos.mLeft = start_print_button_x;
				mButton98Ptr->setPosition(pos);

				pos = mButton100Ptr->getPosition();
				pos.mLeft = start_print_button_x;
				mButton100Ptr->setPosition(pos);

				pos = mButton101Ptr->getPosition();
				pos.mLeft = start_print_button_x;
				mButton101Ptr->setPosition(pos);

				pos = mbed_temp_buttonPtr->getPosition();
				pos.mLeft = start_print_button_x;
				mbed_temp_buttonPtr->setPosition(pos);


				pos = mButton50Ptr->getPosition();
				pos.mLeft = start_print_button_x;
				mButton50Ptr->setPosition(pos);

				pos = mTextView7Ptr->getPosition();
				pos.mLeft = start_print_button_x;
				mTextView7Ptr->setPosition(pos);

				if(screen_size == 7)
				{
				    pos.mLeft = 785;
				    pos.mTop = 40;
				    pos.mWidth = 58;
				    pos.mHeight = 44;
				}
				mstop_ButtonPtr->setPosition(pos);

			}

		break;

	case 2:	mmovePtr->setVisible(true);
			mLayer2_ButtonPtr->setSelected(true);

		break;

	case 3:mfilePtr->setVisible(true);
			mFileListPtr->setVisible(true);
			mFile_ButtonPtr->setSelected(true);
		break;
	case 4:mPrint_Set_WinPtr->setVisible(true);
			mButton73Ptr->setSelected(true);
			break;
	case 5:mScreen_set_winPtr->setVisible(true);
			mScreen_set_ButtonPtr->setSelected(true);
			//WifiManager *pWM = WIFIMANAGER->getConnectionInfo();
			if(WIFIMANAGER->isConnected()){
					char buf[64];
					mTextView27Ptr->setText(WIFIMANAGER->getConnectionInfo()->getSsid());
					snprintf(buf,sizeof(buf),"IP:%s",WIFIMANAGER->getIp());
					mTextView28Ptr->setText(buf);
					snprintf(buf,sizeof(buf),"MAC:%s",WIFIMANAGER->getMacAddr());
					mTextView30Ptr->setText(buf);

			}
			 if(LANGUAGEMANAGER->getCurrentCode() == "zh_CN"){
				 mTextView24Ptr->setText("中文");
			 }
			 else if(LANGUAGEMANAGER->getCurrentCode() == "en_US"){
				 mTextView24Ptr->setText("English");
			 }
			 else if(LANGUAGEMANAGER->getCurrentCode() == "ja_JP"){
				 mTextView24Ptr->setText("Japanese");
			 }
			 mbrightnes_SeekBarPtr->setProgress(100-BRIGHTNESSHELPER->getBrightness()) ;



//sLOGD("%s",*pWM);

	break;

	case 6: mhomePtr->setVisible(true);
			mMain_ButtonPtr->setSelected(false);
			mprintPtr->setVisible(true);

			mFile_name_TextViewPtr->setText(current_file_information.filename.c_str());
			if(current_file_information.filename.size() > 25)
			{
				mFile_name_TextViewPtr->setLongMode(ZKTextView::E_LONG_MODE_SCROLL);
				LOGD("开启");
			}else{
				mFile_name_TextViewPtr->setLongMode(ZKTextView::E_LONG_MODE_DOTS);
				LOGD("关闭");
			}
//			mTextView1Ptr->setText(current_file_information.filename.c_str());
			string save_path = Save_Path + current_file_information.filename + ".png";
			mthumbnail_pngPtr->setBackgroundPic(save_path.c_str());


			pos = mButton98Ptr->getPosition();
			pos.mLeft = end_print_button_x;
			mButton98Ptr->setPosition(pos);

			pos = mButton100Ptr->getPosition();
			pos.mLeft = end_print_button_x;
			mButton100Ptr->setPosition(pos);

			pos = mButton101Ptr->getPosition();
			pos.mLeft = end_print_button_x;
			mButton101Ptr->setPosition(pos);

			pos = mbed_temp_buttonPtr->getPosition();
			pos.mLeft = end_print_button_x;
			mbed_temp_buttonPtr->setPosition(pos);


			pos = mButton50Ptr->getPosition();
			pos.mLeft = end_print_button_x;
			mButton50Ptr->setPosition(pos);

			pos = mTextView7Ptr->getPosition();
			pos.mLeft = end_print_button_x;
			mTextView7Ptr->setPosition(pos);


			//初始化打印界面的缩略图
			init_thumbnail();

			//同时初始化对象排除
			init_exclude_obj();


	}


}




static bool onButtonClick_Main_Button(ZKButton *pButton) {
	//layer_open = true;
	layer_ch(1);

   // pButton->setSelected(!pButton->isSelected());

    return false;
}

static bool onButtonClick_Layer2_Button(ZKButton *pButton) {
	layer_ch(2);

    //pButton->setSelected(!pButton->isSelected());

    return false;
}


static bool onButtonClick_Button6(ZKButton *pButton) {
	pButton->setSelected(!pButton->isSelected());
    return false;
}

static bool onButtonClick_Button59(ZKButton *pButton) {
	pButton->setSelected(!pButton->isSelected());
    return false;
}

static bool onButtonClick_Button75(ZKButton *pButton) {
	pButton->setSelected(!pButton->isSelected());
    return false;
}

static bool onButtonClick_Button76(ZKButton *pButton) {
	pButton->setSelected(!pButton->isSelected());
    return false;
}

static bool onButtonClick_Button77(ZKButton *pButton) {
	pButton->setSelected(!pButton->isSelected());
    return false;
}

static bool onButtonClick_Button79(ZKButton *pButton) {
	pButton->setSelected(!pButton->isSelected());
    return false;
}

static bool onButtonClick_Button81(ZKButton *pButton) {
	pButton->setSelected(!pButton->isSelected());
    return false;
}


static bool onButtonClick_Button98(ZKButton *pButton) {
  //  std::string sourceFilePath = "/mnt/usb1/image.png";
  //  std::string destinationFolderPath = "/data/image.png";

    // Assuming you want to keep the same file name in the destination folder
    //std::string destinationFilePath = destinationFolderPath + "image.png";

//    copyFile(sourceFilePath, destinationFolderPath);
//    mTextView6Ptr->setBackgroundPic("/data/image.png");

//
   // updata_perint_img("/mnt/usb1/image.png");


//    std::string filename = "/data/print.png"; // 替换为你要删除的文件名
//
//    if (std::remove(filename.c_str()) != 0) {
//    		LOGD("err");
//    } else {
//    	LOGD("ok");
//    }
//    filename = "/data/print_smail.png";
//    std::remove(filename.c_str());
//    sync();
//    reboot(RB_AUTOBOOT);

	if(pButton->isSelected()){
		gcode_send2("","SET_LED LED=LED WHITE=0");
		pButton->setSelected(false);
	}
	else
	{
		gcode_send2("","SET_LED LED=LED WHITE=1");
		pButton->setSelected(true);
	}

    return false;
}

static bool onButtonClick_Button100(ZKButton *pButton) {
	if(Ethernet_mode == true)
	{
		GET_WIFI_List.run("");
		mHost_computer_wifiPtr->setVisible(true);
	}else
	{
		EASYUICONTEXT->openActivity("WifiSettingActivity");
//		EASYUICONTEXT->openActivity("NetSettingActivity");
	}

//	EASYUICONTEXT->openActivity("NetSettingActivity");
    return false;
}


static bool onButtonClick_Button84(ZKButton *pButton) {
	//LOGD(" ButtonClick Button84 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}
static bool onButtonClick_Button85(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button85 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}
static bool onButtonClick_Button86(ZKButton *pButton) {
   // LOGD(" ButtonClick Button86 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button87(ZKButton *pButton) {
   // LOGD(" ButtonClick Button87 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button88(ZKButton *pButton) {
   // LOGD(" ButtonClick Button88 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button89(ZKButton *pButton) {
   // LOGD(" ButtonClick Button89 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}
static bool onButtonClick_Button90(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button90 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}
static bool onButtonClick_Button91(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button91 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}
static bool onButtonClick_Button92(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button92 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}
static bool onButtonClick_Button93(ZKButton *pButton) {
  //  LOGD(" ButtonClick Button93 !!!\n");
 	mAJPtr->hideWnd();
 	sContentStr.clear();
	mTextView22Ptr->setText(sContentStr);
    return false;
}
static bool onButtonClick_Button94(ZKButton *pButton) {
   // LOGD(" ButtonClick Button94 !!!\n");
	addOneChar(pButton->getText()[0]);
    return false;
}


void set_aj_layer()
{

	if(mAJPtr->isVisible() == true){
		mAJPtr->setVisible(false);
	}else{
		LayoutPosition pos;
		if(ui_modo == 1)
		{
			pos.mLeft = 396;
			pos.mTop = 83;
			pos.mWidth = 476;
			pos.mHeight = 473;
		}else{
			pos.mLeft = 390;
			pos.mTop = 90;
			pos.mWidth = 477;
			pos.mHeight = 480;
		}
		mAJPtr->setPosition(pos);
		mAJPtr->setVisible(true);
		mTextView22Ptr->setTextSize(35);
	}


}
static bool onButtonClick_Button50(ZKButton *pButton) {
	AJ_id = 2;
	set_aj_layer();
    return false;
}
static bool onButtonClick_Button101(ZKButton *pButton) {
	AJ_id = 0;
	set_aj_layer();

    return false;
}

static bool onButtonClick_AJ_confirm_Button(ZKButton *pButton) {


    // 设置目标URL
    std::string url ;//= "http://" + print_ip + "/printer/gcode/script?script=";
bool close_window = true;
char buf[64];

	switch(AJ_id){

	case 0:	{
		url = "M104 S"+ sContentStr;
		 gcode_send2("",url);

		break;
	}
	case 1:	{
		url = "M140 S"+ sContentStr;
		gcode_send2("",url);
		break;
	}
	case 2:	{
		url = "SET_HEATER_TEMPERATURE HEATER=warehouse TARGET="+ sContentStr;
		gcode_send2("",url);
		break;
	}

	case 3:	{
		//Pid_ext_temp
		Pid_ext_temp = sContentStr;
		StoragePreferences::putString(Pid_ext_temp, "Pid_ext_temp");
		snprintf(buf,sizeof(buf),"%s℃",Pid_ext_temp.c_str());
		mButton23Ptr->setText(buf);
		break;
	}

	case 4:	{
		//Pid_bed_temp
		Pid_bed_temp = sContentStr;
		StoragePreferences::putString(Pid_bed_temp, "Pid_bed_temp");
		snprintf(buf,sizeof(buf),"%s℃",Pid_bed_temp.c_str());
		mButton26Ptr->setText(buf);
		break;
	}

	case 10:	{

		snprintf(buf,sizeof(buf),"MMU_SERVO ANGLE=%s",sContentStr.c_str());
		gcode_send2("",buf);
		mERCF_SERVO_DOWN_ButtonPtr->setText(sContentStr.c_str());
		break;
	}
	case 11:	{

		snprintf(buf,sizeof(buf),"MMU_SERVO ANGLE=%s",sContentStr.c_str());
		gcode_send2("",buf);
		mERCF_SERVO_UP_ButtonPtr->setText(sContentStr.c_str());
		break;
	}
	case 12:	{

		snprintf(buf,sizeof(buf),"MMU_TEST_MOVE move=%s",sContentStr.c_str());
		gcode_send2("",buf);
		mERCF_EX_BUTTONPtr->setText(sContentStr.c_str());
		break;
	}

	case 13:	{
		gcode_send("MMU_HOME",false,false,false);
		snprintf(buf,sizeof(buf),"MMU_CALIBRATE_GEAR LENGTH=%s MEASURED=%s",mERCF_EX_BUTTONPtr->getText().c_str(),sContentStr.c_str());
		gcode_send2("",buf);
		mERCF_EX_TRUE_BUTTONPtr->setText(sContentStr.c_str());
		break;
	}
	case 14:	{

		snprintf(buf,sizeof(buf),"MMU_CALIBRATE_BOWDEN BOWDEN_LENGTH=%s",sContentStr.c_str());
		gcode_send2("",buf);
		mERCF_BOWDEN_CA_BUTTONPtr->setText(sContentStr.c_str());
		break;
	}

	case 20:
		snprintf(buf,sizeof(buf),"M220 S%s",sContentStr.c_str());
		gcode_send2("",buf);
		break;
	case 21:
		snprintf(buf,sizeof(buf),"M221 S%s",sContentStr.c_str());
		gcode_send2("",buf);
		break;
	case 22:
		snprintf(buf,sizeof(buf),"SET_PRESSURE_ADVANCE ADVANCE=%s",sContentStr.c_str());
		gcode_send2("",buf);
		break;
	case 23:
		snprintf(buf,sizeof(buf),"SET_PRESSURE_ADVANCE SMOOTH_TIME=%s",sContentStr.c_str());
		gcode_send2("",buf);
		break;
	case 24:
		snprintf(buf,sizeof(buf),"SET_VELOCITY_LIMIT VELOCITY=%s",sContentStr.c_str());
		gcode_send2("",buf);
		break;
	case 25:
		snprintf(buf,sizeof(buf),"SET_VELOCITY_LIMIT SQUARE_CORNER_VELOCITY=%s",sContentStr.c_str());
		gcode_send2("",buf);
		break;
	case 26:
		snprintf(buf,sizeof(buf),"SET_VELOCITY_LIMIT ACCEL=%s",sContentStr.c_str());
		gcode_send2("",buf);
		break;


	case 88:
		 StoragePreferences::putString("key", sContentStr);
		 break;
	case 89:{
			std::string Key = StoragePreferences::getString("key", "null");
			if(Key == sContentStr)
			{
				mlockPtr->setVisible(false);
			}else{
				mTextview50Ptr->setTextTr("Incorrect Password Entered");
		 		if(LANGUAGEMANAGER->getCurrentCode() == "zh_CN")
		 		{
		 			mTextView22Ptr->setTextSize(35);
		 		}else
		 		{
		 			mTextView22Ptr->setTextSize(26);
		 		}
			}
		}
		 break;
	case 90:{
		std::string Key = StoragePreferences::getString("key", "null");
		if(Key == sContentStr)
		{
			AJ_id = 88;
			close_window = false;
			mTextView22Ptr->setTextTr("Enter New Password");
			mTextView22Ptr->setTextSize(35);

		}else{
			AJ_id = 90;
			close_window = false;
			mTextView22Ptr->setTextTr("Password Verification Error");
	 		if(LANGUAGEMANAGER->getCurrentCode() == "zh_CN")
	 		{
	 			mTextView22Ptr->setTextSize(35);
	 		}else
	 		{
	 			mTextView22Ptr->setTextSize(26);
	 		}
		}
	}
		 break;
	case 888:{
		StoragePreferences::putString("print_ip", sContentStr);
		master_print_ip = sContentStr;
		mButton22Ptr->setText(master_print_ip);
		conn = nullptr;
		if (WS) {

			ws_closs = true;

		}
		}

		 break;
	case 889:{
//		LOGD("IP%s",sContentStr.c_str());
		string new_ip = "http://" + sContentStr;
		Print_info[cur_print_set_num].ip = new_ip;
		Save_all_print_info();
		mPrint_set_listPtr->setVisible(false);
		mPrint_ListView1Ptr->refreshListView();
		}
		break;
	case 890:{
//		LOGD("IP%s",sContentStr.c_str());
		Print_Info _info;
		string new_ip = "http://" + sContentStr;
		_info.ip = new_ip;
		Print_info.push_back(_info);
		Save_all_print_info();
		mPrint_set_listPtr->setVisible(false);
		mPrint_ListView1Ptr->refreshListView();
		}
		break;
}
    sContentStr.clear();

	if(ui_modo == 1){
		mTextView16Ptr->setVisible(false);
	}else{
		mTextView16Ptr->setBackgroundPic("layer2/wendu.png");
	}
    mlyayer2_nozzle_temp_buttonPtr->setSelected(false);
    mlyayer2_bed_temp_buttonPtr->setSelected(false);
    mButton103Ptr->setSelected(false);
    mlayer2_speed_buttonPtr->setSelected(false);
    mFan_layer_open_buttonPtr->setSelected(false);
    //设置新密码时的二次验证
	if(close_window == true)
	{
		mTextView22Ptr->setText("");
		mAJPtr->setVisible(false);
	}
    return false;
}

static bool onButtonClick_Button96(ZKButton *pButton) {
	delOneChar();
    return false;
}

//将\\n替换成%0A(http才用得到)
std::string replace_newline(const std::string& input) {
    std::string output = input;
    size_t pos = 0;
    while ((pos = output.find("\\n", pos)) != std::string::npos) {
        output.replace(pos, 2, "\n");
        pos += 3; // 跳过 "%0A"
    }
    return output;
}

//将\\n替换成%0A(http才用得到)
std::string replace_dots_with_slashes(const std::string& input) {
    std::string output = input;
    size_t pos = 0;
    while ((pos = output.find('.', pos)) != std::string::npos) {
        output.replace(pos, 1, "/");
        pos += 1; // Move past the replaced character
    }
    return output;
}

std::string extract_value(const std::string& json, const std::string& key) {
    std::string search_key = "\"" + key + "\":";
    size_t start = json.find(search_key);
    if (start == std::string::npos) return "";

    start += search_key.length();
    size_t end = json.find_first_of(",}", start);

    // 查找嵌套的对象或数组
    if (json[start] == '{' || json[start] == '[') {
        char open_char = json[start];
        char close_char = (open_char == '{') ? '}' : ']';
        int balance = 1;
        end = start + 1;
        while (balance > 0 && end < json.length()) {
            if (json[end] == open_char) balance++;
            if (json[end] == close_char) balance--;
            end++;
        }
    }

    // 去掉两端的引号和空格
    std::string value = json.substr(start, end - start);
    if (value.front() == '"') value.erase(0, 1);
    if (value.back() == '"') value.pop_back();

    return value;
}

void gcode_send2(std::string method,std::string params){
	std::string sends;
	if(mHTTP_WS_BUTTONPtr->isSelected() == false){
		New_Sw_id();
		if(Calibration_sw == true && strstr(params.c_str(),".is_ca")){
			params.erase(params.length() - 6);
			Cur_Calibration_id = sw_id;
		}


		if(method.empty() || method == "printer.gcode.script")//默认情况下gcode
		{
			gcodes_message.push_back("$ "+ params) ;//控制台显示出来
			//这个是将命令加入到从机命令集合
			if(strstr(params.c_str(),"\\n")){
				Commad +=  replace_newline(params);
			}else{
				Commad += params;
			}

			if (!params.empty() && params.back() != '\n') {
				Commad += "\n";
			}

			sends = "{\"jsonrpc\": \"2.0\",\"method\": \"printer.gcode.script\",\"params\": {\"script\":\"" + params+ "\"},\"id\":" + sw_id + "}";
		}else if(params.empty()){
			sends = "{\"jsonrpc\": \"2.0\",\"method\": \"" + method + "\",\"id\":" + sw_id + "}";
		}else{
			sends = "{\"jsonrpc\": \"2.0\",\"method\": \"" + method + "\",\"params\": {" + params+ "},\"id\":" + sw_id + "}";
		}



		if(WS)
		{
			WS->send(sends);
		}else
		{
	    	Notify_message_list.push_back("Please connect the print");
	    	notify_open_close(true);
		}

	}else{//HTTP
		//将.改成/
		method = replace_dots_with_slashes(method);
		//将\\n改成,\n   再编码成%0A
		if(strstr(params.c_str(),"\\n")){
			params = replace_newline(params);
			params = encode_url2(params);
		}


		//组合成HTTP格式
		if(method.empty() || method == "printer/gcode/script")//默认情况下gcode
		{
			gcodes_message.push_back("$ "+ params) ;//控制台显示出来
			mListView5Ptr->refreshListView();
			//这个是将命令加入到从机命令集合
			Commad += params;
			if (!params.empty() && params.back() != '\n') {
				Commad += "\n";
			}

			sends = "/printer/gcode/script?script="+ params;
		}else if(params.empty()){
			sends = "/" + method;
		}else{
			sends = "/" + method + params ;
		}

		//检测HTTP是否连接
		if(HTTP_is_Connection)
		{
			sends += "\n";//加上结束符，进行区分
			HTTP_data_request += sends;//添加到集合里，temp线程执行发送请求。因为在这里执行会卡顿ui线程
		}else
		{
	    	Notify_message_list.push_back("Please connect the print");
	    	notify_open_close(true);
		}

		LOGD("godes:%s",encode_url(sends).c_str());
//		RestClient::Response r = conn.post(encode_url(sends),"");
//		LOGD("POST:%s",r.body.c_str());


	}





}
void gcode_send(std::string godes,bool move,bool is_Calibration,bool is_Send_directly){

	New_Sw_id();
	if(is_Calibration){
		Cur_Calibration_id = sw_id;
	}

	//LOGD("ID:%s",sw_id.c_str());
	if(move == true){
		gcodes_message.push_back("$ "+ godes) ;

		Commad += "G91\n";
		Commad += godes.substr(0, godes.length() - 2);
		Commad += "\nG90\n";
		godes = "{\"jsonrpc\": \"2.0\",\"method\": \"printer.gcode.script\",\"params\": { \"script\":\"G91\\n"+ godes + "G90\"},\"id\":" + sw_id + "}";
	}else if(is_Send_directly){
		//不做任何处理

	}else{
		gcodes_message.push_back("$ "+ godes) ;
		Commad += godes;
		Commad += "\n";
		godes = "{\"jsonrpc\": \"2.0\",\"method\": \"printer.gcode.script\",\"params\": { \"script\":\""+ godes + "\"},\"id\":" + sw_id + "}";
	}
	LOGD("godes2:%s",godes.c_str());
	if(WS)
	{
//		LOGD("godesfas");
		WS->send(godes);
	}else
	{
    	Notify_message_list.push_back("Please connect the print");
    	notify_open_close(true);
	}

}
static bool onButtonClick_Y_D1_BUTTON(ZKButton *pButton) {
	std::string params;
	if(mForc_ButtonPtr->isSelected()){
		params = "SET_KINEMATIC_POSITION Y=1";
		gcode_send2("",params);
	}

		params = "G91\\nG1 Y-1 F3500\\nG90";
		gcode_send2("",params);
    return false;
}

static bool onButtonClick_Y_D10_BUTTON(ZKButton *pButton) {
	std::string params;
	if(mForc_ButtonPtr->isSelected()){
		params = "SET_KINEMATIC_POSITION Y=10";
		gcode_send2("",params);
	}

		params = "G91\\nG1 Y-10 F3500\\nG90";
		gcode_send2("",params);
    return false;
}

static bool onButtonClick_Y_U10_BUTTON(ZKButton *pButton) {
	std::string params;
	if(mForc_ButtonPtr->isSelected()){
		params = "SET_KINEMATIC_POSITION Y=0";
		gcode_send2("",params);
	}

		params = "G91\\nG1 Y10 F3500\\nG90";
		gcode_send2("",params);
    return false;
}

static bool onButtonClick_X_U10_BUTTON(ZKButton *pButton) {
	std::string params;
	if(mForc_ButtonPtr->isSelected()){
		params = "SET_KINEMATIC_POSITION X=0";
		gcode_send2("",params);
	}

		params = "G91\\nG1 X10 F3500\\nG90";
		gcode_send2("",params);
    return false;
}

static bool onButtonClick_X_D10_BUTTON(ZKButton *pButton) {
	std::string params;
	if(mForc_ButtonPtr->isSelected()){
		params = "SET_KINEMATIC_POSITION X=10";
		gcode_send2("",params);
	}

		params = "G91\\nG1 X-10 F3500\\nG90";
		gcode_send2("",params);
    return false;
}
static bool onButtonClick_FAN1_SW_Button(ZKButton *pButton) {


	if(pButton->isSelected()){
		pButton->setSelected(false);
		gcode_send2("","M106 S0");
		pButton->setTextTr("off");
	}else
	{
		pButton->setSelected(true);
		Fan0_Speed = 100;
		gcode_send2("","M106 S255");

		pButton->setTextTr("on");

	}
    return false;
}

static bool onButtonClick_FAN2_SW_Button(ZKButton *pButton) {

	if(pButton->isSelected()){
		pButton->setSelected(false);
		gcode_send2("","SET_FAN_SPEED FAN="+fan1_name+" SPEED=0.0");
		pButton->setTextTr("off");
	}else
	{
		pButton->setSelected(true);
		Fan1_Speed = 100;
		gcode_send2("","SET_FAN_SPEED FAN="+fan1_name+" SPEED=1.0");
		pButton->setTextTr("on");

	}
    return false;
}

static bool onButtonClick_FAN3_SW_Button(ZKButton *pButton) {

	if(pButton->isSelected()){
		pButton->setSelected(false);
		gcode_send2("","SET_FAN_SPEED FAN="+fan2_name+" SPEED=0.0");
		pButton->setTextTr("off");
	}else
	{
		pButton->setSelected(true);
		Fan2_Speed = 100;
		gcode_send2("","SET_FAN_SPEED FAN="+fan2_name+" SPEED=1.0");
		pButton->setTextTr("on");

	}
    return false;
}

static bool onButtonClick_FAN1_ICON(ZKButton *pButton) {

    return false;
}

static bool onButtonClick_FAN2_ICON(ZKButton *pButton) {
	mAJ1Ptr->setVisible(true);
	sContentStr.clear();
	mTextView46Ptr->setText("");
	AJ_id = 10;
    return false;
}

static bool onButtonClick_FAN3_ICON(ZKButton *pButton) {
	mAJ1Ptr->setVisible(true);
	sContentStr.clear();
	mTextView46Ptr->setText("");
	AJ_id = 11;
    return false;
}

static bool onButtonClick_FAN1_UP(ZKButton *pButton) {

	Fan0_Speed += 26;
   if(Fan0_Speed >= 100)
	   Fan0_Speed = 100;

   std::string url ;

	char buf[32];
		snprintf(buf,sizeof(buf),"M106 S%d",static_cast<int>(rint(Fan0_Speed * 255 / 100)));
		gcode_send2("",buf);
    return false;
}

static bool onButtonClick_FAN1_DOWN(ZKButton *pButton) {

	Fan0_Speed -= 25;
   if(Fan0_Speed <= 0)
	   Fan0_Speed = 0;

	char buf[32];
		snprintf(buf,sizeof(buf),"M106 S%d",static_cast<int>(rint((Fan0_Speed + 1 )* 255 / 100)));
		gcode_send2("",buf);
    return false;
}

static bool onButtonClick_FAN2_UP(ZKButton *pButton) {
	Fan1_Speed += 25;
   if(Fan1_Speed >= 100)
	   Fan1_Speed = 100;

	char buf[32];
	snprintf(buf,sizeof(buf),"SET_FAN_SPEED FAN=%s SPEED=%0.1f",fan1_name.c_str(),(double)Fan1_Speed  / 100);
	gcode_send2("",buf);
    return false;
}

static bool onButtonClick_FAN2_DOWN(ZKButton *pButton) {
	Fan1_Speed -= 25;
   if(Fan1_Speed <= 0)
	   Fan1_Speed = 0;

	char buf[32];
	snprintf(buf,sizeof(buf),"SET_FAN_SPEED FAN=%s SPEED=%0.1f",fan1_name.c_str(),(double)Fan1_Speed  / 100);
	gcode_send2("",buf);
    return false;
}

static bool onButtonClick_FAN3_UP(ZKButton *pButton) {
	Fan2_Speed += 25;
   if(Fan2_Speed >= 100)
	   Fan2_Speed = 100;

   std::string url ;

	char buf[32];
	snprintf(buf,sizeof(buf),"SET_FAN_SPEED FAN=%s SPEED=%0.1f",fan2_name.c_str(),(double)Fan2_Speed  / 100);
	gcode_send2("",buf);
    return false;
}

static bool onButtonClick_FAN3_DOWN(ZKButton *pButton) {
	Fan2_Speed -= 25;
   if(Fan2_Speed <= 0)
	   Fan2_Speed = 0;

   std::string url ;
	char buf[32];
	snprintf(buf,sizeof(buf),"SET_FAN_SPEED FAN=%s SPEED=%0.1f",fan2_name.c_str(),(double)Fan2_Speed  / 100);
	gcode_send2("",buf);
    return false;
}


static bool onButtonClick_hc_hg_Button(ZKButton *pButton) {
    LOGD(" ButtonClick hc_hg_Button !!!\n");
    return false;
}
void tool_layer_ch(int layer)
{
	mwhmovePtr->setVisible(false);
	mtoolPtr->setVisible(false);
//	mtempPtr->setVisible(false);
//	mprintPtr->setVisible(false);
//	mmorePtr->setVisible(false);
//
    mtemp_move_ButtonPtr->setSelected(false);
    mTool_ButtonPtr->setSelected(false);
//    mButton72Ptr->setSelected(false);
//    mButton73Ptr->setSelected(false);
//    mButton74Ptr->setSelected(false);


	switch(layer){

	case 1:mwhmovePtr->setVisible(true);					break;
	case 2:mtoolPtr->setVisible(true);           		     break;
//	case 3:mprintPtr->setVisible(true);               break;
	//case 4:mWHPtr->setVisible(true);                 break;
	//case 5:mmorePtr->setVisible(true);              break;

	}


}
static bool onButtonClick_Tool_Button(ZKButton *pButton) {
	tool_layer_ch(2);
	pButton->setSelected(!pButton->isSelected());
    return false;
}

static bool onButtonClick_temp_move_Button(ZKButton *pButton) {
	tool_layer_ch(1);
	pButton->setSelected(!pButton->isSelected());
    return false;
}
static bool onButtonClick_JZ_Button(ZKButton *pButton) {
	mjz_WindowPtr->setVisible(true);
    return false;
}
static bool onButtonClick_jz_win_close_button(ZKButton *pButton) {
	mjz_WindowPtr->setVisible(false);
    return false;
}

static bool onButtonClick_Button73(ZKButton *pButton) {
	layer_ch(4);

    return false;
}

static bool onButtonClick_Screen_set_Button(ZKButton *pButton) {
	layer_ch(5);
    return false;
}



static bool onButtonClick_Button55(ZKButton *pButton) {
	std::string params;
	if(mButton_moto_reversPtr->isSelected()){
		if(mForc_ButtonPtr->isSelected()){
			params = "SET_KINEMATIC_POSITION Z=10";
			gcode_send2("",params);
		}
			params = "G91\\nG1 Z-10 F3500\\nG90";
			gcode_send2("",params);
	}else
	{
		if(mForc_ButtonPtr->isSelected()){
			params = "SET_KINEMATIC_POSITION Z=0";
			gcode_send2("",params);
		}
			params = "G91\\nG1 Z10 F3500\\nG90";
			gcode_send2("",params);
	}

    return false;
}

static bool onButtonClick_Button2(ZKButton *pButton) {
	std::string params;
	if(mButton_moto_reversPtr->isSelected()){
		if(mForc_ButtonPtr->isSelected()){
			params = "SET_KINEMATIC_POSITION Z=0";
			gcode_send2("",params);
		}
			params = "G91\\nG1 Z10 F3500\\nG90";
			gcode_send2("",params);
	}else
	{
		if(mForc_ButtonPtr->isSelected()){
			params = "SET_KINEMATIC_POSITION Z=10";
			gcode_send2("",params);
		}
			params = "G91\\nG1 Z-10 F3500\\nG90";
			gcode_send2("",params);
	}

    return false;
}

static bool onButtonClick_Button56(ZKButton *pButton) {

	std::string params;
	if(mButton_moto_reversPtr->isSelected()){
		if(mForc_ButtonPtr->isSelected()){
			params = "SET_KINEMATIC_POSITION Z=0";
			gcode_send2("",params);
		}
			params = "G91\\nG1 Z1 F3500\\nG90";
			gcode_send2("",params);
	}else
	{
		if(mForc_ButtonPtr->isSelected()){
			params = "SET_KINEMATIC_POSITION Z=1";
			gcode_send2("",params);
		}
			params = "G91\\nG1 Z-1 F3500\\nG90";
			gcode_send2("",params);
	}


    return false;
}



static bool onButtonClick_Button66(ZKButton *pButton) {
    LOGD(" ButtonClick Button66 !!!\n");
    return false;
}

static bool onButtonClick_Button_home(ZKButton *pButton) {
    // 设置目标URL
	gcode_send2("","G28");
    return false;
}

static bool onButtonClick_Button68(ZKButton *pButton) {
	if(mForc_ButtonPtr->isSelected()){
		gcode_send2("","SET_KINEMATIC_POSITION E=10");
	}
	gcode_send2("","G91\\nG1 E-10 F300\\nG90");
    return false;
}

static bool onButtonClick_Button1(ZKButton *pButton) {
	if(mForc_ButtonPtr->isSelected()){
		gcode_send2("","SET_KINEMATIC_POSITION E=0");
	}
	gcode_send2("","G91\\nG1 E10 F300\\nG90");
    return false;
}

static bool onButtonClick_Button5(ZKButton *pButton) {
	mExclude_Object_windowPtr->setVisible(false);
    return false;
}

static bool onButtonClick_Button3(ZKButton *pButton) {
	std::string params;
	if(mButton_moto_reversPtr->isSelected()){
		if(mForc_ButtonPtr->isSelected()){
			params = "SET_KINEMATIC_POSITION Z=1";
			gcode_send2("",params);
		}
			params = "G91\\nG1 Z-1 F3500\\nG90";
			gcode_send2("",params);
	}else
	{
		if(mForc_ButtonPtr->isSelected()){
			params = "SET_KINEMATIC_POSITION Z=0";
			gcode_send2("",params);
		}
			params = "G91\\nG1 Z1 F3500\\nG90";
			gcode_send2("",params);
	}


    return false;
}

static bool onButtonClick_X_U1_BUTTON(ZKButton *pButton) {
	if(mForc_ButtonPtr->isSelected()){
		gcode_send2("","SET_KINEMATIC_POSITION X=0");
	}
	gcode_send2("","G91\\nG1 X1 F3500\\nG90");
    return false;
}

static bool onButtonClick_X_D1_BUTTON(ZKButton *pButton) {
	if(mForc_ButtonPtr->isSelected()){
		gcode_send2("","SET_KINEMATIC_POSITION X=1");
	}
	gcode_send2("","G91\\nG1 X-1 F3500\\nG90");
    return false;
}

static bool onButtonClick_Y_U1_BUTTON(ZKButton *pButton) {
	if(mForc_ButtonPtr->isSelected()){
		gcode_send2("","SET_KINEMATIC_POSITION Y=0");
	}
	gcode_send2("","G91\\nG1 Y1 F3500\\nG90");

    return false;
}

static bool onButtonClick_Button82(ZKButton *pButton) {
    LOGD(" ButtonClick Button82 !!!\n");
    return false;
}


static int getListItemCount_FileList(const ZKListView *pListView) {
    //LOGD("getListItemCount_FileList !\n");
	//上位机文件
	if(mms_file_buttonPtr->isSelected())
	{
		return (int)File_Gcodes.size() + (int)file_dir.size();
	}else//屏幕文件
	{
		return (int)fileInfos.size();
	}

}

static void obtainListItemData_FileList(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ FileList  !!!\n");

	   static const char* backgroundPics[] = {	"home.png", "up.png", "layer3/folder.png", "file.png", "file.png"};
	   ZKListView::ZKListSubItem* icon = pListItem->findSubItemByID(ID_GCODE_FileList_icon);
//	   static FileType savedFileType = E_FILETYE_MAX;
	 //上位机文件
	if(mms_file_buttonPtr->isSelected())
	{	//如果有文件夹
		if((int)file_dir.size() > 0)
		{
			//先设置文件夹
			if(index < (int)file_dir.size()   )
			{
				pListItem->setText(file_dir[index]);
				//我们将第一个设置为返回上一层的按钮
				if((int)cur_file_dir.size() > 0 && index == 0)
				{
					icon->setBackgroundPic("layer3/back.png");
				}else{

					icon->setBackgroundPic("folder.png");
				}

			}
			else
			{
				//设置文件名
				pListItem->setText(File_Gcodes[index - (int)file_dir.size()].path);
				//设置缩略图
				if( !File_Gcodes[index - (int)file_dir.size() ].thumbnail_path_smail.empty() )
				{

					string save_path = Save_Path + File_Gcodes[index - (int)file_dir.size()].path + ".png";
					//LOGD("save_path:%s",save_path.c_str());
					  icon->setBackgroundPic(save_path.c_str());
				}else{
					icon->setBackgroundPic("file.png");
				}
			}
		}else{
			//设置文件名
			pListItem->setText(File_Gcodes[index].path);
			//设置缩略图
			if( !File_Gcodes[index].thumbnail_path_smail.empty() )
			{

				string save_path = Save_Path + File_Gcodes[index].path + ".png";
				//LOGD("save_path:%s",save_path.c_str());
				  icon->setBackgroundPic(save_path.c_str());
			}else{
				icon->setBackgroundPic("file.png");
			}
		}




	}else{
			//屏幕文件
	     	 FileInfo fi = fileInfos[index];

	     		//LOGD("type:%d",fi.fileType);
//	    	     if(fi.fileType != savedFileType)
//	    	     {
//	    	    	 LOGD("type:%d",fi.fileType);
//
//	    	    	 //savedFileType = fi.fileType;
//
//	    	     }
	    	     icon->setBackgroundPic(backgroundPics[fi.fileType]);//设置背景图
	    	     pListItem->setText(fi.fileName);//设置文件名字





//	   	    ZKListView::ZKListSubItem* inf = pListItem->findSubItemByID(ID_GCODE_fly3dicon);
//	   	    if(strstr(fi.fileName.c_str(), "fly3d") != NULL)
//	   	     {
//	   		  setflyImage(inf, currentDirectory + "/" + fi.fileName, true);
//	   	     }
//	   	     else
//	   		 inf->setBackgroundPic("");

		}


}




static void onListItemClick_FileList(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ FileList  !!!\n");
	mTextView9Ptr->setBackgroundPic("");
	char buf[64];
	//显示同步文件按钮
	if(Slave_Print_ip.size() > 0)
	{
		Sync_file_name = File_Gcodes[index - (int)file_dir.size() ].path;
		mUpdata_SlavePtr->setVisible(true);
		mUpdata_Slave_printingPtr->setVisible(true);
	}else{
		mUpdata_SlavePtr->setVisible(false);
		mUpdata_Slave_printingPtr->setVisible(false);
	}
	 //上位机文件
	if(mms_file_buttonPtr->isSelected())
	{
		mButton_PreheatPtr->setVisible(true);
		mButton_DelPtr->setVisible(true);

			//如果点击的是文件夹
			if(index < (int)file_dir.size()   )
			{
				//我们将第一个设置为返回上一层的按钮
				if((int)cur_file_dir.size() > 0 && index == 0)
				{
					size_t last_slash_pos = cur_file_dir.find_last_of("/\\"); // 搜索最后的'/'或'\'
					if (last_slash_pos != std::string::npos) { // 如果找到了
					    cur_file_dir.erase(last_slash_pos); // 删除从该位置到末尾的所有内容
					}
					get_file(cur_file_dir);
				}else{
					//记录进入了哪个文件夹
					cur_file_dir += "/";
					cur_file_dir += file_dir[index];
					get_file(cur_file_dir);
				}

			}else{//点击了文件

				index = index - (int)file_dir.size();
				mFileListPtr->setVisible(false);
				mprint_surePtr->setVisible(true);
				snprintf(buf,sizeof(buf),"%dh%dm",File_Gcodes[index].estimated_time/3600,(File_Gcodes[index].estimated_time%3600)/60);
				mTextView10Ptr->setText(buf);
				snprintf(buf,sizeof(buf),"%0.3fg",File_Gcodes[index].filament_total*2.404*0.00125);
				mTextView11Ptr->setText(buf);


				mTextView2Ptr->setText(File_Gcodes[index].path);
				current_file_information.filename = File_Gcodes[index].path;
				LOGD("NAME:%s",current_file_information.filename.c_str());
				//记录当前选择了哪个文件，预热时要用
				cur_selected_file_index = index;

				if( !File_Gcodes[index].thumbnail_path_smail.empty() )
				{
					//因为下载清晰的缩略图比较费时间，先设置下分辨率较低的缩略图。
					string save_path = Save_Path + File_Gcodes[index].path + ".png";
					mTextView9Ptr->setBackgroundPic(save_path.c_str());
					//这个会在线程里自动下载文件图片并显示
					Download_thumbnail = true ;

				}else{
					mTextView9Ptr->setBackgroundPic("");
				}

				//如果机器在打印状态或者暂停状态，就不显示打印文件按钮
				if(!(current_file_information.state  == "paused") && !(current_file_information.state  == "printing")){

					mButton7Ptr->setVisible(true);
				}else
				{
					mButton7Ptr->setVisible(false);
				}


			}


		//sd卡或者u盘文件
	}else{
		//关闭预热按钮
		mButton_PreheatPtr->setVisible(false);
		mButton_DelPtr->setVisible(false);
		FileInfo fi = fileInfos[index];
	 	switch (fi.fileType) {
	 	//case E_FILETYPE_HOME:
	 	//	pListView->setVisible(false);
	 	//	mMainMenuPtr->setVisible(true);
	 	//	break;

	 //	case E_FILETYPE_BACK:
	 //		listFiles(currentDirectory, "..");
	 //		break;

	 	case E_FILETYPE_FOLDER:
	 		listFiles(currentDirectory, fi.fileName,false);
	 		break;

	 	case E_FILETYPE_FILE:
	 	//	pListView->setVisible(false);

	 		mprint_surePtr->setVisible(true);
	 		mTextView2Ptr->setText(fi.fileName);
	 		mTextView10Ptr->setText("null");
	 		mTextView11Ptr->setText("null");
	 		mTextView9Ptr->setBackgroundPic("");
	 		fileName = currentDirectory + "/" + fi.fileName;
	 		LOGD("wj:%s",fileName.c_str());


	 		break;

	 	default:
	 		break;
	 	}





	}
}

static bool onButtonClick_Button4(ZKButton *pButton) {
	mFileListPtr->setVisible(true);
	mprint_surePtr->setVisible(false);
    return false;
}

static bool onButtonClick_Button7(ZKButton *pButton) {


		 //上位机文件
		if(mms_file_buttonPtr->isSelected())
		{
			New_Sw_id();
			string path;

			//如果没有进入子文件夹
			if(!cur_file_dir.empty())
			{
				path = cur_file_dir.substr(1, cur_file_dir.size() -1);//移除第一个/
				path += "/";
			}

			if(mHTTP_WS_BUTTONPtr->isSelected() == false){
				gcode_send2("printer.print.start", "\"filename\":\"" + path + File_Gcodes[cur_selected_file_index].path + "\"");

			}else{

				gcode_send2("printer.print.start?","filename=" + path + File_Gcodes[cur_selected_file_index].path);
			}

		}else{
			upload_progress = 0;
			up_file_and_print = true;
			up_sd_file_thread.run();

		}


    return false;
}

static bool onButtonClick_ButtonjpL(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonjpL !!!\n");
    return false;
}

static bool onButtonClick_Buttonjpd(ZKButton *pButton) {
    LOGD(" ButtonClick Buttonjpd !!!\n");
    return false;
}

static bool onButtonClick_Button36(ZKButton *pButton) {
	mrestart_layerPtr->setVisible(false);
    return false;
}
static bool onButtonClick_File_Button(ZKButton *pButton) {
	layer_ch(3);
    //mFileListPtr->refreshListView();

    return false;
}
void temp_layer_ch(int layer){

	if(ui_modo == 1){
		//拟态UI设置背景显示
		mTextView16Ptr->setVisible(true);
		LayoutPosition pos(40, 78, 718, 493);
		mTextView16Ptr->setPosition(pos);
	}


	mlyayer2_nozzle_temp_buttonPtr->setSelected(false);
	mlyayer2_bed_temp_buttonPtr->setSelected(false);
	mButton103Ptr->setSelected(false);
	mlayer2_speed_buttonPtr->setSelected(false);
	mFan_layer_open_buttonPtr->setSelected(false);

	mprint_speed_WindowPtr->setVisible(false);
	mFAN_WindowPtr->setVisible(false);

	char buf[32];
	snprintf(buf, sizeof(buf), "%d%%", speed_factor);
	mlayer2_speed_buttonPtr->setText(buf);

	switch(layer){

	case 0:	mlyayer2_nozzle_temp_buttonPtr->setSelected(true);
			mTextView16Ptr->setBackgroundPic("layer2/wendu_on1.png");


			break;
	case 1:	mlyayer2_bed_temp_buttonPtr->setSelected(true);
			mTextView16Ptr->setBackgroundPic("layer2/wendu_on2.png");

			break;
	case 2:	mButton103Ptr->setSelected(true);

			mTextView16Ptr->setBackgroundPic("layer2/wendu_on3.png");
			break;
	case 3:	mlayer2_speed_buttonPtr->setSelected(true);
			if(speed_factor <= 75){
				mlayer2_speed_buttonPtr->setTextTr("Quiet");
			}else if (speed_factor <= 100){

				mlayer2_speed_buttonPtr->setTextTr("Normal");
			}else if (speed_factor <= 150){

				mlayer2_speed_buttonPtr->setTextTr("Sport");
			}else if (speed_factor >= 200){

				mlayer2_speed_buttonPtr->setTextTr("Berserk");
			}


			mprint_speed_WindowPtr->setVisible(true);
			mTextView16Ptr->setBackgroundPic("layer2/wendu_on4.png");
		break;
	case 4:	mFan_layer_open_buttonPtr->setSelected(true);
			mFAN_WindowPtr->setVisible(true);
			mTextView16Ptr->setBackgroundPic("layer2/wendu_on5.png");
			if(ui_modo == 1){
				LayoutPosition pos(40, 78, 839, 497);
				mTextView16Ptr->setPosition(pos);
			}



		break;

	}

}
static bool onButtonClick_bed_temp_button(ZKButton *pButton) {

		set_aj_layer();
		AJ_id = 1;

    return false;
}
static bool onButtonClick_lyayer2_nozzle_temp_button(ZKButton *pButton) {


	if(pButton->isSelected()){
		mAJPtr->setVisible(false);
		pButton->setSelected(false);
		if(ui_modo == 1){
			mTextView16Ptr->setVisible(false);
		}else{
			mTextView16Ptr->setBackgroundPic("layer2/wendu.png");
		}
	}
	else
	{
		temp_layer_ch(0);
		set_aj_layer();
		AJ_id = 0;
	}

    return false;
}

static bool onButtonClick_lyayer2_bed_temp_button(ZKButton *pButton) {
	if(pButton->isSelected())
	{
		if(ui_modo == 1){
			mTextView16Ptr->setVisible(false);
		}else{
			mTextView16Ptr->setBackgroundPic("layer2/wendu.png");
		}
		mAJPtr->setVisible(false);
		pButton->setSelected(false);

	}else
	{

		temp_layer_ch(1);
		set_aj_layer();
		AJ_id = 1;
	}
    return false;
}
static bool onButtonClick_Button103(ZKButton *pButton) {
	if(pButton->isSelected()){
		if(ui_modo == 1){
			mTextView16Ptr->setVisible(false);
		}else{
			mTextView16Ptr->setBackgroundPic("layer2/wendu.png");
		}
		mAJPtr->setVisible(false);
		pButton->setSelected(false);

	}else
	{
		temp_layer_ch(2);
		set_aj_layer();
		AJ_id = 2;
	}
    return false;
}
static bool onButtonClick_layer2_speed_button(ZKButton *pButton) {

	if(pButton->isSelected()){
		mprint_speed_WindowPtr->setVisible(false);
		pButton->setSelected(false);
		char buf[32];
		snprintf(buf, sizeof(buf), "%d%%", speed_factor);
		mlayer2_speed_buttonPtr->setText(buf);
		if(ui_modo == 1){
			mTextView16Ptr->setVisible(false);
		}else{
			mTextView16Ptr->setBackgroundPic("layer2/wendu.png");
		}
	}else{

		temp_layer_ch(3);
	}

    return false;
}

static bool onButtonClick_Fan_layer_open_button(ZKButton *pButton) {

	if(pButton->isSelected()){
		mFAN_WindowPtr->setVisible(false);
		pButton->setSelected(false);
		if(ui_modo == 1){
			mTextView16Ptr->setVisible(false);
		}else{
			mTextView16Ptr->setBackgroundPic("layer2/wendu.png");
		}
	}
	else
	{
		temp_layer_ch(4);
	}

    return false;
}

void speed_button_ch(int num){

	mButton8Ptr->setSelected(false);
	mButton9Ptr->setSelected(true);
	mButton10Ptr->setSelected(false);
	mButton11Ptr->setSelected(false);
	switch(num){

	case 0:	mButton8Ptr->setSelected(true);
			gcode_send2("","M220 S75");
			mlayer2_speed_buttonPtr->setTextTr("Quiet");

	break;

	case 1:	mButton9Ptr->setSelected(false);
			gcode_send2("","M220 S100");
			mlayer2_speed_buttonPtr->setTextTr("Normal");

	break;

	case 2:	mButton10Ptr->setSelected(true);
			gcode_send2("","M220 S150");
			mlayer2_speed_buttonPtr->setTextTr("Sport");

	break;

	case 3:	mButton11Ptr->setSelected(true);
			gcode_send2("","M220 S200");
			mlayer2_speed_buttonPtr->setTextTr("Berserk");

	break;

	}

}

static bool onButtonClick_Button8(ZKButton *pButton) {
	speed_button_ch(0);
    return false;
}

static bool onButtonClick_Button9(ZKButton *pButton) {
	speed_button_ch(1);
    return false;
}

static bool onButtonClick_Button10(ZKButton *pButton) {
	speed_button_ch(2);
    return false;
}

static bool onButtonClick_Button11(ZKButton *pButton) {
	speed_button_ch(3);
    return false;
}
static bool onButtonClick_File_Refresh_button(ZKButton *pButton) {
	cur_file_dir.clear();
	file_dir.clear();
	get_file("");
    return false;
}
static void onProgressChanged_Print_SeekBar(ZKSeekBar *pSeekBar, int progress) {
    //LOGD(" ProgressChanged Print_SeekBar %d !!!\n", progress);
}

static bool onButtonClick_Skip_it_Button(ZKButton *pButton) {
	mExclude_Object_windowPtr->setVisible(true);
    return false;
}

static bool onButtonClick_Pause_Button(ZKButton *pButton) {
	print_pause_state = true;
		// 发起POST请求
       pButton->setSelected(!pButton->isSelected());


		if(pButton->isSelected()){
			gcode_send2("printer.print.pause","");
		}else
		{
			gcode_send2("printer.print.resume","");
		}




    return false;
}

static bool onButtonClick_Stop_Button(ZKButton *pButton) {
		mTextView18Ptr->setTextTr("Confirm to cancel printing?");
		yes_no_id = 0;
		myes_no_WindowPtr->setVisible(true);

		return false;
}
static bool onButtonClick_obj_B0(ZKButton *pButton) {

	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 0;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B1(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 1;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B2(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 2;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B3(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 3;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B4(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 4;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B5(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 5;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B6(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 6;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B7(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 7;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B8(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 8;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B9(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 9;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B10(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 10;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B11(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 11;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B12(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 12;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B13(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 13;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B14(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 14;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B15(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id =15;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B16(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 16;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B17(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 17;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B18(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 18;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B19(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 19;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B20(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 20;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B21(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 21;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B22(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 22;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B23(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 23;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B24(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 24;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B25(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 25;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B26(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 26;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B27(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 27;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B28(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 28;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B29(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 29;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static bool onButtonClick_obj_B30(ZKButton *pButton) {
	if(!pButton->isSelected())
	{
		mTextView18Ptr->setTextTr("Confirm to cancel the current model?");
		yes_no_id = 1;
		exclude_object_id = 30;
		myes_no_WindowPtr->setVisible(true);

	}
    return false;
}

static void onProgressChanged_Obj_SeekBar(ZKSeekBar *pSeekBar, int progress) {
    //LOGD(" ProgressChanged Obj_SeekBar %d !!!\n", progress);
	float scale = static_cast<float>(progress) / 100.0;

//	//计算当前窗口XY中心点坐标

    int window_end_xpos = window_cur_mid_xpos - windowData.x*(scale/2);
    int window_end_ypos = window_cur_mid_ypos - windowData.y*(scale/2);


	LayoutPosition pos(window_end_xpos, window_end_ypos, windowData.x * scale,  windowData.y * scale);

	mExclude_Object_window2Ptr->setPosition(pos);

	init_exclude_Object_button(scale);

}
static bool onButtonClick_Button12(ZKButton *pButton) {
	myes_no_WindowPtr->setVisible(false);
	if(yes_no_id == 8){
		mCOLOR_ListViewPtr->setVisible(false);
	}

    return false;
}

static bool onButtonClick_Button14(ZKButton *pButton) {

//	std::string url = "http://" + print_ip + "/printer/gcode/script?script=EXCLUDE_OBJECT NAME=" + exclude_object[exclude_object_id].name;
//
//	RestClient::Response r = RestClient::post(encode_url(url), "application/x-www-form-urlencoded", "");
//	//LOGD("%s,%s",url.c_str(),r.body.c_str());
//
//switch(exclude_object_id){
//case 0: mobj_B0Ptr->setSelected(true);mobj_B0Ptr->setBackgroundPic("exclude_object_off.png");break;
//case 1: mobj_B1Ptr->setSelected(true);mobj_B1Ptr->setBackgroundPic("exclude_object_off.png");break;
//case 2: mobj_B2Ptr->setSelected(true);mobj_B2Ptr->setBackgroundPic("exclude_object_off.png");break;
//case 3: mobj_B3Ptr->setSelected(true);mobj_B3Ptr->setBackgroundPic("exclude_object_off.png");break;
//case 4: mobj_B4Ptr->setSelected(true);mobj_B4Ptr->setBackgroundPic("exclude_object_off.png");break;
//case 5: mobj_B5Ptr->setSelected(true);mobj_B5Ptr->setBackgroundPic("exclude_object_off.png");break;
//case 6: mobj_B6Ptr->setSelected(true);mobj_B6Ptr->setBackgroundPic("exclude_object_off.png");break;
//case 7: mobj_B7Ptr->setSelected(true);mobj_B7Ptr->setBackgroundPic("exclude_object_off.png");break;
//case 8: mobj_B8Ptr->setSelected(true);mobj_B8Ptr->setBackgroundPic("exclude_object_off.png");break;
//case 9: mobj_B9Ptr->setSelected(true);mobj_B9Ptr->setBackgroundPic("exclude_object_off.png");break;
//case 10: mobj_B10Ptr->setSelected(true);mobj_B10Ptr->setBackgroundPic("exclude_object_off.png");break;
//case 11: mobj_B11Ptr->setSelected(true);mobj_B11Ptr->setBackgroundPic("exclude_object_off.png");break;
//case 12: mobj_B12Ptr->setSelected(true);mobj_B12Ptr->setBackgroundPic("exclude_object_off.png");break;
//case 13: mobj_B13Ptr->setSelected(true);mobj_B13Ptr->setBackgroundPic("exclude_object_off.png");break;
	char buf[64];
	switch(yes_no_id){
	case 0:
				{
					print_cancel_state = true;
					gcode_send2("printer.print.cancel","");
					mprintPtr->setVisible(false);
					layer_ch(1);
				}
				break;
	case 1:	{
			excluded_objects_button_cancel(exclude_object_id);
			gcode_send2("","EXCLUDE_OBJECT NAME=" + exclude_object[exclude_object_id].name);
	}
		break;
	case 2:updata_perint_img("/mnt/usb1/");
			break;
	case 3:updata_perint_img("/mnt/extsd/");
			break;

	case 5:{
				master_print_ip = xz_print_ip;
				StoragePreferences::putString("print_ip", master_print_ip);
				mButton22Ptr->setText(master_print_ip.c_str());
				conn = nullptr;
				if (WS) {

					ws_closs = true;
				}
			}
			break;
	case 6:
			snprintf(buf,sizeof(buf),"MMU_CALIBRATE_SELECTOR GATE=%d",ERCF_GATE);
			gcode_send2("",buf);
			gcode_send2("","MMU_MOTORS_OFF");
			break;
	case 7:
			snprintf(buf,sizeof(buf),"MMU_HOME TOOL=%d",ERCF_GATE);
			gcode_send2("",buf);
			break;
	case 8:
			snprintf(buf,sizeof(buf),"T%d",ERCF_GATE);
			gcode_send2("",buf);
			mCOLOR_ListViewPtr->setVisible(false);
			break;


	case 9:
		Print_info[cur_print_set_num].img = fileName;
		Save_all_print_info();
		mPrint_img_ListViewPtr->setVisible(false);
		mPrint_set_listPtr->setVisible(false);

		mPrint_ListView1Ptr->refreshListView();

		break;
	case 10:
		{

			string path;

			//如果没有进入子文件夹
			if(!cur_file_dir.empty())
			{
				path = cur_file_dir.substr(1, cur_file_dir.size() -1);//移除第一个//
				path += "/";
			}
			std::string params = "\"path\":\"gcodes/"+ path + File_Gcodes[cur_selected_file_index].path + "\"";

			if(mHTTP_WS_BUTTONPtr->isSelected() == false){
				gcode_send2("server.files.delete_file",params);

			}else{
				gcode_send2("delete_file/server/files/","gcodes/" + path + File_Gcodes[cur_selected_file_index].path);
			}
			get_file(cur_file_dir);
			mprint_surePtr->setVisible(false);
			mFileListPtr->setVisible(true);
		}
		break;
	case 11:

		mprintPtr->setVisible(false);
		mthumbnail_pngPtr->setBackgroundPic("");;
		layer_ch(1);
		break;

	case 12:

		gcode_send2("printer.emergency_stop","");
		break;
	}



	myes_no_WindowPtr->setVisible(false);
    return false;
}

static void onProgressChanged_brightnes_SeekBar(ZKSeekBar *pSeekBar, int progress) {
    //LOGD(" ProgressChanged brightnes_SeekBar %d !!!\n", progress);
	//将屏幕亮度调整为80
	BRIGHTNESSHELPER->setBrightness(100- progress);

}
static bool onButtonClick_Button13(ZKButton *pButton) {
	if(Ethernet_mode == true)
	{
		GET_WIFI_List.run("");
		mHost_computer_wifiPtr->setVisible(true);
	}else
	{
		EASYUICONTEXT->openActivity("WifiSettingActivity");
	}
    return false;
}

static bool onButtonClick_Button15(ZKButton *pButton) {


 	std::string key = StoragePreferences::getString("key", "");

 	if(strcmp(key.c_str(),"")==0){
 		AJ_id = 88;
 		set_aj_layer();
 		mTextView22Ptr->setTextTr("Clear Password,Click to Confirm");
 		if(LANGUAGEMANAGER->getCurrentCode() == "zh_CN")
 		{
 			mTextView22Ptr->setTextSize(35);
 		}else
 		{
 			mTextView22Ptr->setTextSize(22);
 		}

 	}
 	else if(strcmp(key.c_str(),"0")>0)
     {
 		AJ_id = 90;
 		set_aj_layer();
 		mTextView22Ptr->setTextTr("Verify Password");
 		mTextView22Ptr->setTextSize(35);
     }

    return false;
}

static bool onButtonClick_Button16(ZKButton *pButton) {
	EASYUICONTEXT->openActivity("LanguageSettingActivity");
    return false;
}

static bool onButtonClick_Button17(ZKButton *pButton) {
	mTime_out_winPtr->setVisible(true);
		switch (time_out)
		{
			case 0:	moretime[0].bOn = true;break;
			case 10:moretime[1].bOn = true;break;
			case 30:moretime[2].bOn = true;break;
			case 60:moretime[3].bOn = true;break;
			case 120: moretime[4].bOn = true;break;
			case 300:moretime[5].bOn = true;break;
			case 1800:moretime[6].bOn = true;break;
			case 3600: moretime[7].bOn = true;break;
		}
		mTime_out_listPtr->refreshListView();
    return false;
}
static int getListItemCount_Time_out_list(const ZKListView *pListView) {
    //LOGD("getListItemCount_Time_out_list !\n");
    return sizeof(moretime) / sizeof(more_time);
}

static void obtainListItemData_Time_out_list(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ Time_out_list  !!!\n");
	ZKListView::ZKListSubItem* psubButton = pListItem->findSubItemByID(ID_GCODE_SubItem1);
	pListItem->setTextTr(moretime[index].mainText);
	psubButton->setSelected(moretime[index].bOn);
}

static void onListItemClick_Time_out_list(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ Time_out_list  !!!\n");


			moretime[0].bOn = false;
			moretime[1].bOn = false;
			moretime[2].bOn = false;
			moretime[3].bOn = false;
			moretime[4].bOn = false;
			moretime[5].bOn = false;
			moretime[6].bOn = false;
			moretime[7].bOn = false;
			moretime[index].bOn = true;
 		switch (index)
 		{
 			case 0:StoragePreferences::putInt("cstime", 0);  time_out = 0; mTextView21Ptr->setTextTr("time0");break;
			case 1:StoragePreferences::putInt("cstime", 10); time_out = 10;mTextView21Ptr->setTextTr("time1");  break;
			case 2:StoragePreferences::putInt("cstime", 30); time_out = 30;mTextView21Ptr->setTextTr("time2");  break;
			case 3:StoragePreferences::putInt("cstime", 60); time_out = 60;mTextView21Ptr->setTextTr("time3");  break;
			case 4:StoragePreferences::putInt("cstime", 120);time_out = 120;mTextView21Ptr->setTextTr("time4");  break;
			case 5:StoragePreferences::putInt("cstime", 300);time_out = 300;mTextView21Ptr->setTextTr("time5");  break;
			case 6:StoragePreferences::putInt("cstime", 1800);time_out = 1800;mTextView21Ptr->setTextTr("time6"); break;
			case 7:StoragePreferences::putInt("cstime", 3600);time_out = 3600;mTextView21Ptr->setTextTr("time7"); break;
 		}

 		mTime_out_winPtr->setVisible(false);


}

static bool onButtonClick_Button18(ZKButton *pButton) {
	AJ_id = 89;
	set_aj_layer();
    return false;
}

void layer4_ch(int layer)
{

	mButton20Ptr->setSelected(false);
	mButton31Ptr->setSelected(false);
	mButton19Ptr->setSelected(false);

	mConnect_WindowPtr->setVisible(false);
	mGcode_layerPtr->setVisible(false);
	mERCFPtr->setVisible(false);

	switch(layer){

	case 1:	mConnect_WindowPtr->setVisible(true);
			mButton20Ptr->setSelected(true);
			break;
	case 2:	mGcode_layerPtr->setVisible(true);
			mButton31Ptr->setSelected(true);
			break;
	case 3:	mERCFPtr->setVisible(true);
			mButton19Ptr->setSelected(true);
			break;



	}
}
static bool onButtonClick_Button19(ZKButton *pButton) {
	layer4_ch(3);
    return false;
}

static bool onButtonClick_Button20(ZKButton *pButton) {
	layer4_ch(1);
    return false;
}

static int getListItemCount_Print_ListView1(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView1 !\n");
    return Print_info.size() + 1 ;
}

static void obtainListItemData_Print_ListView1(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView1  !!!\n");

	char buf[64];
	ZKListView::ZKListSubItem* mac = pListItem->findSubItemByID(ID_GCODE_Print_mac1);
	ZKListView::ZKListSubItem* nname = pListItem->findSubItemByID(ID_GCODE_Print_name1);
	ZKListView::ZKListSubItem* Print_state = pListItem->findSubItemByID(ID_GCODE_Print_state1);
	ZKListView::ZKListSubItem* img = pListItem->findSubItemByID(ID_GCODE_Print_img2);



	if(index == (int)Print_info.size() )
	{

		pListItem->setBackgroundPic("layer4/print_add.png");
		pListItem->setText("");
		mac->setText("");
		nname->setText("");
		Print_state->setBackgroundPic("");
		if(ui_modo == 1){
			pListItem->setBackgroundColor(0xFFcacaca);
		}else{
			pListItem->setBackgroundColor(0xFF808080);
		}

	}else
	{
		//主机设置
		if(strstr(Print_info[index].ip.c_str(), master_print_ip.c_str()))
		{
			pListItem->setBackgroundColor(0xFFA020F0);
		}else{
				//从机设置
			  if (std::find(Slave_Print_ip.begin(), Slave_Print_ip.end(), Print_info[index].ip) != Slave_Print_ip.end()) {
				  pListItem->setBackgroundColor(0xFFFF6100);
			    } else {
			    	pListItem->setBackgroundColor(0xFF808080);
			    }


		}



		pListItem->setBackgroundPic("layer4/list_bg.png");
		//机器名设置
		if(!Print_info[index].name.empty())
		{
			nname->setText(Print_info[index].name);
		}else{
			nname->setTextTr("print name");
		}
		//机器图片设置
		if(!Print_info[index].img.empty())
		{
			img->setBackgroundPic(Print_info[index].img.c_str());
		}else{
			img->setBackgroundPic("");
		}
	//	if(!Print_info[index].mac.empty())

		//ip显示
			snprintf(buf,sizeof(buf),"%s",Print_info[index].ip.c_str() + 7);
			pListItem->setText(buf);

			//macx显示
			mac->setText(Print_info[index].mac);

			//状态设置
			if(Print_info[index].state == "disconnect")
			{
				Print_state->setBackgroundPic("layer4/state0.png");
			}
			else if(Print_info[index].state == "standby"){
				Print_state->setBackgroundPic("layer4/state1.png");
			}else if(Print_info[index].state == "printing"){
				Print_state->setBackgroundPic("layer4/state2.png");
			}else if(Print_info[index].state == "paused"){
				Print_state->setBackgroundPic("layer4/state3.png");
			}else if(Print_info[index].state == "complete"){
				Print_state->setBackgroundPic("layer4/state4.png");
			}else{
				Print_state->setBackgroundPic("layer4/state0.png");
			}
	}

}

static void onListItemClick_Print_ListView1(ZKListView *pListView, int index, int id) {

	char buf[64];
if(index < (int)Print_info.size())
{

	//主机
	if(mButton42Ptr->isSelected() == true){
		//切换机器后关闭打印界面，以便其它机器初始化，打印界面
		mprintPtr->setVisible(false);
		snprintf(buf,sizeof(buf),"%s",Print_info[index].ip.c_str() + 7);
		master_print_ip = buf;
		StoragePreferences::putString("print_ip", master_print_ip);
		mButton22Ptr->setText(master_print_ip);
		//因为不能强行关闭，在同一线程里关闭连接
		conn = nullptr;
		if (WS) {

			ws_closs = true;
		}

		//如果这个ip在从机地址集合中，我们就删除这个ip
	    auto it = std::find(Slave_Print_ip.begin(), Slave_Print_ip.end(), "http://" + master_print_ip); // 查找字符串在vector中的位置

	    if (it != Slave_Print_ip.end()) { // 确保找到了字符串
	        Slave_Print_ip.erase(it); // 删除找到的元素
	        LOGD("删除了");
	    }

	    //添加从机
	}else if(mPrint_set_buttonPtr->isSelected() == true){
    	mPrint_set_listPtr->setVisible(true);
    	cur_print_set_num = index;

    }else if(mButton43Ptr->isSelected() == true && !strstr(Print_info[index].ip.c_str(),master_print_ip.c_str()) ){
    	//LOGD("ok");

    	if(Slave_Print_ip.size() > 0)
    	{

			if (!(std::find(Slave_Print_ip.begin(), Slave_Print_ip.end(), Print_info[index].ip) != Slave_Print_ip.end()) )
			{
				LOGD("add ip:%s",Print_info[index].ip.c_str());
				Slave_Print_ip.push_back(Print_info[index].ip);
			}else{

	            for (int i=0; i<(int)Slave_Print_ip.size(); i++)
	            {
	            	//如果选的这个ip已经存在Slave_Print_ip中了，我们就把这个删除
	            	if(Slave_Print_ip[i] == Print_info[index].ip)
	            	{
	            	    auto it = Slave_Print_ip.begin() + i; // 获取第三个元素的迭代器

	            	    if (it != Slave_Print_ip.end()) { // 确保迭代器有效
	            	        Slave_Print_ip.erase(it); // 删除第三个元素
	            	    }

	            		break;
	            	}

	            }

			}

    	}else
    	{
    		Slave_Print_ip.push_back(Print_info[index].ip);
    		LOGD("add ip:%s",Print_info[index].ip.c_str());
    	}

    }
//	for (const auto& info : Slave_Print_ip) {
//    		LOGD("info ip:%s",info.c_str());
//    	}


mPrint_ListView1Ptr->refreshListView();

}else{

	sContentStr = "192.168.";
	mTextView22Ptr->setText(sContentStr);
	set_aj_layer();
	AJ_id = 890;

}




}
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

static bool onButtonClick_Button21(ZKButton *pButton) {

	 if(start_scan_print_ip == false)
	 {

		 System_info.clear();
		 start_scan_print_ip = true;
		 scan_Print_udp.run();
		 scan_print.run();
		 scan_print1.run();
		 scan_print2.run();
		 scan_print3.run();
		 scan_print4.run();
		 scan_print5.run();
		 scan_print6.run();
		 scan_print7.run();
		 scan_print8.run();
		 scan_print9.run();
		 scan_print10.run();
		 scan_print11.run();
		 scan_print12.run();
		 scan_print13.run();
		 scan_print14.run();
		 scan_print15.run();
		 scan_print16.run();
		 scan_print17.run();
		 scan_print18.run();
		 scan_print19.run();

	 }


    return false;
}
static bool onButtonClick_Button22(ZKButton *pButton) {
//    LOGD(" ButtonClick Button22 !!!\n");
	sContentStr = "192.168.";
	mTextView22Ptr->setText(sContentStr);
	set_aj_layer();
	AJ_id = 888;



    return false;
}
static bool onButtonClick_Button23(ZKButton *pButton) {
	set_aj_layer();
	AJ_id = 3;
    return false;
}

static bool onButtonClick_Button24(ZKButton *pButton) {
//    LOGD(" ButtonClick Button24 !!!\n");
    pButton->setSelected(!pButton->isSelected());

    return false;
}

static bool onButtonClick_Button25(ZKButton *pButton) {
    LOGD(" ButtonClick Button25 !!!\n");
    return false;
}

static bool onButtonClick_Button26(ZKButton *pButton) {
	set_aj_layer();
	AJ_id = 4;
    return false;
}


static bool onButtonClick_Button80(ZKButton *pButton) {
    // 将数组的所有元素设置为0
    for (int i = 0; i < 10; ++i) {
        Calibration_yes_no[i] = 0;
    }
	Calibration_term.clear();
	Calibration_error.clear();
	Calibration_send_Z_TILT = false;
	std::string Command ;

	if(mButton59Ptr->isSelected() == false)
	{
		Command = "PID_CALIBRATE HEATER=extruder TARGET=" + Pid_ext_temp;
		Calibration_term.push_back(Command)	;
	}
	if(mButton75Ptr->isSelected() == false)
	{
		Command = "PID_CALIBRATE HEATER=heater_bed TARGET=" + Pid_bed_temp;
		Calibration_term.push_back(Command)	;
	}
	if(mButton79Ptr->isSelected() == false)
	{
		Command = "SHAPER_CALIBRATE";
		Calibration_term.push_back(Command)	;
	}
	if(mButton76Ptr->isSelected() == false)
	{
		Command = "G28\\nBED_MESH_CALIBRATE";
		Calibration_term.push_back(Command)	;
	}
	if(mButton77Ptr->isSelected() == false)
	{
		Command = "QUAD_GANTRY_LEVEL";
		Calibration_term.push_back(Command)	;
	}
if(Calibration_term.empty())
{
	Notify_message_list.push_back("Calibration_term");
	notify_open_close(true);
	return false;
}



	Calibration_sw = true;
	Cur_Calibration_term = 0;
	mListView2Ptr->refreshListView();
	mcur_jz_WinPtr->setVisible(true);
	if(mHTTP_WS_BUTTONPtr->isSelected() == false){
		gcode_send2("",Calibration_term[0] + ".is_ca");//喷头PID
	}else{
		//http必须设置长连接我们才能知道叫准时发生的错误
		ca_thread.run();
	}

    return false;
}

static int getListItemCount_ListView2(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView2 !\n");
    return Calibration_term.size();
}

static void obtainListItemData_ListView2(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView2  !!!\n");
	 ZKListView::ZKListSubItem* icon = pListItem->findSubItemByID(ID_GCODE_SubItem3);

	if(strstr(Calibration_term[index].c_str(),"extruder")){
		 pListItem->setTextTr("Calibrate nozzle heating");
	}else if(strstr(Calibration_term[index].c_str(),"heater_bed")){
		 pListItem->setTextTr("Calibrate bed heating");
	}else if(strstr(Calibration_term[index].c_str(),"SHAPER_CALIBRATE")){
		 pListItem->setTextTr("Calibrate resonance frequency");
	}else if(strstr(Calibration_term[index].c_str(),"BED_MESH_CALIBRATE")){
		 pListItem->setTextTr("Calibrate bed leveling grid");
	}else if(strstr(Calibration_term[index].c_str(),"QUAD_GANTRY_LEVEL")){
		 pListItem->setTextTr("Calibrate multi-Z bed leveling");
	}

	if(Cur_Calibration_term == index)
	{
		pListItem->setTextColor(0xFF8040);
		icon->setBackgroundPic("layer2/tool/test.png");
	}else if(Calibration_yes_no[index] == 1)
	{
		pListItem->setTextColor(0x00ff00);
		icon->setBackgroundPic("layer2/tool/yes.png");
	}else if(Calibration_yes_no[index] == 2)
	{
		pListItem->setTextColor(0xFF0000);
		icon->setBackgroundPic("layer2/tool/no.png");
	}else {
		pListItem->setTextColor(0xffffff);
		icon->setBackgroundPic("layer2/tool/null.png");
	}

	//LOGD("初始化");

}

static void onListItemClick_ListView2(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView2  !!!\n");
}

static bool onButtonClick_Button27(ZKButton *pButton) {

	mcur_jz_WinPtr->setVisible(false);

    return false;
}
static int getListItemCount_ListView3(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView3 !\n");
    return Calibration_error.size();;
}

static void obtainListItemData_ListView3(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView3  !!!\n");

//	if(strstr(Calibration_error[index].c_str(),"extruder")){
//		 pListItem->setText(Calibration_error[index].c_str());
//		 pListItem->setTextSize(25);
//	}else if(strstr(Calibration_error[index].c_str(),"heater_bed")){
//		 pListItem->setText("校准热床");
//	}else if(strstr(Calibration_error[index].c_str(),"SHAPER_CALIBRATE")){
//		 pListItem->setText("校准共振");
//	}else if(strstr(Calibration_error[index].c_str(),"BED_MESH_CALIBRATE")){
//		 pListItem->setText("校准网床");
//	}else if(strstr(Calibration_error[index].c_str(),"quad_gantry_level")){
//		 pListItem->setText("校准多Z");
//	}
	pListItem->setText(Calibration_error[index].c_str());

}

static void onListItemClick_ListView3(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView3  !!!\n");
}
static bool onButtonClick_Button28(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button29(ZKButton *pButton) {

	mTextView41Ptr->setTextTr("Restarting, please wait");

	std::string godes;
	gcodes_message.push_back("printer.firmware_restart");
	gcodes_message.push_back("printer.restart");


	gcode_send2("printer.firmware_restart","");
	gcode_send2("printer.restart","");
	gcode_send2("printer.firmware_restart","");
	gcode_send2("printer.restart","");
    return false;
}

static bool onButtonClick_Button30(ZKButton *pButton) {
    LOGD(" ButtonClick Button30 !!!\n");
    return false;
}
static bool onButtonClick_Button31(ZKButton *pButton) {
	layer4_ch(2);
    return false;
}

static int getListItemCount_ListView5(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView5 !\n");
    return gcodes_message.size();
}

static void obtainListItemData_ListView5(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView5  !!!\n");
	 pListItem->setText(gcodes_message[index]);

	 if(strstr(gcodes_message[index].c_str(),"$ "))
	 {
		 pListItem->setTextColor(0x0080FF);

	 }else if(strstr(gcodes_message[index].c_str(),"!! "))
	 {
		 pListItem->setTextColor(0xFF0000);
	 } else {
		 if(ui_modo == 1){
			 pListItem->setTextColor(0x000000);
		 }else
		 {
			 pListItem->setTextColor(0xFFFFFF);
		 }

	 }
}

static void onListItemClick_ListView5(ZKListView *pListView, int index, int id) {
	mAJ1Ptr->setVisible(true);
	sContentStr.clear();
	mTextView46Ptr->setText("");
	AJ_id = 0;
}

static bool onButtonClick_Button125(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_0(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_1(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_2(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_3(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_4(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_5(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_6(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_7(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_8(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_9(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button137(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button138(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_a(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_b(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_c(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_d(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_e(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_f(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_g(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_h(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_i(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_j(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_k(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_l(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_m(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_n(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_o(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_p(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_q(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_r(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_s(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_t(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_u(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_v(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_w(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_x(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_y(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button_z(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button165(ZKButton *pButton) {

    // 设置目标URL
    std::string url ;


	switch(AJ_id){

	case 0:gcode_send2("",sContentStr);

			break;
	case 1:
		Print_info[cur_print_set_num].name = sContentStr;
		Save_all_print_info();
		mAJ1Ptr->setVisible(false);
		mPrint_set_listPtr->setVisible(false);
		mPrint_ListView1Ptr->refreshListView();
		break;

	case 2:
		Print_info[cur_print_set_num].ip = sContentStr,
		Save_all_print_info();
		mAJ1Ptr->setVisible(false);
		mPrint_set_listPtr->setVisible(false);
		mPrint_ListView1Ptr->refreshListView();
		break;

	case 3:
		mname_ButtonPtr->setText(sContentStr.c_str());
		mAJ1Ptr->setVisible(false);
		break;
	case 4:
		mgcode_ButtonPtr->setText(sContentStr.c_str());
		mAJ1Ptr->setVisible(false);
		break;

	case 10:
		fan1_name = sContentStr;
		StoragePreferences::putString("fan1_name", sContentStr);
		mFAN2_ICONPtr->setText(sContentStr.c_str());
		mAJ1Ptr->setVisible(false);
		Subscription_status();
		break;
	case 11:
		fan2_name = sContentStr;
		StoragePreferences::putString("fan2_name", sContentStr);
		mFAN3_ICONPtr->setText(sContentStr.c_str());
		mAJ1Ptr->setVisible(false);
		Subscription_status();
		break;

	}


	mTextView46Ptr->setText("");
	sContentStr.clear();




    return false;
}

static bool onButtonClick_Button166(ZKButton *pButton) {
	addOneChar(' ');
    return false;
}

static bool onButtonClick_Button167(ZKButton *pButton) {
	delOneChar();
    return false;
}

static bool onButtonClick_Button168(ZKButton *pButton) {
	mAJ1Ptr->setVisible(false);
    return false;
}
static bool onButtonClick_Zoffset_Up_button(ZKButton *pButton) {

	char buf[64];
	if(mZ_Offset_Reverse_ButtonPtr->isSelected()){
		snprintf(buf,sizeof(buf),"SET_GCODE_OFFSET Z_ADJUST=-%0.3f MOVE=1",zoffset_size);
	}else
	{
		snprintf(buf,sizeof(buf),"SET_GCODE_OFFSET Z_ADJUST=%0.3f MOVE=1",zoffset_size);
	}
	gcode_send2("",buf);
    return false;
}

static bool onButtonClick_Zoffset_Down_button(ZKButton *pButton) {
	char buf[64];
	if(mZ_Offset_Reverse_ButtonPtr->isSelected()){
		snprintf(buf,sizeof(buf),"SET_GCODE_OFFSET Z_ADJUST=%0.3f MOVE=1",zoffset_size);
	}else
	{
		snprintf(buf,sizeof(buf),"SET_GCODE_OFFSET Z_ADJUST=-%0.3f MOVE=1",zoffset_size);
	}
	gcode_send2("",buf);
    return false;
}
static int getListItemCount_ERCF_ListView(const ZKListView *pListView) {
    //LOGD("getListItemCount_ERCF_ListView !\n");
    return mmu.all_tool_num;
}

static void obtainListItemData_ERCF_ListView(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ERCF_ListView  !!!\n");


	pListItem->setText(index);
	ZKListView::ZKListSubItem* psubButton = pListItem->findSubItemByID(ID_GCODE_T_NUM_sure);
	if(mmu.cur_tool_num == index)
		psubButton->setSelected(true);
	else
		psubButton->setSelected(false);

//LOGD("A:%d",ERCF_GATE_SW_index[index]);
	if(ERCF_GATE_SW_index[index] != -1)
		pListItem->setBackgroundColor(ercf_color[ERCF_GATE_SW_index[index]].color);
	else
		pListItem->setBackgroundColor(0xFF6C6C6C);
}

static void onListItemClick_ERCF_ListView(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ERCF_ListView  !!!\n");
	ERCF_GATE = index;
	mCOLOR_ListViewPtr->setVisible(true);
	char buf[64];
	snprintf(buf,sizeof(buf),"Confirm switch to tool%d?",index);
	mTextView18Ptr->setTextTr(buf);
	yes_no_id = 8;
	myes_no_WindowPtr->setVisible(true);


}

static bool onButtonClick_ERCF_CA_BUTTON(ZKButton *pButton) {

	mERCF_CA_WindowPtr->setVisible(true);
    return false;
}

static bool onButtonClick_ERCF_E_ADD(ZKButton *pButton) {
	gcode_send2("","MMU_TEST_MOVE MOVE=10 SPEED=50");
    return false;
}

static bool onButtonClick_ERCF_E(ZKButton *pButton) {

	gcode_send2("","MMU_TEST_MOVE MOVE=-10 SPEED=50");
    return false;
}

static bool onButtonClick_ERCF_MOTOR_OFF(ZKButton *pButton) {
    gcode_send2("","MMU_MOTORS_OFF");
    return false;
}

static bool onButtonClick_ERCF_HOME(ZKButton *pButton) {
	gcode_send2("","MMU_HOME");
    return false;
}
static bool onButtonClick_Button34(ZKButton *pButton) {
    LOGD(" ButtonClick Button34 !!!\n");
    return false;
}

static bool onButtonClick_Button35(ZKButton *pButton) {
	mERCF_TOOL_WindowPtr->setVisible(true);
    return false;
}

static bool onButtonClick_Button37(ZKButton *pButton) {
	mERCF_SERVO_WindowPtr->setVisible(true);
    return false;
}

static bool onButtonClick_Button38(ZKButton *pButton) {
	mERCF_EX_WindowPtr->setVisible(true);
    return false;
}

static bool onButtonClick_Button39(ZKButton *pButton) {
	mERCF_SENSOR_WindowPtr->setVisible(true);
    return false;
}

static bool onButtonClick_Button40(ZKButton *pButton) {
	mERCF_BOWDEN_WindowPtr->setVisible(true);
    return false;
}
static bool onButtonClick_ERCF_SENSOR_BACK(ZKButton *pButton) {
	mERCF_SENSOR_WindowPtr->setVisible(false);
    return false;
}


static bool onButtonClick_ERCF_TOOOL_CA(ZKButton *pButton) {
	gcode_send2("","MMU_CALIBRATE_SELECTOR");
    return false;
}
static bool onButtonClick_ERCF_TOOL_BACK(ZKButton *pButton) {
	mERCF_TOOL_WindowPtr->setVisible(false);
    return false;
}
static int getListItemCount_ListView6(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView6 !\n");
    return mmu.all_tool_num;;
}

static void obtainListItemData_ListView6(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView6  !!!\n");
	pListItem->setText(index);
}

static void onListItemClick_ListView6(ZKListView *pListView, int index, int id) {
	ERCF_GATE = index;
	char buf[64];
	snprintf(buf,sizeof(buf),"Confirm test tool%d?",index);
	mTextView18Ptr->setTextTr(buf);
	yes_no_id = 7;
	myes_no_WindowPtr->setVisible(true);

}
static int getListItemCount_ERCF_CA_ListView(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView4 !\n");
    return mmu.all_tool_num;;
}

static void obtainListItemData_ERCF_CA_ListView(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView4  !!!\n");
	pListItem->setText(index);
}

static void onListItemClick_ERCF_CA_ListView(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView4  !!!\n");
	ERCF_GATE = index;
	char buf[64];
	snprintf(buf,sizeof(buf),"Confirm calibration tool%d?",index);
	mTextView18Ptr->setTextTr(buf);
	yes_no_id = 6;
	myes_no_WindowPtr->setVisible(true);

}

static bool onButtonClick_ERCF_MOTOR_OFF1(ZKButton *pButton) {
	gcode_send2("","MMU_MOTORS_OFF");

    return false;
}


static bool onButtonClick_ERCF_SERVO_DOWN_Button(ZKButton *pButton) {
	mTextView22Ptr->setText(mERCF_SERVO_DOWN_ButtonPtr->getText().c_str());
	sContentStr = mERCF_SERVO_DOWN_ButtonPtr->getText();
	set_aj_layer();
	AJ_id = 10;
    return false;
}

static bool onButtonClick_ERCF_SERVO_UP_Button(ZKButton *pButton) {
	mTextView22Ptr->setText(mERCF_SERVO_UP_ButtonPtr->getText().c_str());
	sContentStr = mERCF_SERVO_UP_ButtonPtr->getText();
	set_aj_layer();
	AJ_id = 11;
    return false;
}
static bool onButtonClick_ERCF_SERVO_BACK(ZKButton *pButton) {

	mERCF_SERVO_WindowPtr->setVisible(false);
    return false;
}
static bool onButtonClick_ERCF_EX_BACK(ZKButton *pButton) {
	mERCF_EX_WindowPtr->setVisible(false);
    return false;
}

static bool onButtonClick_ERCF_EX_BUTTON(ZKButton *pButton) {
	set_aj_layer();
	AJ_id = 12;
    return false;
}

static bool onButtonClick_ERCF_EX_TRUE_BUTTON(ZKButton *pButton) {
	set_aj_layer();
	AJ_id = 13;
    return false;
}
static bool onButtonClick_ERCF_SENSOR_TRUE_BUTTON(ZKButton *pButton) {

	gcode_send2("","MMU_CALIBRATE_ENCODER");
    return false;
}
static bool onButtonClick_ERCF_BOWDEN_CA_BUTTON(ZKButton *pButton) {

	set_aj_layer();
	AJ_id = 14;
    return false;
}
static bool onButtonClick_ERCF_BOWDEN_BACK(ZKButton *pButton) {
    mERCF_BOWDEN_WindowPtr->setVisible(false);
    return false;
}
static bool onButtonClick_ERCF_CA_BACK(ZKButton *pButton) {
	mERCF_CA_WindowPtr->setVisible(false);
    return false;
}
static int getListItemCount_COLOR_ListView(const ZKListView *pListView) {
    //LOGD("getListItemCount_COLOR_ListView !\n");
   // return sizeof(ercf_color);
    return 30;
}

static void obtainListItemData_COLOR_ListView(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ COLOR_ListView  !!!\n");
	pListItem->setBackgroundColor(ercf_color[index].color);
	//LOGD("num:%d,COLOR:%02X",index,ercf_color[index].color);

}

static void onListItemClick_COLOR_ListView(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ COLOR_ListView  !!!\n");
	char buf[64];
	snprintf(buf,sizeof(buf),"COLOR%d",ERCF_GATE);
	StoragePreferences::putInt(buf, index);
	//将颜色对应的颜色值更新到动态数组里
	ERCF_GATE_SW_index[ERCF_GATE] = index;
	mERCF_ListViewPtr->refreshListView();
	myes_no_WindowPtr->setVisible(false);
	mCOLOR_ListViewPtr->setVisible(false);
}
static bool onButtonClick_ERCF_MOTOR_OFF2(ZKButton *pButton) {
	gcode_send2("","MMU_MOTORS_OFF");
    return false;
}
static bool onButtonClick_Button41(ZKButton *pButton) {

    upfile u;

     //u.up("http://192.168.6.139","/mnt/usb1/aa.gcode");
    return false;
}
static bool onButtonClick_Button42(ZKButton *pButton) {
	mPrint_set_buttonPtr->setSelected(false);
	mButton43Ptr->setSelected(false);
	pButton->setSelected(true);

    return false;
}

static bool onButtonClick_Button43(ZKButton *pButton) {
	//StoragePreferences::clear();
	mPrint_set_buttonPtr->setSelected(false);
	mButton42Ptr->setSelected(false);
	pButton->setSelected(true);
    return false;
}

static bool onButtonClick_Button44(ZKButton *pButton) {

	if(!pButton->isSelected()){
		pButton->setSelected(true);

		Slave_Print_ip.clear();
	    for (int i=0; i<(int)Print_info.size(); i++)
	    {
	    	//如果选的这个ip已经存在Slave_Print_ip中了，我们就把这个删除
	    	if(!strstr(Print_info[i].ip.c_str(), master_print_ip.c_str()))
	    	{
	    		Slave_Print_ip.push_back(Print_info[i].ip);
	    	}

	    }

	}
	else
	{
		pButton->setSelected(false);

		Slave_Print_ip.clear();
	}
    mPrint_ListView1Ptr->refreshListView();
    return false;
}

static int getListItemCount_Print_set_list(const ZKListView *pListView) {
    //LOGD("getListItemCount_Print_set_list !\n");
    return 5;
}

static void obtainListItemData_Print_set_list(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ Print_set_list  !!!\n");
	//if(LANGUAGEMANAGER->getCurrentCode() == "zh_CN")
	//{
		pListItem->setTextTr(print_set[index].mainText);
	//}else
	//{
	//	pListItem->setText(en_print_set[index].mainText);
	//}

}

static void onListItemClick_Print_set_list(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ Print_set_list  !!!\n");
	mPrint_img_ListViewPtr->setVisible(false);
	switch(index){
	case 0:
//		   static IMEContext::SIMETextInfo info;
//		   info.imeTextType = IMEContext::E_IME_TEXT_TYPE_ALL; //数字键盘
//		   info.isPassword = false; //非密码
//		   info.text = "";  //默认内容为空
//		   EASYUICONTEXT->showIME(&info, &ime_text_update_listener);
		mAJ1Ptr->setVisible(true);
		AJ_id = 1;
		break;

	case 1:
		  if (udesk == true) {
		    //TF卡已经挂载
			  listFiles("/mnt", "usb1/img",true);
		  } else if(sdcard == true) {
		    //TF卡未挂载
			  listFiles("/mnt", "extsd/img",true);
		  }else{
		    	Notify_message_list.push_back("plase Install sdcard");
		    	notify_open_close(true);
		  }

		//mprintPtr->setVisible(true);
		mPrint_img_ListViewPtr->setVisible(true);
		mPrint_img_ListViewPtr->setSelection(1);//跳转到第一行
		break;


	case 2:
		sContentStr = "192.168.";
		mTextView22Ptr->setText(sContentStr);
		set_aj_layer();
		AJ_id = 889;
		break;

	case 3:
		Print_info_size_ch = true;
		if(cur_print_set_num <= (int)Print_info.size() - 1){
			Print_info.erase(Print_info.begin() + cur_print_set_num);
		}

		//储存数据
		Save_all_print_info();
		mPrint_ListView1Ptr->refreshListView();
		mPrint_set_listPtr->setVisible(false);
		break;
	case 4:
		mPrint_set_listPtr->setVisible(false);
		mPrint_img_ListViewPtr->setVisible(false);
		mAJ1Ptr->setVisible(false);
		break;
	}

}
static bool onButtonClick_Print_set_button(ZKButton *pButton) {
	mButton43Ptr->setSelected(false);
	mButton42Ptr->setSelected(false);
	pButton->setSelected(true);
    return false;
}
static int getListItemCount_Notify_ListView(const ZKListView *pListView) {
    //LOGD("getListItemCount_Notify_ListView !\n");
    return Notify_message_list.size() ;
}

static void obtainListItemData_Notify_ListView(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ Notify_ListView  !!!\n");
//if(index == (int)Notify_message_list.size() )
//{
//	pListItem->setText("关闭窗口");
//}else{
	pListItem->setTextTr(Notify_message_list[index].c_str());
//}


}

static void onListItemClick_Notify_ListView(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ Notify_ListView  !!!\n");

//	if(index == (int)Notify_message_list.size())
//	{
//		mNotify_ListViewPtr->setVisible(false);
//	}else{
		if( id == ID_GCODE_Notify_ListView_del)
		{

		        	    auto it = Notify_message_list.begin() + index; // 获取第三个元素的迭代器

		        	    if (it != Notify_message_list.end()) { // 确保迭代器有效
		        	    	Notify_message_list.erase(it); // 删除第三个元素

		        	    }
		        	    mNotify_ListViewPtr->refreshListView();
		        	    mNotify_ListViewPtr->setSelection(index - 1);
		        	    if( (int)Notify_message_list.size() == 0 )
		        	    {
		        	    	notify_open_close(false);
		        	    }
		}
	//}





}
static int getListItemCount_Print_img_ListView(const ZKListView *pListView) {
    //LOGD("getListItemCount_Print_img_ListView !\n");
    return fileInfos.size();
}

static void obtainListItemData_Print_img_ListView(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ Print_img_ListView  !!!\n");
	//char buf[64];

     FileInfo fi = fileInfos[index];
     string img_path = currentDirectory + "/" + fi.fileName;
	 pListItem->setBackgroundPic(img_path.c_str());//设置文件名字
	 LayoutPosition pos = pListView->getPosition();
	 if(index == 1){
		 pos.mHeight = pos.mHeight * 2;
		 pListView->setPosition(pos);
	 }else{
		 pos.mHeight = 100;
		 pListView->setPosition(pos);
	 }


}

static void onListItemClick_Print_img_ListView(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ Print_img_ListView  !!!\n");
	FileInfo fi = fileInfos[index];
		fileName = currentDirectory + "/" + fi.fileName;
		LOGD("wj:%s",fileName.c_str());
		mTextView18Ptr->setTextTr("Confirm picture?");
		yes_no_id = 9;
		myes_no_WindowPtr->setVisible(true);


}

static bool onButtonClick_Updata_Slave(ZKButton *pButton) {

		//检测是否有u盘/sd卡
	  if(udesk == true || sdcard == true)
	  {
		  	up_file_and_print = false;
			upload_progress_list.clear();
			up_file_Thread.run();
	  }else
	  {
		  Notify_message_list.push_back("A USB disk must be installed to use this function") ;
		  notify_open_close(true);
	  }
    return false;
}

static bool onButtonClick_Updata_Slave_printing(ZKButton *pButton) {
   // LOGD(" ButtonClick Updata_Slave_printing !!!\n");
	//检测是否有u盘/sd卡
  if(udesk == true || sdcard == true)
  {
	  	up_file_and_print = true;
		upload_progress_list.clear();
		up_file_Thread.run();
  }else
  {
	  Notify_message_list.push_back("A USB disk must be installed to use this function") ;
	  notify_open_close(true);
  }

    return false;
}
static int getListItemCount_download_list(const ZKListView *pListView) {
    //LOGD("getListItemCount_download_list !\n");
    return Slave_Print_ip.size() + 2;
}

static void obtainListItemData_download_list(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ download_list  !!!\n");
	char buf[64];
	ZKListView::ZKListSubItem* File_progress = pListItem->findSubItemByID(ID_GCODE_up_file_progress);
	ZKListView::ZKListSubItem* UD_speed = pListItem->findSubItemByID(ID_GCODE_ud_speed);

	if(index == 0)
	{

		pListItem->setTextTr("close the window");//设置文件名字
		pListItem->setBackgroundColor(0xFFFF0000);
		File_progress->setText("X");
		UD_speed->setText(" ");
		File_progress->setBackgroundColor(0xFFFF0000);
	}else if(index == 1)
	{

		pListItem->setBackgroundColor(0xFF6C6C6C);
		File_progress->setBackgroundColor(0xFF6C6C6C);

		//从主机共享文件
		if(mms_file_buttonPtr->isSelected())
		{

			snprintf(buf,sizeof(buf),"文件下载:大小:%0.2fm",total_to_download/1024/1024);
			pListItem->setText(buf);//设置文件名字
			if(file_progress < 100){
				snprintf(buf,sizeof(buf),"%0.2f%%",file_progress);
				File_progress->setText(buf);
				//设置下载速度
				if(file_progress > 0 && up_download_time != 0)
				{
					up_download_speed = (total_to_download/1024/1024 * (file_progress/100)) / (up_download_time / 1000);
					snprintf(buf,sizeof(buf),"%0.2fm/s",up_download_speed);
					UD_speed->setText(buf);
				}
			}else
			{
				snprintf(buf,sizeof(buf),"%0.2fm/s",up_download_speed);
				UD_speed->setText(buf);
				File_progress->setText("100.00%");
			}
		}else{//从sd共享文件

			pListItem->setText(fileName);//设置文件名字
			UD_speed->setText("");
			File_progress->setText("100.00%");
		}
	}else{
		pListItem->setBackgroundColor(0xFF6C6C6C);
		snprintf(buf,sizeof(buf),"上传>>%s",Slave_Print_ip[index-2].c_str());
		pListItem->setText(buf);//设置上传ip名字
		//如果当前行数大于 上传数，我们就让这一行显示为0%
		if((index - 2) > (int)upload_progress_list.size())
		{

			File_progress->setBackgroundColor(0xFF6C6C6C);
			File_progress->setText("0.00%");
			UD_speed->setText("");

		}else if((index - 2) == (int)upload_progress_list.size())
		{
			UD_speed->setText("");
			//设置下载速度
			if(upload_progress > 0 && up_download_time != 0)
			{
				up_speed = (total_to_download/1024/1024 * (upload_progress/100)) / (up_download_time / 1000);
				snprintf(buf,sizeof(buf),"%0.2fm/s",up_speed);
				UD_speed->setText(buf);
			}

			//设置进度百分比
			snprintf(buf,sizeof(buf),"%0.2f%%",upload_progress);
			File_progress->setText(buf);

		}else
		{

				if(atoi(upload_progress_list[index-2].c_str()) == 1)
				{
					snprintf(buf,sizeof(buf),"%0.2fm/s",atof(upload_speed_list[index - 2].c_str()));
					UD_speed->setText(buf);
					File_progress->setText("100.00%");

				}else
				{

					//LOGD("为什么！！");
					UD_speed->setText("");
					snprintf(buf,sizeof(buf),"网络错误:%s",upload_progress_list[index-2].c_str());
					File_progress->setBackgroundColor(0xFF6C6C6C);
					File_progress->setText(buf);
				}

			}

	}
}

static void onListItemClick_download_list(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ download_list  !!!\n");
	if(index == 0)
	{
    	if(!mms_file_buttonPtr->isSelected())
    	{
    		Slave_Print_ip.pop_back();
    	}
		mdownload_listPtr->refreshListView();
		mdownload_listPtr->setVisible(false);
		up_file_Thread.requestExit();
	}
}
static bool onButtonClick_Udesk_button(ZKButton *pButton) {

	if(udesk == false){
    	Notify_message_list.push_back("plase Install udesk");
    	notify_open_close(true);
	}

    mms_file_buttonPtr->setSelected(false);
    mUdesk_buttonPtr->setSelected(true);
    mSd_buttonPtr->setSelected(false);
    listFiles("/mnt", "usb1",false);
    return false;
}

static bool onButtonClick_Sd_button(ZKButton *pButton) {
	if(sdcard == false){
    	Notify_message_list.push_back("plase Install sdcard");
    	notify_open_close(true);
	}
    mms_file_buttonPtr->setSelected(false);
    mUdesk_buttonPtr->setSelected(false);
    mSd_buttonPtr->setSelected(true);
    listFiles("/mnt", "extsd",false);
    return false;
}
static bool onButtonClick_ms_file_button(ZKButton *pButton) {

    mms_file_buttonPtr->setSelected(true);
    mUdesk_buttonPtr->setSelected(false);
    mSd_buttonPtr->setSelected(false);
    mFileListPtr->refreshListView();
    return false;
}
static bool onButtonClick_Buzz_BUTTON(ZKButton *pButton) {
	if(!pButton->isSelected()){
		CONFIGMANAGER->setBeepEnable(true);
		pButton->setSelected(true);
		mTextView76Ptr->setTextTr("on");
		StoragePreferences::putBool("Buzzer", true);
	}
	else
	{
		CONFIGMANAGER->setBeepEnable(false);
		pButton->setSelected(false);
		mTextView76Ptr->setTextTr("off");
		StoragePreferences::putBool("Buzzer", false);
	}

    return false;
}

void notify_open_close(bool sw_layer)
{



	if(sw_layer == true)
	{
		if( !mNotify_ListViewPtr->isVisible()){
			LayoutPosition pButton_pos = mopen_notifyPtr->getPosition();
			LayoutPosition Notify_pos = mNotify_ListViewPtr->getPosition();
			LayoutPosition new_pButton_pos(pButton_pos.mLeft - Notify_pos.mWidth,pButton_pos.mTop,pButton_pos.mWidth,pButton_pos.mHeight);
			mopen_notifyPtr->setPosition(new_pButton_pos);
			mNotify_ListViewPtr->setVisible(true);
			mopen_notifyPtr->setVisible(true);
			mopen_notifyPtr->setSelected(true);
		}

		mNotify_ListViewPtr->refreshListView();
	}else{
		if( mNotify_ListViewPtr->isVisible()){

			LayoutPosition pButton_pos = mopen_notifyPtr->getPosition();
			LayoutPosition Notify_pos = mNotify_ListViewPtr->getPosition();
			LayoutPosition new_pButton_pos(pButton_pos.mLeft + Notify_pos.mWidth,pButton_pos.mTop,pButton_pos.mWidth,pButton_pos.mHeight);
			mopen_notifyPtr->setPosition(new_pButton_pos);
			mNotify_ListViewPtr->setVisible(false);
			mopen_notifyPtr->setSelected(false);
			//没有消息时 展开按钮  不显示
		    if( (int)Notify_message_list.size() == 0 )
		    {
		    	mopen_notifyPtr->setVisible(false);
		    }
		}


	}


}

static bool onButtonClick_open_notify(ZKButton *pButton) {
    //LOGD(" ButtonClick open_notify !!!\n");


	if(pButton->isSelected()){

		notify_open_close(false);

	}
	else
	{
		notify_open_close(true);

	}



    return false;
}
static int getListItemCount_ListViewWifiInfo(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListViewWifiInfo !\n");
    return WiFi_Info.size();
}

static void obtainListItemData_ListViewWifiInfo(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListViewWifiInfo  !!!\n");
	ZKListView::ZKListSubItem *pLevelItem = pListItem->findSubItemByID(ID_GCODE_LISTSUBITEM_LEVEL);//信号强度图片
	ZKListView::ZKListSubItem *pNameItem = pListItem->findSubItemByID(ID_GCODE_LISTSUBITEM_NAME);//wifi名字
	ZKListView::ZKListSubItem *pSubItem = pListItem->findSubItemByID(ID_GCODE_LISTSUBITEM_SUB);//加密方式
	ZKListView::ZKListSubItem *WIFI_IP = pListItem->findSubItemByID(ID_GCODE_WIFI_IP);//显示ip
	ZKListView::ZKListSubItem *WIFI_freq = pListItem->findSubItemByID(ID_GCODE_WIFI_freq);//显示ip

	//设置wifi2.4G/5G
	if(WiFi_Info[index].freq > 4000){
		WIFI_freq->setText("5G");
	}else
	{
		WIFI_freq->setText("2.4G");
	}

	//wifi名字
	pNameItem->setText(WiFi_Info[index].ssid);//wifi名字
	//是否已经连接
	if(WiFi_Info[index].use == true)
	{

		//屏幕设置界面的wifi名字
		mTextView27Ptr->setText(WiFi_Info[index].ssid);//wifi名字

		pNameItem->setSelected(true);//wifi名字变色
		pSubItem->setTextTr("connected");//安全性那里显示已连接
		//显示已连接的wifi ip
		for (size_t i = 0; i < devices_Info.size(); ++i) {
//			LOGD("IP:%s",devices_Info[i].ip_address.c_str());
//			if(devices_Info[i].connection == WiFi_Info[index].ssid)
//			{
				WIFI_IP->setText(devices_Info[i].ip_address);//显示当前机器ip

				//屏幕设置界面的ip地址
				mTextView28Ptr->setText(devices_Info[i].ip_address);//wifi名字

//			}
//
		}

	} else {
		pNameItem->setSelected(false);//wifi名字不变色
		WIFI_IP->setText("");//不显示当前机器ip

		//如果没有加密
		if( WiFi_Info[index].security.empty() )
		{
			pSubItem->setTextTr("Open WiFi");//显示加密方式
		}else{//有加密
			pSubItem->setText(WiFi_Info[index].security);//显示加密方式
		}
	}

//根据wifi 信号强度/加密方式 设置wifi强度图标
	int wifi_signal = WiFi_Info[index].signal / 21;//0-20 /21 =0   20-40/21 = 1
//	LOGD("PIC:%d,%d",wifi_signal,WiFi_Info[index].signal);
	char buf[32];
	//如果没有加密
	if( WiFi_Info[index].security.empty() )
	{
		snprintf(buf,sizeof(buf),"wifi/wifi_%d.png",wifi_signal);
	}else{//有加密
		snprintf(buf,sizeof(buf),"wifi/wifi_a%d.png",wifi_signal);
	}
	pLevelItem->setBackgroundPic(buf);
//wifi强度图标显示完成




}

static void onListItemClick_ListViewWifiInfo(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListViewWifiInfo  !!!\n");
	if(WiFi_Info[index].use == true)
	{
		mWindowDisconnectPtr->setVisible(true);
		mTextConnectSecTypePtr->setText(WiFi_Info[index].security);//显示加密方式
		mTextConnectSsidPtr->setText(WiFi_Info[index].ssid);//wifi名字

	}else{
		//如果没有密码就不显示输入密码那些框
		if( WiFi_Info[index].security.empty() )
		{
			mTextview9Ptr->setVisible(false);
			mEdittextPwdPtr->setVisible(false);
			mButtonShowPwdPtr->setVisible(false);
		}else
		{
			mTextview9Ptr->setVisible(true);
			mEdittextPwdPtr->setVisible(true);
			mButtonShowPwdPtr->setVisible(true);
		}
		mWindowSetPtr->setVisible(true);
		mTextSecTypePtr->setText(WiFi_Info[index].security);//显示加密方式
		mTextSsidPtr->setText(WiFi_Info[index].ssid);//wifi名字
	}

}




static bool onButtonClick_ButtonConnect(ZKButton *pButton) {
	Start_connect_wifi = true;//线程里会自动开启连接；
	mWindowSetPtr->setVisible(false);

    return false;
}

static void onEditTextChanged_EdittextPwd(const std::string &text) {
    //LOGD(" onEditTextChanged_ EdittextPwd %s !!!\n", text.c_str());
}

static bool onButtonClick_ButtonShowPwd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonShowPwd !!!\n");
	pButton->setSelected(!pButton->isSelected());
	mEdittextPwdPtr->setPassword(!pButton->isSelected());
    return false;
}

static bool onButtonClick_ButtonDisconnect(ZKButton *pButton) {
//    LOGD(" ButtonClick ButtonDisconnect !!!\n");
    Disconnect_wifi = true;
    mWindowDisconnectPtr->setVisible(false);
    return false;
}


static bool onButtonClick_Buttonautoconnect(ZKButton *pButton) {
//    LOGD(" ButtonClick Buttonautoconnect !!!\n");
    pButton->setSelected(!pButton->isSelected());
    return false;
}
static bool onButtonClick_ButtonForget(ZKButton *pButton) {
//    LOGD(" ButtonClick ButtonForget !!!\n");

    Forget_wifi = true;
    mWindowDisconnectPtr->setVisible(false);
    return false;
}

static bool onButtonClick_Button_Preheat(ZKButton *pButton) {
//    LOGD(" ButtonClick Button_Preheat !!!\n");

	char buf[64];
	snprintf(buf,sizeof(buf),"M104 S%0.1f\\nM140 S%0.1f",File_Gcodes[cur_selected_file_index].first_layer_extr_temp,File_Gcodes[cur_selected_file_index].first_layer_bed_temp);
	gcode_send2("",buf);

    return false;
}

static bool onButtonClick_Button_Del(ZKButton *pButton) {
	mTextView18Ptr->setTextTr("Confirm file deletion?");
	yes_no_id = 10;
	myes_no_WindowPtr->setVisible(true);
    return false;
}

static bool onButtonClick_Button_unlock(ZKButton *pButton) {
	gcode_send2("","M84");
    return false;
}

static bool onButtonClick_Button_moto_revers(ZKButton *pButton) {
	pButton->setSelected(!pButton->isSelected());
	if(pButton->isSelected() ){
		StoragePreferences::putBool("moto_revers", true);
	}else{
		StoragePreferences::putBool("moto_revers", false);
	}


    return false;
}

static int getListItemCount_Language_ListView(const ZKListView *pListView) {
    //LOGD("getListItemCount_Language_ListView !\n");
     return sizeof(lanugage) / sizeof(Lanugage);;
}

static void obtainListItemData_Language_ListView(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
	ZKListView::ZKListSubItem* psubButton = pListItem->findSubItemByID(ID_GCODE_SubItem4);
	pListItem->setText(lanugage[index].mainText);
	psubButton->setSelected(lanugage[index].bOn);
}

static void onListItemClick_Language_ListView(ZKListView *pListView, int index, int id) {
	lanugage[0].bOn = false;
	lanugage[1].bOn = false;
	lanugage[index].bOn = true;
	switch (index)
	{
		case 0:EASYUICONTEXT->updateLocalesCode("zh_CN"); break;//设置为中文
		case 1:EASYUICONTEXT->updateLocalesCode("en_US"); break;//设置为英文

	}

}
static bool onButtonClick_stop_Button(ZKButton *pButton) {
	mTextView18Ptr->setTextTr("Confirm emergency stop?");
	yes_no_id = 12;
	myes_no_WindowPtr->setVisible(true);


    return false;
}
static bool onButtonClick_Button45(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Customize_Button(ZKButton *pButton) {
//    LOGD(" ButtonClick Customize_Button !!!\n");
	pButton->setSelected(!pButton->isSelected());
	mCustomize_ListViewPtr->refreshListView();





    return false;
}

static bool onButtonClick_type_Button(ZKButton *pButton) {
    LOGD(" ButtonClick type_Button !!!\n");
    return false;
}


static bool onButtonClick_Button46(ZKButton *pButton) {
	pButton->setSelected(!pButton->isSelected());
	if(!pButton->isSelected() ){

		mButton_aPtr->setText("A");
		mButton_bPtr->setText("B");
		mButton_cPtr->setText("C");
		mButton_dPtr->setText("D");
		mButton_ePtr->setText("E");
		mButton_fPtr->setText("F");
		mButton_gPtr->setText("G");
		mButton_hPtr->setText("H");
		mButton_iPtr->setText("I");
		mButton_jPtr->setText("J");
		mButton_kPtr->setText("K");
		mButton_lPtr->setText("L");
		mButton_mPtr->setText("M");
		mButton_nPtr->setText("N");
		mButton_oPtr->setText("O");
		mButton_pPtr->setText("P");
		mButton_qPtr->setText("Q");
		mButton_rPtr->setText("R");
		mButton_sPtr->setText("S");
		mButton_tPtr->setText("T");
		mButton_uPtr->setText("U");
		mButton_vPtr->setText("V");
		mButton_wPtr->setText("W");
		mButton_xPtr->setText("X");
		mButton_yPtr->setText("Y");
		mButton_zPtr->setText("Z");
		mButton_print_Ptr->setText("PRINT_");
	}else{
		mButton_aPtr->setText("a");
		mButton_bPtr->setText("b");
		mButton_cPtr->setText("c");
		mButton_dPtr->setText("d");
		mButton_ePtr->setText("e");
		mButton_fPtr->setText("f");
		mButton_gPtr->setText("g");
		mButton_hPtr->setText("h");
		mButton_iPtr->setText("i");
		mButton_jPtr->setText("j");
		mButton_kPtr->setText("k");
		mButton_lPtr->setText("l");
		mButton_mPtr->setText("m");
		mButton_nPtr->setText("n");
		mButton_oPtr->setText("o");
		mButton_pPtr->setText("p");
		mButton_qPtr->setText("q");
		mButton_rPtr->setText("r");
		mButton_sPtr->setText("s");
		mButton_tPtr->setText("t");
		mButton_uPtr->setText("u");
		mButton_vPtr->setText("v");
		mButton_wPtr->setText("w");
		mButton_xPtr->setText("x");
		mButton_yPtr->setText("y");
		mButton_zPtr->setText("z");
		mButton_print_Ptr->setText("print_");
	}



    return false;
}

static bool onButtonClick_Button47(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button48(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button49(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button51(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button52(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button53(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static bool onButtonClick_Button54(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}

static int getListItemCount_Customize_ListView(const ZKListView *pListView) {
    //LOGD("getListItemCount_Customize_ListView !\n");
    return Customize_button.size() + 1;
}

static void obtainListItemData_Customize_ListView(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ Customize_ListView  !!!\n");

	ZKListView::ZKListSubItem* smail_edit_img= pListItem->findSubItemByID(ID_GCODE_smail_edit);

	//检测是不是最后一个按钮
	if(index == (int)Customize_button.size())
	{
		pListItem->setText("");
		pListItem->setBackgroundPic("Drop/print_add.png");
//		pListItem->setBackgroundColor(0xFFE5E5E5);
	}else{
		pListItem->setText(Customize_button[index].name);
		pListItem->setBackgroundPic("Drop/list_bg.png");
	}

	//设置右上角标
	if(mCustomize_ButtonPtr->isSelected() == true)
	{
		smail_edit_img->setBackgroundPic("Drop/smail_edit.png");
	}else{
		smail_edit_img->setBackgroundPic("");
	}

}

static void onListItemClick_Customize_ListView(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ Customize_ListView  !!!\n");

	del_Customize_num = index;
//	LOGD()
	//按了最后一共添加按钮
	if(index == (int)Customize_button.size() )
	{
		Selected_gpio = "null";
		mgcode_Button_pinPtr->setTextTr("Unbound GPIO");
		mname_ButtonPtr->setText("");
		mgcode_ButtonPtr->setText("");
		mCustomize_WindowPtr->setVisible(true);

	}else{
		//打开设置了
		if(mCustomize_ButtonPtr->isSelected())
		{
			Selected_gpio = Customize_button[index].Gpio;
			if(Customize_button[index].Gpio == "GPIO_136"){
				mgcode_Button_pinPtr->setText("PE8");
			}else if(Customize_button[index].Gpio == "GPIO_138"){
				mgcode_Button_pinPtr->setText("PE10");
			}else if(Customize_button[index].Gpio == "GPIO_200"){
				mgcode_Button_pinPtr->setText("PG8");
			}else if(Customize_button[index].Gpio == "GPIO_201"){
				mgcode_Button_pinPtr->setText("PG9");
			}else if(Customize_button[index].Gpio == "GPIO_202"){
				mgcode_Button_pinPtr->setText("PG10");
			}else if(Customize_button[index].Gpio == "GPIO_203"){
				mgcode_Button_pinPtr->setText("PG11");
			}else {
				mgcode_Button_pinPtr->setTextTr("Unbound GPIO");
			}

			mname_ButtonPtr->setText(Customize_button[index].name);
			mgcode_ButtonPtr->setText(Customize_button[index].gcode);
			mCustomize_WindowPtr->setVisible(true);
		}else{//发送gcode
			gcode_send2("",Customize_button[index].gcode);
		}


	}


}
static bool onButtonClick_name_Button(ZKButton *pButton) {
//    LOGD(" ButtonClick name_Button !!!\n");

    AJ_id = 3;
	//免得客户重新输入很多，直接将内容显示到键盘上
	sContentStr = mname_ButtonPtr->getText();
	mTextView46Ptr->setText(sContentStr);
    mAJ1Ptr->setVisible(true);
    return false;
}

static bool onButtonClick_gcode_Button(ZKButton *pButton) {
	AJ_id = 4;
	//免得客户重新输入很多，直接将内容显示到键盘上
	sContentStr = mgcode_ButtonPtr->getText();
	mTextView46Ptr->setText(sContentStr);
	mAJ1Ptr->setVisible(true);
	return false;
}

void save_Customize_buttons(){
    Json::Value root;
    //添加数组
    Json::Value array;
    //json的嵌套
    Json::Value sub;



    for (const auto& info : Customize_button)
    {
    	//储存mac前我们先检测当前的MAC是否已被储存

        sub["name"] = info.name;
        sub["type"] = info.type;
        sub["gcode"] = info.gcode;
        sub["Gpio"] = info.Gpio;
        array.append(sub);

    }
    root["Customize_buttons"] = array;
    LOGD("root: %s", root.toStyledString().c_str());
    StoragePreferences::putString("Customize_buttons", root.toStyledString());
    //刷新列表
    mCustomize_ListViewPtr->refreshListView();

}
static bool onButtonClick_Button57(ZKButton *pButton) {
//    LOGD(" ButtonClick Button57 !!!\n");
//

	//修改已保存的内容
	if(del_Customize_num <= (int)Customize_button.size() - 1){
		mCustomize_WindowPtr->setVisible(false);
		Customize_buttons _cu;

		Customize_button[del_Customize_num].name = mname_ButtonPtr->getText();
		Customize_button[del_Customize_num].gcode = mgcode_ButtonPtr->getText();
		Customize_button[del_Customize_num].Gpio = Selected_gpio;

		//没有内容直接提示+返回
		if(Customize_button[del_Customize_num].gcode.size() < 1)
		{
	    	Notify_message_list.push_back("Please add gcode");
	    	notify_open_close(true);
			return false;
		}
	}else{//新增加的GPIO
		mCustomize_WindowPtr->setVisible(false);
		Customize_buttons _cu;

		_cu.name = mname_ButtonPtr->getText();
		_cu.gcode = mgcode_ButtonPtr->getText();
		_cu.Gpio = Selected_gpio;

		//没有内容直接提示+返回
		if(_cu.gcode.size() < 1)
		{
	    	Notify_message_list.push_back("Please add gcode");
	    	notify_open_close(true);
			return false;
		}

		Customize_button.push_back(_cu);

	}
	//储存按钮数据
	save_Customize_buttons();


	mGPIO_ListViewPtr->setVisible(false);
    return false;
}
static bool onButtonClick_Button58(ZKButton *pButton) {
	mCustomize_WindowPtr->setVisible(false);
	if(del_Customize_num <= (int)Customize_button.size() - 1){
        Customize_button.erase(Customize_button.begin() + del_Customize_num);
        //刷新列表
        mCustomize_ListViewPtr->refreshListView();

	}
	//储存按钮数据
	save_Customize_buttons();

    return false;
}
static bool onButtonClick_Button60(ZKButton *pButton) {
//	addOneChar(pButton->getText()[0]);
	addOneChar('\\');
	addOneChar('n');
    return false;
}

static bool onButtonClick_Button_(ZKButton *pButton) {
	addOneChar(pButton->getText()[0]);
    return false;
}
static bool onButtonClick_Button_print_(ZKButton *pButton) {
	sContentStr += pButton->getText();
	if(mAJ1Ptr->isVisible())
		mTextView46Ptr->setText(sContentStr);
	if(mlockPtr->isVisible())
		mButton18Ptr->setText(sContentStr);
    return false;
}

static bool onButtonClick_Button61(ZKButton *pButton) {
//    LOGD(" ButtonClick Button61 !!!\n");
//
	gcode_send2("","BED_MESH_PROFILE LOAD=\\\"default\\\"");
	mCAM_BED_MESHPtr->setBackgroundPic("");
	Download_graph_mesh = true;
	mCAM_BED_MESHPtr->setVisible(true);

    return false;
}
static bool onButtonClick_Button62(ZKButton *pButton) {
//	pButton->setSelected(!pButton->isSelected());
//	if(pButton->isSelected() ){
	mCAM_BED_MESHPtr->setBackgroundPic("");
		mCAM_BED_MESHPtr->setVisible(true);
		open_cam = true;
//	}else{
//		mTextView82Ptr->setVisible(false);
//		open_cam = false;
//	}
//


    return false;
}







static bool onButtonClick_zoffset0005_Button(ZKButton *pButton) {
	zoffset_size = 0.005;
	mzoffset0005_ButtonPtr->setSelected(true);
	mzoffset001_ButtonPtr->setSelected(false);
	mzoffset0025_ButtonPtr->setSelected(false);
	mzoffset005_ButtonPtr->setSelected(false);

    return false;
}

static bool onButtonClick_zoffset001_Button(ZKButton *pButton) {
	zoffset_size = 0.01;
	mzoffset0005_ButtonPtr->setSelected(false);
	mzoffset001_ButtonPtr->setSelected(true);
	mzoffset0025_ButtonPtr->setSelected(false);
	mzoffset005_ButtonPtr->setSelected(false);
    return false;
}

static bool onButtonClick_zoffset0025_Button(ZKButton *pButton) {
	zoffset_size = 0.025;
	mzoffset0005_ButtonPtr->setSelected(false);
	mzoffset001_ButtonPtr->setSelected(false);
	mzoffset0025_ButtonPtr->setSelected(true);
	mzoffset005_ButtonPtr->setSelected(false);
    return false;
}

static bool onButtonClick_zoffset005_Button(ZKButton *pButton) {
	zoffset_size = 0.05;
	mzoffset0005_ButtonPtr->setSelected(false);
	mzoffset001_ButtonPtr->setSelected(false);
	mzoffset0025_ButtonPtr->setSelected(false);
	mzoffset005_ButtonPtr->setSelected(true);
    return false;
}
static bool onButtonClick_Z_Offset_Reverse_Button(ZKButton *pButton) {
	pButton->setSelected(!pButton->isSelected());
	if(pButton->isSelected() ){
		StoragePreferences::putBool("Z_Offset_moto_revers", true);
	}else{
		StoragePreferences::putBool("Z_Offset_moto_revers", false);
	}
    return false;
}
static int getListItemCount_ListView1(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView1 !\n");
	return sizeof(speed_info) / sizeof(Print_speed_info);
}

static void obtainListItemData_ListView1(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView1  !!!\n");

	ZKListView::ZKListSubItem* psubButton = pListItem->findSubItemByID(ID_GCODE_SubItem6);
	pListItem->setTextTr(speed_info[index].mainText);
	psubButton->setText(speed_info[index].num);
}

static void onListItemClick_ListView1(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView1  !!!\n");

	if(index != 0)
	{
		mAJPtr->setVisible(true);
		switch(index){
		case 1:
			AJ_id = 20;
			break;
		case 2:
			AJ_id = 21;
			break;
		case 3:
			AJ_id = 22;
			break;
		case 4:
			AJ_id = 23;
			break;
		case 5:
			AJ_id = 24;
			break;
		case 6:
			AJ_id = 25;
			break;
		case 7:
			AJ_id = 26;
			break;


		}


	}
}
static bool onButtonClick_speed_Button(ZKButton *pButton) {


	pButton->setSelected(!pButton->isSelected());

	if(pButton->isSelected()){
		mspeed_windowPtr->setVisible(true);
	}else
	{
		mspeed_windowPtr->setVisible(false);
	}
    return false;
}


static int getListItemCount_Host_macros_list(const ZKListView *pListView) {
    //LOGD("getListItemCount_Host_macros_list !\n");
    return Host_Macros_list.size();;
}

static void obtainListItemData_Host_macros_list(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ Host_macros_list  !!!\n");
	pListItem->setText(Host_Macros_list[index]);
}

static void onListItemClick_Host_macros_list(ZKListView *pListView, int index, int id) {
	gcode_send2("",Host_Macros_list[index]);
}



bool isGpioPresent(const std::string& targetGpio) {
    for (const auto& button : Customize_button) {
        if (button.Gpio == targetGpio) {
            return true;
        }
    }
    return false;
}

static int getListItemCount_GPIO_ListView(const ZKListView *pListView) {
    //LOGD("getListItemCount_GPIO_ListView !\n");
	return sizeof(gpio_list) / sizeof(Gpio_list);
}

static void obtainListItemData_GPIO_ListView(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ GPIO_ListView  !!!\n");


	pListItem->setTextTr(gpio_list[index].mainText.c_str());

	if(isGpioPresent(gpio_list[index].gpio) == true)
	{
		pListItem->setBackgroundColor(0xFFFF0000);//设置已被其它按钮选择的gpio为红色

		if(Customize_button[del_Customize_num].Gpio == gpio_list[index].gpio)//设置当前按钮选择的gpio为绿色
		{
			pListItem->setBackgroundColor(0xFF009789);
		}
	}else{
		pListItem->setBackgroundColor(0xFF6C6C6C);
	}


}


static void onListItemClick_GPIO_ListView(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ GPIO_ListView  !!!\n");


		//选择GPIO，关闭列表
		if(index != 0){
			//选择的这个GPIO已经被选择了，同时不是当前选项的gpio
			if(isGpioPresent(gpio_list[index].gpio) && Customize_button[del_Customize_num].Gpio != gpio_list[index].gpio)
			{
		    	Notify_message_list.push_back("GPIO has already been selected!");
		    	notify_open_close(true);
				return;
			}
		}
		Selected_gpio = gpio_list[index].gpio;
		mGPIO_ListViewPtr->setSelection(0);
		mGPIO_ListViewPtr->refreshListView();
		mGPIO_ListViewPtr->setVisible(false);

		if(Selected_gpio == "GPIO_136"){
			mgcode_Button_pinPtr->setText("PE8");
		}else if(Selected_gpio == "GPIO_138"){
			mgcode_Button_pinPtr->setText("PE10");
		}else if(Selected_gpio == "GPIO_200"){
			mgcode_Button_pinPtr->setText("PG8");
		}else if(Selected_gpio == "GPIO_201"){
			mgcode_Button_pinPtr->setText("PG9");
		}else if(Selected_gpio == "GPIO_202"){
			mgcode_Button_pinPtr->setText("PG10");
		}else if(Selected_gpio == "GPIO_203"){
			mgcode_Button_pinPtr->setText("PG11");
		}else {
			mgcode_Button_pinPtr->setTextTr("Unbound GPIO");
		}
}
static bool onButtonClick_gcode_Button_pin(ZKButton *pButton) {
//    LOGD(" ButtonClick gcode_Button_pin !!!\n");
    mGPIO_ListViewPtr->setVisible(true);
    mGPIO_ListViewPtr->refreshListView();
    return false;
}
static bool onButtonClick_Forc_Button(ZKButton *pButton) {
	pButton->setSelected(!pButton->isSelected());
    return false;
}


static bool onButtonClick_HTTP_WS_BUTTON(ZKButton *pButton) {
//    LOGD(" ButtonClick HTTP_WS_BUTTON !!!\n");
    pButton->setSelected(!pButton->isSelected());
    conn = nullptr;
	if (WS) {

		ws_closs = true;
	}

	if(pButton->isSelected()){
		StoragePreferences::putBool("Http", true);
	}else
	{
		StoragePreferences::putBool("Http", false);
	}

    return false;
}

