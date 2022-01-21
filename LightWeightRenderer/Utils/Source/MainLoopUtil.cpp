//
// Created by MisThe on 2022/1/21.
//

#include <iostream>
#include "../Head/MainLoopUtil.h"
#include "../Head/TraverUtil.h"

std::queue<std::function<bool()>> MainLoopUtil::loop_queue;

void MainLoopUtil::DropLoop(int index) {

}

void MainLoopUtil::Run() {
    std::function<bool(std::function<bool()> func)> func = [](std::function<bool()> func)->bool {
        return func();
    };
    while (loop_queue.size() > 0) {
        TraverUtil::TraverQueueBool<std::function<bool()>>(&loop_queue,func);
    }
}

int MainLoopUtil::AddLoop(std::function<bool()> loop, std::function<void()> end) {
    loop_queue.push(loop);
    return 0;
}
