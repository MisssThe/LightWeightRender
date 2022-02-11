//
// Created by MisThe on 2022/1/27.
//

#include "../../../Head/Graph/GraphController/MaterialController.h"

bool MaterialController::isReady = false;
std::string MaterialController::material_config_path = "LightWeightRenderer/Config/MaterialConfig.json";
std::unordered_map<std::string, Material *> MaterialController::material_map;
std::unordered_map<std::string, std::string> MaterialController::material_path_map;

void MaterialController::Init() {
    if (!isReady) {
        isReady = true;
        InitAsset(material_config_path, [](std::string name, JValue *value) {
            material_map.insert(std::pair<std::string,Material*>(name,new Material(value->asString())));
            material_path_map.insert(std::pair<std::string,std::string>(name,value->asString()));
        }, [](std::string name, JValue *value) {
            material_path_map.insert(std::pair<std::string,std::string>(name,value->asString()));
        });
    }
}

Material *MaterialController::SaveMaterial(std::string name, Material *material) {
    return nullptr;
}

Material *MaterialController::CreateMaterial() {
    return nullptr;
}

void MaterialController::AddMaterial(JValue value) {
    std::string shaderName = value["shader"].asString();
    Shader *shader = ShaderController::GetShader(shaderName);
    std::unordered_map<std::string, Shader::KeyWord> keyWordMap = shader->getKeyWordMap();
}

Material *MaterialController::GetMaterial(std::string name) {
    if (material_map.find(name) != material_map.end())
        return material_map[name];
    else if (material_path_map.find(name) != material_path_map.end()) {
        material_map.insert(std::pair<std::string, Material *>(name, new Material(material_path_map[name])));
        return material_map[name];
    } else
        LogUtil::LogError("get material","error material path");
    return nullptr;
}
