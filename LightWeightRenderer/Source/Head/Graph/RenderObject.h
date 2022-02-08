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
    RenderObject();
    static RenderObject*CreateRenderObject();
    bool render();
    RenderType getType();
    void destroy();
    void destroyImmediately();
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
