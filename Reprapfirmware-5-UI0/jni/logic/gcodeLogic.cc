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
#include <cmath>
#include <vector>

#include <cstring>

#include "Scan_Print.h"
#include "Print_save.h"

#include <APP/Version.h>
#include <APP/Socket.h>
#include <APP/Util.h>

#include "gcodeLogic.h"
#include "ID.h"
#include "manager/LanguageManager.h"
#include "sys/sysinfo.h"
#include "net/NetManager.h"
#include <system/Thread.h>
//#include "io/ioutil.h"
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

#include "Marlin_serial_data.h"
#include"thumbnail.h"
#include "Print_Gcode.h"


//MARLIN
extern std::vector<std::string> tempItems;
extern std::vector<std::string> xyze_pos;
extern std::string FR;
extern int cur_print_file_size;//打印文件总大小
extern int cur_file_size;//打印文件指针位置
std::string send_gcode_buff;
std::string send_gcode_buff2;

std::string print_state;//打印机状态，printing，idel，pause，cencel

//std::string print_Preheat_temp_heat;//打印预热温度


FILE* f;

bool make_RRF_big_Thumbnail = false;//大的RRF缩略图
bool make_RRF_big_Thumbnail_sure = false;//多线程里生成完成标志
bool make_RRF_print_big_Thumbnail_sure = false;//多线程里生成完成标志

bool make_big_Thumbnail = false;//大的缩略图
bool make_big_Thumbnail_sure = false;//多线程里生成完成标志

bool can_send = false;//打印状态标志

bool CA_Hotend = false;//校准喷头PID标志
bool CA_Hotbed = false;//校准热床PID标志
bool CA_mesh = false;//校准调平标志

Thumbnail thumbnail;
Scan_Print_send_commd scan_Print_send_commd;
Serial_Data_Parsing serial_Data_Parsing;
int print_time = 0;//记录打印时间
//MARLIN




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

//打印界面显示
std::string Print_Filename;
int total_layer = 0;
int current_layer = 0;

std::string Select_Filename;

bool start_scan_print_ip = false;

void gcode_send(std::string godes,bool move,bool is_Calibration,bool is_Send_directly);
//用于储存需要校准哪些项
vector<string> Calibration_term;
vector<string> Calibration_error;
bool Calibration_sw = false;
bool Calibration_Break_ok = false;
bool Calibration_send_Z_TILT = false;
bool Calibration_wait_reboot = false;
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

std::string xz_print_ip;



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
}




string currentDirectory;
string fileName;

extern vector<FileInfo> fileInfos;
//bool compare(const FileInfo& inf1, const FileInfo& inf2) {
//	return inf1.datetime > inf2.datetime;
//}
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
			fflush(fp);
			fclose(fp);
			sync();
			fp = NULL;
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
			fflush(fp);
			fclose(fp);
			sync();
			fp = NULL;
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
        || ch == ';'  || ch == '\''  || ch == '"'
        || ch == '<'  || ch == '>'  || ch == ','
        ) {
            encoded_url << ch;
        } else {
            encoded_url << '%' << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(static_cast<unsigned char>(ch));
        }
    }

    return encoded_url.str();
}

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

void Print_init(){

	print_time = 0;
	mPause_ButtonPtr->setSelected(false);
	mTextView42Ptr->setTextTr("-0");
	mTextView43Ptr->setTextTr("-0");
	mTextView3Ptr->setTextTr("0%");
	mPrint_SeekBarPtr->setProgress(0);


}

void Print_ok(){
	send_gcode_buff.clear();
	send_gcode_buff += "M104 S0\r\n";
	send_gcode_buff += "M140 S0\r\n";
	send_gcode_buff += "G28 X Y\r\n";
	send_gcode_buff += "M106 S0\r\n";
	send_gcode_buff += "M84\r\n";
	mPause_ButtonPtr->setSelected(false);
	mTextView43Ptr->setTextTr("-0");
	mTextView3Ptr->setTextTr("100%");
	mPrint_SeekBarPtr->setProgress(100);
	mTextView18Ptr->setTextTr("printok?");
	yes_no_id = 0;
	myes_no_WindowPtr->setVisible(true);
	mPrint_again_ButtonPtr->setVisible(true);

}

void Print_Preheat(){

 	f = fopen(fileName.c_str(), "r");
 	if(f == NULL) {
 		LOGD("文件打开失败");
 		return;
 	}
 	find_Preheat_temp(fileName,0);


}





//运行下一个任务文件
void run_next_task_file(bool complete){

	if(task_List.size() > 0)
	{
		//打印完成后这个任务数量减少1
		if(complete == true && start_task_List == true)
		{

			//预热下一个文件温度
			char buf[64];
			if (!task_List.empty()) {
			    std::string targetPath = task_List[0].name;
			    for (size_t index = 0; index < File_Gcodes.size(); ++index) {
			        if (File_Gcodes[index].path == targetPath) {
						snprintf(buf,sizeof(buf),"M104 S%0.1f\\nM140 S%0.1f",File_Gcodes[index].first_layer_extr_temp,File_Gcodes[index].first_layer_bed_temp);
						gcode_send(buf,false,false,false);
			            break; // 找到后退出循环
			        }
			    }
			}

			//有可能打印的时候上下移动了列表，找到这一项删除
//			if (!task_List.empty()) {
//			    std::string targetPath = current_file_information.filename.c_str();
//			    for (size_t index = 0; index < task_List.size(); ++index) {
//			        if (task_List[index].name == targetPath) {
//			        	task_List[index].Quantity --;
//			        	if(task_List[index].Quantity < 1)
//			        	{
//			        		task_List.erase(task_List.begin() + index); // 移除第x个元素
//			        	}
//			            break; // 找到后退出循环
//			        }
//			    }
//			}

			task_List[0].Quantity --;
			gcode_send("start_cd",false,false,false);
		}else{
			start_task_List = true;
		}

		//完成后检查这个任务数值是否为0，是就移除列表中这一行
		while (!task_List.empty() && task_List[0].Quantity < 1) {
		    task_List.erase(task_List.begin()); // 移除第一个元素
		}

		if(!task_List.empty() && task_List[0].Quantity >= 1 && task_List_state == true){

			std::string Gcommand = "{\"jsonrpc\": \"2.0\",\"method\": \"printer.print.start\",\"params\": { \"filename\":\"" + task_List[0].name + "\"},\"id\":" + sw_id + "}";
			gcode_send(Gcommand,false,false,true);
		}

		//刷新下列表
		mTask_ListPtr->refreshListView();
	}

}






//***********************************************************************************
//***********************************************************************************
//***********************************************************************************
//***********************************************************************************
//***********************************************************************************
//***********************************************************************************
//***********************************************************************************
//***********************************************************************************
//***********************************************************************************
//***********************************************************************************
//***********************************************************************************
//***********************************************************************************
//***********************************************************************************
//***********************************************************************************
//***********************************************************************************
//***********************************************************************************
//***********************************************************************************
//***********************************************************************************

//系统进行重启了，我们需要对所有需要重置的参数进行重置
void init_sys_reboot(){
	FR.clear();
	mlayer2_speed_buttonPtr->setText("100%");//速度设置

//风扇开关重置
	mFAN1_SW_ButtonPtr->setSelected(false);
	mFAN2_SW_ButtonPtr->setSelected(false);
	mFAN3_SW_ButtonPtr->setSelected(false);
	mFAN0_ViewPtr->setText("0%");
	mFAN1_ViewPtr->setText("0%");
	mFAN2_ViewPtr->setText("0%");
	Fan0_Speed = 0;
	Fan1_Speed = 0;
	Fan2_Speed = 0;
	mFan0_PointerPtr->setTargetAngle(0);
	mFan1_PointerPtr->setTargetAngle(0);
	mFan2_PointerPtr->setTargetAngle(0);

	z_offset = 0;
    mTextView45Ptr->setText("Z offset:");

	//界面关闭，切换到主界面
	mprintPtr->setVisible(false);
	layer_ch(1);

		Notify_message_list.push_back("sys_reboot") ;
		notify_open_close(true);
}



void Refresh_data()
{
	char buf[256];
	 if(make_RRF_big_Thumbnail_sure == true)
	 {
		 	mTextView9Ptr->setBackgroundPic("/tmp/big_Thumbnail.png");
			make_RRF_big_Thumbnail_sure = false;
	 }

	if((print_state == "printing" || print_state == "pause") && mprintPtr->isVisible() == false)
	{
		layer_ch(6);
	}

	//    因为刷新文件列表占用太大，所以我们在展开列表的时候，不进行其它状态的更新。必须更新的内容写到上面
 if(mfilePtr->isVisible() == false )
 {


	 if(make_RRF_print_big_Thumbnail_sure ){
		 make_RRF_print_big_Thumbnail_sure = false;
		 mthumbnail_pngPtr->setBackgroundPic("/tmp/big_Thumbnail_Print.png");
	 }


		if(Refresh_list_num == true)
		{
			Refresh_list_num = false;
			mNum_ListViewPtr->refreshListView();
		}


		//t0温度显示
	if(!tempItems.empty() && tempItems.size() >= 6)
	{
		//由于多线程，很可能检测的时候不为空，显示的时候就变成空的了，多次赋值检查，避免崩溃
		std::vector<std::string> TempItems = tempItems;
		if(!TempItems.empty() && TempItems.size() >= 6)
		{

			snprintf(buf,sizeof(buf),"%s",TempItems[5].c_str());
			mlyayer2_nozzle_temp_buttonPtr->setText(buf);
			snprintf(buf,sizeof(buf),"/ %s℃",TempItems[4].c_str());
			mNozzle_Temp_ViewPtr->setText(buf);
			//首页温度显示
			snprintf(buf,sizeof(buf),"%s",TempItems[4].c_str());
			mButton101Ptr->setText(buf);
			//t0温度显示

			//热床温度显示

			snprintf(buf,sizeof(buf),"%s",TempItems[3].c_str());
			mlyayer2_bed_temp_buttonPtr->setText(buf);

			snprintf(buf,sizeof(buf),"/ %s℃",TempItems[2].c_str());
			//设置温度显示
			mBed_Temp_ViewPtr->setText(buf);
			snprintf(buf,sizeof(buf),"%s",TempItems[2].c_str());
			mbed_temp_buttonPtr->setText(buf);
			//热床温度显示
		}
	}
	if(!xyze_pos.empty() )
	{
		std::vector<std::string> Xyze_pos = xyze_pos;
		if(!Xyze_pos.empty())
		{
			//xyz坐标
			snprintf(buf, sizeof(buf), "X:%s", Xyze_pos[0].c_str());
			mTextView34Ptr->setText(buf);

			snprintf(buf, sizeof(buf), "Y:%s", Xyze_pos[1].c_str());
			mTextView35Ptr->setText(buf);

			snprintf(buf, sizeof(buf), "Z:%s", Xyze_pos[2].c_str());
			mTextView36Ptr->setText(buf);
			//xyz坐标
		}
	}

		// 移动倍率
	if(!FR.empty()){
		speed_info[0].num = FR;
		mlayer2_speed_buttonPtr->setText(FR);
		mListView1Ptr->refreshListView();
	}


       //挤出倍率
//       if (gcode_move.isMember("extrude_factor")) {
//        snprintf(buf, sizeof(buf), "%d%%", gcode_move["extrude_factor"].asInt() * 100);
//      	speed_info[2].num = buf;
//      	mListView1Ptr->refreshListView();
//       }
//


	//风扇界面设置
	if(Fan0_Speed > 0){
		mFAN1_SW_ButtonPtr->setSelected(true);
	}else{
		mFAN1_SW_ButtonPtr->setSelected(false);
	}
	snprintf(buf,sizeof(buf),"%d%%",Fan0_Speed);
	mFAN0_ViewPtr->setText(buf);
	mFan0_PointerPtr->setTargetAngle(Fan0_Speed * 2.7);

	if(Fan1_Speed > 0){
		mFAN2_SW_ButtonPtr->setSelected(true);
	}else{
		mFAN2_SW_ButtonPtr->setSelected(false);
	}
	snprintf(buf,sizeof(buf),"%d%%",Fan1_Speed);
	mFAN1_ViewPtr->setText(buf);
	mFan1_PointerPtr->setTargetAngle(Fan1_Speed * 2.7);

	if(Fan2_Speed > 0){
		mFAN3_SW_ButtonPtr->setSelected(true);
	}else{
		mFAN3_SW_ButtonPtr->setSelected(false);
	}
	snprintf(buf,sizeof(buf),"%d%%",Fan2_Speed);
	mFAN2_ViewPtr->setText(buf);
	mFan2_PointerPtr->setTargetAngle(Fan2_Speed * 2.7);


	//打印文件进度+打印时间
	if(can_send == true)
	{
	    // 计算打印进度
	    double progress = (float)cur_file_size / (float)cur_print_file_size;

		if(cur_print_file_size > 0 && cur_file_size > 0){
			snprintf(buf, sizeof(buf), "%0.2f%%", progress * 100);
//			LOGD("大小a:%d,%d,%f",cur_file_size,cur_print_file_size,(float)cur_file_size / (float)cur_print_file_size);
			mTextView3Ptr->setText(buf);
			mPrint_SeekBarPtr->setProgress(static_cast<int>(progress * 100));
		}

		if(print_time > 0){
			 // 计算小时数
			 int hours = static_cast<int>((float)print_time / 3600);
			 // 计算剩余的秒数
			 int remainingSeconds = print_time % 3600;
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
			 mTextView42Ptr->setText(buf);

			 //计算剩余时间
			    // 计算总预计打印时间
			    double total_time = print_time / progress;
//			    LOGD("TIME:%f,,time:%d,%f",total_time,print_time,progress);
			    // 计算剩余打印时间
			    double remaining_time = total_time - print_time;
				 // 计算小时数
				hours = static_cast<int>(remaining_time / 3600);
				 // 计算剩余的秒数
				remainingSeconds = (int)remaining_time % 3600;
				 // 计算分钟数
				minutes = remainingSeconds / 60;

				seconds = remainingSeconds % 60;

				 if(hours > 0)
				 {
					 snprintf(buf,sizeof(buf),"-%dh %dm %ds",hours,minutes,seconds);
				 }else
				 {
					 snprintf(buf,sizeof(buf),"-%dm %ds",minutes,seconds);
				 }
				 mTextView43Ptr->setText(buf);



		}
		else{
			mTextView42Ptr->setText("-0");
		}

	}

}else{//列表在显示
 mFileListPtr->refreshListView();
}

}

void run_next_Calibration(){

	Cur_Calibration_term ++;
	mListView2Ptr->refreshListView();
	mListView2Ptr->refreshListView();
	mListView3Ptr->refreshListView();

//	LOGD("cc:%d,%d",Cur_Calibration_term,(int)Calibration_term.size());
	if(Cur_Calibration_term + 1 > (int)Calibration_term.size()){
		Calibration_sw = false;
		//最后一次运行完才保存
		if(mButton24Ptr->isSelected() == true){
			gcode_send("M500",false,false,false);//喷头PID
		}
		return;
	}
	//每次校准完保存
	if(mButton24Ptr->isSelected() == false){
		gcode_send("M500",false,false,false);//喷头PID
	}
	gcode_send(Calibration_term[Cur_Calibration_term],false,true,false);//喷头PID

}






 class Temp_Thread: public Thread {
 public:
   /**
    * 线程创建成功后会调用该函数，可以在该函数中做一些初始化操作
    * return true   继续线程
    *        false  退出线程
    */
   virtual bool readyToRun() {
     LOGD("zzzzTzzzzhread 已经创建完成");
     return true;
   }

   /**
    * 线程循环函数
    *
    * return true  继续线程循环
    *        false 推出线程
    */
   virtual bool threadLoop() {
     //LOGD("线程循环函数");

     //检查是否有退出线程的请求，如果有，则返回false，立即退出线程
     if (exitPending()) {
       return false;
     }


     Refresh_data();

	if(Preheat_sw == true){
		Preheat_sw = false;

	}




     usleep(1000 * 100);

     //返回真，继续下次线程循环
     return true;
   }
 };
 static Temp_Thread temp_thread;









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



	serial_Data_Parsing.run();
	temp_thread.run();

	//键盘长按监听
	mButton167Ptr->setLongClickListener(&longButtonClickListener);

	//开机后获取z轴是否需要翻转
	moto_revers = StoragePreferences::getBool("moto_revers", false);
	mButton_moto_reversPtr->setSelected(moto_revers);
	//开机后获取z偏移按钮z轴是否需要翻转
	zoffset_moto_revers = StoragePreferences::getBool("Z_Offset_moto_revers", false);
	mButton_moto_reversPtr->setSelected(zoffset_moto_revers);


	mmove1_ButtonPtr->setSelected(true);
	mzoffset0005_ButtonPtr->setSelected(true);//最偏移按钮初始化选中状态
	mButton20Ptr->setSelected(true);
	mtemp_move_ButtonPtr->setSelected(true);
    mms_file_buttonPtr->setSelected(true);
    mUdesk_buttonPtr->setSelected(false);
    mSd_buttonPtr->setSelected(false);

    mButton42Ptr->setSelected(true);
    mButton43Ptr->setSelected(false);
    mPrint_set_buttonPtr->setSelected(false);





	FILE *fp;
	if(!(fp=fopen("/data/print.png","rb"))==NULL)
	{
	  	mTextView6Ptr->setBackgroundPic("/data/print.png");
		fflush(fp);
		fclose(fp);
		sync();
		fp = NULL;
	}
	if(!(fp=fopen("/data/print_smail.png","rb"))==NULL)
	{
		mTextView4Ptr->setBackgroundPic("/data/print_smail.png");
		fflush(fp);
		fclose(fp);
		sync();
		fp = NULL;
	}




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

//if(WIFIMANAGER->isConnected()){
//		char buf[64];
//		mTextView27Ptr->setText(WIFIMANAGER->getConnectionInfo()->getSsid());
//		snprintf(buf,sizeof(buf),"IP:%s",WIFIMANAGER->getIp());
//		mTextView28Ptr->setText(buf);
//		snprintf(buf,sizeof(buf),"MAC:%s",WIFIMANAGER->getMacAddr());
//		mTextView30Ptr->setText(buf);
//}

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
 	Serial_data += data.str;					// 字符串连接起来

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
		//非打印模式下，每秒确定当前温度和位置
		if(can_send == false){

			UARTCONTEXT->send((const unsigned char*)"M409 K\"heat\" F\"f\"\r\n", strlen("M409 K\"heat\" F\"f\"\r\n"));
			UARTCONTEXT->send((const unsigned char*)"M409 K\"move\" F\"f\"\r\n", strlen("M409 K\"move\" F\"f\"\r\n"));
			UARTCONTEXT->send((const unsigned char*)"M409 K\"state\" F\"f\"\r\n", strlen("M409 K\"state\" F\"f\"\r\n"));
			if(print_state == "printing")
			{
				UARTCONTEXT->send((const unsigned char*)"M409 K\"job\"\r\n", strlen("M409 K\"job\"\r\n"));

			}else if(print_state == "pause")
			{
				UARTCONTEXT->send((const unsigned char*)"M17\r\n", strlen("M17\r\n"));
			}
		}else{
			print_time ++;
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

			break;
	case 1:


		break;
	case 2:

		if(make_big_Thumbnail_sure == true)
		{
			mTextView9Ptr->setBackgroundPic("/tmp/big_Thumbnail.png");
			make_big_Thumbnail_sure = false;
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
			if (mDrop_down_menuPtr->isVisible() == true && (mDrop_down_menuPtr->getPosition().isHit(ev.mX, ev.mY)) && !mCustomize_ListViewPtr->getPosition().isHit(ev.mX, ev.mY))
			{
				down_menu_close_sw = true;
				down_menu_y_Pos = ev.mY;
			}

			//右侧任务栏
			if(ev.mX >= 750 && mTask_list_WindowPtr->isVisible() == false)
			{
				Right_task_sw = true;
				Right_task_x_Pos = ev.mX;
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

			//打开右拉栏
			if(Right_task_sw == true )
			{

				if((Right_task_x_Pos - ev.mX) >= 100){
					mTask_list_WindowPtr->setVisible(true);
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
			Right_task_sw = false;
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

//	if(screen_size == 7)
//	{
//	    pos.mLeft = 964;
//	    pos.mTop = 0;
//	    pos.mWidth = 58;
//	    pos.mHeight = 44;
//	}
//	mstop_ButtonPtr->setPosition(pos);


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

//				if(screen_size == 7)
//				{
//				    pos.mLeft = 785;
//				    pos.mTop = 40;
//				    pos.mWidth = 58;
//				    pos.mHeight = 44;
//				}
//				mstop_ButtonPtr->setPosition(pos);

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


			mFile_name_TextViewPtr->setText(fileName);
			if(fileName.size() > 25)
			{
				mFile_name_TextViewPtr->setLongMode(ZKTextView::E_LONG_MODE_SCROLL);
				LOGD("开启");
			}else{
				mFile_name_TextViewPtr->setLongMode(ZKTextView::E_LONG_MODE_DOTS);
				LOGD("关闭");
			}

			mthumbnail_pngPtr->setBackgroundPic("/tmp/big_Thumbnail.png");


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
//			init_thumbnail();

			//同时初始化对象排除
//			init_exclude_obj();


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
		gcode_send("SET_LED LED=LED WHITE=0",false,false,false);
		pButton->setSelected(false);
	}
	else
	{
		gcode_send("SET_LED LED=LED WHITE=1",false,false,false);
		pButton->setSelected(true);
	}

    return false;
}

static bool onButtonClick_Button100(ZKButton *pButton) {
	if(Ethernet_mode == true)
	{

		mHost_computer_wifiPtr->setVisible(true);
	}else
	{
		EASYUICONTEXT->openActivity("WifiSettingActivity");
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
			pos.mLeft = 303;
			pos.mTop = 60;
			pos.mWidth = 372;
			pos.mHeight = 384;
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
		// 发起POST请求
		//RestClient::Response r = RestClient::post(url, "application/x-www-form-urlencoded", "");
		 gcode_send(url,false,false,false);

		break;
	}


	case 1:	{
		url = "M140 S"+ sContentStr;
		// 发起POST请求
		//RestClient::Response r = RestClient::post(url, "application/x-www-form-urlencoded", "");
		gcode_send(url,false,false,false);
		break;
	}
	case 2:	{
		url = "SET_HEATER_TEMPERATURE HEATER=warehouse TARGET="+ sContentStr;
		gcode_send(url,false,false,false);
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
		gcode_send(buf,false,false,false);
		mERCF_SERVO_DOWN_ButtonPtr->setText(sContentStr.c_str());
		break;
	}
	case 11:	{

		snprintf(buf,sizeof(buf),"MMU_SERVO ANGLE=%s",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		mERCF_SERVO_UP_ButtonPtr->setText(sContentStr.c_str());
		break;
	}
	case 12:	{

		snprintf(buf,sizeof(buf),"MMU_TEST_MOVE move=%s",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		mERCF_EX_BUTTONPtr->setText(sContentStr.c_str());
		break;
	}

	case 13:	{
		gcode_send("MMU_HOME",false,false,false);
		snprintf(buf,sizeof(buf),"MMU_CALIBRATE_GEAR LENGTH=%s MEASURED=%s",mERCF_EX_BUTTONPtr->getText().c_str(),sContentStr.c_str());
		gcode_send(buf,false,false,false);
		mERCF_EX_TRUE_BUTTONPtr->setText(sContentStr.c_str());
		break;
	}
	case 14:	{

		snprintf(buf,sizeof(buf),"MMU_CALIBRATE_BOWDEN BOWDEN_LENGTH=%s",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		mERCF_BOWDEN_CA_BUTTONPtr->setText(sContentStr.c_str());
		break;
	}

	case 20:
		snprintf(buf,sizeof(buf),"M220 S%s",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		gcode_send("M220",false,false,false);
		break;
	case 21:

		snprintf(buf,sizeof(buf),"M221 S%s",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		snprintf(buf,sizeof(buf),"%s%%",sContentStr.c_str());
		speed_info[1].num = buf;
		mListView1Ptr->refreshListView();
		break;
	case 22:
		snprintf(buf,sizeof(buf),"SET_PRESSURE_ADVANCE ADVANCE=%s",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		break;
	case 23:
		snprintf(buf,sizeof(buf),"SET_PRESSURE_ADVANCE SMOOTH_TIME=%s",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		break;
	case 24:
		snprintf(buf,sizeof(buf),"SET_VELOCITY_LIMIT VELOCITY=%s",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		break;
	case 25:
		snprintf(buf,sizeof(buf),"SET_VELOCITY_LIMIT SQUARE_CORNER_VELOCITY=%s",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		break;
	case 26:
		snprintf(buf,sizeof(buf),"SET_VELOCITY_LIMIT ACCEL=%s",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		break;

	case 30:
		snprintf(buf,sizeof(buf),"M906 %s\r\nM500\r\nM503\r\n",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		break;
	case 31:
		snprintf(buf,sizeof(buf),"M92 %s\r\nM500\r\nM503\r\n",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		break;
	case 32:
		snprintf(buf,sizeof(buf),"M203 %s\r\nM500\r\nM503\r\n",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		break;
	case 33:
		snprintf(buf,sizeof(buf),"M201 %s\r\nM500\r\nM503\r\n",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		break;
	case 34:
		snprintf(buf,sizeof(buf),"M204 %s\r\nM500\r\nM503\r\n",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		break;
	case 35:
		snprintf(buf,sizeof(buf),"M301 %s\r\nM500\r\nM503\r\n",sContentStr.c_str());
		gcode_send(buf,false,false,false);
		break;
	case 36:
		snprintf(buf,sizeof(buf),"M205 %s\r\nM500\r\nM503\r\n",sContentStr.c_str());
		gcode_send(buf,false,false,false);
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

void gcode_send(std::string godes,bool move,bool is_Calibration,bool is_Send_directly){

	if(!is_Send_directly){
		send_gcode_buff2 += godes;
		if(!strstr(godes.c_str(),"\n")){
			send_gcode_buff2 += "\r\n";
		}
	    send_gcode_buff2 += send_gcode_buff;
	    send_gcode_buff.clear();
	    send_gcode_buff += send_gcode_buff2;
	    send_gcode_buff2.clear();
	}else{
		send_gcode_buff += godes;
	}



	//设置校准列表，显示测试状态
	if(is_Calibration == true){
		Calibration_yes_no[Cur_Calibration_term] = 1;
	}

}
static bool onButtonClick_Y_D1_BUTTON(ZKButton *pButton) {
    // 设置目标URL
	gcode_send("G1 Y-1 F3500\\n",true,false,false);
    return false;
}

static bool onButtonClick_Y_D10_BUTTON(ZKButton *pButton) {
	char buf[64];
	send_gcode_buff += "G91\r\n";
	snprintf(buf,sizeof(buf),"G1 Y-%0.1f F3500\r\n",move_size);
	send_gcode_buff += buf;
	send_gcode_buff += "G90\r\n";

    return false;
}

static bool onButtonClick_Y_U10_BUTTON(ZKButton *pButton) {
	char buf[64];
	send_gcode_buff += "G91\r\n";
	snprintf(buf,sizeof(buf),"G1 Y%0.1f F3500\r\n",move_size);
	send_gcode_buff += buf;
	send_gcode_buff += "G90\r\n";
    return false;
}

static bool onButtonClick_X_U10_BUTTON(ZKButton *pButton) {
	char buf[64];
	send_gcode_buff += "G91\r\n";
	snprintf(buf,sizeof(buf),"G1 X%0.1f F3500\r\n",move_size);
	send_gcode_buff += buf;
	send_gcode_buff += "G90\r\n";

    return false;
}

static bool onButtonClick_X_D10_BUTTON(ZKButton *pButton) {
	char buf[64];
	send_gcode_buff += "G91\r\n";
	snprintf(buf,sizeof(buf),"G1 X-%0.1f F3500\r\n",move_size);
	send_gcode_buff += buf;
	send_gcode_buff += "G90\r\n";
    return false;
}
static bool onButtonClick_FAN1_SW_Button(ZKButton *pButton) {


	if(pButton->isSelected()){
		pButton->setSelected(false);
		gcode_send("M106 S0",false,false,false);
		pButton->setTextTr("off");
		Fan0_Speed = 0;
	}else
	{
		pButton->setSelected(true);
		Fan0_Speed = 100;
		gcode_send("M106 S255",false,false,false);

		pButton->setTextTr("on");

	}
    return false;
}

static bool onButtonClick_FAN2_SW_Button(ZKButton *pButton) {

	if(pButton->isSelected()){
		pButton->setSelected(false);
		gcode_send("M106 P2 S0",false,false,false);
		pButton->setTextTr("off");
		Fan1_Speed = 0;
	}else
	{
		pButton->setSelected(true);
		Fan1_Speed = 100;
		gcode_send("M106 P2 S255",false,false,false);
		pButton->setTextTr("on");

	}
    return false;
}

static bool onButtonClick_FAN3_SW_Button(ZKButton *pButton) {

	if(pButton->isSelected()){
		pButton->setSelected(false);
		gcode_send("M106 P2 S0",false,false,false);
		pButton->setTextTr("off");
		Fan2_Speed = 0;
	}else
	{
		pButton->setSelected(true);
		Fan2_Speed = 100;
		gcode_send("M106 P2 S255",false,false,false);
		pButton->setTextTr("on");

	}
    return false;
}

static bool onButtonClick_FAN1_ICON(ZKButton *pButton) {
    LOGD(" ButtonClick FAN1_ICON !!!\n");
    return false;
}

static bool onButtonClick_FAN2_ICON(ZKButton *pButton) {
    LOGD(" ButtonClick FAN2_ICON !!!\n");
    return false;
}

static bool onButtonClick_FAN3_ICON(ZKButton *pButton) {
    LOGD(" ButtonClick FAN3_ICON !!!\n");
    return false;
}

static bool onButtonClick_FAN1_UP(ZKButton *pButton) {

	Fan0_Speed += 25;
   if(Fan0_Speed >= 100)
	   Fan0_Speed = 100;

	char buf[32];
	snprintf(buf,sizeof(buf),"_M106 S%d",static_cast<int>(rint(Fan0_Speed * 255 / 100)));
	gcode_send(buf,false,false,false);
    return false;
}

static bool onButtonClick_FAN1_DOWN(ZKButton *pButton) {

	Fan0_Speed -= 25;
   if(Fan0_Speed <= 0)
	   Fan0_Speed = 0;

	char buf[32];
	snprintf(buf,sizeof(buf),"_M106 S%d",static_cast<int>(rint((Fan0_Speed + 1 )* 255 / 100)));
	gcode_send(buf,false,false,false);
    return false;
}

static bool onButtonClick_FAN2_UP(ZKButton *pButton) {
	Fan1_Speed += 25;
   if(Fan1_Speed >= 100)
	   Fan1_Speed = 100;

	char buf[32];
	snprintf(buf,sizeof(buf),"_M106 P1 S%d",static_cast<int>(rint((Fan1_Speed + 1 )* 255 / 100)));
	gcode_send(buf,false,false,false);
    return false;
}

static bool onButtonClick_FAN2_DOWN(ZKButton *pButton) {
	Fan1_Speed -= 25;
   if(Fan1_Speed <= 0)
	   Fan1_Speed = 0;

	char buf[32];
	snprintf(buf,sizeof(buf),"_M106 P1 S%d",static_cast<int>(rint((Fan1_Speed + 1 )* 255 / 100)));
	gcode_send(buf,false,false,false);
    return false;
}

static bool onButtonClick_FAN3_UP(ZKButton *pButton) {
	Fan2_Speed += 25;
   if(Fan2_Speed >= 100)
	   Fan2_Speed = 100;

   std::string url ;

	char buf[32];
	snprintf(buf,sizeof(buf),"_M106 P2 S%d",static_cast<int>(rint((Fan2_Speed + 1 )* 255 / 100)));
	gcode_send(buf,false,false,false);
    return false;
}

static bool onButtonClick_FAN3_DOWN(ZKButton *pButton) {
	Fan2_Speed -= 25;
   if(Fan2_Speed <= 0)
	   Fan2_Speed = 0;

   std::string url ;
	char buf[32];
	snprintf(buf,sizeof(buf),"_M106 P2 S%d",static_cast<int>(rint((Fan2_Speed + 1 )* 255 / 100)));
	gcode_send(buf,false,false,false);
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

    mtemp_move_ButtonPtr->setSelected(false);
    mTool_ButtonPtr->setSelected(false);
    mButton_cdPtr->setSelected(false);



	switch(layer){

	case 1:mwhmovePtr->setVisible(true);					break;
	case 2:mtoolPtr->setVisible(true);           		     break;
	case 3:
								break;
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
	send_gcode_buff += "M503\r\n";
	layer_ch(4);

    return false;
}

static bool onButtonClick_Screen_set_Button(ZKButton *pButton) {
	layer_ch(5);
    return false;
}



static bool onButtonClick_Button55(ZKButton *pButton) {
	char buf[64];
	send_gcode_buff += "G91\r\n";
	snprintf(buf,sizeof(buf),"G1 Z%0.1f F3500\r\n",move_size);
	send_gcode_buff += buf;
	send_gcode_buff += "G90\r\n";
    return false;
}

static bool onButtonClick_Button2(ZKButton *pButton) {
	char buf[64];
	send_gcode_buff += "G91\r\n";
	snprintf(buf,sizeof(buf),"G1 Z-%0.1f F3500\r\n",move_size);
	send_gcode_buff += buf;
	send_gcode_buff += "G90\r\n";
    return false;
}

static bool onButtonClick_Button56(ZKButton *pButton) {

	if(moto_revers){
		gcode_send("G1 Z1 F600\\n",true,false,false);
	}else
	{
		gcode_send("G1 Z-1 F600\\n",true,false,false);
	}


    return false;
}



static bool onButtonClick_Button66(ZKButton *pButton) {
    LOGD(" ButtonClick Button66 !!!\n");
    return false;
}

static bool onButtonClick_Button_home(ZKButton *pButton) {
    // 设置目标URL
	send_gcode_buff += "G28\r\n";
    return false;
}

static bool onButtonClick_Button68(ZKButton *pButton) {
	send_gcode_buff += "G91\r\n";
	send_gcode_buff += "G1 E-10 F600\r\n";
	send_gcode_buff += "G90\r\n";
    return false;
}

static bool onButtonClick_Button1(ZKButton *pButton) {
	send_gcode_buff += "G91\r\n";
	send_gcode_buff += "G1 E10 F600\r\n";
	send_gcode_buff += "G90\r\n";
    return false;
}

static bool onButtonClick_Button5(ZKButton *pButton) {
	mExclude_Object_windowPtr->setVisible(false);
    return false;
}

static bool onButtonClick_Button3(ZKButton *pButton) {


	send_gcode_buff +="G28 Z\r\n";

    return false;
}

static bool onButtonClick_X_U1_BUTTON(ZKButton *pButton) {
	send_gcode_buff +="G28 X\r\n";

    return false;
}

static bool onButtonClick_X_D1_BUTTON(ZKButton *pButton) {
	gcode_send("G1 X-1 F3500\\n",true,false,false);
    return false;
}

static bool onButtonClick_Y_U1_BUTTON(ZKButton *pButton) {
	send_gcode_buff +="G28 Y\r\n";


    return false;
}

static bool onButtonClick_Button82(ZKButton *pButton) {
    LOGD(" ButtonClick Button82 !!!\n");
    return false;
}


static int getListItemCount_FileList(const ZKListView *pListView) {
    //LOGD("getListItemCount_FileList !\n");

		return (int)fileInfos.size();

}

static void obtainListItemData_FileList(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
//    LOGD(" obtainListItemData_ FileList  !!!\n");

		   static const char* backgroundPics[] = {	"home.png", "up.png", "folder.png", "file.png", "file.png"};
		   static FileType File_Type = E_FILETYPE_FILE;

		   FileInfo fi = fileInfos[index];

		   pListItem->setText(fi.fileName);//设置文件名字

		 if(fi.fileType == File_Type)
		 {
			string img_path = "/tmp/" + fi.fileName + ".png";
			if(access(img_path.c_str(), F_OK) == 0){//有缩略图
				pListItem->setBackgroundPic(img_path.c_str());//设置背景图
			}else{//没有缩略图
				pListItem->setBackgroundPic("file.png");//设置背景图
			}

		 }else{
			pListItem->setBackgroundPic(backgroundPics[fi.fileType]);//设置背景图
		 }



}




static void onListItemClick_FileList(ZKListView *pListView, int index, int id) {

		FileInfo fi = fileInfos[index];
		switch (fi.fileType) {
		//case E_FILETYPE_HOME:
		//	pListView->setVisible(false);
		//	mMainMenuPtr->setVisible(true);
		//	break;

	//	case E_FILETYPE_BACK:
	//		listFiles(acurrentDirectory, "..");
	//		break;

		case E_FILETYPE_FOLDER:
			if(mBoard_SD_ButtonPtr->isSelected() == false){
				listFiles(currentDirectory, fi.fileName,false);
			}else{
				fileInfos.clear();
				currentDirectory += fi.fileName + "/";
				gcode_send("M20 S2 P0:/gcodes/" + currentDirectory,false,false,false);

			}

			break;

		case E_FILETYPE_FILE:
			mTextView9Ptr->setBackgroundPic("");//清空缩略图显示
			mTextView2Ptr->setText(fi.fileName);//设置文件名称
			mprint_surePtr->showWnd();
			fileName = currentDirectory + fi.fileName;
			LOGD("NAME:%s",fileName.c_str());

			//屏幕SD卡/u盘
			if(mBoard_SD_ButtonPtr->isSelected() == false){

				make_big_Thumbnail = true;
				FILE* fn;
			 	fn = fopen(fileName.c_str(), "r");
			 	if(fn == NULL) {

			 		LOGD("文件打开失败");
			 	}
			 	LOGD("文件打开成功");
				fflush(fn);
				fclose(fn);
				sync();
				fn = NULL;

			}else{
				LOGD("AAACCC");
				make_RRF_big_Thumbnail = true;
				send_gcode_buff += "M36 ";
				send_gcode_buff += fileName;
				send_gcode_buff += "\r\n";
				Send_serial_commands();

			}

			break;

		default:
			break;
		}


}

static bool onButtonClick_Button4(ZKButton *pButton) {
	mFileListPtr->setVisible(true);
	mprint_surePtr->setVisible(false);
    return false;
}

static bool onButtonClick_Button7(ZKButton *pButton) {

 	f = fopen(fileName.c_str(), "r");
 	if(f == NULL) {

 		LOGD("文件打开失败");
 		return false;
 	}
 	Print_init();
 	printGCode(fileName,0);

 	mprint_surePtr->setVisible(false);//关闭预览界面
 	layer_ch(6);


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
	//屏幕SD卡/u盘
	if(mBoard_SD_ButtonPtr->isSelected() == false){
		listFiles("/mnt", "extsd",false);
		thumbnail.run();
	}else{
		currentDirectory.clear();
		gcode_send("M20 S2 P0:/gcodes",false,false,false);
	}




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

	}
	else
	{

		temp_layer_ch(2);
		set_aj_layer();
		AJ_id = 2;
	}
    return false;
}
static bool onButtonClick_layer2_speed_button(ZKButton *pButton) {

	if(pButton->isSelected()){

		pButton->setSelected(false);
		mAJPtr->setVisible(false);

	}else{
		pButton->setSelected(true);
		mAJPtr->setVisible(true);
		AJ_id = 20;
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
			gcode_send("M220 S75",false,false,false);
			mlayer2_speed_buttonPtr->setTextTr("Quiet");

	break;

	case 1:	mButton9Ptr->setSelected(false);
			gcode_send("M220 S100",false,false,false);
			mlayer2_speed_buttonPtr->setTextTr("Normal");

	break;

	case 2:	mButton10Ptr->setSelected(true);
			gcode_send("M220 S150",false,false,false);
			mlayer2_speed_buttonPtr->setTextTr("Sport");

	break;

	case 3:	mButton11Ptr->setSelected(true);
			gcode_send("M220 S200",false,false,false);
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
	if(mms_file_buttonPtr->isSelected())
		listFiles("/mnt", "extsd",false);
	else{
		listFiles("/mnt", "usb1",false);
	}
		thumbnail.run();

		 mFileListPtr->refreshListView();
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


       pButton->setSelected(!pButton->isSelected());


		if(pButton->isSelected()){
			 send_gcode_buff2.clear();;
			 send_gcode_buff2 += send_gcode_buff;
			 send_gcode_buff.clear();
			 send_gcode_buff += "M25\r\n";
			 send_gcode_buff += send_gcode_buff2;
			 send_gcode_buff2.clear();
		}else
		{
			send_gcode_buff += "M24\r\n";
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
	mPrint_again_ButtonPtr->setVisible(false);
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
			can_send = false;
			if(f){//检查文件指针有没有关闭
				fflush(f);
				fclose(f);
				sync();
				f = NULL;
			}
				mprintPtr->setVisible(false);
				mPrint_again_ButtonPtr->setVisible(false);
				mthumbnail_pngPtr->setBackgroundPic("");
				layer_ch(1);
				//检测有没有打印完，打印完就不执行归位动作
				if(mPrint_SeekBarPtr->getProgress() < 100){
					send_gcode_buff.clear();
					send_gcode_buff += "M104 S0\r\n";
					send_gcode_buff += "M140 S0\r\n";
					send_gcode_buff += "G28 X Y\r\n";
					send_gcode_buff += "M106 S0\r\n";
					send_gcode_buff += "M84\r\n";
				}

				break;
	case 1:	{
			excluded_objects_button_cancel(exclude_object_id);
			gcode_send("EXCLUDE_OBJECT NAME=" + exclude_object[exclude_object_id].name,false,false,false);
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
				if (WS) {
					ws_closs = true;
				}
			}
			break;
	case 6:
			snprintf(buf,sizeof(buf),"MMU_CALIBRATE_SELECTOR GATE=%d",ERCF_GATE);
			gcode_send(buf,false,false,false);
			gcode_send("MMU_MOTORS_OFF",false,false,false);
			break;
	case 7:
			snprintf(buf,sizeof(buf),"MMU_HOME TOOL=%d",ERCF_GATE);
			gcode_send(buf,false,false,false);
			break;
	case 8:
			snprintf(buf,sizeof(buf),"T%d",ERCF_GATE);
			gcode_send(buf,false,false,false);
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
		    remove(fileName.c_str()) ;
			mprint_surePtr->setVisible(false);
			mFileListPtr->setVisible(true);
			listFiles("/mnt", "extsd",false);
		}
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



		pListItem->setBackgroundPic("");
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
	if(mButton42Ptr->isSelected() == true){
		//切换机器后关闭打印界面，以便其它机器初始化，打印界面
		mprintPtr->setVisible(false);
		snprintf(buf,sizeof(buf),"%s",Print_info[index].ip.c_str() + 7);
		master_print_ip = buf;
		StoragePreferences::putString("print_ip", master_print_ip);
		mButton22Ptr->setText(master_print_ip);
		//因为不能强行关闭，在同一线程里关闭连接
		if (WS) {
			ws_closs = true;
		}

		//如果这个ip在从机地址集合中，我们就删除这个ip
	    auto it = std::find(Slave_Print_ip.begin(), Slave_Print_ip.end(), master_print_ip); // 查找字符串在vector中的位置

	    if (it != Slave_Print_ip.end()) { // 确保找到了字符串
	        Slave_Print_ip.erase(it); // 删除找到的元素
	    }

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
		Command = "M303 E0 C8 S" + Pid_ext_temp;
		Calibration_term.push_back(Command)	;
	}
	if(mButton75Ptr->isSelected() == false)
	{
		Command = "M303 E-1 C8 S" + Pid_bed_temp;
		Calibration_term.push_back(Command)	;
	}
//	if(mButton79Ptr->isSelected() == false)
//	{
//		Command = "SHAPER_CALIBRATE";
//		Calibration_term.push_back(Command)	;
//	}
	if(mButton76Ptr->isSelected() == false)
	{
		Command = "G28\r\nG29\r\n";
		Calibration_term.push_back(Command)	;
	}
//	if(mButton77Ptr->isSelected() == false)
//	{
//		Command = "QUAD_GANTRY_LEVEL";
//		Calibration_term.push_back(Command)	;
//	}
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
	gcode_send(Calibration_term[0],false,true,false);//喷头PID
    return false;
}

static int getListItemCount_ListView2(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView2 !\n");
    return Calibration_term.size();
}

static void obtainListItemData_ListView2(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView2  !!!\n");
	 ZKListView::ZKListSubItem* icon = pListItem->findSubItemByID(ID_GCODE_SubItem3);

	if(strstr(Calibration_term[index].c_str(),"M303 E0")){
		 pListItem->setTextTr("Calibrate nozzle heating");
	}else if(strstr(Calibration_term[index].c_str(),"M303 E-1")){
		 pListItem->setTextTr("Calibrate bed heating");
	}else if(strstr(Calibration_term[index].c_str(),"SHAPER_CALIBRATE")){
		 pListItem->setTextTr("Calibrate resonance frequency");
	}else if(strstr(Calibration_term[index].c_str(),"G29")){
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

	New_Sw_id();
	godes = "{\"jsonrpc\": \"2.0\",\"method\": \"printer.firmware_restart\",\"id\":" + sw_id + "}";
	gcode_send(godes,false,false,true);

	New_Sw_id();
	godes = "{\"jsonrpc\": \"2.0\",\"method\": \"printer.restart\",\"id\":" + sw_id + "}";
	gcode_send(godes,false,false,true);
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
		 pListItem->setTextColor(0x000000);
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
	//mAJPtr->setVisible(false);


    // 设置目标URL
    std::string url ;//= "http://" + print_ip + "/printer/gcode/script?script=";

//char buf[64];

	switch(AJ_id){

	case 0:gcode_send(sContentStr,false,false,false);

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
	if(zoffset_moto_revers){
		z_offset -= zoffset_size;
	}else
	{
		z_offset += zoffset_size;
	}
    snprintf(buf,sizeof(buf),"%.3f",zoffset_size);
    send_gcode_buff2 += "M290 Z";
    send_gcode_buff2 += buf;
    send_gcode_buff2 += "\r\nM500\r\n";

    send_gcode_buff2 += send_gcode_buff;
    send_gcode_buff.clear();
    send_gcode_buff += send_gcode_buff2;
    send_gcode_buff2.clear();

    snprintf(buf,sizeof(buf),"Z offset:%.3f",z_offset);
    mTextView45Ptr->setText(buf);
    return false;
}

static bool onButtonClick_Zoffset_Down_button(ZKButton *pButton) {
	char buf[64];
	if(zoffset_moto_revers){
		z_offset -= zoffset_size;
	}else
	{
		z_offset += zoffset_size;
	}

    snprintf(buf,sizeof(buf),"%.2f",zoffset_size);
    send_gcode_buff2 += "M290 Z";
    send_gcode_buff2 += buf;
    send_gcode_buff2 += "\r\nM500\r\n";

    send_gcode_buff2 += send_gcode_buff;
    send_gcode_buff.clear();
    send_gcode_buff += send_gcode_buff2;
    send_gcode_buff2.clear();

    snprintf(buf,sizeof(buf),"Z offset:%.3f",z_offset);
    mTextView45Ptr->setText(buf);
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
	gcode_send("MMU_TEST_MOVE MOVE=10 SPEED=50",false,false,false);
    return false;
}

static bool onButtonClick_ERCF_E(ZKButton *pButton) {

	gcode_send("MMU_TEST_MOVE MOVE=-10 SPEED=50",false,false,false);
    return false;
}

static bool onButtonClick_ERCF_MOTOR_OFF(ZKButton *pButton) {
    gcode_send("MMU_MOTORS_OFF",false,false,false);
    return false;
}

static bool onButtonClick_ERCF_HOME(ZKButton *pButton) {
	gcode_send("MMU_HOME",false,false,false);
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
	gcode_send("MMU_CALIBRATE_SELECTOR",false,false,false);
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
	gcode_send("MMU_MOTORS_OFF",false,false,false);

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

	gcode_send("MMU_CALIBRATE_ENCODER",false,false,false);
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
	gcode_send("MMU_MOTORS_OFF",false,false,false);
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

	if(strstr(Notify_message_list[index].c_str(),"Unknown command:"))
	{
		pListItem->setText(Notify_message_list[index].c_str());
	}else{
		pListItem->setTextTr(Notify_message_list[index].c_str());
	}




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
	thumbnail.run();
	mFileListPtr->refreshListView();
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
	listFiles("/mnt", "extsd",false);
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

	Print_Preheat();
	mprint_surePtr->setVisible(false);
    return false;
}

static bool onButtonClick_Button_Del(ZKButton *pButton) {
	mTextView18Ptr->setTextTr("Confirm file deletion?");
	yes_no_id = 10;
	myes_no_WindowPtr->setVisible(true);
    return false;
}

static bool onButtonClick_Button_unlock(ZKButton *pButton) {
	send_gcode_buff +="M84\r\n";

    return false;
}

static bool onButtonClick_Button_moto_revers(ZKButton *pButton) {
	pButton->setSelected(!pButton->isSelected());
	if(pButton->isSelected() ){
		StoragePreferences::putBool("moto_revers", true);
		moto_revers = true;
	}else{
		StoragePreferences::putBool("moto_revers", false);
		moto_revers = false;
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
    LOGD(" ButtonClick stop_Button !!!\n");
    New_Sw_id();
    string godes;
	godes = "{\"jsonrpc\": \"2.0\",\"method\": \"printer.emergency_stop\",\"id\":" + sw_id + "}";
	if(WS)
	{
		WS->send(godes);
	}else
	{
    	Notify_message_list.push_back("Please connect the print");
    	notify_open_close(true);
	}

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
		pListItem->setBackgroundPic("layer4/print_add.png");
//		pListItem->setBackgroundColor(0xFFE5E5E5);
	}else{
		pListItem->setText(Customize_button[index].name);
		pListItem->setBackgroundPic("");
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
	if(index == (int)Customize_button.size() )
	{
		mname_ButtonPtr->setText("");
		mgcode_ButtonPtr->setText("");
		mCustomize_WindowPtr->setVisible(true);

	}else{
		//打开设置了
		if(mCustomize_ButtonPtr->isSelected())
		{
			mname_ButtonPtr->setText(Customize_button[index].name);
			mgcode_ButtonPtr->setText(Customize_button[index].gcode);
			mCustomize_WindowPtr->setVisible(true);
		}else{//发送gcode


			gcode_send(Customize_button[index].gcode,false,false,false);
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

		//没有内容直接提示+返回
		if(Customize_button[del_Customize_num].gcode.size() < 1)
		{
	    	Notify_message_list.push_back("Please add gcode");
	    	notify_open_close(true);
			return false;
		}
	}else{
		mCustomize_WindowPtr->setVisible(false);
		Customize_buttons _cu;

		_cu.name = mname_ButtonPtr->getText();
		_cu.gcode = mgcode_ButtonPtr->getText();

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
	gcode_send("BED_MESH_PROFILE LOAD=\\\"default\\\"",false,false,false);
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



void save_ip_buttons(){
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
        array.append(sub);

    }
    root["Customize_buttons"] = array;
    LOGD("root: %s", root.toStyledString().c_str());
    StoragePreferences::putString("Customize_buttons", root.toStyledString());
    //刷新列表
    mCustomize_ListViewPtr->refreshListView();

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
		zoffset_moto_revers = true;
	}else{
		StoragePreferences::putBool("Z_Offset_moto_revers", false);
		zoffset_moto_revers = false;
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
	pListItem->setText(speed_info[index].mainText);
	psubButton->setText(speed_info[index].num);
}

static void onListItemClick_ListView1(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView1  !!!\n");

//	if(index != 0)
//	{

		mAJPtr->setVisible(true);
		switch(index){
		case 0:
			AJ_id = 20;
			break;
		case 1:
			AJ_id = 21;
			break;
		case 2:
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

//
//		}


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
static bool onButtonClick_move10_Button(ZKButton *pButton) {
	move_size = 10;
	mmove01_ButtonPtr->setSelected(false);
	mmove1_ButtonPtr->setSelected(false);
	mmove10_ButtonPtr->setSelected(true);
	mmove100_ButtonPtr->setSelected(false);
    return false;
}

static bool onButtonClick_move01_Button(ZKButton *pButton) {
	move_size = 0.1;
	mmove01_ButtonPtr->setSelected(true);
	mmove1_ButtonPtr->setSelected(false);
	mmove10_ButtonPtr->setSelected(false);
	mmove100_ButtonPtr->setSelected(false);
    return false;
}

static bool onButtonClick_move1_Button(ZKButton *pButton) {
	move_size = 1;
	mmove01_ButtonPtr->setSelected(false);
	mmove1_ButtonPtr->setSelected(true);
	mmove10_ButtonPtr->setSelected(false);
	mmove100_ButtonPtr->setSelected(false);
    return false;
}

static bool onButtonClick_move100_Button(ZKButton *pButton) {
	move_size = 100;
	mmove01_ButtonPtr->setSelected(false);
	mmove1_ButtonPtr->setSelected(false);
	mmove10_ButtonPtr->setSelected(false);
	mmove100_ButtonPtr->setSelected(true);
    return false;
}


static bool onButtonClick_Button_td(ZKButton *pButton) {
	gcode_send("start_t",false,false,false);

    return false;
}

static bool onButtonClick_Button_cl(ZKButton *pButton) {
	gcode_send("start_c",false,false,false);

    return false;
}
static bool onButtonClick_Button_add_list(ZKButton *pButton) {
	string path;

	task_List_state = true;

	//如果有进入子文件夹
	if(!cur_file_dir.empty())
	{
		path = cur_file_dir.substr(1, cur_file_dir.size() -1);//移除第一个//
		path += "/";
	}
	path = path + current_file_information.filename;





    // 在task_List中查找匹配的name
    bool found = false;
    for (Task_List& task : task_List) {
        if (task.name == path) {
            task.Quantity++; // 如果找到了匹配的name，增加其Quantity
            found = true;

            break;
        }
    }

    // 如果没有找到匹配的name，则创建新的Task_List对象并添加到vector中
    if (!found) {
        task_List.push_back({path, 1}); // 注意这里使用了初始化列表来构造新的Task_List
    }

    //第一次添加直接打印
	if(task_List.size() == 1 && start_task_List == false &&
			current_file_information.state != "printing" && current_file_information.state != "paused")
	{
		run_next_task_file(false);
	}


	mTask_ListPtr->refreshListView();
    return false;
}

static int getListItemCount_Task_List(const ZKListView *pListView) {
    //LOGD("getListItemCount_Task_List !\n");
    return task_List.size() + 1;
}

static void obtainListItemData_Task_List(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ Task_List  !!!\n");
	ZKListView::ZKListSubItem* num = pListItem->findSubItemByID(ID_GCODE_Task_List_num);
	ZKListView::ZKListSubItem* icon = pListItem->findSubItemByID(ID_GCODE_Task_List_icon);
	ZKListView::ZKListSubItem* state = pListItem->findSubItemByID(ID_GCODE_Task_List_state);
	ZKListView::ZKListSubItem* del = pListItem->findSubItemByID(ID_GCODE_Task_List_del);
	ZKListView::ZKListSubItem* up = pListItem->findSubItemByID(ID_GCODE_Task_List_up);
	ZKListView::ZKListSubItem* down = pListItem->findSubItemByID(ID_GCODE_Task_List_down);
	ZKListView::ZKListSubItem* add = pListItem->findSubItemByID(ID_GCODE_Task_List_add);
	ZKListView::ZKListSubItem* dec = pListItem->findSubItemByID(ID_GCODE_Task_List_dec);





	string save_path = Save_Path + task_List[index - 1].name + ".png";
	//第一个我们只显示暂停队列
	if(index == 0){
		up->setVisible(false);
		down->setVisible(false);
		add->setVisible(false);
		dec->setVisible(false);
		num->setVisible(false);
		icon->setVisible(false);
		del->setVisible(false);

		state->setVisible(true);
		state->setSelected(task_List_state);
		if(task_List_state){
			state->setText("状态: 运行中");
		}else{
			state->setText("状态: 暂停中");
		}
		pListItem->setText("");//当前文件名称/路径
	}else{
//		pListItem->setVisible(true);
		up->setVisible(true);
		down->setVisible(true);
		add->setVisible(true);
		dec->setVisible(true);
		num->setVisible(true);
		icon->setVisible(true);
		del->setVisible(true);
		state->setVisible(false);
		pListItem->setText(task_List[index - 1].name);//当前文件名称/路径
		num->setText(task_List[index - 1].Quantity);//当前任务数量
		icon->setBackgroundPic(save_path.c_str());
	}
}

static void onListItemClick_Task_List(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ Task_List  !!!\n");
	if(index == 0){

		task_List_state = !task_List_state;
		if(task_List_state &&
				current_file_information.state != "printing" && current_file_information.state != "paused"){
			run_next_task_file(false);
		}

	}else{
		index = index - 1;//第一个idex给了状态显示
		//增加任务数量
		if(id == ID_GCODE_Task_List_add)
		{
			task_List[index].Quantity ++;
		}else if(id == ID_GCODE_Task_List_dec)//减少任务数量
		{
			task_List[index].Quantity --;
		}else if( id == ID_GCODE_Task_List_del)//删除任务
		{

		     auto it = task_List.begin() + index; // 获取第三个元素的迭代器

		     if (it != task_List.end()) { 	// 确保迭代器有效
		        task_List.erase(it); 		// 删除第三个元素
		     }
		       mTask_ListPtr->setSelection(index - 1);

		}else if( id == ID_GCODE_Task_List_up && index > 0)
		{
		    std::iter_swap(task_List.begin() + index - 1, task_List.begin() + index); // 交换元素

		}else if( id == ID_GCODE_Task_List_down && (index+1) < (int)task_List.size() )
		{
		    std::iter_swap(task_List.begin() + index , task_List.begin() + index + 1); // 交换元素
		}

	}




	pListView->refreshListView();
}
static bool onButtonClick_Button_cd(ZKButton *pButton) {
	tool_layer_ch(3);
	pButton->setSelected(!pButton->isSelected());
    return false;
}
static int getListItemCount_Num_ListView(const ZKListView *pListView) {
    //LOGD("getListItemCount_Num_ListView !\n");

	switch(set_list_num){
	case 0:return Driver_current.size();
	case 1:return Plus.size();
	case 2:return Max_feed.size();
	case 3:return Max_Acc.size();
	case 4:return Acceleration.size();
	case 5:return Hotend_PID.size();
	case 6:return Advanced.size();
	}
	return 0;
}

static void obtainListItemData_Num_ListView(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ Num_ListView  !!!\n");
	switch(set_list_num){
	case 0: pListItem->setText(Driver_current[index]);break;
	case 1: pListItem->setText(Plus[index]);break;
	case 2: pListItem->setText(Max_feed[index]);break;
	case 3: pListItem->setText(Max_Acc[index]);break;
	case 4: pListItem->setText(Acceleration[index]);break;
	case 5: pListItem->setText(Hotend_PID[index]);break;
	case 6: pListItem->setText(Advanced[index]);break;
	}
}

static void onListItemClick_Num_ListView(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ Num_ListView  !!!\n");
	switch(set_list_num){
	case 0: AJ_id = 30; sContentStr = Driver_current[index][0];	break;
	case 1: AJ_id = 31; sContentStr = Plus[index][0];	break;
	case 2: AJ_id = 32; sContentStr = Max_feed[index][0];	break;
	case 3: AJ_id = 33; sContentStr = Max_Acc[index][0];	break;
	case 4: AJ_id = 34; sContentStr = Acceleration[index][0];	break;
	case 5: AJ_id = 35; sContentStr = Hotend_PID[index][0];	break;
	case 6: AJ_id = 36; sContentStr = Advanced[index][0];	break;
	}
	set_aj_layer();



}

static int getListItemCount_Set_ListView(const ZKListView *pListView) {
    //LOGD("getListItemCount_Set_ListView !\n");
    return sizeof(set_list)/ sizeof(Print_set_list);
}

static void obtainListItemData_Set_ListView(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ Set_ListView  !!!\n");
	pListItem->setText(set_list[index].mainText);
	if(index == set_list_num){
		pListItem->setSelected(true);
	}else
	{
		pListItem->setSelected(false);
	}


}

static void onListItemClick_Set_ListView(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ Set_ListView  !!!\n");
	set_list_num = index;
	mNum_ListViewPtr->refreshListView();
}
static bool onButtonClick_Print_again_Button(ZKButton *pButton) {
	myes_no_WindowPtr->setVisible(false);
	mPrint_again_ButtonPtr->setVisible(false);

 	f = fopen(fileName.c_str(), "r");
 	if(f == NULL) {
 		LOGD("文件打开失败");
 		return false;
 	}

 	printGCode(fileName,0);
 	layer_ch(6);

    return false;
}
static bool onButtonClick_Board_SD_Button(ZKButton *pButton) {
	currentDirectory.clear();
	gcode_send("M20 S2 P0:/gcodes",false,false,false);
	mBoard_SD_ButtonPtr->setSelected(true);
    mms_file_buttonPtr->setSelected(false);
    mUdesk_buttonPtr->setSelected(false);
    mSd_buttonPtr->setSelected(false);
    mFileListPtr->refreshListView();
    return false;
}
