//
// Created by MisThe on 2022/1/21.
// 编译现有着色器，避免重复编译
//

#ifndef LIGHTWEIGHTRENDERER_SHADER_H
#define LIGHTWEIGHTRENDERER_SHADER_H

#include <string>
#include <glad.h>
#include <unordered_map>
#include "../../../../Utils/Head/StringUtil.h"
#include "../../../../Utils/Head/FileUtil.h"

class Shader {
public:
    struct KeyWord
    {
        std::string dataType;
        int location;
    };
    struct ShaderInfo
    {
        unsigned int shaderID;
        std::unordered_map<std::string,KeyWord>*keyWordMap;
    };
    std::unordered_map<std::string,KeyWord> keyWordMap;
public:
    Shader(std::string vertexPath,std::string fragmentPath);
    std::string getName();
    void use();
private:
    std::string shaderName;
    unsigned int shaderID;
    static std::string cut_of_word;
    static std::unordered_map<std::string,ShaderInfo> shader_map;
private:
    void init(std::string path);
    void setName(std::string name,std::string path);
    void compile(std::string*codeStr,int shaderType);
    void check(unsigned int shader,bool isProgram);
    void findKeyWord(std::string*code);
};


#endif //LIGHTWEIGHTRENDERER_SHADER_H
