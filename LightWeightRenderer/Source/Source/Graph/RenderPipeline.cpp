//
// Created by MisThe on 2022/1/20.
//

#include "../../Head/Graph/RenderPipeline.h"

void RenderPipeline::render() {
    TraverUtil::TraverQueue<std::queue<RenderObject*>*>(&this->renderQueue,[](std::queue<RenderObject*>* queue) {
        TraverUtil::TraverQueue<RenderObject*>(queue,[](RenderObject* object){
            return object->render();
        });
    });
}

void RenderPipeline::init() {
    //扫描文件夹查找所有shader文件

    //扫描配置目录查找所有shader文件

    //编译shader文件
}


void RenderPipeline::loadShader() {

}


int RenderPipeline::addObject(RenderObject *ro) {

    return 0;
}

int RenderPipeline::addObject(RenderObject ro) {
    return addObject(&ro);
}

void RenderPipeline::dropObject(int index) {

}