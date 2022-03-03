//
// Created by MisThe on 2022/2/21.
//

#include "../../Head/Object/ObjectLoop.h"

std::queue<BaseObject*> ObjectLoop::object_queue;

void ObjectLoop::Init() {
    Json::Value root = Config::GetObjectConfig();
    //根据json info初始化object
    InitAsset(&root, [](std::string name, JValue *value) {
            std::string path = value->asString();
            object_queue.push(CreateBaseObject(path));
        }, [](std::string name, JValue *value) {
        //啥都不干
    });
}

void ObjectLoop::Run() {
    ThreadUtil::Start([]() {
        TraverUtil::TraverQueueBool<BaseObject*>(&object_queue,[](BaseObject* bo)->bool{
            if (bo)
                return bo->use();
            return false;
        });
    },1000);
}

void ObjectLoop::AddObject(BaseObject* object) {
    if (object)
        object_queue.push(object);
}

BaseObject *ObjectLoop::CreateBaseObject(std::string path) {
    return nullptr;
}
