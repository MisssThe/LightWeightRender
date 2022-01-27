//
// Created by MisThe on 2022/1/21.
// 实现材质功能，存储自定义数据
// 记录的数据暂处于内存中，刷新或更换shader时刷新磁盘文件
//

#ifndef LIGHTWEIGHTRENDERER_MATERIAL_H
#define LIGHTWEIGHTRENDERER_MATERIAL_H


#include "Shader.h"
#include "../../../../Utils/Head/JsonUtil.h"

class Material {
public:
    Material(std::string path);
    Material* RefreshPanel();
    void setShader(Shader*shader);
    bool render();
private:
    Shader*shader;
    std::string shaderName;
    struct Info
    {
        std::string type;
        std::string value;
        bool modify;
    };
    std::unordered_map<std::string,Info> property_map;
private:
    void init();
};


#endif //LIGHTWEIGHTRENDERER_MATERIAL_H
