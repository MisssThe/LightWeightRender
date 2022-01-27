//
// Created by MisThe on 2022/1/27.
//

#ifndef LIGHTWEIGHTRENDERER_GRAPHCONTROLLER_H
#define LIGHTWEIGHTRENDERER_GRAPHCONTROLLER_H


#include "ShaderController.h"
#include "MeshController.h"
#include "MaterialController.h"

class GraphController {
public:
    static void Init()
    {
        ShaderController::Init();
        MeshController::Init();
        MaterialController::Init();
    }
    static void Restart()
    {
        Init();
    }
};


#endif //LIGHTWEIGHTRENDERER_GRAPHCONTROLLER_H
