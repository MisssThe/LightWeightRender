//
// Created by MisThe on 2022/1/20.
// 封装常用json文件操作
//

#ifndef LIGHTWEIGHTRENDERER_JSONUTIL_H
#define LIGHTWEIGHTRENDERER_JSONUTIL_H

#include <queue>
#include "TraverUtil.h"
#include "StringUtil.h"
#include "FileUtil.h"
#include "DataSaveUtil.h"

typedef Json::Value JValue;

class JsonUtil {
public:
    static Json::Value ReadJson(std::string path);

    //key:A-->B-->C 路径格式
    static void WriteJson(std::queue<std::string> keyPath, std::string value, std::string path);

    static void UpdateJson(std::queue<std::string> keyPath, std::string value, std::string path);

    static void WriteJson(Json::Value value, std::string path);

    template<class T>
    static std::vector<int> JsonToArray(Json::Value root) {
        if (!root.empty()) {
            int length = root.size();
            std::vector<int> vec;
            for (int i = 0; i < length; ++i) {
                std::string type = typeid(T).name();
                if (type == typeid(float).name()) {
                    float data = root[i].asFloat();
                    vec.push_back(DataSaveUtil::SaveData(data));
                } else if (type == typeid(int).name()) {
                    int data = root[i].asInt();
                    vec.push_back(DataSaveUtil::SaveData(data));
                } else if (type == typeid(std::string).name()) {
                    std::string data = root[i].asString();
                    vec.push_back(DataSaveUtil::SaveData(data));
                } else if (type == typeid(Json::Value).name()) {
                    Json::Value data = root[i];
                    vec.push_back(DataSaveUtil::SaveData(data));
                }
            }
            return vec;
        }
        return std::vector<int>();
    }

private:
    static std::string CheckPath(std::string path);

    static std::string current_path;
};


#endif //LIGHTWEIGHTRENDERER_JSONUTIL_H
