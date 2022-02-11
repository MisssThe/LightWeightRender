//
// Created by MisThe on 2022/1/27.
//

#ifndef LIGHTWEIGHTRENDERER_MESHCONTROLLER_H
#define LIGHTWEIGHTRENDERER_MESHCONTROLLER_H


#include "../BaseRender/Mesh.h"
#include "../../../../Utils/Head/JsonUtil.h"
#include "AssetController.h"

class MeshController : public AssetController
{
public:
    static void Init();
    static Mesh*GetMesh(std::string name);
    static Mesh*GetSquareMesh();
    static Mesh*GetCubeMesh();
private:
    static std::unordered_map<std::string,Mesh*> mesh_map;
    static std::unordered_map<std::string,std::string> mesh_path_map;
    static std::string mesh_config_path;
    static bool isReady;

    static std::string square_mesh_name;
    static std::string cube_mesh_name;
};


#endif //LIGHTWEIGHTRENDERER_MESHCONTROLLER_H
