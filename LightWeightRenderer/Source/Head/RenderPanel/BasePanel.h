//
// Created by MisThe on 2022/3/2.
//

#ifndef LIGHTWEIGHTRENDERER_BASEPANEL_H
#define LIGHTWEIGHTRENDERER_BASEPANEL_H


#include "../Graph/Window.h"
#include "../Graph/RenderPipeline.h"

class BasePanel {
protected:
    void init()
    {
        this->pipeline = new RenderPipeline();
        this->panelID = this->pipeline->getIndex();
        this->window = new Window([this]() {
            this->pipeline->render();
        }, this->panelName, this->width, this->height);
    }
    virtual void update() = 0;
private:
    Window* window;
    RenderPipeline* pipeline;
protected:
    std::string panelName;
    int width,height;
    int panelID = -1;
    int intervalTime;
public:
    BasePanel()
    {

    }
    GLFWwindow* getWindow()
    {
        return this->window->getWindow();
    }
    void run()
    {
        ThreadUtil::Start([this]() {
            this->update();
        }, this->intervalTime);
    }
};


#endif //LIGHTWEIGHTRENDERER_BASEPANEL_H
