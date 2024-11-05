/*
 * upfile.h
 *
 *  Created on: 2024年2月26日
 *      Author: 23398
 */

#ifndef SRC_UPFILE_UPFILE_H_
#define SRC_UPFILE_UPFILE_H_

#include <iostream>
#include <fstream>
#include <assert.h>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring>

#include "../../src/include/system/Thread.h"

class upfile {
public:
	upfile();
	virtual ~upfile();

	int up(std::string url,std::string path);
};
#endif /* SRC_UPFILE_UPFILE_H_ */

