//
// Created by MisThe on 2022/2/16.
// 渲染器组件
// 生成时自动添加到pipeline中
//

#ifndef LIGHTWEIGHTRENDERER_BASERENDERER_H
#define LIGHTWEIGHTRENDERER_BASERENDERER_H

#include "BaseRender/Material.h"
#include "BaseRender/Mesh.h"
#include "BaseRender/Shader.h"

enum RenderType
{
    BEGIN,
    OPAQUE,
    TRANSPARENT,
    END
};

class BaseRenderer
{
public:
    BaseRenderer();
    RenderType getType();
    bool render(glm::mat4 model = glm::mat4(1));
    void setMaterial(std::string name);
    void setMaterial(Material*material);
    void setShader(Shader*shader);
    void setShader(std::string name);
    void setMesh(Mesh*mesh);
    void setMesh(std::string name);
private:
    RenderType type;
    Material*  material;
    Shader*    shader;
    Mesh*      mesh;
    bool       isReady;
};


#endif //LIGHTWEIGHTRENDERER_BASERENDERER_H
