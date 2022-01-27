//
// Created by MisThe on 2022/1/25.
//

#include "../../Head/Extend/TexturePacker.h"

void TexturePacker::pack(std::vector<Texture> textures, TexturePacker::PackType type) {
    this->textures = textures;

    //对texture按面积大小排序(从小到大)
    SortUtil::Sort<Texture>(&this->textures,[](Texture t1,Texture t2)->bool {
        int area1 = t1.getHeight() * t1.getWidth();
        int area2 = t2.getHeight() * t2.getWidth();
        if (area1 < area2)
            return true;
        else
            return false;
    },SortUtil::SortType::BUBBLE);
    do {
        switch (type) {
            case TexturePacker::PackType::LLABF:
                this->rectPackByLLABF();
                break;
            case TexturePacker::PackType::BT:
                this->rectPackByBT(
                        {{0,0},{0,0}},
                        {{0,0},{this->size.x, this->size.y}}
                );
                break;
        }
        //判断是否需要继续打包额外图集
        if (this->standbyTextures.size() == 0)
            break;
        else
            TraverUtil::TraverVector<Texture>(&this->standbyTextures,[this](Texture texture){
                this->textures.push_back(texture);
            });
        this->standbyTextures.clear();
    } while (true);
}

//----------------------- LLABF实现 -----------------------
void TexturePacker::rectPackByLLABF() {
    TraverUtil::TraverVector<Texture>(&this->textures,[this](Texture texture){
        if (this->FFF()) {

        } else if (this->WFF()) {

        } else if (this->HFF()) {

        } else if (this->JWFF()) {

        } else if (this->PF()) {

        }
    });
}

bool TexturePacker::FFF() {
    return false;
}

bool TexturePacker::WFF() {
    return false;
}

bool TexturePacker::HFF() {
    return false;
}

bool TexturePacker::JWFF() {
    TraverUtil::TraverVector<Texture>(&this->textures,[this](Texture texture)->bool {
        if ((texture.getWidth() + textures[0].getWidth()) == this->size.x)
        {
            return true;
        }
        return false;
    });
    return false;
}

bool TexturePacker::PF() {
    return false;
}
//----------------------- LLABF实现 -----------------------


//----------------------- 二叉树实现 -----------------------
//默认向右配置大区域
void TexturePacker::rectPackByBT(ClearArea area1,ClearArea area2) {
    if (this->textures.size() > 0)
    {
        ClearArea nextArea;
        Texture texture = this->textures[this->textures.size() - 1];
        this->textures.resize(this->textures.size() - 1);
        if (this->calculatePosAndSize(texture,&area1,&nextArea))
        {
            texture = this->textures[this->textures.size() - 1];
            this->textures.resize(this->textures.size() - 1);
            this->rectPackByBT(area1,nextArea);
        }
        if (!this->calculatePosAndSize(texture,&area2,&nextArea))
        {
            this->textures.push_back(texture);
        }
        this->rectPackByBT(area2,nextArea);
    }
}

bool TexturePacker::calculatePosAndSize(Texture texture, TexturePacker::ClearArea* area1,TexturePacker::ClearArea* area2) {
//    if ()
    if (texture.getWidth() < area1->size.x || texture.getHeight() < area1->size.y)
    {
        return false;
    }
    TexturePacker::ClearArea tempArea = *area1;
    area1->pos  = {tempArea.pos.x,     tempArea.pos.y + texture.getHeight()};
    area1->size = {texture.getWidth(),tempArea.size.y - texture.getHeight()};
    area2->pos  = {tempArea.pos.x + texture.getWidth(),      tempArea.pos.y};
    area2->size = {tempArea.size.x - texture.getWidth(),texture.getHeight()};
    return true;
}

//----------------------- 二叉树实现 -----------------------