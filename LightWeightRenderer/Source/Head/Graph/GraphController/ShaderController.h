//
// Created by MisThe on 2022/1/27.
// 预加载所有shader
//

#ifndef LIGHTWEIGHTRENDERER_SHADERCONTROLLER_H
#define LIGHTWEIGHTRENDERER_SHADERCONTROLLER_H


#include "../BaseRender/Shader.h"
#include "AssetController.h"

class ShaderController : public AssetController
{
public:
    static void Init();
    static Shader*GetShader(std::string shaderName);
    static Shader*GetDefaultShader();
//    static Shader*CreateShader();
//    static Shader*CreateShader();
//    static Shader*CreateShader();
private:
    static std::unordered_map<std::string,Shader*> shader_map;
    static std::unordered_map<std::string,std::unordered_map<unsigned int ,std::string>*> shader_path_map;
    static bool isReady;
    static std::string shader_default_name;
private:
    static unsigned int CheckType(std::string str);
    static void CreateShader(std::string name,std::vector<Json::Value>* value,bool create);
};


#endif //LIGHTWEIGHTRENDERER_SHADERCONTROLLER_H
