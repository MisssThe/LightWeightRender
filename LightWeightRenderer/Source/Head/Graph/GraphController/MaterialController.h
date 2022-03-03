//
// Created by MisThe on 2022/1/27.
//

#ifndef LIGHTWEIGHTRENDERER_MATERIALCONTROLLER_H
#define LIGHTWEIGHTRENDERER_MATERIALCONTROLLER_H


#include "../BaseRender/Material.h"
#include "../../../../Utils/Head/JsonUtil.h"
#include "AssetController.h"
#include "../../../Head/Graph/GraphController/ShaderController.h"

class MaterialController : public AssetController
{
public:
    static void Init();
    static Material* GetMaterial(std::string name);
    static Material* SaveMaterial(std::string name,Material* material);
    static Material*CreateMaterial();

private:
    static std::unordered_map<std::string,Material*> material_map;
    static std::unordered_map<std::string, std::string> material_path_map;
    static bool isReady;
private:
    static void AddMaterial(JValue value);
};


#endif //LIGHTWEIGHTRENDERER_MATERIALCONTROLLER_H
