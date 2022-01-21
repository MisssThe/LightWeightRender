//
// Created by MisThe on 2022/1/21.
// 封装常用文件操作
//

#ifndef LIGHTWEIGHTRENDERER_FILEUTIL_H
#define LIGHTWEIGHTRENDERER_FILEUTIL_H

#include <string>
#include <fstream>
#include <sstream>
#include "../Head/LogUtil.h"

class FileUtil {
public:
    static std::string * ReadFile(std::string path, unsigned int ioState = std::ifstream::failbit | std::ifstream::badbit);
    static void WriteFile();
};


#endif //LIGHTWEIGHTRENDERER_FILEUTIL_H
