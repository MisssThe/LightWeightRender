//
// Created by MisThe on 2022/2/16.
//

#include "../../Head/Object/BaseComponent.h"

std::vector<BaseComponent*> BaseComponent::getComponents(std::string name) {
    std::vector<BaseComponent*> result;
    TraverUtil::TraverQueue<void*>(&this->objectInfo->queueUtil->void_queue,[&name, &result](void* com) {
        if (((BaseComponent*)com)->getName() == name)
        {
            result.push_back((BaseComponent *)com);
        }
    });
    return result;
}

BaseComponent *BaseComponent::getComponent(std::string name) {
    BaseComponent* result = nullptr;
    TraverUtil::TraverQueueBreak<void*>(&this->objectInfo->queueUtil->void_queue,[&name, &result](void* com)->bool {
        if (((BaseComponent*)com)->getName() == name)
        {
            result = (BaseComponent *) com;
            return true;
        }
        return false;
    });
    return result;
}

std::string BaseComponent::getName() {
    return this->name;
}

BaseComponent::BaseComponent() {
    this->isEnable = false;
}

void BaseComponent::invoke() {
    if (this->isEnable)
        this->use();
    else
        LogUtil::LogError("invoke component","not enable");
}

void BaseComponent::init(ObjectInfo *objectInfo) {
    if (objectInfo)
        this->objectInfo = objectInfo;
    this->initProperty();
    this->isEnable = true;
    //判断property是否初始化
    if (this->name.empty())
        LogUtil::LogError("init base component","error name");
}
