//
// Created by MisThe on 2022/1/20.
// 常用数据结构遍历，模版函数不要在cpp文件中定义
//

#ifndef LIGHTWEIGHTRENDERER_TRAVERUTIL_H
#define LIGHTWEIGHTRENDERER_TRAVERUTIL_H

#include <queue>
#include <vector>
#include <unordered_map>
#include <map>
#include <json.h>


class TraverUtil{
public:
    template<class T> static void TraverQueue(std::queue<T>*queue,std::function<void(T)> func) {
        if (queue != nullptr) {
            int length = queue->size();
            if (length > 0) {
                T element;
                for (int i = 0; i < length; ++i) {
                    element = queue->front();
                    func(element);
                    queue->pop();
                    queue->push(element);
                }
            }
        }
    }
    //@return false：剔除 true：继续
    template<class T> static void TraverQueueBool(std::queue<T>*queue,std::function<bool(T)> func) {
        if (queue != nullptr) {
            int length = queue->size();
            if (length > 0) {
                T element;
                for (int i = 0; i < length; ++i) {
                    element = queue->front();
                    queue->pop();
                    if (func(element))
                        queue->push(element);
                }
            }
        }
    }
    //@return false：继续 true：结束
    template<class T> static void TraverQueueBreak(std::queue<T>*queue,std::function<bool(T)> func) {
        if (queue != nullptr) {
            int length = queue->size();
            if (length > 0) {
                T element;
                for (int i = 0; i < length; ++i) {
                    element = queue->front();
                    queue->pop();
                    if (func(element))
                        return;
                }
            }
        }
    }
    //@return true: 存在 false: 不存在
    template<class T> static bool ExistInQueue(std::queue<T>* queue,T value)
    {
        bool isExist = false;
        TraverQueueBreak<T>(queue,[&value, &isExist](T v) {
            if (v == value)
                isExist = true;
            return isExist;
        });
        return isExist;
    }

    template<class T> static void TraverVector(std::vector<T>*vector,std::function<void(T)> func) {
        if (vector != nullptr) {
            int length = vector->size();
            for (int i = 0; i < length; ++i) {
                func((*vector)[i]);
            }
        }
    }

    //@return true:成功中断 false:未中断
    template<class T> static bool TraverVectorBool(std::vector<T>*vector,std::function<bool(T)> func) {
        if (vector != nullptr) {
            int length = vector->size();
            for (int i = 0; i < length; ++i) {
                if (func((*vector)[i]))
                {
                    return true;
                }
            }
        }
        return false;
    }
    template<class T1,class T2> static void TraverUMap(std::unordered_map<T1,T2>*umap,std::function<void(T1,T2)> func) {
        if (umap != nullptr) {
            for (auto item:*umap)
            {
                func(item.first,item.second);
            }
        }
    }
    template<class T1,class T2> static void TraverMap(std::map<T1,T2>*map,std::function<void(T1,T2)> func) {
        if (map != nullptr) {
            for (auto item:*map)
            {
                func(item.first,item.second);
            }
        }
    }

    //不可中断json value 遍历
    static void TraverJsonValue(Json::Value* json,std::function<void(std::string,Json::Value*)> func){
        if (!json->empty() && json->isObject()) {
            Json::Value::Members members = json->getMemberNames();
            for (std::string member: members) {
                Json::Value *temp = &(*json)[member];
                func(member, temp);
                TraverJsonValue(temp, func);
            }
        }
    }

    //map取交集操作
    template<class T1,class T2,class T3> static void MapIntersect(std::unordered_map<T1,T2>*map1,std::unordered_map<T1,T3>*map2,std::function<void(T2,T3)> func)
    {
        TraverUMap(map1,[&map2, &func](T1 key,T2 value) {
            if (map2->find(key) != map2->end())
                func(value,map2[key]);
        });
    }

    // 可中断json value遍历
    // @return true 中断，false 继续
    static bool TraverJsonValueBool(Json::Value* json,std::function<bool(std::string,Json::Value*)> func){
        if (!json->empty() && json->isObject()) {
            Json::Value::Members members = json->getMemberNames();
            for (std::string member: members) {
                Json::Value *temp = &(*json)[member];
                if (func(member, temp))
                    return true;
                if (TraverJsonValueBool(temp, func))
                    return true;
            }
        }
        return false;
    }

    static void TraverString(std::string str,std::function<void(char)> func)
    {
        int length = str.length();
        for (int i = 0; i < length; ++i) {
            func(str[i]);
        }
    }
    //遍历枚举
    template<class T> static void TraverEnum(T begin,T end,std::function<void(T)> func)
    {
        int int_begin = (int)begin + 1;
        int int_end  = end;
        for (int i = int_begin; i < int_end; ++i) {
            func(T(i));
        }
    }
};

#endif //LIGHTWEIGHTRENDERER_TRAVERUTIL_H
