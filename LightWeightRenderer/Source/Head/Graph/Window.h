//
// Created by MisThe on 2022/1/20.
// 构建一个显示窗口
//

#ifndef LIGHTWEIGHTRENDERER_WINDOW_H
#define LIGHTWEIGHTRENDERER_WINDOW_H


#include <string>
#include <glad.h>
#include <glfw3.h>
#include "../../../Utils/Head/LogUtil.h"
#include "../../../Utils/Head/ThreadUtil.h"
#include "../../../Utils/Head/MainLoopUtil.h"

class Window
{
public:
    Window(std::string name = "test",int width = 0,int height = 0);
    ~Window();
private:
    void initContext();
    void initWindow();
    bool run();
    void updateWindow();
    void deleteWindow();
private:
    GLFWwindow*window;
    int width,height;
    std::string windowName;
    bool isFirst;
    int windowID;
    static bool isInit;
    static int base_id;
    static std::queue<int> id_queue;
};


#endif //LIGHTWEIGHTRENDERER_WINDOW_H
