//
// Created by MisThe on 2022/1/20.
// 通用线程工具，封装多线程开发所需基本功能
// 若提供的基本函数不会自然运行完成则无法调用除start外其余功能
//

#ifndef LIGHTWEIGHTRENDERER_THREADUTIL_H
#define LIGHTWEIGHTRENDERER_THREADUTIL_H

#include <thread>
#include <unordered_map>
#include "TraverUtil.h"
#include "LogUtil.h"

class ThreadUtil
{
public:
    static int Start(std::function<void()> func, int interval = 0, bool endless = false);
    static void Pause(int threadID = -1);
    static void Resume(int threadID = -1);
    static void Stop(int threadID = -1);
private:
    struct PrivateThread
    {
    public:
        int         threadID;
        bool*       pauseFlag;
        bool*       stopFlag;
        std::thread*thread;
        PrivateThread()
        {
            pauseFlag = new bool;
            stopFlag  = new bool;
        }
    };
    static std::unordered_map<int,PrivateThread*> thread_map;
    static int thread_id;
    static bool isLoading;
private:
    ThreadUtil();
    static void ControlThread(int threadID,bool flag,bool  isStop);
};


#endif //LIGHTWEIGHTRENDERER_THREADUTIL_H
