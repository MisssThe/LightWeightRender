//
// Created by MisThe on 2022/1/27.
//

#ifndef LIGHTWEIGHTRENDERER_MATERIALCONTROLLER_H
#define LIGHTWEIGHTRENDERER_MATERIALCONTROLLER_H


#include "../BaseRender/Material.h"
#include "../../../../Utils/Head/JsonUtil.h"

class MaterialController {
public:
    static void Init();
    static Material*CreateMaterial();

private:
    static std::unordered_map<std::string,Material*> material_map;
    static bool isReady;
    static std::string material_config_path;
};


#endif //LIGHTWEIGHTRENDERER_MATERIALCONTROLLER_H
