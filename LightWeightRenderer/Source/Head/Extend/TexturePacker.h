//
// Created by MisThe on 2022/1/25.
// 实现图集打包功能（LLABF、二叉树）
// 默认从左下角开始排列
//

#ifndef LIGHTWEIGHTRENDERER_TEXTUREPACKER_H
#define LIGHTWEIGHTRENDERER_TEXTUREPACKER_H

#include <vector>
#include <glm/vec2.hpp>
#include "../Graph/BaseRender/Texture.h"
#include "../../../Utils/Head/TraverUtil.h"
#include "../../../Utils/Head/SortUtil.h"

class TexturePacker {
public:
    enum PackType
    {
        LLABF,BT
    };
public:
    void pack(std::vector<Texture*> textures,PackType type);
private:
    std::vector<Texture*> textures;
    std::vector<Texture*> standbyTextures;       //texture无法装入图集时暂时放入备用容器
    struct int2
    {
        int x,y;
    };
    struct ClearArea
    {
        int2 pos;
        int2 size;
    };
    int2 size;                   //2的整数倍
private:
    void rectPackByLLABF();     //矩形装箱LLABF实现
    void rectPackByBT(ClearArea area1,ClearArea area2);        //矩形装箱二叉树实现
    bool calculatePosAndSize(Texture texture, ClearArea* area1, TexturePacker::ClearArea* area2);
    bool FFF();                 //完全匹配优先（full fit first）
    bool WFF();                 //宽度匹配（width fit first）
    bool HFF();                 //高度匹配（height fit first）
    bool JWFF();                //组合宽度匹配（join width fit first）
    bool PF();                  //可装入优先（place able first）
};


#endif //LIGHTWEIGHTRENDERER_TEXTUREPACKER_H
