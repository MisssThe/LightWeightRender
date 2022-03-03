//
// Created by MisThe on 2022/2/21.
//

#ifndef LIGHTWEIGHTRENDERER_RENDERERCOMPONENT_H
#define LIGHTWEIGHTRENDERER_RENDERERCOMPONENT_H


#include "RenderPipeline.h"
#include "../Object/BaseComponent.h"

class RendererComponent : public BaseComponent
{
public:
    RendererComponent();
protected:
    bool use() override;
    void initProperty() override;
private:
    BaseRenderer* baseRenderer;
    int renderIndex = -1;
    bool isReady;
};


#endif //LIGHTWEIGHTRENDERER_RENDERERCOMPONENT_H
