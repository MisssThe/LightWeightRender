//
// Created by MisThe on 2022/2/11.
// 封装资源加载通用部分
//

#ifndef LIGHTWEIGHTRENDERER_ASSETCONTROLLER_H
#define LIGHTWEIGHTRENDERER_ASSETCONTROLLER_H

#include "../../../../Utils/Head/JsonUtil.h"
#include "../../../../Config/Config.h"

class AssetController {
protected:
    static void InitAsset(Json::Value* root, std::function<void(std::string,JValue*)> preheatFunc, std::function<void(std::string,JValue*)> passivityFunc) {
        bool flag_1 = false, flag_2 = false;
        bool success = TraverUtil::TraverJsonValueBool(root, [&flag_1, &flag_2, &preheatFunc, &passivityFunc](std::string name, JValue *value) -> bool {
            if (name == "preheat") {
                TraverUtil::TraverJsonValue(value,[&preheatFunc](std::string name,JValue* v){
                    preheatFunc(name,v);
                });
                flag_1 = true;
            }
            else if (name == "passivity") {
                TraverUtil::TraverJsonValue(value,[&passivityFunc](std::string name,JValue* v){
                    passivityFunc(name,v);
                });
                flag_2 = true;
            }
            return flag_1 && flag_2;
        });
        if (!success)
            LogUtil::LogError("init asset", "asset config error:[]");
    }
};


#endif //LIGHTWEIGHTRENDERER_ASSETCONTROLLER_H
