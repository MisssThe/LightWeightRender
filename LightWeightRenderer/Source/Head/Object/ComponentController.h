//
// Created by MisThe on 2022/2/18.
// 动态编译该文件（）修改频繁
// 记录注册所有component
//

#ifndef LIGHTWEIGHTRENDERER_COMPONENTCONTROLLER_H
#define LIGHTWEIGHTRENDERER_COMPONENTCONTROLLER_H

#include "BaseComponent.h"
#include "../Graph/BaseRenderer.h"
#include "../Graph/RendererComponent.h"

class ComponentController : public AssetController
{
public:
    static BaseComponent* CreateComponent(std::string name);
    static bool isNecessary(std::string name);
    static bool isOnly(std::string name);
private:
    static std::unordered_map<std::string,std::function<BaseComponent*()>> component_map;
    static std::unordered_map<std::string,int> necessary_map;
    static std::unordered_map<std::string,int> only_map;
    static bool isReady;
private:
    ComponentController();
    static void Init();
};


#endif //LIGHTWEIGHTRENDERER_COMPONENTCONTROLLER_H
