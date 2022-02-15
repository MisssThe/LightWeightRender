//
// Created by MisThe on 2022/2/9.
//

#include "../../../Head/Graph/BaseRender/Camera.h"

Camera::Camera(Transform* transform,float ratio,float degrees,float near,float far) {
    this->ratio   = ratio;
    this->degrees = degrees;
    this->near    = near;
    this->far     = far;
    this->p_matrix = glm::perspective(glm::radians(degrees), ratio, near, far);
    this->transform = transform;
}

const glm::mat4 &Camera::getPMatrix() const {
    return this->p_matrix;
}

const glm::mat4 &Camera::getVMatrix() const {
    return -this->transform->getMatrix();
}

void Camera::update() {
    this->p_matrix = glm::perspective(glm::radians(degrees), ratio, near, far);
}

void Camera::setRatio(float ratio) {
    Camera::ratio = ratio;
    this->update();
}

float Camera::getRatio() const {
    return ratio;
}

float Camera::getDegrees() const {
    return degrees;
}

float Camera::getNear() const {
    return near;
}

float Camera::getFar() const {
    return far;
}

void Camera::setDegrees(float degrees) {
    Camera::degrees = degrees;
    this->update();
}

void Camera::setNear(float near) {
    Camera::near = near;
    this->update();
}

void Camera::setFar(float far) {
    Camera::far = far;
    this->update();
}
