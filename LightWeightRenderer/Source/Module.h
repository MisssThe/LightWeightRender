//
// Created by MisThe on 2022/1/20.
// 模块基类，保证所有模块有良好继承关系
//

#ifndef LIGHTWEIGHTRENDERER_MODULE_H
#define LIGHTWEIGHTRENDERER_MODULE_H
class Module
{
protected:
    //----------组件生命周期-----------
    virtual void init()   = 0;
    virtual void update() = 0;
    virtual void pause()  = 0;
    virtual void resume() = 0;
    virtual void stop()   = 0;
};
#endif //LIGHTWEIGHTRENDERER_MODULE_H
