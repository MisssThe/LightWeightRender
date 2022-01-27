//
// Created by MisThe on 2022/1/26.
// 封装常用排序
//

#ifndef LIGHTWEIGHTRENDERER_SORTUTIL_H
#define LIGHTWEIGHTRENDERER_SORTUTIL_H


#include <functional>

class SortUtil {
public:
    enum SortType
    {
        BUBBLE,SELECTION,INSERTION,SHELL,MERGE,QUICK,HEAP,COUNTING,BUCKET,RADIX
    };
public:
    template<class T> static void Sort(std::vector<T>* vec,std::function<bool(T,T)> func,SortType type)
    {
        switch (type) {
            case SortType::BUBBLE:
                BubbleSort<T>(vec,func);
                break;
            case SortType::SELECTION:
                break;
            case SortType::INSERTION:
                break;
            case SortType::SHELL:
                break;
            case SortType::MERGE:
                break;
            case SortType::QUICK:
                break;
            case SortType::HEAP:
                break;
            case SortType::COUNTING:
                break;
            case SortType::BUCKET:
                break;
            case SortType::RADIX:
                break;
        }
    }
private:
    template<class T> static void BubbleSort(std::vector<T>*vec,std::function<bool(T,T)> func)
    {
        int length = vec->size();
        for (int i = length - 1; i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                bool flag = func((*vec)[j],(*vec)[j+1]);
                if (flag)
                {
                    T temp      = (*vec)[j];
                    (*vec)[j]   = (*vec)[j+1];
                    (*vec)[j+1] = temp;
                }
            }
        }
    }
//    SELECTION,INSERTION,SHELL,MERGE,QUICK,HEAP,COUNTING,BUCKET,RADIX

};


#endif //LIGHTWEIGHTRENDERER_SORTUTIL_H
