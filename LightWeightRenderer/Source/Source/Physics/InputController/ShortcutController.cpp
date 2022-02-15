//
// Created by MisThe on 2022/2/14.
//

#include "../../../Head/Physics/InputController/ShortcutController.h"

std::unordered_map<KeyCode, std::function<void()>> ShortcutController::shortcut_map;

void ShortcutController::Update() {
    TraverUtil::TraverUMap<KeyCode, std::function<void()>>(&shortcut_map, [](KeyCode code, std::function<void()> func) {
        InputController::UseFunc(BaseEquip::EquipType::KEYBOARD, [&code, &func](BaseEquip *equip) {
            if (((KeyboardEquip*)equip)->getKeyClickState(code) == ClickState::PRESS)
            {
                func();
            }
        });
    });
}

void ShortcutController::Init() {
    shortcut_map.insert(std::pair<KeyCode, std::function<void()>>(KeyCode::FUNCTION_ESCAPE, []() {
        exit(0);
    }));
}
