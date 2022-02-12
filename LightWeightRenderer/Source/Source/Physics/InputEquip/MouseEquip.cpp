//
// Created by MisThe on 2022/2/12.
//

#include "../../../Head/Physics/InputEquip/MouseEquip.h"

void MouseEquip::use() {

}

void MouseEquip::update() {
    //刷新鼠标点击情况
    this->mouseClickState_1 = this->updateClick(0, this->mouseClickState_1);
    this->mouseClickState_2 = this->updateClick(1, this->mouseClickState_2);
    //刷新鼠标运动情况
    this->updateMove();
}

MouseMoveState MouseEquip::getMouseMoveState() const {
    return mouseMoveState;
}

MouseClickState MouseEquip::getMouseClickState(bool isLeft) const {
    if (isLeft)
        return mouseClickState_1;
    return mouseClickState_2;
}

void MouseEquip::updateMove() {
    MathUtil::double2 oldPosition = this->position;
    glfwGetCursorPos(this->window,&(this->position.x),&(this->position.y));
    if (oldPosition.equal(this->position))
        this->mouseMoveState = MouseMoveState::STOP;
    else
        if (this->mouseClickState_1 != MouseClickState::HOLD)
            this->mouseMoveState = MouseMoveState::SLIDE;
        else
            this->mouseMoveState = MouseMoveState::DRAG;
}

MouseClickState MouseEquip::updateClick(int button,MouseClickState state) {
    int click = glfwGetMouseButton(window,button);
    int oldClick = state;
    int newClick = click?(oldClick < PRESS?PRESS:HOLD):(oldClick > LOOSE?RELEASE:LOOSE);
    return MouseClickState(newClick);
}

void MouseEquip::indirectUpdate() {
    LogUtil::LogError("indirect update", "try to direct use");
}
