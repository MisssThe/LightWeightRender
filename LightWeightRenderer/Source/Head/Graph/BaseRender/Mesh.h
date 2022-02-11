//
// Created by MisThe on 2022/1/21.
//

#ifndef LIGHTWEIGHTRENDERER_MESH_H
#define LIGHTWEIGHTRENDERER_MESH_H

#include <glad.h>
#include <string>
#include <unordered_map>
#include "../../../Head/Graph/MeshLoader/BaseLoader.h"
#include "../../../Head/Graph/MeshLoader/GeneralLoader.h"

class Mesh {
public:
    Mesh(std::string path);
    int getIndexSize();
    void use();
private:
    std::string meshName;
    unsigned int VAO;
    BaseLoader::MeshInfo*meshInfo;
    int indexSize;
private:
    void loadMesh(std::string path);
    void processMesh(BaseLoader::MeshInfo* meshInfo);
};


#endif //LIGHTWEIGHTRENDERER_MESH_H
