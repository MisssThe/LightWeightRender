//
// Created by MisThe on 2022/2/12.
//

#ifndef LIGHTWEIGHTRENDERER_MOUSEEQUIP_H
#define LIGHTWEIGHTRENDERER_MOUSEEQUIP_H


#include "BaseEquip.h"
#include "../../../../Utils/Head/MathUtil.h"

enum MouseMoveState
{
    SLIDE,DRAG,STOP     //鼠标左键在hold状态下移动视为drag
};

class MouseEquip : public BaseEquip
{
protected:
    void use() override;
protected:
    void update() override;
public:
    void indirectUpdate() override;
    MouseMoveState getMouseMoveState() const;
    ClickState getMouseClickState(bool isLeft = true) const;
private:
    MouseMoveState mouseMoveState;
    ClickState mouseClickState_1,mouseClickState_2;
    MathUtil::double2 position;
private:
    void updateMove();
    ClickState updateClick(int button,ClickState state);
};


#endif //LIGHTWEIGHTRENDERER_MOUSEEQUIP_H
