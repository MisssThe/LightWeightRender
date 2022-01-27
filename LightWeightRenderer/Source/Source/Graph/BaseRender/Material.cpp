//
// Created by MisThe on 2022/1/21.
//

#include "../../../Head/Graph/BaseRender/Material.h"

bool Material::isReady = false;

Material::Material(Shader *shader) {
    //初始化material基础设置，只会初始化一次
//    if ()
    //创建临时材质,根据shader 关键字创建面板
//    shader->keyWordMap;
}

Material::Material(Shader *shader,std::string name) {
    //读取材质配置文件，没有则创建

}



void Material::use(Transform*transform) {
    if (transform != nullptr)
    {

    }
    TraverUtil::TraverUMap<std::string,Shader::KeyWord>(&this->shader->keyWordMap,[](std::string name,Shader::KeyWord keyWord){

    });
}

void Material::setShader(Shader*shader)
{
    this->shader = shader;
    if (this->shader == nullptr)
        this->shader = new Shader("","");
}

void Material::setTransform(Transform *transform) {
    this->transform = transform;
    if (this->transform == nullptr)
        this->transform = new Transform();
}

void Material::init() {

    isReady = true;
}
