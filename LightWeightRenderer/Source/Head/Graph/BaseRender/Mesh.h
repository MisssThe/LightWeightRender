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
    struct MeshInfo
    {

    };
public:
    Mesh(std::string path);
    void use();
private:
    std::string meshName;
    unsigned int VAO;
    static std::unordered_map<std::string,MeshInfo> mesh_map;
private:
    void loadMesh(std::string path);
    void processMesh(BaseLoader::MeshInfo* meshInfo);
};


#endif //LIGHTWEIGHTRENDERER_MESH_H
