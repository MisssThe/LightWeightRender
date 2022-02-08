//
// Created by MisThe on 2022/1/21.
//

#include "../Head/FileUtil.h"

std::string FileUtil::current_path;

void FileUtil::WriteFile() {

}


std::string* FileUtil::ReadFile(std::string path,unsigned int ioState)
{
    path = CheckPath(path);
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
        LogUtil::LogError("ReadFile","file read failed:[" + path + "]\n");
    }
    return code;
}

std::string FileUtil::CheckPath(std::string path) {
    if (current_path == "")
    {
        current_path = std::filesystem::current_path();
        current_path = StringUtil::SplitAndReduce(&current_path,"/",3);
    }
    std::ifstream file;
    file.open(path);
    if (file.is_open())
    {
        file.close();
        return path;
    }
    path = current_path + path;
    file.open(path);
    if (file.is_open())
    {
        file.close();
        return path;
    }
    LogUtil::LogError("check path","file not exit[" + path + "]\n");
    return NULL;}
