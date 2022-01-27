//
// Created by MisThe on 2022/1/21.
// 记录的数据暂处于内存中，刷新或更换shader时刷新磁盘文件
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
    void use();
private:
    std::string meshName;
    unsigned int VAO;
    BaseLoader::MeshInfo*meshInfo;
private:
    void loadMesh(std::string path);
    void processMesh(BaseLoader::MeshInfo* meshInfo);
};


#endif //LIGHTWEIGHTRENDERER_MESH_H
