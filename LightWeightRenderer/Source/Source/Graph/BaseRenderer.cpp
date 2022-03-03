//
// Created by MisThe on 2022/2/16.
//

#include "../../Head/Graph/BaseRenderer.h"
#include "../../Head/Graph/GraphController/MeshController.h"
#include "../../Head/Graph/GraphController/MaterialController.h"

RenderType BaseRenderer::getType() {
    return this->type;
}

bool BaseRenderer::render() {
    this->mesh->render();
    this->shader->render();
    this->material->render();
    glDrawElements(GL_TRIANGLES, this->mesh->getIndexSize(), GL_UNSIGNED_INT, 0);
    return false;
}

BaseRenderer::BaseRenderer() {
    //用默认设置填充
    this->isReady = true;
    this->shader = ShaderController::GetDefaultShader();
    this->mesh = MeshController::GetSquareMesh();
    this->material = new Material();
    this->type = RenderType::OPAQUE;
}

void BaseRenderer::setMaterial(Material *material) {
    if (!material)
        material = new Material();
    this->material = material;
}

void BaseRenderer::setShader(Shader *shader) {
    if (!shader)
        shader = ShaderController::GetDefaultShader();
    this->shader = shader;
}

void BaseRenderer::setMesh(Mesh *mesh) {
    if (!mesh)
        mesh = MeshController::GetSquareMesh();
    this->mesh = mesh;
}

void BaseRenderer::setMesh(std::string name) {
    Mesh* tempMesh = MeshController::GetMesh(name);
    this->setMesh(tempMesh);
}

void BaseRenderer::setMaterial(std::string name) {
    Material* tempMaterial = MaterialController::GetMaterial(name);
    this->setMaterial(tempMaterial);
}

void BaseRenderer::setShader(std::string name) {
    Shader* tempShader = ShaderController::GetShader(name);
    this->setShader(tempShader);
}

