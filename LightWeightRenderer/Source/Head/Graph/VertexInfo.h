//
// Created by MisThe on 2022/1/21.
//

#ifndef LIGHTWEIGHTRENDERER_VERTEXINFO_H
#define LIGHTWEIGHTRENDERER_VERTEXINFO_H

#include <vector>
#include <glm/glm.hpp>
#include "../../../Utils/Head/MathUtil.h"

struct AttriStruct
{
public:
    int vertexNum  = 3;
    int offset     = 3;
    long initOffset = 3;
};

struct Vertex
{
public:
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec3 tangent;
    glm::vec4 color;
    glm::vec2 texcoord;
    glm::vec4 standby1;
    glm::vec4 standby2;
    glm::vec4 standby3;
public:
    int addStandby(glm::vec4 value,int index = 0)
    {
        index = MathUtil::Saturate(index,0,3);
        switch (index) {
            case 0:
                standby1 = value;
                break;
            case 1:
                standby2 = value;
                break;
            case 2:
                standby3 = value;
                break;
        }
        return MathUtil::Saturate(++index,0,3);
    }
};

class VertexInfo {
public:
    float*vertex;
    unsigned int*index;
    int vertexSize;
    int indexSize;
    std::vector<AttriStruct> attriVec;
};


#endif //LIGHTWEIGHTRENDERER_VERTEXINFO_H
