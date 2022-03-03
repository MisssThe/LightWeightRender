//
// Created by MisThe on 2022/2/21.
//

#include "RendererComponent.h"

//从object loop 添加到 render pipe line中
bool RendererComponent::use() {
    if (!this->isEnable && this->renderIndex > 0)
    {
        this->objectInfo->getPipeline()->dropRenderer(this->renderIndex);
        this->renderIndex = -1;
    }
    if (this->isReady || !this->baseRenderer)
        return true;
    this->isReady = true;
    this->renderIndex = this->objectInfo->getPipeline()->addRenderer(this->baseRenderer);
    return false;
}

void RendererComponent::initProperty() {
    this->name = "RendererComponent";
}

RendererComponent::RendererComponent() {
    this->isReady = false;
    this->baseRenderer = new BaseRenderer();
}