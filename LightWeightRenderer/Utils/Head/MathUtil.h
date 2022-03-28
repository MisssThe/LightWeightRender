//
// Created by MisThe on 2022/1/20.
// 封装常用数学工具
//

#ifndef LIGHTWEIGHTRENDERER_MATHUTIL_H
#define LIGHTWEIGHTRENDERER_MATHUTIL_H

#include <ostream>
#include "string"

enum DataType
{
    VEC,VEC2,VEC3
};

class MathUtil {
public:
    struct int2
    {
    public:
        int x, y;
    public:
        bool equal(int2 num);
        friend std::ostream &operator<<(std::ostream &os, const int2 &int2);
    };
    struct float2
    {

    };
    struct double2
    {
    public:
        double x, y;
    public:
        bool equal(double2 num);

        friend std::ostream &operator<<(std::ostream &os, const double2 &double2);
    };
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
