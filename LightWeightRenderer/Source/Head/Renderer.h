//
// Created by MisThe on 2022/2/8.
//

#ifndef LIGHTWEIGHTRENDERER_BASERENDERER_H
#define LIGHTWEIGHTRENDERER_RENDERER_H


#include "Graph/RenderPipeline.h"
#include "../Head/Graph/Window.h"
#include "../Head/Graph/GraphController/GraphController.h"
#include "../Head/Physics/Physics.h"
#include "Object/BaseObject.h"
#include "RenderPanel/ShowPanel.h"
#include "RenderPanel/InfoPanel.h"

class Renderer {
public:
    static void Init();
    static void Run();
    static void Stop();
private:
    static ShowPanel showPanel;
    static InfoPanel infoPanel;
private:
    Renderer();
};


#endif //LIGHTWEIGHTRENDERER_BASERENDERER_H
