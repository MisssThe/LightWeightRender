//
// Created by MisThe on 2022/1/21.
//

#include "../../../Head/Graph/BaseRender/Transform.h"

void Transform::setScale(float x, float y,float z) {
    this->scale = {x, y, z};
    this->createMatrix();
}

void Transform::setPosition(float x, float y, float z) {
    this->position = {x, y, z};
    this->createMatrix();
}

void Transform::setRotation(float x, float y, float z) {
    this->rotation = {x, y, z};
    this->createMatrix();
}

glm::mat4 Transform::getMatrix() {
    return this->matrix;
}

void Transform::createMatrix() {
    this->matrix = glm::mat4(1.0f);
    this->matrix = glm::translate(this->matrix, this->position);
    this->matrix = glm::rotate(this->matrix, glm::radians(this->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    this->matrix = glm::rotate(this->matrix, glm::radians(this->rotation.y), glm::vec3(1.0f, 1.0f, 0.0f));
    this->matrix = glm::rotate(this->matrix, glm::radians(this->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    this->matrix = glm::scale(this->matrix,this->scale);
}

glm::vec3 Transform::getPosition() {
    return this->position;
}

glm::vec3 Transform::getRotation() {
    return this->rotation;
}

glm::vec3 Transform::getScale() {
    return this->scale;
}
