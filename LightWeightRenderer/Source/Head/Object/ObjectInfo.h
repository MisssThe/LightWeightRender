//
// Created by MisThe on 2022/3/3.
// 主要为了让组件可以逆向访问object信息
//

#ifndef LIGHTWEIGHTRENDERER_OBJECTINFO_H
#define LIGHTWEIGHTRENDERER_OBJECTINFO_H


#include "../../../Utils/Head/VoidQueueUtil.h"
#include "string"
#include "../Graph/RenderPipeline.h"

class ObjectInfo {
public:
    ObjectInfo(RenderPipeline* pipeline)
    {
        if (pipeline)
            this->pipeline = pipeline;
    }
    RenderPipeline* getPipeline()
    {
        return this->pipeline;
    }
    VoidQueueUtil* queueUtil;
    std::string name;
    int windowID = -1;
    int objectID = -1;
    bool isAlive;
private:
    RenderPipeline* pipeline;
};


#endif //LIGHTWEIGHTRENDERER_OBJECTINFO_H
