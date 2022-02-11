//
// Created by MisThe on 2022/1/21.
//

#include "../../../Head/Graph/BaseRender/Shader.h"

std::string Shader::cut_of_word = "//------------ UNIFORM ------------";

void Shader::use() {
    glUseProgram(this->shaderID);
}

Shader::Shader(std::unordered_map<unsigned int ,std::string> paths) {
    this->shaderID = glCreateProgram();
    TraverUtil::TraverUMap<unsigned int,std::string>(&paths,[this](unsigned int type,std::string path){
        std::string *code = FileUtil::ReadFile(path);
        this->compile(code,type);
        this->findKeyWord(code);
        delete code;
    });
    glLinkProgram(this->shaderID);
    this->findKeyWordLocation();
}

void Shader::compile(std::string*codeStr,int shaderType) {
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
            int index = keyWordVec.size() - 1;
            if (index > 0) {
                this->keyWordMap.insert(std::pair<std::string, KeyWord>(keyWordVec[index], {keyWordVec[1], 0}));
            }
        });
    }
}

void Shader::findKeyWordLocation() {
    TraverUtil::TraverUMap<std::string, KeyWord>(&this->keyWordMap,[this](std::string name,KeyWord keyWord){
        int location = glGetUniformLocation(this->shaderID,name.c_str());
        this->keyWordMap[name].location = location;
    });
}

const std::unordered_map<std::string, Shader::KeyWord> &Shader::getKeyWordMap() const {
    return keyWordMap;
}
