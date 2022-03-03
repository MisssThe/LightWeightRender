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
        bool flag = false;
        TraverUtil::TraverJsonValueBool(root, [&flag, &preheatFunc, &passivityFunc](std::string name, JValue *value) -> bool {
            flag = false;
            if (name == "preheat") {
                TraverUtil::TraverJsonValue(value,[&preheatFunc](std::string name,JValue* v){
                    preheatFunc(name,v);
                });
                return false;
            }
            else if (name == "passivity") {
                TraverUtil::TraverJsonValue(value,[&passivityFunc](std::string name,JValue* v){
                    passivityFunc(name,v);
                });
                return false;
            }
            flag = true;
            return true;
            return true;
        });
        if (flag)
            LogUtil::LogError("init asset", "asset config error:[]");
    }
};


#endif //LIGHTWEIGHTRENDERER_ASSETCONTROLLER_H
