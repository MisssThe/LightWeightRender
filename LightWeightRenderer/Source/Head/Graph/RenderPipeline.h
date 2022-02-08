//
// Created by MisThe on 2022/1/20.
//

#ifndef LIGHTWEIGHTRENDERER_RENDERPIPELINE_H
#define LIGHTWEIGHTRENDERER_RENDERPIPELINE_H


#include "BaseRender/Material.h"
#include "BaseRender/Mesh.h"
#include "BaseRender/Shader.h"
#include "BaseRender/Transform.h"
#include "RenderObject.h"

class RenderPipeline {
public:
    RenderPipeline();
    int  addObject(RenderObject*ro);
    int  addObject(RenderObject ro);
    void dropObject(int index);
    void render();
private:
    static bool isInit;
    struct RenderQueue
    {
        RenderType type;
        std::queue<RenderObject*> queue;
    };
    std::queue<RenderQueue*> renderQueue;
private:
    void init();
    void loadShader();
};


#endif //LIGHTWEIGHTRENDERER_RENDERPIPELINE_H
