//
// Created by MisThe on 2022/2/12.
// 封装输入设备
// 输入设备不能在外部直接调用，只能通过input controller间接使用
//

#ifndef LIGHTWEIGHTRENDERER_BASEEQUIP_H
#define LIGHTWEIGHTRENDERER_BASEEQUIP_H
#include "../../Graph/Window.h"
#include "../../../../Utils/Head/TraverUtil.h"
#include "../../../../Utils/Head/LogUtil.h"
//#include "glfw3.h"

enum ClickState {
    RELEASE, LOOSE, PRESS, HOLD
};

class BaseEquip {
public:
    enum EquipType
    {
        ERROR,MOUSE,KEYBOARD
    };
    int id = -1;
public:
    void setEquipType(BaseEquip::EquipType type)
    {
        if (this->type == EquipType::ERROR)
            this->type = type;
    }
    EquipType getEquipType()
    {
        return this->type;
    }
    void setWindow(GLFWwindow *window) {
        if (!window)
            LogUtil::LogError("init equip", "error window");
        this->window = window;
    }
    void externalUpdate() {
        if (window)
            this->indirectUpdate();
        else
            LogUtil::LogError("update mouse", "null window");
    }
    virtual void indirectUpdate() = 0;
protected:
    virtual void use() = 0;
    virtual void update() = 0;
    GLFWwindow *window;
protected:
    ClickState updateClickState(int click, ClickState oldState) {
        int oldClick = oldState;
        int newClick = click ? (oldClick < PRESS ? PRESS : HOLD) : (oldClick > LOOSE ? RELEASE : LOOSE);
        return ClickState(newClick);
    }
private:
    EquipType type;
};

#endif //LIGHTWEIGHTRENDERER_BASEEQUIP_H
