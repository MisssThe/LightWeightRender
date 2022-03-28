//
// Created by MisThe on 2022/2/18.
//

#include "../../Head/Object/ComponentController.h"
#include "../../Head/Graph/RendererComponent.h"

std::unordered_map<std::string,int> ComponentController::only_map;
std::unordered_map<std::string,int> ComponentController::necessary_map;
bool ComponentController::isReady = false;

std::unordered_map<std::string,std::function<BaseComponent*()>> ComponentController::component_map = {
        {"RendererComponent" , []()->BaseComponent* { return reinterpret_cast<BaseComponent *>(new RendererComponent());}}
};

bool ComponentController::isNecessary(std::string name) {
    Init();
    return false;
//    return TraverUtil::ExistInQueue<std::string>(&necessary_map,name);
}

bool ComponentController::isOnly(std::string name) {
    Init();
    return false;
//    return TraverUtil::ExistInQueue<std::string>(&only_map,name);
}

BaseComponent *ComponentController::CreateComponent(std::string name)
{
    Init();
    BaseComponent* com = nullptr;
    if (component_map.find(name) != component_map.end())
        com = component_map[name]();
    return com;
}

ComponentController::ComponentController() {

}

void ComponentController::Init() {
    if (isReady)
        return;
    isReady = true;
    JValue root = Config::GetComponentConfig();
    InitAsset(&root, [](std::string name, JValue *value) {
        if ((*value)[0].asBool())
            if (necessary_map.find(name) == necessary_map.end())
                necessary_map.insert(std::pair<std::string,int>(name,1));
        if ((*value)[1].asBool())
            if (only_map.find(name) == only_map.end())
                only_map.insert(std::pair<std::string,int>(name,1));
        }, [](std::string name, JValue *value) {

    });
}
