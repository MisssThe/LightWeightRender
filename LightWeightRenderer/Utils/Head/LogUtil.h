//
// Created by MisThe on 2022/1/20.
//

#ifndef LIGHTWEIGHTRENDERER_LOGUTIL_H
#define LIGHTWEIGHTRENDERER_LOGUTIL_H

#include <string>
#include <iostream>

class LogUtil {
public:
    static void LogError(std::string func,std::string context);
    static void LogWarning(std::string func,std::string context);
};

#endif //LIGHTWEIGHTRENDERER_LOGUTIL_H
