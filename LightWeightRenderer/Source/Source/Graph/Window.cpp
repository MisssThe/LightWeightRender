//
// Created by MisThe on 2022/1/20.
// macos 限制了gui只能在主线程运行（无法在子线程创建window）
//


#include "../../Head/Graph/Window.h"

bool Window::isInit = false;
int  Window::base_id = 0;
std::queue<int> Window::id_queue;

Window::Window(std::string name, int width, int height) {
    this->windowName = name;
    this->width = width;
    this->height = height;
    this->windowID = ++base_id;
    id_queue.push(this->windowID);
    if (!isInit)
        this->initContext();
    this->initWindow();
    MainLoopUtil::AddLoop([this]()->bool {
        return this->run();
    });
}

void Window::initContext() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    isInit = true;
}

void Window::initWindow() {
    this->window = glfwCreateWindow(this->width, this->height, this->windowName.c_str(), NULL, NULL);
    if (window == NULL)
    {
        LogUtil::LogError("init window","Failed to create GLFW window");
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        LogUtil::LogError("init window","Failed to initialize GLAD");
    }
}


bool Window::run() {
    if (!glfwWindowShouldClose(this->window)) {
        this->updateWindow();
        return true;
    } else {
        this->deleteWindow();
        return false;
    }
}

void Window::updateWindow() {
    glfwMakeContextCurrent(this->window);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(this->window);
    int id = id_queue.front();
    if (this->windowID == id)
        glfwPollEvents();
}

void Window::deleteWindow() {
    //保证线程安全
    ThreadUtil::Stop();
    if (window != nullptr)
    {
        glfwDestroyWindow(this->window);
        this->window = nullptr;
    }
    TraverUtil::TraverQueueBool<int>(&id_queue,[this](int id)->bool {
        if (id == this->windowID)
            return false;
        return true;
    });
    if (id_queue.size() == 0) {
        glfwTerminate();
        isInit = false;
    }
    ThreadUtil::Resume();
}

Window::~Window() {
    this->deleteWindow();
}
