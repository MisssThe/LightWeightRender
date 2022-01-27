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

    template<class T> static void TraverVector(std::vector<T>*vector,std::function<void(T)> func) {
        if (vector != nullptr) {
            int length = vector->size();
            for (int i = 0; i < length; ++i) {
                func((*vector)[i]);
            }
        }
    }
    template<class T> static void TraverVectorBool(std::vector<T>*vector,std::function<bool(T)> func) {
        if (vector != nullptr) {
            int length = vector->size();
            for (int i = 0; i < length; ++i) {
                if (func((*vector)[i]))
                {
                    break;
                }
            }
        }
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
    static void TraverJsonValue(Json::Value* json,std::function<void(std::string,Json::Value*)> func){
        if (json->empty()) {
            Json::Value::Members members = json->getMemberNames();
            for (std::string member: members) {
                Json::Value *temp = &(*json)[member];
                TraverJsonValue(temp, func);
                func(member, temp);
            }
        }
    }
    static void TraverString(std::string str,std::function<void(char)> func)
    {
        int length = str.length();
        for (int i = 0; i < length; ++i) {
            func(str[i]);
        }
    }
};

#endif //LIGHTWEIGHTRENDERER_TRAVERUTIL_H
