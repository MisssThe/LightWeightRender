//
// Created by MisThe on 2022/1/27.
//

#include "../../../Head/Graph/GraphController/ShaderController.h"


std::unordered_map<std::string, Shader *> ShaderController::shader_map;
std::unordered_map<std::string, std::unordered_map<unsigned int, std::string> *> ShaderController::shader_path_map;
bool ShaderController::isReady = false;
std::string ShaderController::shader_default_name = "UI";


void ShaderController::Init() {
    if (!isReady) {
        isReady = true;
        std::function<void(std::string, JValue *value, bool)> func = [](std::string name, JValue *value, bool flag) {
            std::vector<int> index_vec = JsonUtil::JsonToArray<Json::Value>(*value);
            std::vector<Json::Value> vec = DataSaveUtil::UseData<Json::Value>(index_vec);
            CreateShader(name, &vec, flag);
        };
        Json::Value root = Config::GetShaderConfig();
        InitAsset(&root, [&func](std::string name, JValue *value) {
            func(name,value,true);
        }, [&func](std::string name, JValue *value) {
            func(name,value, false);
        });
    }
}

Shader *ShaderController::GetShader(std::string shaderName) {
    if (shader_map.find(shaderName) != shader_map.end())
        return shader_map[shaderName];
    LogUtil::LogError("get shader", "error shader name[" + shaderName + "]\n");\
    return nullptr;
}

unsigned int ShaderController::CheckType(std::string str) {
    if (str == "vertex")
        return 0x8B31;
    else if (str == "fragment")
        return 0x8B30;
    else if (str == "geometry")
        return 0x8DD9;
//    else if (str == "tessellation")
//        return 4;
    else
        LogUtil::LogError("check shader type", "type error");
    return -1;
}

Shader *ShaderController::GetDefaultShader() {
    return GetShader(shader_default_name);
}

void ShaderController::CreateShader(std::string name, std::vector<Json::Value> *value, bool create) {
    std::unordered_map<unsigned int, std::string> *shaderPathMap = new std::unordered_map<unsigned int, std::string>();
    TraverUtil::TraverVector<Json::Value>(value, [&shaderPathMap](JValue v) {
        std::string name = v.getMemberNames()[0];
        unsigned int type = CheckType(name);
        shaderPathMap->insert(std::pair<unsigned int, std::string>(type, v[name].asString()));
    });
    shader_path_map.insert(
            std::pair<std::string, std::unordered_map<unsigned int, std::string> *>(name, shaderPathMap));
    if (create)
        shader_map.insert(std::pair<std::string, Shader *>(name, new Shader(*shaderPathMap)));
}