//
// Created by MisThe on 2022/2/16.
// 弃用不必要的方法

#ifndef LIGHTWEIGHTRENDERER_RENDERCOMPONENT_H
#define LIGHTWEIGHTRENDERER_RENDERCOMPONENT_H

#include "../../../Utils/Head/JsonUtil.h"
#include "string"
#include "../../../Utils/Head/MathUtil.h"

class RenderComponent
{
public:
    struct KeyWord
    {
    private:
        DataType dataType;
    public:
        int location;
    public:
        KeyWord() {}
        KeyWord(std::string type)
        {
            if (type == "float")
                this->dataType = DataType::VEC;
            else if (type == "float2")
                this->dataType = DataType::VEC2;
            else if (type == "float3")
                this->dataType = DataType::VEC3;
        }
        bool equalType(std::string type)
        {
            switch (this->dataType) {
                case DataType::VEC:
                    return type == "float";
                case DataType::VEC2:
                    return type == "float2";
                case DataType::VEC3:
                    return type == "float3";
            }
        }
        //数据刷新时要重新调用
        std::function<void()> getFunc(Json::Value* value)
        {
            switch (this->dataType) {
                case DataType::VEC:
                {
                    float vec = value->asFloat();
                    return [this, vec]() { glUniform1f(this->location, vec); };
                }
                case DataType::VEC2:
                {
                    std::vector<float> vec = JsonUtil::JsonToArray<float>(value);
                    return [this, vec]() {glUniform2fv(this->location,2,vec.begin().base());};
                }
                case DataType::VEC3:
                {
                    std::vector<float> vec = JsonUtil::JsonToArray<float>(value);
                    return [this, vec]() { glUniform3fv(this->location, 3, &(vec[0])); };
                }
                default:
                    LogUtil::LogError("Shader Get Func","error type");
            }
        }
    private:
    };
public:
    virtual void render() = 0;
};


#endif //LIGHTWEIGHTRENDERER_RENDERCOMPONENT_H
