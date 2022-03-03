//
// Created by MisThe on 2022/2/16.
// 组件基类，所有要加载到render object上的物体需要继承次类
//

#ifndef LIGHTWEIGHTRENDERER_BASECOMPONENT_H
#define LIGHTWEIGHTRENDERER_BASECOMPONENT_H

#include "unordered_map"
#include "queue"
#include "../../../Utils/Head/VoidQueueUtil.h"
#include "../../../Utils/Head/TraverUtil.h"
#include "../../../Utils/Head/LogUtil.h"
#include "ObjectInfo.h"

//配置component属性
struct ComponentProperty
{
    bool isOnly;            //是否唯一
    bool isNecessary;       //是否必备
};

class BaseComponent {
public:
    BaseComponent();
    void invoke();
    void init(ObjectInfo* objectInfo);
    std::string getName();
    BaseComponent* getComponent(std::string name);
    std::vector<BaseComponent*> getComponents(std::string name);
protected:
    virtual bool use() = 0;
    virtual void initProperty() = 0;
    std::string name;
    ComponentProperty property;
    ObjectInfo* objectInfo;
    bool isEnable;
};


#endif //LIGHTWEIGHTRENDERER_BASECOMPONENT_H
