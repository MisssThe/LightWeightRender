//
// Created by MisThe on 2022/2/11.
// 将要用到的数据暂存，减弱数据类型强制性
// 不建议频繁使用
//

#ifndef LIGHTWEIGHTRENDERER_DATASAVEUTIL_H
#define LIGHTWEIGHTRENDERER_DATASAVEUTIL_H

#include <iostream>
#include "TraverUtil.h"
#include "LogUtil.h"

class DataSaveUtil {
public:
    template<class T> static T FindData(int index)
    {
        void* data = nullptr;
        if (data_map.find(index) != data_map.end())
            data = data_map[index];
        else
            LogUtil::LogError("find data","index error");
        return *(T*)data;
    }

    template<class T> static T UseData(int index)
    {
        T result = FindData<T>(index);
        data_map.erase(index);
        return result;
    }

    //只能限定同种数据类型
    template<class T> static std::vector<T> UseData(std::vector<int> index_vec)
    {
        std::vector<T> vec;
        TraverUtil::TraverVector<int>(&index_vec,[&vec](int index){
            vec.push_back(UseData<T>(index));
        });
        return vec;
    }
    static int SaveData(int data);
    static int SaveData(char data);
    static int SaveData(float data);
    static int SaveData(bool data);
    static int SaveData(std::string data);
    static int SaveData(Json::Value data);
private:
    static std::unordered_map<int,void*> data_map;
    static long int base_index;
private:
    DataSaveUtil();

    template<class T> static void SaveDataReal(int key,T data)
    {
        data_map.insert(std::pair<int, void *>(key, data));
    }
};


#endif //LIGHTWEIGHTRENDERER_DATASAVEUTIL_H
