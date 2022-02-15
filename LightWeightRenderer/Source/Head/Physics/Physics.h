//
// Created by MisThe on 2022/2/12.
//

#ifndef LIGHTWEIGHTRENDERER_PHYSICS_H
#define LIGHTWEIGHTRENDERER_PHYSICS_H

#include "InputController/InputController.h"
#include "../../../Utils/Head/ThreadUtil.h"

class Physics {
public:
    Physics();

    static void Init(std::vector<GLFWwindow*> windowVec);
    static void Run();
    static void Stop();
private:
    static bool isReady;
};


#endif //LIGHTWEIGHTRENDERER_PHYSICS_H
