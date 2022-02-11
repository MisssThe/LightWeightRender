//
// Created by MisThe on 2022/1/21.
//

#include "../../../Head/Graph/BaseRender/Material.h"

static std::unordered_map<std::string,std::string> external_property_map = {
        {"1",""},
        {"2",""}
};

Material *Material::RefreshPanel() {
    return nullptr;
}

Material::Material(std::string path) {
    Json::Value root = JsonUtil::ReadJson(path);
    std::string shaderName = root["shader"].asString();
    if (shaderName.empty())
        LogUtil::LogError("init material","error shader name[" + path + "]");
    Shader*shader = ShaderController::GetShader(shaderName);
    std::unordered_map<std::string, Shader::KeyWord> keyWordMap = shader->getKeyWordMap();
    this->initMaterial(&keyWordMap,&root);
}

void Material::use() {
    TraverUtil::TraverUMap<std::string,Info>(&this->property_map,[this](std::string name,Info info){
        this->setValue(info.type,info.value,info.location);
    });
}

void Material::setValue(std::string type, std::string value,int location) {
    if (type == "float")
        glUniform1f(location,std::stof(value));
    else if (type == "")
        return;
}

Material::Material() {

}

void Material::initMaterial(std::unordered_map<std::string, Shader::KeyWord>* keyWordMap,Json::Value* root) {
    TraverUtil::TraverUMap<std::string,Shader::KeyWord>(keyWordMap,[&root, this](std::string name,Shader::KeyWord keyWord){
        Info info;
        info.location = keyWord.location;
        info.type = keyWord.dataType;
        if (root->isMember(name))
            info.value = (*root)[name].asString();
        else
            return;
//        else if (Material::external_property_map.find(name) != Material::external_property_map.end())
//            info.value = Material::external_property_map[name];
        this->property_map.insert(std::pair<std::string,Info>(name,info));
    });
}


void Material::setMaterialValue(std::string name, std::string value) {
    if (this->property_map.find(name) != this->property_map.end())
        this->property_map[name].value = value;
}