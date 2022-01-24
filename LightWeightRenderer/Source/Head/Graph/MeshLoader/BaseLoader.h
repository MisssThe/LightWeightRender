//
// Created by MisThe on 2022/1/24.
//

#ifndef LIGHTWEIGHTRENDERER_BASELOADER_H
#define LIGHTWEIGHTRENDERER_BASELOADER_H

#include <vector>
#include <string>
#include "../../../../Utils/Head/MathUtil.h"
#include <glm/glm.hpp>
#include <unordered_map>
#include "../../../../Utils/Head/LogUtil.h"

class BaseLoader {
public:
    struct Vertex
    {
    public:
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec3 tangent;
        glm::vec4 color;
        glm::vec2 texCoord;
        glm::vec4 standby1;
        glm::vec4 standby2;
        glm::vec4 standby3;
    public:
        int addStandby(glm::vec4 value,int index = 0);
    };
    struct TempMesh
    {
    public:
        void addVertex(Vertex vertex);
        void addIndex(unsigned int index);
        Vertex operator[](int index);
        std::vector<Vertex> vertexVec;
        std::vector<unsigned int> indexVec;
    };
    struct AttriStruct
    {
    public:
        int vertexNum  = 3;
        int offset     = 3;
        long initOffset = 3;
    };
    struct MeshInfo
    {
        float*vertex;
        unsigned int*index;
        int vertexSize;
        int indexSize;
        std::vector<AttriStruct> attriVec;
        ~MeshInfo();
    };
public:
    MeshInfo* load(std::string path);
    static void Clear()
    {
        mesh_map.clear();
    }
private:
    static std::unordered_map<std::string,MeshInfo*> mesh_map;
    MeshInfo* processMesh(TempMesh*tempMesh);
protected:
    Vertex tempVertex;
    TempMesh*tempMesh;
    virtual TempMesh* starLoad(std::string path) = 0;
};


#endif //LIGHTWEIGHTRENDERER_BASELOADER_H
