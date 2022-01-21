//
// Created by MisThe on 2022/1/20.
//

#include "../Head/LogUtil.h"

void LogUtil::LogWarning(std::string func, std::string context) {

}

void LogUtil::LogError(std::string func, std::string context) {
    std::cout << func << "," << context;
    exit(0);
}
