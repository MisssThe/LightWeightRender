//
// Created by MisThe on 2022/2/11.
//

#include "../Head/DataSaveUtil.h"

//index: 0 = int
std::unordered_map<int, void *> DataSaveUtil::data_map;
long int DataSaveUtil::base_index = 0;

DataSaveUtil::DataSaveUtil() {

}

int DataSaveUtil::SaveData(int data) {
    int index = base_index++;
    int *tempData = new int();
    *tempData = data;
    SaveDataReal(index, tempData);
    return index;
}

int DataSaveUtil::SaveData(char data) {
    int index = base_index++;
    char *tempData = new char();
    *tempData = data;
    SaveDataReal(index, tempData);
    return index;
}

int DataSaveUtil::SaveData(float data) {
    int index = base_index++;
    float *tempData = new float();
    *tempData = data;
    SaveDataReal(index, tempData);
    return index;
}

int DataSaveUtil::SaveData(bool data) {
    int index = base_index++;
    bool *tempData = new bool();
    *tempData = data;
    SaveDataReal(index, tempData);
    return index;
}

int DataSaveUtil::SaveData(std::string data) {
    int index = base_index++;
    std::string *tempData = new std::string();
    *tempData = data;
    SaveDataReal(index, tempData);
    return index;
}

int DataSaveUtil::SaveData(Json::Value data) {
    int index = base_index++;
    Json::Value *tempData = new Json::Value();
    *tempData = data;
    SaveDataReal(index, tempData);
    return index;
}