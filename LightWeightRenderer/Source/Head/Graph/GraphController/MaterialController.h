//
// Created by MisThe on 2022/1/27.
//

#ifndef LIGHTWEIGHTRENDERER_MATERIALCONTROLLER_H
#define LIGHTWEIGHTRENDERER_MATERIALCONTROLLER_H


#include "../BaseRender/Material.h"

class MaterialController {
public:
    static void Init();
    static Material*CreateMaterial();

private:
    std::unordered_map<std::string,Material*> material_map;
};


#endif //LIGHTWEIGHTRENDERER_MATERIALCONTROLLER_H
