//
// Created by MisThe on 2022/1/20.
// 封装常用数学工具
//

#ifndef LIGHTWEIGHTRENDERER_MATHUTIL_H
#define LIGHTWEIGHTRENDERER_MATHUTIL_H


class MathUtil {
public:
    //限制输入范围
    template<class T> static T Saturate(T x,T t1,T t2)
    {
        x = x < t1 ? t1 : x;
        x = x > t2 ? t2 : x;
        return x;
    }
};


#endif //LIGHTWEIGHTRENDERER_MATHUTIL_H
