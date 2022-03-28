//
// Created by MisThe on 2022/3/2.
//

#ifndef LIGHTWEIGHTRENDERER_SHOWPANEL_H
#define LIGHTWEIGHTRENDERER_SHOWPANEL_H


#include "BasePanel.h"

class ShowPanel : public BasePanel
{
public:
    ShowPanel()
    {
        this->init();
    }
protected:
    void initProperty() override {
        this->panelName = "info panel";
        this->width = 1280;
        this->height = 720;
    }

    void initView() override {

    }

    void bindClick() override {

    }
    void update() override {

    }
};


#endif //LIGHTWEIGHTRENDERER_SHOWPANEL_H
