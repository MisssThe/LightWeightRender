//
// Created by MisThe on 2022/2/10.
//

#ifndef LIGHTWEIGHTRENDERER_RENDEROBJECTCONTROLLER_H
#define LIGHTWEIGHTRENDERER_RENDEROBJECTCONTROLLER_H

#include "../RenderObject.h"
#include "AssetController.h"

class RenderObjectController : public AssetController
{
public:
    static void Init();
    static void GetObject(std::string name);
    static void TraverObject(std::function<void(RenderObject*)> func);
private:
    static std::string object_config_path;
    static bool isReady;
    static std::unordered_map<std::string,RenderObject*> object_map;
    static std::unordered_map<std::string,std::string> object_path_map;
private:
    RenderObjectController();
};


#endif //LIGHTWEIGHTRENDERER_RENDEROBJECTCONTROLLER_H
