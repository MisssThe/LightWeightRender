//
// Created by MisThe on 2022/1/20.
// 封装常用json文件操作
//

#ifndef LIGHTWEIGHTRENDERER_JSONUTIL_H
#define LIGHTWEIGHTRENDERER_JSONUTIL_H

#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include "../Head/LogUtil.h"
#include "TraverUtil.h"

class JsonUtil
{
public:
    static Json::Value ReadJson(std::string path);
    //key:A-->B-->C 路径格式
    static void        WriteJson(std::queue<std::string> keyPath,std::string value,std::string path);
    static void        UpdateJson(std::queue<std::string> keyPath,std::string value,std::string path);
    static void        WriteJson(Json::Value value,std::string path);
};


#endif //LIGHTWEIGHTRENDERER_JSONUTIL_H
