//
// Created by MisThe on 2022/2/9.
// 当ro被标记为camera时会从pipeline中剔除，由camera接管相关操作
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
    void update();
private:
    Transform* transform;
    glm::mat4 p_matrix;
    glm::mat4 v_matrix;
public:
    const glm::mat4* getPMatrix() const;
    const glm::mat4* getVMatrix() const;
    void setRatio(float ratio);
    void setDegrees(float degrees);
    void setNear(float near);
    void setFar(float far);
    float getRatio() const;
    float getDegrees() const;
    float getNear() const;
    float getFar() const;

private:
    float ratio;
    float degrees;
    float near;
    float far;
};


#endif //LIGHTWEIGHTRENDERER_CAMERA_H
