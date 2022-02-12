//
// Created by MisThe on 2022/1/20.
//

#include "../Head/ThreadUtil.h"

int ThreadUtil::thread_id = 0;
std::unordered_map<int,ThreadUtil::PrivateThread*> ThreadUtil::thread_map;
bool ThreadUtil::isLoading = false;

ThreadUtil::ThreadUtil() {
    //不能额外构造
}

//@param endless false：无限循环 true：只运行一次
int ThreadUtil::Start(std::function<void()> func,bool endless) {
    while (isLoading)
    {
        //保证线程安全
    }
    isLoading = true;
    thread_id++;
    PrivateThread* tempThread = new PrivateThread();
    *tempThread->stopFlag = endless;
    *tempThread->pauseFlag = false;
    tempThread->threadID = thread_id;
    tempThread->thread = new std::thread([&tempThread](std::function<void()> func){
        while (true){
            func();
            while (*(tempThread->pauseFlag));
            if (*(tempThread->stopFlag)) return;
        }
    },func);
    return tempThread->threadID;
}

void ThreadUtil::Pause(int threadID) {
    //阻塞进程，依然会有开销
    ControlThread(threadID, true, false);
}

void ThreadUtil::Resume(int threadID) {
    ControlThread(threadID, false, false);
}

void ThreadUtil::Stop(int threadID) {
    ControlThread(threadID, true, true);
}

void ThreadUtil::ControlThread(int threadID, bool flag, bool isStop) {
    std::queue<int> threadIDQueue;
    TraverUtil::TraverUMap<int,PrivateThread*>(&thread_map,[&threadID, &threadIDQueue](int id,PrivateThread*thread){
        if (threadID < 0 || (threadID == id)) {
            threadIDQueue.push(id);
        }
    });
    if (threadIDQueue.size() > 0)
    {
        TraverUtil::TraverQueue<int>(&threadIDQueue,[&isStop, &flag](int id){
            if (thread_map.find(id) != thread_map.end()) {
                if (isStop)
                    *thread_map[id]->stopFlag = flag;
                else
                    *thread_map[id]->pauseFlag = flag;
            }
        });
    }
    else
    {
        LogUtil::LogWarning("control thread","try to use an invalid thread id to control thread");
    }
}
