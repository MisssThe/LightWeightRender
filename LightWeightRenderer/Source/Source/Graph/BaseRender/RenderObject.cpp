//
// Created by MisThe on 2022/1/21.
//

#include "../../../Head/Graph/BaseRender/RenderObject.h"

RenderObject::RenderObject(RenderOrder order,Shader *shader, Material *material, Mesh *mesh, Transform *transform) {
    this->order = order;
    this->setShader(shader);
    this->setTransform(transform);
    this->setMaterial(material);
    this->setMesh(mesh);
}

void RenderObject::setMaterial(Material *material) {
    this->material = material;
    if (this->material == nullptr)
        this->material = new Material(this->shader);
    this->material->setTransform(this->transform);
}

void RenderObject::setMesh(Mesh *mesh) {
    if (mesh != nullptr)
        this->mesh = mesh;
}

void RenderObject::setTransform(Transform *transform) {
    if (transform != nullptr)
        this->transform = transform;
}

void RenderObject::setShader(const Shader *shader) {
    if (this->shader != shader)
    {
        if (shader == nullptr)
            shader = new Shader("","");
        this->shader = (Shader*)shader;
        this->setMaterial(nullptr);
    }
}

bool RenderObject::render() {
    //根据自身属性绘制
    this->shader->use();
    this->material->use();
    this->mesh->use();
    glDrawElements(GL_TRIANGLES, 60000, GL_UNSIGNED_INT, 0);
    return isAlive;
}

RenderObject::RenderOrder RenderObject::GetOrder() {
    return this->order;
}

void RenderObject::dropImmediately() {

}

void RenderObject::drop() {
    isAlive = false;
}
