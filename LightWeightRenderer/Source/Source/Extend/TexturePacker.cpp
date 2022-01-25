//
// Created by MisThe on 2022/1/25.
//

#include "../../Head/Extend/TexturePacker.h"

void TexturePacker::pack(TexturePacker::PackType type) {
    switch (type) {
        case TexturePacker::PackType::LLABF:
            this->rectPackByLLABF();
            break;
        case TexturePacker::PackType::BT:
            this->rectPackByBT();
            break;
    }
}

//----------------------- LLABF实现 -----------------------
void TexturePacker::rectPackByLLABF() {
    while (true)
    {
        if (FFF()) {

        } else if (WFF()) {

        } else if (HFF()) {

        } else if (JWFF()) {

        } else if (PF()) {

        }
    }
}

bool TexturePacker::FFF() {

}

bool TexturePacker::WFF() {

}

bool TexturePacker::HFF() {

}

bool TexturePacker::JWFF() {

}

bool TexturePacker::PF() {

}
//----------------------- LLABF实现 -----------------------


//----------------------- 二叉树实现 -----------------------
void TexturePacker::rectPackByBT() {

}
//----------------------- 二叉树实现 -----------------------