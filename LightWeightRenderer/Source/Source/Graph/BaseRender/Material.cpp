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
//        this->property_map.insert(std::pair<std::string,Info>(name,{(*value)[0].asString(),(*value)[1].asString(),(*value)[2].asBool()}));
    });
}

void Material::use() {
    //设置常量信息
    this->property_map.find("");
    TraverUtil::TraverVector<std::string>(&ConstUtil::CONST_SHADER_QUEUE,[this](std::string key){
//        if (this->property_map.find(key) != this->property_map.end())
//        {
////            Info info = this->property_map[key];
////            this->setValue(info.type,info.value,info.location);
//        }
        std::cout << "hh";
    });
    //设置自定义信息
//    TraverUtil::TraverUMap<std::string,Info>(&this->property_map,[this](std::string name,Info info){
//        this->setValue(info.type,info.value,info.location);
//    });
}

void Material::setValue(std::string type, std::string value,int location) {

}
