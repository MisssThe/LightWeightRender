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

glm::mat4 Camera::use(unsigned int program) {
//    int vLocation = glGetUniformLocation(program, "Model");
//    int pLocation = glGetUniformLocation(program, "Projection");
//    this->v_matrix = -transform->getMatrix();
//    glUniformMatrix4fv(vLocation, 1, GL_FALSE, &this->v_matrix[0][0]);
//    glUniformMatrix4fv(pLocation, 1, GL_FALSE, &this->p_matrix[0][0]);
}
