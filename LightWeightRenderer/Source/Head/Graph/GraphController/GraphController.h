//
// Created by MisThe on 2022/1/27.
// 对加载的资源集中管理
// 考虑资源自动卸载与资源预加载
// Controller流程（shader controller -> mesh controller -> material controller -> object controller      ）
//

#ifndef LIGHTWEIGHTRENDERER_GRAPHCONTROLLER_H
#define LIGHTWEIGHTRENDERER_GRAPHCONTROLLER_H


#include "ShaderController.h"
#include "MeshController.h"
#include "MaterialController.h"
#include "TextureController.h"
#include "RenderObjectController.h"

class GraphController {
public:
    static void Init()
    {
        ShaderController::Init();
        MeshController::Init();
        MaterialController::Init();
        TextureController::Init();
        RenderObjectController::Init();
    }
    static void Restart()
    {
        Init();
    }
};


#endif //LIGHTWEIGHTRENDERER_GRAPHCONTROLLER_H
