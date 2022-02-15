//
// Created by MisThe on 2022/2/14.
//

#ifndef LIGHTWEIGHTRENDERER_KEYBOARDEQUIP_H
#define LIGHTWEIGHTRENDERER_KEYBOARDEQUIP_H


#include "BaseEquip.h"

enum KeyCode {
    NUM_BEGIN = 47,
    NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5, NUM_6, NUM_7, NUM_8, NUM_9,
    NUM_END,

    LETTER_BEGIN = 64,
    LETTER_A, LETTER_B, LETTER_C, LETTER_D, LETTER_E, LETTER_F, LETTER_G, LETTER_H, LETTER_I,
    LETTER_J, LETTER_K, LETTER_L, LETTER_M, LETTER_N, LETTER_O, LETTER_P, LETTER_Q, LETTER_R,
    LETTER_S, LETTER_T, LETTER_U, LETTER_V, LETTER_W, LETTER_X, LETTER_Y, LETTER_Z,
    LETTER_END,

    FUNCTION_BEGIN = 255,
    FUNCTION_ESCAPE, FUNCTION_ENTER, FUNCTION_TAB, FUNCTION_BACKSPACE, FUNCTION_INSERT, FUNCTION_DELETE, FUNCTION_RIGHT,
    FUNCTION_LEFT, FUNCTION_DOWN, FUNCTION_UP, FUNCTION_PAGE_UP, FUNCTION_PAGE_DOWN, FUNCTION_HOME,
    FUNCTION_END
};

class KeyboardEquip : public BaseEquip {
public:
    KeyboardEquip();
    void indirectUpdate() override;
    ClickState getKeyClickState(KeyCode code);
protected:
    void use() override;
    void update() override;
private:
    std::unordered_map<KeyCode, ClickState> keyMap;
};


#endif //LIGHTWEIGHTRENDERER_KEYBOARDEQUIP_H
