//
// Created by MisThe on 2022/1/20.
// 构建一个显示窗口
// 所有窗口共用顶点、材质等信息
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
    Window(std::function<void()> func,std::string name = "test",int width = 0,int height = 0);
    ~Window();
    GLFWwindow *getWindow() const;
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
    int windowID;
    std::function<void()> renderFUnc;
    static bool isInit;
    static int base_id;
    static std::queue<int> id_queue;
    static GLFWwindow* main_window;
};


#endif //LIGHTWEIGHTRENDERER_WINDOW_H
