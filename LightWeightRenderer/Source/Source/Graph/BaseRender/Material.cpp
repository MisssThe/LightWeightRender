//
// Created by MisThe on 2022/1/21.
//

#include "../../../Head/Graph/BaseRender/Material.h"
#include "../../../Head/Graph/GraphController/CameraController.h"

Material::Material(std::string path) {
    Json::Value root = JsonUtil::ReadJson(path);
}

Material::Material() {

}

void Material::render() {
    TraverUtil::TraverVector<Info>(&this->property_map,[this](Info info){
        info.func();
    });
}

void Material::bindShader(std::unordered_map<std::string, RenderComponent::KeyWord> *property) {
    //取交集填充info
    property_map.clear();
    TraverUtil::TraverJsonValue(&content,[&property, this](std::string name,Json::Value* value) {
        if (property->find(name) != property->end())
        {
            RenderComponent::KeyWord keyWord = property->find(name)->second;
            if (!keyWord.equalType((*value)["type"].asString())) {
                property_map.push_back({keyWord.getFunc(value)});
            }
        }
    });
}

