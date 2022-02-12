//
// Created by MisThe on 2022/2/12.
// 封装输入设备
// 输入设备不能在外部直接调用，只能通过input controller间接使用
//

#ifndef LIGHTWEIGHTRENDERER_BASEEQUIP_H
#define LIGHTWEIGHTRENDERER_BASEEQUIP_H

#include "../../../../Utils/Head/TraverUtil.h"
#include "../../../../Utils/Head/LogUtil.h"
#include "glfw3.h"

class BaseEquip {
public:
    void setWindow(GLFWwindow* window)
    {
        if (!window)
            LogUtil::LogError("init equip","error window");
        this->window = window;
    }
    void externalUpdate()
    {
        if (window)
            this->indirectUpdate();
        else
            LogUtil::LogError("update mouse","null window");
    }
    virtual void indirectUpdate() = 0;
protected:
    virtual void use() = 0;
    virtual void update() = 0;
    GLFWwindow* window;
};


#endif //LIGHTWEIGHTRENDERER_BASEEQUIP_H
