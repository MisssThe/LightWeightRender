//
// Created by MisThe on 2022/1/20.
//

#include "../Head/JsonUtil.h"
#include "../Head/TraverUtil.h"

Json::Value JsonUtil::ReadJson(std::string path) {
    std::ifstream jsonFile;
    jsonFile.open(path);
    Json::Value root;
    Json::CharReaderBuilder reader;
    JSONCPP_STRING errs;
    Json::parseFromStream(reader, jsonFile, &root, &errs);
    jsonFile.close();
    return root;
}


void JsonUtil::WriteJson(Json::Value value, std::string path) {

}

void JsonUtil::WriteJson(std::queue<std::string> jsonPath, std::string value, std::string path) {
    Json::Value root = ReadJson(path);
    Json::Value head = root;
    if (!root.empty()) {
        std::string front = jsonPath.front();
        jsonPath.pop();
        TraverUtil::TraverQueueBool<std::string>(&jsonPath,[&root](std::string key)->bool {
            if (root[key].empty())
                return false;
            root = root[key];
            return false;
        });
        std::cout << root;
        TraverUtil::TraverQueue<std::string>(&jsonPath,[&root](std::string key){
            root[key] = Json::Value();
            root = root[key];
        });
        std::cout << head;

        if (!root.empty())
            root[front] = value;
        else
            LogUtil::LogError("Write Json","invalid json key path");
    } else {
        LogUtil::LogError("Write Json","invalid json path");
    }
}

void JsonUtil::UpdateJson(std::queue<std::string> keyPath, std::string value, std::string path) {
    Json::Value root = ReadJson(path);
    if (!root.empty()) {
        std::string front = keyPath.front();
        keyPath.pop();
        TraverUtil::TraverQueue<std::string>(&keyPath,[&root](std::string key){
            root = root[key];
            if (root.empty())
                return;
        });
        if (!root.empty())
            root[front] = value;
        else
            LogUtil::LogError("Update Json","invalid json key path");

    } else {
        LogUtil::LogError("Update Json","invalid json path");
    }

}