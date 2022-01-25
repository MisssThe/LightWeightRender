//
// Created by MisThe on 2022/1/25.
// 实现图集打包功能（LLABF、二叉树）
//

#ifndef LIGHTWEIGHTRENDERER_TEXTUREPACKER_H
#define LIGHTWEIGHTRENDERER_TEXTUREPACKER_H


class TexturePacker {
public:
    enum PackType
    {
        LLABF,BT
    };
public:
    void pack(PackType type);
private:
    void rectPackByLLABF();     //矩形装箱LLABF实现
    void rectPackByBT();        //矩形装箱二叉树实现
    bool FFF();                 //完全匹配优先（full fit first）
    bool WFF();                 //宽度匹配（width fit first）
    bool HFF();                 //高度匹配（height fit first）
    bool JWFF();                //组合宽度匹配（join width fit first）
    bool PF();                  //可装入优先（place able first）
};


#endif //LIGHTWEIGHTRENDERER_TEXTUREPACKER_H
