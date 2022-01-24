//
// Created by MisThe on 2022/1/24.
//

#include "../../../Head/Graph/MeshLoader/BaseLoader.h"

std::unordered_map<std::string,BaseLoader::MeshInfo*> BaseLoader::mesh_map;

BaseLoader::MeshInfo *BaseLoader::processMesh(BaseLoader::TempMesh *tempMesh) {
    MeshInfo*finalMesh = new MeshInfo();
    finalMesh->vertex = reinterpret_cast<float *>(&tempMesh->vertexVec[0]);
    finalMesh->index = &tempMesh->indexVec[0];
    finalMesh->vertexSize = tempMesh->vertexVec.size() * sizeof(Vertex);
    finalMesh->indexSize = tempMesh->indexVec.size() * sizeof(unsigned int);
    finalMesh->attriVec.push_back({3,27,0});
    finalMesh->attriVec.push_back({3,27,3});
    finalMesh->attriVec.push_back({3,27,6});
    finalMesh->attriVec.push_back({4,27,9});
    finalMesh->attriVec.push_back({2,27,13});
    finalMesh->attriVec.push_back({4,27,15});
    finalMesh->attriVec.push_back({4,27,19});
    finalMesh->attriVec.push_back({4,27,23});
    return finalMesh;
}

BaseLoader::MeshInfo *BaseLoader::load(std::string path)
{
    MeshInfo* meshInfo = mesh_map[path];
    if (meshInfo == nullptr)
    {
        meshInfo = this->processMesh(this->starLoad(path));
        mesh_map[path] = meshInfo;
    }
    return meshInfo;
}

BaseLoader::MeshInfo::~MeshInfo()
{
    attriVec.clear();
    delete vertex;
}

void BaseLoader::TempMesh::addVertex(BaseLoader::Vertex vertex)
{
    vertexVec.push_back(vertex);
}

void BaseLoader::TempMesh::addIndex(unsigned int index)
{
    indexVec.push_back(index);
}

BaseLoader::Vertex BaseLoader::TempMesh::operator[](int index)
{
    if (index < vertexVec.size()) {
        return vertexVec[index];
    }
    LogUtil::LogError("IndexVertex","index out of range");
    return Vertex();
}

int BaseLoader::Vertex::addStandby(glm::vec4 value, int index)
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
