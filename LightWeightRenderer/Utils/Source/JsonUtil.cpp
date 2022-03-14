//
// Created by MisThe on 2022/1/20.
//

#include "../Head/JsonUtil.h"
#include "../Head/TraverUtil.h"

std::string JsonUtil::current_path;

Json::Value JsonUtil::ReadJson(std::string path) {
    path = CheckPath(path);
    std::ifstream jsonFile;
    jsonFile.open(path);
    Json::Value root;
    Json::CharReaderBuilder reader;
    JSONCPP_STRING errs;
    Json::parseFromStream(reader, jsonFile, &root, &errs);
    jsonFile.close();
    return root;
}


std::string JsonUtil::CheckPath(std::string path) {
    if (current_path == "") {
        current_path = std::filesystem::current_path();
        current_path = StringUtil::SplitAndReduce(&current_path, "/", 3);
    }
    std::ifstream file;
    file.open(path);
    if (file.is_open()) {
        file.close();
        return path;
    }
    path = current_path + path;
    file.open(path);
    if (file.is_open()) {
        file.close();
        return path;
    }
    LogUtil::LogError("check path", "file not exit[" + path + "]\n");
    return NULL;
}

void JsonUtil::WriteJson(Json::Value value, std::string path) {
    std::string name = value.getMemberNames()[0];
    WriteJson(name, value[name], path);
}

bool JsonUtil::IsExit(std::string key, Json::Value v) {
    return IsExit(key, &v);
}

bool JsonUtil::IsExit(std::string key, Json::Value *v) {
    if (!isObject(v))
        return false;
    std::vector<std::string> names = v->getMemberNames();
    return TraverUtil::TraverVectorBool<std::string>(&names, [&key](std::string name) -> bool {
        if (name == key)
            return true;
        return false;
    });
}

bool JsonUtil::isObject(Json::Value *v) {
    return !v->empty() && v->isObject();
}
