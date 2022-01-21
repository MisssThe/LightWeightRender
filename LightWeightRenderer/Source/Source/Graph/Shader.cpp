//
// Created by MisThe on 2022/1/21.
//

#include "../../Head/Graph/Shader.h"

std::string Shader::cut_of_word = "//--------------------Uniform--------------------";

void Shader::use() {
    glUseProgram(this->shaderID);
}

Shader::Shader(std::string vertexPath, std::string fragmentPath, std::string shaderName) {
    this->setName(shaderName,vertexPath);
    std::string*vCode = FileUtil::ReadFile(vertexPath);
    std::string*fCode = FileUtil::ReadFile(fragmentPath);
    this->shaderID = glCreateProgram();
    compile(vCode,GL_VERTEX_SHADER);
    compile(fCode,GL_FRAGMENT_SHADER);
    glLinkProgram(this->shaderID);
}

void Shader::setName(std::string name, std::string path) {
    if (name.empty()) {
        std::vector<std::string> vec = StringUtil::Split(&path, "/");
        name = vec[vec.size() - 1];
    }
    this->shaderName = name;
}

void Shader::compile(std::string*codeStr,int shaderType) {
    this->findKeyWord(codeStr);
    unsigned int shader = glCreateShader(shaderType);
    const char* codeChar = codeStr->c_str();
    glShaderSource(shader, 1, &codeChar, NULL);
    glCompileShader(shader);
    this->check(shader,false);
    glAttachShader(shaderID,shader);
    glDeleteShader(shader);
}

void Shader::check(unsigned int shader, bool isProgram) {
    int success;
    char infoLog[1024];
    if (!isProgram)
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            LogUtil::LogError("ShaderCompile", std::string(infoLog));
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            LogUtil::LogError("ProgramCompile", std::string(infoLog));
        }
    }
}

void Shader::findKeyWord(std::string*code) {
    std::vector<std::string> strVec;
    strVec = StringUtil::Split(code,cut_of_word);
    if (strVec.size() > 2)
    {
        strVec = StringUtil::Split(&strVec[1],";");
        std::function<void(std::string)> func = [](std::string str){};
        TraverUtil::TraverVector<std::string>(&strVec,[this](std::string str) {
            std::vector<std::string> keyWordVec = StringUtil::Split(&str, " ");
            keyWordVec[0];
            int index = keyWordVec.size() - 1;
            if (index > 0) {
                int location = glGetUniformLocation(this->shaderID,"");
                this->keyWordMap.insert(std::pair<std::string, KeyWord>(keyWordVec[index], {keyWordVec[0], location}));
            }
        });
    }
}
