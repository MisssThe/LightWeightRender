//
// Created by MisThe on 2022/2/10.
// 实现资源管理通用部分
//

#ifndef LIGHTWEIGHTRENDERER_ASSETCONTROLLER_H
#define LIGHTWEIGHTRENDERER_ASSETCONTROLLER_H


#include <value.h>

class AssetController {
private:
    AssetController();
    void loadAsset(Json::Value root);
};


#endif //LIGHTWEIGHTRENDERER_ASSETCONTROLLER_H
