//
// Created by MisThe on 2022/1/21.
// 实现材质功能，存储自定义数据
// 渲染的最小单位
//

#ifndef LIGHTWEIGHTRENDERER_MATERIAL_H
#define LIGHTWEIGHTRENDERER_MATERIAL_H


#include "Shader.h"
#include "Transform.h"
#include "Mesh.h"

class Material {
public:
    Material(std::string path);
    Material* RefreshPanel();                                                 //创建显示面板
    void use(Transform*transform);
    void setShader(Shader*shader);
    void setTransform(Transform*transform);
    bool render();
private:
    Shader*shader;
    Transform*transform;
    Mesh*mesh;
    bool isAlive;
    static bool isReady;
    static std::unordered_map<std::string,std::function<void(Shader*)>> type_func;
private:
    void init();
};


#endif //LIGHTWEIGHTRENDERER_MATERIAL_H
