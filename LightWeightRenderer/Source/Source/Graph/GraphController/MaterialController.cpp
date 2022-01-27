//
// Created by MisThe on 2022/1/27.
//

#include "../../../Head/Graph/GraphController/MaterialController.h"

bool MaterialController::isReady = false;
std::string MaterialController::material_config_path = "LightWeightRenderer/Config/Material/MaterialConfig.json";
std::unordered_map<std::string,Material*> MaterialController::material_map;

void MaterialController::Init() {
    if (!isReady)
    {
        isReady = true;
        Json::Value root = JsonUtil::ReadJson(material_config_path);
        TraverUtil::TraverJsonValue(&root,[](std::string name,Json::Value*value){
            material_map.insert(std::pair<std::string,Material*>(name,new Material(value->asString())));
        });
    }
}
