//
// Created by MisThe on 2022/1/20.
//

#ifndef LIGHTWEIGHTRENDERER_RENDERPIPELINE_H
#define LIGHTWEIGHTRENDERER_RENDERPIPELINE_H


#include "../../Head/Graph/BaseRenderer.h"

class RenderPipeline {
public:
    RenderPipeline();
    int  addRenderer(BaseRenderer*br);
    void dropRenderer(int index);
    void render();
    static RenderPipeline* GetPipeLine(int index);
    int getIndex();
private:
    static bool isInit;
    struct RenderQueue
    {
        RenderType type;
        std::queue<BaseRenderer*> queue;
    };
    std::queue<RenderQueue*> renderQueue;
    static std::vector<RenderPipeline*> pipeline_vec;
    int index = -1;
private:
    void init();
    void loadShader();
};


#endif //LIGHTWEIGHTRENDERER_RENDERPIPELINE_H
