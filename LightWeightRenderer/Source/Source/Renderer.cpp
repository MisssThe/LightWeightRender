//
// Created by MisThe on 2022/2/8.
//

#include "../Head/Renderer.h"

void Renderer::Init() {
    //--------初始化窗口------------
    RenderPipeline *pipeline1 = new RenderPipeline();
    RenderPipeline *pipeline2 = new RenderPipeline();

    Window w1([pipeline1](){
        pipeline1->render();
    },"Light Weight Renderer",800,600),
           w2([pipeline2]() {
        pipeline2->render();
    },"Light Weight Renderer",1000,500);

    GraphController::Init();
    int index = 0;
    RenderObjectController::TraverObject([&pipeline1, &index, &pipeline2](RenderObject* ro) {
        index = ((index+1) % 2);
        if (index == 0)
            pipeline1->addObject(ro);
        else
            pipeline2->addObject(ro);
    });
    MainLoopUtil::Run();
}

void Renderer::Run() {
}

void Renderer::Stop() {
    glfwTerminate();
}
