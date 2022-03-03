//
// Created by MisThe on 2022/2/21.
//

#ifndef LIGHTWEIGHTRENDERER_CONFIG_H
#define LIGHTWEIGHTRENDERER_CONFIG_H

#include "../Utils/Head/JsonUtil.h"

class Config {
public:
    static Json::Value GetShaderConfig()
    {
        return JsonUtil::ReadJson("LightWeightRenderer/Config/ShaderConfig.json");
    }
    static Json::Value GetMeshConfig()
    {
        return JsonUtil::ReadJson("LightWeightRenderer/Config/MeshConfig.json");
    }
    static Json::Value GetMaterialConfig()
    {
        return JsonUtil::ReadJson("LightWeightRenderer/Config/MaterialConfig.json");
    }
    static Json::Value GetObjectConfig()
    {
        return JsonUtil::ReadJson("LightWeightRenderer/Config/ObjectConfig.json");
    }
    static Json::Value GetComponentConfig()
    {
        return JsonUtil::ReadJson("LightWeightRenderer/Config/ComponentConfig.json");
    }
};


#endif //LIGHTWEIGHTRENDERER_CONFIG_H
