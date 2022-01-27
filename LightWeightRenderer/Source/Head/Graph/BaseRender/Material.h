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
    Material(Shader*shader);                    //临时材质
    Material(Shader*shader,std::string name);   //本地材质
    void use(Transform*transform);
    void setShader(Shader*shader);
    void setTransform(Transform*transform);
private:
    Shader*shader;
    Transform*transform;
    static bool isReady;
    static std::unordered_map<std::string,std::function<void()>> type_func;
private:
    void init();
};


#endif //LIGHTWEIGHTRENDERER_MATERIAL_H
