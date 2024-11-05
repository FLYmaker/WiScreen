/*
 * mainLogic.h
 *
 *  Created on: 2024年7月9日
 *      Author: 10589
 */

#ifndef JNI_LOGIC_MAINLOGIC_H_
#define JNI_LOGIC_MAINLOGIC_H_

#include <string.h>

enum FileType { E_FILETYPE_HOME, E_FILETYPE_BACK, E_FILETYPE_FOLDER, E_FILETYPE_FILE, E_FILETYE_MAX };

struct FileInfo {
	std::string fileName;
	FileType fileType;
	long datetime;
};
extern std::vector<FileInfo> fileInfos;
bool compare(const FileInfo& a, const FileInfo& b);





#endif /* JNI_LOGIC_MAINLOGIC_H_ */
