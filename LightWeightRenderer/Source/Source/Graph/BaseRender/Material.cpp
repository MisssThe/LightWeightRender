//
// Created by MisThe on 2022/1/21.
//

#include "../../../Head/Graph/BaseRender/Material.h"

bool Material::isReady = false;
std::unordered_map<std::string,std::function<void(Shader*)>> Material::type_func;

bool Material::render() {
    this->mesh->use();
    this->shader->use();
    glDrawElements(GL_TRIANGLES, 60000, GL_UNSIGNED_INT, 0);
    return this->isAlive;
}


Material::Material(Shader *shader, Mesh *mesh, Transform *transform) {
//    if (shader == nullptr)
//        this->shader = new Shader()
}

Material::Material(Shader *shader, Mesh *mesh, Transform *transform, std::string name) {

}

Material *Material::infoPanel() {
//    Material*mat = new Material()
    return nullptr;
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
//    if (this->shader == nullptr)
}

void Material::setTransform(Transform *transform) {
    this->transform = transform;
    if (this->transform == nullptr)
        this->transform = new Transform();
}

void Material::init() {
    type_func.insert(std::pair<std::string,std::function<void(Shader*)>>("",[](Shader* shader){
//        glUniform1f(shader->keyWordMap)

    }));
//    type_func.insert(std::pair<std::string,std::function<void()>());
    isReady = true;
}
