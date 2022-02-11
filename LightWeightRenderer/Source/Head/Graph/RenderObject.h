//
// Created by MisThe on 2022/1/27.
// 在展示场景显示的物体
//

#ifndef LIGHTWEIGHTRENDERER_RENDEROBJECT_H
#define LIGHTWEIGHTRENDERER_RENDEROBJECT_H

#include "BaseRender/Transform.h"
#include "../../Head/Graph/GraphController/ShaderController.h"
#include "../../Head/Graph/GraphController/MeshController.h"
#include "../../Head/Graph/GraphController/MaterialController.h"
enum RenderType
{
    BEGIN,
    OPAQUE,
    TRANSPARENT,
    END
};

class RenderObject {
public:
    RenderObject(RenderType type = RenderType::OPAQUE);
    RenderObject(Shader*shader,Material*material,Mesh*mesh,Transform*transform,RenderType type = RenderType::OPAQUE);
    static RenderObject*CreateRenderObject();
    bool render();
    RenderType getType();
    void destroy();
    void destroyImmediately();
    void setMaterial(Material *material);
    void setShader(Shader *shader);
    void setMesh(Mesh *mesh);

    void setTransform(Transform *transform);

private:
    RenderType  renderType;
    Material*   material;
    Shader*     shader;
    Transform*  transform;
    Mesh*       mesh;
    std::string name;
    bool isAlive;
};


#endif //LIGHTWEIGHTRENDERER_RENDEROBJECT_H
