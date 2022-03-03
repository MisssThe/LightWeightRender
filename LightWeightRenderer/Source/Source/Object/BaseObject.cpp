//
// Created by MisThe on 2022/1/27.
//

#include "../../Head/Object/BaseObject.h"
#include "../../Head/Graph/GraphController/CameraController.h"


void BaseObject::destroy() {
    this->objectInfo->isAlive = false;
}

void BaseObject::destroyImmediately() {

}

void BaseObject::delComponent() {
    TraverUtil::TraverQueueBool<void *>(&this->objectInfo->queueUtil->void_queue, [](void *com) -> bool {
        return false;
    });
}

bool BaseObject::use() {
    TraverUtil::TraverQueue<void *>(&this->objectInfo->queueUtil->void_queue, [](void *com) {
        ((BaseComponent *) com)->invoke();
    });
    return this->objectInfo->isAlive;
}

BaseObject::BaseObject() {

}

void BaseObject::addComponent(std::string comName) {
    BaseComponent *com = ComponentController::CreateComponent(comName);
    if (com) {
        com->init(this->objectInfo);
        this->objectInfo->queueUtil->void_queue.push(com);
    }
}

BaseComponent *BaseObject::getComponent(std::string name) {
    if (this->objectInfo->queueUtil->void_queue.size() < 1)
        return nullptr;
    BaseComponent *com = static_cast<BaseComponent *>(this->objectInfo->queueUtil->void_queue.front());
    return com->getComponent(name);
}

bool BaseObject::slowUse() {
    return false;
}
