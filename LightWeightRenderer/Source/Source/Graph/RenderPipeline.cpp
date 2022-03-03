//
// Created by MisThe on 2022/1/20.
// 和批方式（按材质和批（可以节省材质数据设置））
//

#include "../../Head/Graph/RenderPipeline.h"

std::vector<RenderPipeline*> RenderPipeline::pipeline_vec;

void RenderPipeline::render() {
    TraverUtil::TraverQueue<RenderQueue*>(&this->renderQueue,[](RenderQueue* queue) {
        TraverUtil::TraverQueue<BaseRenderer*>(&queue->queue,[](BaseRenderer* object){
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
    this->index = pipeline_vec.size();
    pipeline_vec.push_back(this);
}

int RenderPipeline::addRenderer(BaseRenderer *br) {
    if (br)
    {
        if ((int)br->getType() > this->renderQueue.size())
            LogUtil::LogError("add object in pipeline","error render type");
        TraverUtil::TraverQueue<RenderQueue*>(&this->renderQueue,[&br, this](RenderQueue*rq){
            if (rq->type == br->getType())
                rq->queue.push(br);
        });
    }
    else
        LogUtil::LogError("add object in pipeline","null object");
    return 0;
}

void RenderPipeline::dropRenderer(int index) {

}

RenderPipeline::RenderPipeline() {
    this->init();
}

RenderPipeline *RenderPipeline::GetPipeLine(int index) {
    return nullptr;
}

int RenderPipeline::getIndex() {
    return this->index;
}

void RenderPipeline::loadShader() {

}
