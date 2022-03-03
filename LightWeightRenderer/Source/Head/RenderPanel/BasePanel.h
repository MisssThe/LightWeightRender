//
// Created by MisThe on 2022/3/2.
//

#ifndef LIGHTWEIGHTRENDERER_BASEPANEL_H
#define LIGHTWEIGHTRENDERER_BASEPANEL_H


#include "../Graph/Window.h"
#include "../Graph/RenderPipeline.h"
#include "../Object/BaseObject.h"

class BasePanel {
protected:
    void init()
    {
        this->pipeline = new RenderPipeline();
        this->panelID = this->pipeline->getIndex();
        this->window = new Window([this]() {
            this->pipeline->render();
        }, this->panelName, this->width, this->height);
        this->windowID = this->window->getWindowID();
    }
    virtual void update() = 0;
private:
    Window* window;
    RenderPipeline* pipeline;
private:
    void objectLoop()
    {
        TraverUtil::TraverQueueBool<BaseObject*>(&objectQueue,[](BaseObject* object) ->bool {
            return object->use();
        });
    }
protected:
    std::string panelName;
    int width,height;
    int panelID = -1;
    int intervalTime;
    int windowID;
    std::queue<BaseObject*> objectQueue;
public:
    BasePanel()
    {

    }
    Window* getWindow()
    {
        return this->window;
    }
    void run()
    {
        ThreadUtil::Start([this]() {
            this->update();
            this->objectLoop();
        }, this->intervalTime);
    }
};


#endif //LIGHTWEIGHTRENDERER_BASEPANEL_H
