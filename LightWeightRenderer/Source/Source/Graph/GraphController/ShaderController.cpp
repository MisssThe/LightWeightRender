//
// Created by MisThe on 2022/1/27.
//

#include "../../../Head/Graph/GraphController/ShaderController.h"


std::string ShaderController::shader_config_path = "LightWeightRenderer/Config/ShaderConfig.json";
std::unordered_map<std::string,Shader*> ShaderController::shader_map;
bool ShaderController::isReady = false;
std::string ShaderController::shader_default_name = "UI";


void ShaderController::Init() {
    if (!isReady) {
        isReady = true;
        //读取config目录查找指定shader
        Json::Value value = JsonUtil::ReadJson(shader_config_path);
        std::unordered_map<unsigned int, std::string> *shaderMap = nullptr;
        TraverUtil::TraverJsonValue(&value, [&shaderMap](std::string name, Json::Value *v) {
            int length = v->size();
            shaderMap = new std::unordered_map<unsigned int, std::string>();
            for (int i = 0; i < length; ++i) {
                std::string str = ((*v)[i]).getMemberNames()[0];
                unsigned int type = CheckType(str);
                std::string path = ((*v)[i])[str].asString();
                shaderMap->insert(std::pair<unsigned int, std::string>(type, path));
            }
            shader_map.insert(std::pair<std::string, Shader *>(name, new Shader(*shaderMap)));
        });
    }
}

Shader *ShaderController::GetShader(std::string shaderName) {
    if (shader_map.find(shaderName) != shader_map.end())
        return shader_map[shaderName];
    LogUtil::LogError("get shader","error shader name["+shaderName+"]\n");
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
        LogUtil::LogError("check shader type","type error");
    return -1;
}

Shader *ShaderController::GetDefaultShader() {
    return GetShader(shader_default_name);
}
