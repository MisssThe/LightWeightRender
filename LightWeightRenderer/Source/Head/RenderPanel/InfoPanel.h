//
// Created by MisThe on 2022/3/2.
//

#ifndef LIGHTWEIGHTRENDERER_INFOPANEL_H
#define LIGHTWEIGHTRENDERER_INFOPANEL_H


#include "BasePanel.h"
#include "../Physics/InputController/InputController.h"
#include "../Object/BaseObject.h"

class InfoPanel : public BasePanel
{
private:
    struct Info
    {
    public:
        Info(int pos):pos(pos),area(100){}
        Info(int pos,int  area):pos(pos),area(area){}
        std::string name;
        int pos;            // panel上方pos
        int area;           // panel长度
    };
public:
protected:
    void initProperty() override {
        this->panelName = "info panel";
        this->width = 400;
        this->height = 800;
        this->intervalTime = 100;
    }

    void initView() override {

    }

    void bindClick() override {

    }

public:
    InfoPanel()
    {
        this->init();
    }
    void update() override {
        InputController::UseFunc(BaseEquip::EquipType::MOUSE, [this](BaseEquip *equip) {
            MouseEquip* mouse = (MouseEquip*)equip;
            MathUtil::double2 pos = mouse->getMousePosition();
            if (mouse->getMouseClickState() == ClickState::PRESS)
            {
                this->addInfo();
            }
        }, this->windowID);
    }
    void addInfo()
    {
        BaseObject* object = new BaseObject(this->windowID);
        object->addComponent("RendererComponent");
        this->objectQueue.push(object);
//        infoQueue.push(new BaseObject());
//        Info* info = infoQueue.front();
//        int pos = info->pos + info->area;
//        this->infoQueue.push(new Info(pos));
//        if (infoQueue.size() > 10)
//        {
//            exit(0);
//        }
    }
private:
};


#endif //LIGHTWEIGHTRENDERER_INFOPANEL_H
