//
// Created by MisThe on 2022/1/20.
//

#include "../../Head/Graph/RenderPipeline.h"

void RenderPipeline::render() {
    TraverUtil::TraverQueue<RenderQueue*>(&this->renderQueue,[](RenderQueue* queue) {
        TraverUtil::TraverQueue<RenderObject*>(&queue->queue,[](RenderObject* object){
            return object->render();
        });
    });
}

void RenderPipeline::init() {
    int begin = RenderType::BEGIN;
    for (int i = ++begin; i < RenderType::END; ++i) {
        RenderQueue* rq = new RenderQueue();
        rq->type = RenderType(i);
        this->renderQueue.push(rq);
    }
}


int RenderPipeline::addObject(RenderObject *ro) {
    if (ro)
    {
        if ((int)ro->getType() > this->renderQueue.size())
            LogUtil::LogError("add object in pipeline","error render type");
        TraverUtil::TraverQueue<RenderQueue*>(&this->renderQueue,[&ro, this](RenderQueue*rq){
            if (rq->type == ro->getType())
                rq->queue.push(ro);
        });

    }
    else
        LogUtil::LogError("add object in pipeline","null object");
    return 0;
}

int RenderPipeline::addObject(RenderObject ro) {
    return addObject(&ro);
}

void RenderPipeline::dropObject(int index) {

}

RenderPipeline::RenderPipeline() {
    this->init();
}
