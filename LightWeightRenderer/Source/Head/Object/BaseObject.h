//
// Created by MisThe on 2022/1/27.
// 在展示场景显示的物体
//

#ifndef LIGHTWEIGHTRENDERER_BASEOBJECT_H
#define LIGHTWEIGHTRENDERER_BASEOBJECT_H

#include "ComponentController.h"
#include "ObjectInfo.h"

class BaseObject {
public:
    BaseObject(int windowIndex);
    bool use();
    bool slowUse();             //主要做检测工作等不太需要实时性的
    void addComponent(std::string comName);
    void delComponent();
    BaseComponent* getComponent(std::string name);
    void destroy();
    void destroyImmediately();
private:
    ObjectInfo* objectInfo;
};


#endif //LIGHTWEIGHTRENDERER_BASEOBJECT_H
