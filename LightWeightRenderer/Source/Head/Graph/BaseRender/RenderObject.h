//
// Created by MisThe on 2022/1/21.
// 基础渲染体（模型、着色器、材质、变化）
//

#ifndef LIGHTWEIGHTRENDERER_RENDEROBJECT_H
#define LIGHTWEIGHTRENDERER_RENDEROBJECT_H


#include "Material.h"
#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"

class RenderObject {
public:
    enum RenderOrder        //渲染优先级
    {
        OPAQUE,TRANSPARENT
    };
public:
    RenderObject(RenderOrder order,Shader*shader,Material*material,Mesh*mesh,Transform*transform);
    bool render();
    void setMaterial(Material*material);
    void setShader(const Shader*shader);
    void setTransform(Transform*transform);
    void setMesh(Mesh*mesh);
    RenderOrder GetOrder();
    void drop();
    void dropImmediately();
private:
    Material*material;
    Mesh*mesh;
    Shader*shader;
    Transform*transform;
    RenderOrder order;
    bool isAlive;
};


#endif //LIGHTWEIGHTRENDERER_RENDEROBJECT_H
