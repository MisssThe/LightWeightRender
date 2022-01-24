//
// Created by MisThe on 2022/1/21.
// 实现材质功能，存储自定义数据
//

#ifndef LIGHTWEIGHTRENDERER_MATERIAL_H
#define LIGHTWEIGHTRENDERER_MATERIAL_H


#include "Shader.h"
#include "Transform.h"

class Material {
public:
    Material(Shader*shader);
    void use();
    void setTransform(Transform*transform);
};


#endif //LIGHTWEIGHTRENDERER_MATERIAL_H
