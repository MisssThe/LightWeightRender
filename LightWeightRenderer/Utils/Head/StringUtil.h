//
// Created by MisThe on 2022/1/21.
//

#ifndef LIGHTWEIGHTRENDERER_STRINGUTIL_H
#define LIGHTWEIGHTRENDERER_STRINGUTIL_H

#include <string>
#include <vector>
#include "TraverUtil.h"

class StringUtil {
public:
    static std::vector<std::string> Split(std::string*str,std::string flag);        //按标志符分割字符串
    static std::string SplitAndReduce(std::string*str,std::string flag,int num);    //从末端删除指定数量按标志符分割的字符串
};


#endif //LIGHTWEIGHTRENDERER_STRINGUTIL_H
