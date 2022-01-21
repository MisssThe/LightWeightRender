//
// Created by MisThe on 2022/1/21.
//

#include "../Head/FileUtil.h"

void FileUtil::WriteFile() {

}

std::string* FileUtil::ReadFile(std::string path,unsigned int ioState)
{
    std::string* code;
    std::ifstream file;
    file.exceptions(ioState);
    try
    {
        file.open(path);
        std::stringstream stream;
        stream << file.rdbuf();
        file.close();
        code = new std::string(stream.str());
    }
    catch (std::ifstream::failure& e)
    {
        LogUtil::LogError("ReadFile","file read failed:" + path);
    }
    return code;
}