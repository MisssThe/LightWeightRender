//
// Created by MisThe on 2022/1/27.
// 预加载所有shader
//

#ifndef LIGHTWEIGHTRENDERER_SHADERCONTROLLER_H
#define LIGHTWEIGHTRENDERER_SHADERCONTROLLER_H


#include "../BaseRender/Shader.h"
#include "../../../../Utils/Head/JsonUtil.h"

class ShaderController {
public:
    static void Init();
    static Shader*GetShader(std::string shaderName);
    static Shader*GetDefaultShader();
//    static Shader*CreateShader();
//    static Shader*CreateShader();
//    static Shader*CreateShader();
private:
    static std::unordered_map<std::string,Shader*> shader_map;
    static std::string shader_config_path;
    static bool isReady;
    static std::string shader_default_name;
private:
    static unsigned int CheckType(std::string str);
};


#endif //LIGHTWEIGHTRENDERER_SHADERCONTROLLER_H
