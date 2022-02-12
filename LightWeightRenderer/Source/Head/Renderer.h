//
// Created by MisThe on 2022/2/8.
//

#ifndef LIGHTWEIGHTRENDERER_RENDERER_H
#define LIGHTWEIGHTRENDERER_RENDERER_H


#include "Graph/RenderPipeline.h"
#include "../Head/Graph/Window.h"
#include "../Head/Graph/GraphController/GraphController.h"
#include "../Head/Physics/Physics.h"

class Renderer {
public:
    static void Init();
    static void Run();
    static void Stop();
};


#endif //LIGHTWEIGHTRENDERER_RENDERER_H
