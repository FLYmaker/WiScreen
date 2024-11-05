/*
 * thumbnail.cpp
 *
 *  Created on: 2024年7月9日
 *      Author: 10589
 */

#include"thumbnail.h"
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
#include "utils/Log.h"
#include <string.h>
#include "mainLogic.h"
extern std::string fileName;
extern bool make_big_Thumbnail;
extern bool make_big_Thumbnail_sure;
extern std::string currentDirectory;
std::vector<FileInfo> fileInfos;

//FileInfo fi = fileInfos[index];
bool compare(const FileInfo& inf1, const FileInfo& inf2) {
    // 如果 a 是 E_FILETYPE_FOLDER 且 b 不是，a 应该排在前面
    if (inf1.fileType == E_FILETYPE_FOLDER && inf2.fileType != E_FILETYPE_FOLDER) {
        return true;
    }
    // 如果 b 是 E_FILETYPE_FOLDER 且 a 不是，b 应该排在前面
    if (inf2.fileType == E_FILETYPE_FOLDER && inf1.fileType != E_FILETYPE_FOLDER) {
        return false;
    }
	return inf1.datetime > inf2.datetime;
}

// Base64 解码表
static const unsigned char base64_table[65] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// 查找 Base64 字符在表中的索引
inline unsigned char base64_char_index(char c) {
    const char *pos = strchr((const char *)base64_table, c);
    if (pos == nullptr) return 255;
    return pos - (const char *)base64_table;
}

// Base64 解码函数
std::vector<unsigned char> base64_decode(const std::string &encoded_string) {
    size_t in_len = encoded_string.size();
    if (in_len % 4 != 0) throw std::runtime_error("Invalid base64 input length.");

    size_t out_len = (in_len / 4) * 3;
    if (encoded_string[in_len - 1] == '=') out_len--;
    if (encoded_string[in_len - 2] == '=') out_len--;

    std::vector<unsigned char> decoded_data(out_len);
    size_t j = 0;
    for (size_t i = 0; i < in_len;) {
        unsigned char a = base64_char_index(encoded_string[i++]);
        unsigned char b = base64_char_index(encoded_string[i++]);
        unsigned char c = base64_char_index(encoded_string[i++]);
        unsigned char d = base64_char_index(encoded_string[i++]);

        decoded_data[j++] = (a << 2) | (b >> 4);
        if (j < out_len) decoded_data[j++] = (b << 4) | (c >> 2);
        if (j < out_len) decoded_data[j++] = (c << 6) | d;
    }

    return decoded_data;
}


// 保存数据到文本文件
void save_data_to_text_file(const std::vector<unsigned char> &data, const std::string &file_path) {
    std::ofstream file(file_path.c_str(), std::ios::out | std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open file for writing data.");
    }
    file.write(reinterpret_cast<const char *>(&data[0]), data.size());
     file.close();
}

// 读取文件并提取 Base64 数据
std::string extract_base64_data(const std::string &file_path) {
//    FILE *f = fopen(file_path.c_str(), "r");
//    if (!f) throw std::runtime_error("Failed to open file.");
//
//    char buf[1024];
//    char *rslt = NULL;
//    std::string base64_data;
//    bool in_thumbnail = false;
//    LOGD("t1");
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
////                LOGD(":%s",line.substr(2).c_str());
//            }
//        }
//    }
//
//    fclose(f);
	FILE *f = fopen(file_path.c_str(), "r");
	if (!f) throw std::runtime_error("Failed to open file.");

	char buf[1024];
	bool in_thumbnail = false;
	std::string base64_data;

	while (fgets(buf, sizeof(buf), f)) {
	    if (strncasecmp(buf, "; thumbnail begin", 15) == 0) {
	        in_thumbnail = true;
	        continue;
	    }
	    if (strncasecmp(buf, "; thumbnail end", 13) == 0) {
	        in_thumbnail = false;
	        continue;
	    }
	    if (in_thumbnail && buf[0] == ';' && buf[1] == ' ') {
	        const char* start = &buf[2];
	        const char* end = strchr(start, '\n');
	        if (end) {
	            base64_data.append(start, end - start);
	        } else {
	            base64_data.append(start);
	        }
	    }
	}

	fclose(f);

    // 清理Base64数据，去除无效字符
    base64_data.erase(std::remove_if(base64_data.begin(), base64_data.end(), [](char c) {
        return !isalnum(c) && c != '+' && c != '/' && c != '=';
    }), base64_data.end());



    return base64_data;
}






static size_t offset = 0;

// 读取PNG数据到图像内存
void read_png_data_from_memory(const std::vector<unsigned char> &data, png_structp &png, png_infop &info, std::vector<png_bytep> &row_pointers) {
    png = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png) throw std::runtime_error("Failed to create PNG read struct.");

    info = png_create_info_struct(png);
    if (!info) throw std::runtime_error("Failed to create PNG info struct.");

    if (setjmp(png_jmpbuf(png))) throw std::runtime_error("Error during PNG read.");

    // Set up the custom read function
    png_set_read_fn(png, (png_voidp)&data, [](png_structp png_ptr, png_bytep outBytes, png_size_t byteCountToRead) {
        auto &data = *(std::vector<unsigned char> *)png_get_io_ptr(png_ptr);
        memcpy(outBytes, &data[offset], byteCountToRead);
        offset += byteCountToRead;
    });

    png_read_info(png, info);

    int width = png_get_image_width(png, info);
    int height = png_get_image_height(png, info);
    png_byte bit_depth = png_get_bit_depth(png, info);
    png_byte color_type = png_get_color_type(png, info);

    if (bit_depth == 16) png_set_strip_16(png);
    if (color_type == PNG_COLOR_TYPE_PALETTE) png_set_palette_to_rgb(png);
    if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8) png_set_expand_gray_1_2_4_to_8(png);
    if (png_get_valid(png, info, PNG_INFO_tRNS)) png_set_tRNS_to_alpha(png);
    if (color_type == PNG_COLOR_TYPE_RGB || color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_PALETTE) png_set_filler(png, 0xFF, PNG_FILLER_AFTER);
    if (color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_GRAY_ALPHA) png_set_gray_to_rgb(png);

    png_read_update_info(png, info);

    row_pointers.resize(height);
    for (int y = 0; y < height; y++) {
        row_pointers[y] = (png_bytep)malloc(png_get_rowbytes(png, info));
    }

    png_read_image(png, &row_pointers[0]);
}

// 缩放图像
std::vector<png_bytep> resize_image(const std::vector<png_bytep> &src, int src_width, int src_height, int dst_width, int dst_height) {
    std::vector<png_bytep> dst(dst_height);
    for (int y = 0; y < dst_height; y++) {
        dst[y] = (png_bytep)malloc(dst_width * 4);  // Assuming 4 bytes per pixel (RGBA)
        for (int x = 0; x < dst_width; x++) {
            int src_x = x * src_width / dst_width;
            int src_y = y * src_height / dst_height;
            memcpy(&dst[y][x * 4], &src[src_y][src_x * 4], 4);
        }
    }
    return dst;
}

// 保存PNG数据到文件
void save_png_file(const std::string &file_name, std::vector<png_bytep> &row_pointers, int width, int height) {
	offset = 0;
    FILE *fp = fopen(file_name.c_str(), "wb");
    if (!fp) throw std::runtime_error("Failed to open file for writing.");

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png) throw std::runtime_error("Failed to create PNG write struct.");

    png_infop info = png_create_info_struct(png);
    if (!info) throw std::runtime_error("Failed to create PNG info struct.");

    if (setjmp(png_jmpbuf(png))) throw std::runtime_error("Error during PNG creation.");

    png_init_io(png, fp);
    png_set_IHDR(
        png,
        info,
        width,  // width
        height,  // height
        8,    // bit depth
        PNG_COLOR_TYPE_RGBA,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT
    );

    png_write_info(png, info);

    for (int y = 0; y < height; ++y) {
        png_write_row(png, row_pointers[y]);
    }

    png_write_end(png, nullptr);

    fclose(fp);

    png_destroy_write_struct(&png, &info);
}





void run_sf(std::vector<unsigned char> png_data,std::string fileName){
	                  // 读取PNG数据到内存
	                  png_structp png = nullptr;
	                  png_infop info = nullptr;
	                  std::vector<png_bytep> row_pointers;
	                  read_png_data_from_memory(png_data, png, info, row_pointers);
	                  png_data.clear();
	                  int width = png_get_image_width(png, info);
	                  int height = png_get_image_height(png, info);

	                  // 缩小图像分辨率
	                  int new_width = width / 5;   // 或者任何你需要的新的宽度
	                  int new_height = height / 5; // 或者任何你需要的新的高度
	                  if(strstr(fileName.c_str(), "big_Thumbnail"))
	                  {
		                   new_width = width;   // 或者任何你需要的新的宽度
		                   new_height = height; // 或者任何你需要的新的高度
	                  }
	                  std::vector<png_bytep> resized_row_pointers = resize_image(row_pointers, width, height, new_width, new_height);

	                  // 保存缩小后的PNG文件
	                  save_png_file("/tmp/" + fileName + ".png", resized_row_pointers, new_width, new_height);
	                  //因为打印界面显示了缩略图以后，图片资源就会被占用，再进入文件列表就没办法查看了，所以存2个图片分开显示
	                  if(strstr(fileName.c_str(), "big_Thumbnail"))
	                  {
	                	  save_png_file("/tmp/" + fileName + ".png", resized_row_pointers, new_width, new_height);

	                  }
	                  LOGD("Resized PNG image saved as %s_resized.png", fileName.c_str());

	                  // 释放内存
	                  for (auto row : row_pointers) {
	                      free(row);
	                  }
	                  row_pointers.clear();
	                  for (auto row : resized_row_pointers) {
	                      free(row);
	                  }
	                  resized_row_pointers.clear();
	                  png_destroy_read_struct(&png, &info, nullptr);


}



//获取RRF缩略图

//M36获取缩略图的格式以及起始偏移量

void RRF_make_Thumbnail(std::string base64_data,std::string fileName){

	try {

		  if(!base64_data.empty()){
			    base64_data.erase(std::remove_if(base64_data.begin(), base64_data.end(), [](char c) {
			        return !isalnum(c) && c != '+' && c != '/' && c != '=';
			    }), base64_data.end());

				  std::vector<unsigned char> png_data = base64_decode(base64_data);
				  run_sf(png_data,fileName);

		  }

      } catch (const std::exception &ex) {

      }
}












bool can_run = false;
bool Thumbnail::readyToRun() {
	can_run = true;
    return true;
}

bool Thumbnail::threadLoop() {
    if (exitPending()) {
        return false;
    }
	   static FileType savedFileType = E_FILETYPE_FILE;

	if(can_run){
		for(int i = 0 ; i < (int)fileInfos.size(); i++)
		{
//			LOGD("SIZE:%d",(int)fileInfos.size());
			if(fileInfos[i].fileType == savedFileType)
			{
				try {

				  std::string base64_data = extract_base64_data(currentDirectory+ "/" + fileInfos[i].fileName);
				  if(!base64_data.empty()){
					  std::vector<unsigned char> png_data = base64_decode(base64_data);
					  run_sf(png_data,fileInfos[i].fileName);
				  }

                } catch (const std::exception &ex) {
                    LOGD("Error processing file %s: %s", fileInfos[i].fileName.c_str(), ex.what());
                }
			}

		}
		can_run = false;
	 }

	if(make_big_Thumbnail == true){
		make_big_Thumbnail = false;
		make_big_Thumbnail_sure = false;
//		LOGD("NAME2:%s",fileName.c_str());
		std::string base64_data = extract_base64_data(fileName);
		if(!base64_data.empty()){
		  std::vector<unsigned char> png_data = base64_decode(base64_data);
		  run_sf(png_data,"big_Thumbnail");
		  make_big_Thumbnail_sure = true;
		}


}


    usleep(1000 * 100);
    return true;
}
