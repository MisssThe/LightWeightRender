//
// Created by MisThe on 2022/2/9.
//

#ifndef LIGHTWEIGHTRENDERER_CAMERA_H
#define LIGHTWEIGHTRENDERER_CAMERA_H


#include <glad.h>
#include "Transform.h"
#include "string"
#include "../../../Utils/Head/TraverUtil.h"
#include "../../../../Utils/Head/LogUtil.h"

class Camera {
public:
    Camera(Transform* transform,float ratio,float degrees = 45,float near = 0.1,float far = 100);
    glm::mat4 use(unsigned int program);
private:
    Transform* transform;
    glm::mat4 p_matrix;
    glm::mat4 v_matrix;
    float ratio;
    float degrees;
    float near;
    float far;
};


#endif //LIGHTWEIGHTRENDERER_CAMERA_H
