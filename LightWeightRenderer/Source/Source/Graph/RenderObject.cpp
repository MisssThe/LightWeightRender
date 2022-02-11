//
// Created by MisThe on 2022/1/27.
//

#include "../../Head/Graph/RenderObject.h"
#include "../../Head/Graph/GraphController/CameraController.h"

RenderObject *RenderObject::CreateRenderObject() {
    RenderObject *temp = nullptr;
    temp = new RenderObject();
    temp->shader = ShaderController::GetDefaultShader();
    temp->mesh = MeshController::GetSquareMesh();
    temp->material = new Material();
    return temp;
}

bool RenderObject::render() {
    this->mesh->use();
    this->shader->use();
    this->material->use();
    glDrawElements(GL_TRIANGLES, this->mesh->getIndexSize(), GL_UNSIGNED_INT, 0);
    return this->isAlive;
}

RenderType RenderObject::getType() {
    return this->renderType;
}

void RenderObject::destroy() {
    this->isAlive = false;
}

void RenderObject::destroyImmediately() {

}

void RenderObject::setMaterial(Material *material) {
    if (!material) {
        LogUtil::LogWarning("create render object", "error material");
    }
    RenderObject::material = material;
}

void RenderObject::setShader(Shader *shader) {
    if (!shader) {
        shader = ShaderController::GetDefaultShader();
        LogUtil::LogWarning("create render object", "error shader");
    }
    RenderObject::shader = shader;
}

void RenderObject::setMesh(Mesh *mesh) {
    if (!mesh) {
        mesh = MeshController::GetSquareMesh();
        LogUtil::LogWarning("create render object", "error mesh");
    }
    RenderObject::mesh = mesh;
}

void RenderObject::setTransform(Transform *transform) {
    if (!transform) {
        transform = new Transform();
        LogUtil::LogWarning("create render object", "error transform");
    }
    RenderObject::transform = transform;
}

RenderObject::RenderObject(Shader *shader, Material *material, Mesh *mesh, Transform *transform, RenderType type) {
    this->setShader(shader);
    this->setMaterial(material);
    this->setMesh(mesh);
    this->setTransform(transform);
    this->renderType = type;
    this->isAlive = true;
}

RenderObject::RenderObject(RenderType type) {
    this->renderType = type;
    this->isAlive = true;
}
