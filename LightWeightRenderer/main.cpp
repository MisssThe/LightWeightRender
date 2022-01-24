#include <iostream>
#include "Utils/Head/JsonUtil.h"
#include "Source/Head/Graph/Window.h"
#include "Source/Head/Graph/RenderPipeline.h"

int main() {
    RenderPipeline pipeline1,pipeline2;
    Window w1([&pipeline1](){
        pipeline1.render();
        },"qqq",800,600),
        w2([&pipeline2]() {
            pipeline2.render();
        },"ccc",1000,500);

    MainLoopUtil::Run();
    return 0;
}