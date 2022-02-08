//
// Created by MisThe on 2022/1/21.
//

#include "../../../Head/Graph/BaseRender/Material.h"

void Material::setShader(Shader*shader)
{
    this->shader = shader;
}


Material *Material::RefreshPanel() {
    return nullptr;
}

Material::Material(std::string path) {
    Json::Value root = JsonUtil::ReadJson(path);
    TraverUtil::TraverJsonValue(&root,[this](std::string name,Json::Value*value) {
        this->property_map.insert(std::pair<std::string,Info>(name,{(*value)[0].asString(),(*value)[1].asString(),(*value)[2].asBool()}));
    });
}

void Material::use() {

}
