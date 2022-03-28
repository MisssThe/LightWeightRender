//
// Created by MisThe on 2022/2/8.
//

#include "../Head/Renderer.h"

//ShowPanel Renderer::showPanel;
InfoPanel Renderer::infoPanel;


void Renderer::Init() {
    try {
        GraphController::Init();
        Physics::Init({infoPanel.getWindow()});
        Physics::Run();
        infoPanel.run();
//        showPanel.run();
        MainLoopUtil::Run();
    } catch (...) {

    }
}

void Renderer::Run() {
}

void Renderer::Stop() {
    glfwTerminate();
}

Renderer::Renderer() {

}

