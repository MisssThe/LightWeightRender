//
// Created by MisThe on 2022/2/21.
// 只能有一个object loop
//

#ifndef LIGHTWEIGHTRENDERER_OBJECTLOOP_H
#define LIGHTWEIGHTRENDERER_OBJECTLOOP_H


#include "../../../Utils/Head/TraverUtil.h"
#include "BaseObject.h"
#include "../../../Config/Config.h"
#include "../../../Utils/Head/ThreadUtil.h"

class ObjectLoop : public AssetController
{
public:
    static void Init();
    static void Run();
    static void AddObject(BaseObject*object);
private:
    static std::queue<BaseObject*> object_queue;
private:
    static BaseObject* CreateBaseObject(std::string path);
};


#endif //LIGHTWEIGHTRENDERER_OBJECTLOOP_H
