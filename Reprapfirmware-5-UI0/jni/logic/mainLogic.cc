#pragma once
#include "uart/ProtocolSender.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <png.h>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <cctype>
#include <cmath>
#include <string.h>

#include <dirent.h>
#include <sys/stat.h>

#include "mainLogic.h"
#include"thumbnail.h"
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

//
//// Base64 解码表
//static const unsigned char base64_table[65] =
//    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
//
//// 查找 Base64 字符在表中的索引
//inline unsigned char base64_char_index(char c) {
//    const char *pos = strchr((const char *)base64_table, c);
//    if (pos == nullptr) return 255;
//    return pos - (const char *)base64_table;
//}
//
//// Base64 解码函数
//std::vector<unsigned char> base64_decode(const std::string &encoded_string) {
//    size_t in_len = encoded_string.size();
//    if (in_len % 4 != 0) throw std::runtime_error("Invalid base64 input length.");
//
//    size_t out_len = (in_len / 4) * 3;
//    if (encoded_string[in_len - 1] == '=') out_len--;
//    if (encoded_string[in_len - 2] == '=') out_len--;
//
//    std::vector<unsigned char> decoded_data(out_len);
//    size_t j = 0;
//    for (size_t i = 0; i < in_len;) {
//        unsigned char a = base64_char_index(encoded_string[i++]);
//        unsigned char b = base64_char_index(encoded_string[i++]);
//        unsigned char c = base64_char_index(encoded_string[i++]);
//        unsigned char d = base64_char_index(encoded_string[i++]);
//
//        decoded_data[j++] = (a << 2) | (b >> 4);
//        if (j < out_len) decoded_data[j++] = (b << 4) | (c >> 2);
//        if (j < out_len) decoded_data[j++] = (c << 6) | d;
//    }
//
//    return decoded_data;
//}
//
//
//// 保存数据到文本文件
//void save_data_to_text_file(const std::vector<unsigned char> &data, const std::string &file_path) {
//    std::ofstream file(file_path.c_str(), std::ios::out | std::ios::binary);
//    if (!file) {
//        throw std::runtime_error("Failed to open file for writing data.");
//    }
//    file.write(reinterpret_cast<const char *>(&data[0]), data.size());
//     file.close();
//}
//
//// 读取文件并提取 Base64 数据
//std::string extract_base64_data(const std::string &file_path) {
//    FILE *f = fopen(file_path.c_str(), "r");
//    if (!f) throw std::runtime_error("Failed to open file.");
//
//    char buf[1024];
//    char *rslt = NULL;
//    std::string base64_data;
//    bool in_thumbnail = false;
//
//    while ((rslt = fgets(buf, sizeof(buf), f)) != NULL) {
////    	LOGD(":%c",*rslt);
//
//        std::string line(buf);
//        if (line.find("; thumbnail begin") != std::string::npos) {
//            in_thumbnail = true;
//        } else if (line.find("; thumbnail end") != std::string::npos) {
//            in_thumbnail = false;
//        } else if (in_thumbnail) {
//            if (line.size() > 2 && line[0] == ';' && line[1] == ' ') {
//                base64_data += line.substr(2);
//                LOGD(":%s",line.substr(2).c_str());
//            }
//        }
//    }
//
//    fclose(f);
//
//    // 清理Base64数据，去除无效字符
//    base64_data.erase(std::remove_if(base64_data.begin(), base64_data.end(), [](char c) {
//        return !isalnum(c) && c != '+' && c != '/' && c != '=';
//    }), base64_data.end());
//
//    return base64_data;
//}
//
//



//FILE* f;
//FILE* fn;//屏幕预览直针
//string currfile_name;
//
//
//Thumbnail thumbnail;
//
//
//string acurrentDirectory;
//string afileName;


// 列出TF卡中的文件夹
// void listFiles(string folder, string subFolder) {
// 	// /mnt/extsd就是顶级目录
//
// 	if((folder == "/mnt") && (subFolder == ".."))
// 		return;
//
// 	fileInfos.clear();
// //	fileInfos.push_back({"返回主目录", E_FILETYPE_HOME});
// //	fileInfos.push_back({"返回上级目录", E_FILETYPE_BACK});
//
// 	if(subFolder == "..") {			// 上一级目录
// 		for(int len = folder.length(); len > 0; len --) {
// 			if(folder[len - 1] == '/') {
// 				acurrentDirectory = folder.substr(0, len);
// 				//LOGD("%d",len);
// 				break;
// 		}
// 		}
// 	} else {
// 		acurrentDirectory = folder + "/" + subFolder;
// 	}
//
//     DIR *d;
//     struct dirent *file;
//     if(!(d = opendir(acurrentDirectory.c_str())))  {
//         LOGE("无法打开目录 %s!!!\n",acurrentDirectory.c_str());
// 		mLVFolderPtr->refreshListView();
//         return;
//     }
//
////     while((file = readdir(d)) != NULL) {
////         if(strncmp(file->d_name, ".", 1) == 0)
////             continue;
////
////         if(file->d_type == DT_REG )
////         	fileInfos.push_back({file->d_name, E_FILETYPE_FILE});
////         else if(file->d_type == DT_DIR)
////         	fileInfos.push_back({file->d_name, E_FILETYPE_FOLDER});
////     }
//
//     while ((file = readdir(d)) != NULL) {
//     		if (strncmp(file->d_name, ".", 1) == 0)
//     			continue;
//
//     		struct stat file_stat;
//     		stat((acurrentDirectory + "/" + file->d_name).c_str(), &file_stat);
//
//     		if (file->d_type == DT_REG) {
//     			if((strstr(file->d_name, "gcode")||(strstr(file->d_name, "fly"))) != NULL) {
//     				FileInfo inf = { file->d_name, E_FILETYPE_FILE, file_stat.st_mtime };
//     				fileInfos.push_back(inf);
//     			}
//     		} else if (file->d_type == DT_DIR) {
//     			FileInfo inf = { file->d_name, E_FILETYPE_FOLDER, file_stat.st_mtime };
//     			fileInfos.push_back( inf);
//     		}
//     	}
//     	closedir(d);
//
//     	std::stable_sort(fileInfos.begin() + 2, fileInfos.end(), compare);
//     	mLVFolderPtr->refreshListView();
//
// }







/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	//{0,  6000}, //定时器id=0, 时间间隔6秒
	//{1,  1000},
};

/**
 * 当界面构造时触发
 */
static void onUI_init(){
    //Tips :添加 UI初始化的显示代码到这里,如:mText1Ptr->setText("123");
//	listFiles("/mnt", "extsd/");
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
static void onProtocolDataUpdate(const SProtocolData &data) {

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
static bool onUI_Timer(int id){
	switch (id) {

		default:
			break;
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
static bool onmainActivityTouchEvent(const MotionEvent &ev) {
    switch (ev.mActionStatus) {
		case MotionEvent::E_ACTION_DOWN://触摸按下
			//LOGD("时刻 = %ld 坐标  x = %d, y = %d", ev.mEventTime, ev.mX, ev.mY);
			break;
		case MotionEvent::E_ACTION_MOVE://触摸滑动
			break;
		case MotionEvent::E_ACTION_UP:  //触摸抬起
			break;
		default:
			break;
	}
	return false;
}
static bool onButtonClick_Button1(ZKButton *pButton) {

//        std::string file_path = "/mnt/extsd/input.txt";
//        std::string base64_data = extract_base64_data(file_path);
//        std::vector<unsigned char> png_data = base64_decode(base64_data);
//        save_data_to_text_file(png_data, "/mnt/extsd/png_data.txt");
//	listFiles("/mnt", "extsd");
//	thumbnail.run();
    return false;
}


static int getListItemCount_LVFolder(const ZKListView *pListView) {
    //LOGD("getListItemCount_LVFolder !\n");

    return fileInfos.size();

}

static void obtainListItemData_LVFolder(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {

//	   static const char* backgroundPics[] = {	"home.png", "up.png", "folder.png", "file.png", "file.png"};
//	   static FileType File_Type = E_FILETYPE_FILE;
//
//	   FileInfo fi = fileInfos[index];
//
//	   pListItem->setText(fi.fileName);//设置文件名字
//
//	 if(fi.fileType == File_Type)
//	 {
//		string img_path = "/tmp/" + fi.fileName + ".png";
//		pListItem->setBackgroundPic(img_path.c_str());//设置背景图
//	 }else{
//		pListItem->setBackgroundPic(backgroundPics[fi.fileType]);//设置背景图
//	 }




}
//文件页面
static void onListItemClick_LVFolder(ZKListView *pListView, int index, int id) {
//
//	FileInfo fi = fileInfos[index];
//	switch (fi.fileType) {
//	//case E_FILETYPE_HOME:
//	//	pListView->setVisible(false);
//	//	mMainMenuPtr->setVisible(true);
//	//	break;
//
////	case E_FILETYPE_BACK:
////		listFiles(acurrentDirectory, "..");
////		break;
//
//	case E_FILETYPE_FOLDER:
//		listFiles(acurrentDirectory, fi.fileName);
//		break;
//
//	case E_FILETYPE_FILE:
//	//	pListView->setVisible(false);
//
//
//
////	Extract_print_files_curr_pos.clear();
////		 for(int i=0;i<32;i++)
////		 {
////			 Extract_print_files_bool[i] = 1;
////		 }
////	    Extract_print_files.clear();
////		mwinQueryPrintPtr->showWnd();
////		mwinPrintPtr->hideWnd();
////		mdfPtr->setTextColor(0x000000);
////	    mdfPtr->setTextTr("Are you sure you need to print?");
//		afileName = acurrentDirectory + "/" + fi.fileName;
////		LOGD("wj:%s",afileName.c_str());
////
////	 	fn = fopen( afileName.c_str(), "r");
////	 	if(fn == NULL) {
////
////	 		LOGD("文件打开失败");
////	 	}
////	 	LOGD("文件打开成功");
////
//
//		break;
//
//	default:
//		break;
//	}
//



}
