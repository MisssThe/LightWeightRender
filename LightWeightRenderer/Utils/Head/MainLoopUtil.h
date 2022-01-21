//
// Created by MisThe on 2022/1/21.
// 收集程序中所有需要在主循环中一直运行的功能，避免阻塞流程
//

#ifndef LIGHTWEIGHTRENDERER_MAINLOOPUTIL_H
#define LIGHTWEIGHTRENDERER_MAINLOOPUTIL_H


#include <queue>

class MainLoopUtil
{
public:
    static int  AddLoop(std::function<bool()> loop,std::function<void()> end = nullptr);
    static void DropLoop(int index);
    static void Run();
private:
    static std::queue<std::function<bool()>> loop_queue;
};


#endif //LIGHTWEIGHTRENDERER_MAINLOOPUTIL_H
