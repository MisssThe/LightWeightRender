//
// Created by MisThe on 2022/2/8.
//

#include "../../../Head/Graph/GraphController/TextureController.h"
#include "../../../../Utils/Head/JsonUtil.h"

bool TextureController::isReady = false;
std::string TextureController::texture_config_path = "LightWeightRenderer/Config/TextureConfig.json";
std::unordered_map<std::string,Texture*> TextureController::texture_map;
std::unordered_map<std::string,std::string> TextureController::texture_path_map;

void TextureController::Init() {
    if (!isReady) {
        isReady = true;
        Json::Value root = JsonUtil::ReadJson(texture_config_path);
        TraverUtil::TraverJsonValueBool(&root,[](std::string name,Json::Value*value)->bool{
            if (name == "preheat")
                TraverUtil::TraverJsonValue(value,[](std::string name,Json::Value*v){
                    std::string path = v->asString();
                    path = FileUtil::CheckPath(path);
                    texture_path_map.insert(std::pair<std::string,std::string>(name,path));
                    Texture* texture = new Texture(path);
                    texture_map.insert(std::pair<std::string,Texture*>(name,texture));
                });
            else if (name == "passivity")
                TraverUtil::TraverJsonValue(value,[](std::string name,Json::Value*v){
                    std::string path = FileUtil::CheckPath(v->asString());
                    texture_path_map.insert(std::pair<std::string,std::string>(name,path));
                });
            else
                return true;
            return false;
        });
    }
}

Texture *TextureController::GetTexture(std::string name) {
    if (texture_map.find(name) == texture_map.end())
    {
        std::string path = texture_path_map[name];
        Texture* texture = new Texture(path);
        texture_map.insert(std::pair<std::string,Texture*>(name,texture));
    }
    return texture_map[name];
}
