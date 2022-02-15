//
// Created by MisThe on 2022/2/14.
//

#include "../../../Head/Physics/InputEquip/KeyboardEquip.h"

void KeyboardEquip::indirectUpdate() {
    LogUtil::LogError("indirect update in keyboard", "try to indirect use update");
}

void KeyboardEquip::use() {

}

void KeyboardEquip::update() {
    TraverUtil::TraverUMap<KeyCode, ClickState>(&this->keyMap, [this](KeyCode keyCode, ClickState clickState) {
        int click = glfwGetKey(this->window, keyCode);
        clickState = this->updateClickState(click, clickState);
        this->keyMap[keyCode] = clickState;
    });
}

ClickState KeyboardEquip::getKeyClickState(KeyCode code) {
    return this->keyMap[code];
}

KeyboardEquip::KeyboardEquip() {
    std::function<void(KeyCode)> func = [this](KeyCode code) {
        this->keyMap.insert(std::pair<KeyCode, ClickState>(code, ClickState::LOOSE));
    };
    TraverUtil::TraverEnum<KeyCode>(KeyCode::NUM_BEGIN, KeyCode::NUM_END, func);
    TraverUtil::TraverEnum<KeyCode>(KeyCode::LETTER_BEGIN, KeyCode::LETTER_END, func);
    TraverUtil::TraverEnum<KeyCode>(KeyCode::FUNCTION_BEGIN, KeyCode::FUNCTION_END, func);
}
