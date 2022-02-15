//
// Created by MisThe on 2022/2/14.
// 快捷键功能注册
//

#ifndef LIGHTWEIGHTRENDERER_SHORTCUTCONTROLLER_H
#define LIGHTWEIGHTRENDERER_SHORTCUTCONTROLLER_H

#include "../../../../Utils/Head/TraverUtil.h"
#include "InputController.h"

class ShortcutController {
public:
    static void Init();
    static void Update();
private:
    static std::unordered_map<KeyCode,std::function<void()>> shortcut_map;
};


#endif //LIGHTWEIGHTRENDERER_SHORTCUTCONTROLLER_H
