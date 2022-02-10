//
// Created by MisThe on 2022/1/27.
//

#include "../../Head/Graph/RenderObject.h"
#include "../../Head/Graph/GraphController/CameraController.h"

RenderObject::RenderObject() {
    this->renderType = RenderType::OPAQUE;
    this->isAlive = true;
}

RenderObject *RenderObject::CreateRenderObject() {
    RenderObject* temp = nullptr;
    temp = new RenderObject();
    temp->shader = ShaderController::GetDefaultShader();
    temp->mesh   = MeshController::GetCubeMesh();
    return temp;
}

bool RenderObject::render() {
    this->mesh->use();
    this->shader->use();
//    this->material->use();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
