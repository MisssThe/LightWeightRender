//
// Created by MisThe on 2022/1/21.
// 实现材质功能，存储自定义数据
// 记录的数据暂处于内存中，刷新或更换shader时刷新磁盘文件
//

#ifndef LIGHTWEIGHTRENDERER_MATERIAL_H
#define LIGHTWEIGHTRENDERER_MATERIAL_H


#include "Shader.h"
#include "../../../../Utils/Head/JsonUtil.h"
#include "../../../../Utils/Head/ConstUtil.h"
#include "../../../Head/Graph/GraphController/ShaderController.h"

class Material {
public:
    Material();
    Material(std::string path);
    Material* RefreshPanel();
    void setMaterialValue(std::string name,std::string value);
    void use();
private:
    Shader*shader;
    std::string shaderName;
    struct Info
    {
        std::string type;
        std::string value;
        int location;
    };
    std::unordered_map<std::string,Info> property_map;
    static std::unordered_map<std::string,std::string> external_property_map;
private:
    void initMaterial(std::unordered_map<std::string, Shader::KeyWord>* keyWordMap,Json::Value* root);
    void setValue(std::string type,std::string value,int location);
};


#endif //LIGHTWEIGHTRENDERER_MATERIAL_H
