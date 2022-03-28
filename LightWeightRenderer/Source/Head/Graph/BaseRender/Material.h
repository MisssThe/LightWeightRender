//
// Created by MisThe on 2022/1/21.
// 实现材质功能，存储自定义数据
// 记录的数据暂处于内存中，刷新或更换shader时刷新磁盘文件
//

#ifndef LIGHTWEIGHTRENDERER_MATERIAL_H
#define LIGHTWEIGHTRENDERER_MATERIAL_H


#include "../../../../Utils/Head/JsonUtil.h"
#include "../../../../Utils/Head/ConstUtil.h"
#include "Texture.h"

class Material : public RenderComponent
{
public:
    Material();                     //创建一个空material
    Material(std::string path);     //根据文本创建material
    void render() override;
    void bindShader(std::unordered_map<std::string, RenderComponent::KeyWord>* property);
private:
    struct Info
    {
        std::function<void()> func;
    };
    std::vector<Info> property_map;
    Json::Value content;
private:
};


#endif //LIGHTWEIGHTRENDERER_MATERIAL_H
