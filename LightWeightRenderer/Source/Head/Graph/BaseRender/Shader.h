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
public:
    Shader(std::unordered_map<unsigned int,std::string> paths);

    const std::unordered_map<std::string, KeyWord> &getKeyWordMap() const;

    void use();
private:
    std::unordered_map<std::string,KeyWord> keyWordMap;
    unsigned int shaderID;
    static std::string cut_of_word;
private:
    void compile(std::string*codeStr,int shaderType);
    void check(unsigned int shader,bool isProgram);
    void findKeyWord(std::string*code);
    void findKeyWordLocation();
};


#endif //LIGHTWEIGHTRENDERER_SHADER_H
