//
// Created by MisThe on 2022/1/21.
//

#ifndef LIGHTWEIGHTRENDERER_MESH_H
#define LIGHTWEIGHTRENDERER_MESH_H

#include "../VertexInfo.h"
#include <string>

class Mesh {
public:
    VertexInfo*vertex;
public:
    Mesh(std::string path);
    void use();
private:
    std::string meshName;
private:
    void loadMesh(std::string path);
    void processMesh();
};


#endif //LIGHTWEIGHTRENDERER_MESH_H
