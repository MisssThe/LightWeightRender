//
// Created by MisThe on 2022/1/21.
//

#include "../../../Head/Graph/BaseRender/Material.h"
#include "../../../Head/Graph/GraphController/CameraController.h"

Material::Material(std::string path) {
    Json::Value root = JsonUtil::ReadJson(path);
    std::string shaderName = root["shader"].asString();
    if (shaderName.empty())
        LogUtil::LogError("init material","error shader name[" + path + "]");
    Shader*shader = ShaderController::GetShader(shaderName);
    std::unordered_map<std::string, Shader::KeyWord> keyWordMap = shader->getKeyWordMap();
    this->initMaterial(&keyWordMap,&root);
}

void Material::use(Transform* transform) {
    TraverUtil::TraverUMap<std::string,Info>(&this->property_map,[this](std::string name,Info info){
        this->setValue(info.type,info.value,info.location);
    });
    //额外变量设置
    this->setExternalValue(transform);
}

void Material::setValue(std::string type, std::string value,int location) {
    if (type == "float")
        glUniform1f(location,std::stof(value));
    else if (type == "")
        return;
}

Material::Material() {

}

void Material::setExternalValue(Transform* transform) {
//    glm::mat4 p_matrix = CameraController::GetCamera()->getPMatrix();
//    glm::mat4 v_matrix = CameraController::GetCamera()->getVMatrix();
//    glm::mat4 m_matrix = transform->getMatrix();
//    glUniformMatrix4fv(this->external_property_map["Model"], 1, GL_FALSE, glm::value_ptr(m_matrix));      //Model矩阵
//    glUniformMatrix4fv(this->external_property_map["View"], 1, GL_FALSE, glm::value_ptr(v_matrix));       //View矩阵
//    glUniformMatrix4fv(this->external_property_map["Project"], 1, GL_FALSE, glm::value_ptr(p_matrix));    //Projection矩阵

}

void Material::initMaterial(std::unordered_map<std::string, Shader::KeyWord>* keyWordMap,Json::Value* root) {
    TraverUtil::TraverUMap<std::string,Shader::KeyWord>(keyWordMap,[&root, this](std::string name,Shader::KeyWord keyWord){
        Info info;
        info.location = keyWord.location;
        info.type = keyWord.dataType;
        if (root->isMember(name)) {
            info.value = (*root)[name].asString();
            this->property_map.insert(std::pair<std::string, Info>(name, info));
        } else {
            this->external_property_map.insert(std::pair<std::string,int>(name,keyWord.location));
        }
    });
}

