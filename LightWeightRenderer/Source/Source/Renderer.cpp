//
// Created by MisThe on 2022/2/8.
//

#include "../Head/Renderer.h"

void Renderer::Init() {
    //--------初始化窗口------------
    RenderPipeline *pipeline1 = new RenderPipeline();
    RenderPipeline *pipeline2 = new RenderPipeline();

    Window w1([pipeline1]() {
        pipeline1->render();
    }, "Light Weight Renderer", 1920, 1080),
            w2([pipeline2]() {
        pipeline2->render();
    }, "Light Weight Renderer", 400, 800);

    GraphController::Init();
    RenderObjectController::TraverObject([&pipeline1, &pipeline2](RenderObject *ro) {
        //根据object创建属性面板
        pipeline1->addObject(ro);
//        pipeline2->addObject(CreateInfoPanel(ro));
    });

    Physics::Init({w1.getWindow(), w2.getWindow()});
    Physics::Run();
    MainLoopUtil::Run();
}

void Renderer::Run() {
}

void Renderer::Stop() {
    glfwTerminate();
}

RenderObject* Renderer::CreateInfoPanel(RenderObject* ro) {
    RenderObject* infoPanel = new RenderObject(
            ShaderController::GetDefaultShader(),
            new Material(),
            MeshController::GetSquareMesh(),
            new Transform(std::vector<float>({})),
            RenderType::OPAQUE
            );
    return infoPanel;
}
