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
    static bool IsExit(std::string key, Json::Value v);
    static bool IsExit(std::string key, Json::Value* v);
    static Json::Value ReadJson(std::string path);
    static void WriteJson(Json::Value value, std::string path);
    template<class T> static void WriteJson(std::string key,T value,std::string path)
    {
        path = CheckPath(path);
        Json::Value root = ReadJson(path);

        bool success = IsExit(key,&root);
        if (success)
            root[key] = value;
        success = success || TraverUtil::TraverJsonValueBool(&root,[&key, &value, &path](std::string str,Json::Value* v) -> bool{
            if (IsExit(key, v))
            {
                (*v)[key] = value;
                return true;
            }
           return false;
        });
        if (success) {
            std::ostringstream oss;
            Json::StreamWriterBuilder swb;
            std::unique_ptr<Json::StreamWriter> sw(swb.newStreamWriter());
            std::ofstream jsonFile;
            jsonFile.open(path);
            sw->write(root,&jsonFile);
            jsonFile.close();
        }
    }
    template<class T> static std::vector<T> JsonToArray(Json::Value root) {
        if (!root.empty()) {
            int length = root.size();
            std::vector<void*> vec;
            for (int i = 0; i < length; ++i) {                            // 装箱
                std::string type = typeid(T).name();
                void* value = nullptr;
                if (type == typeid(float).name()) {
                    int data = root[i].asFloat();
                    value = &data;
                } else if (type == typeid(int).name()) {
                    int data = root[i].asInt();
                    value = &data;
                } else if (type == typeid(std::string).name()) {
                    std::string data = root[i].asString();
                    value = &data;
                } else if (type == typeid(Json::Value).name()) {
                    value = &root[i];
                }
                vec.push_back(value);
            }
            std::vector<T> result;
            TraverUtil::TraverVector<void*>(&vec,[&result](void* data) {     //拆箱
                result.push_back(*(T*)data);
            });
            return result;
        }
        return std::vector<T>();
    }

private:
    static std::string CheckPath(std::string path);
    static bool isObject(Json::Value* v);
    static std::string current_path;
};


#endif //LIGHTWEIGHTRENDERER_JSONUTIL_H
