//
// Created by MisThe on 2022/1/21.
//

#include "../Head/StringUtil.h"

std::vector<std::string> StringUtil::Split(std::string*strPtr, std::string flag) {
    std::string str = *strPtr;
    std::vector<std::string> result;
    if(str.empty())
    {
        return result;
    }
    int pos = 0;
    int flagLen = flag.length();
    str = str + flag;
    std::string temp;
    do
    {
        pos = str.find(flag);
        temp = str.substr(0,pos);
        if (!temp.empty())
        {
            result.push_back(temp);
        }
        str = str.substr(pos + flagLen,str.size());
    } while (!str.empty());
    return result;
}

std::string StringUtil::SplitAndReduce(std::string *str, std::string flag, int num) {
    std::vector<std::string> temp = Split(str,flag);
    num = temp.size() - num + 1;
    std::string finalStr = "/";
    TraverUtil::TraverVector<std::string>(&temp,[&finalStr, &num](std::string str){
        if (num-- > 0)
            finalStr += (str + "/");
    });
    return finalStr;
}
