#include <iostream>
#include "Utils/Head/JsonUtil.h"
#include "Source/Head/Graph/Window.h"
#include "Source/Head/Graph/RenderPipeline.h"
#include "Utils/Head/SortUtil.h"
#include "Source/Head/Graph/GraphController/GraphController.h"
#include <unordered_map>
int main() {
    RenderPipeline pipeline1,pipeline2;

    Window w1([&pipeline1](){
            pipeline1.render();
        },"Light Weight Renderer",800,600),
        w2([&pipeline2]() {
            pipeline2.render();
        },"ccc",1000,500);

    GraphController::Init();
    MainLoopUtil::Run();
    return 0;
}