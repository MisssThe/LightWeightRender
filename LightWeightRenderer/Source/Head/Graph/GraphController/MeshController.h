//
// Created by MisThe on 2022/1/27.
//

#ifndef LIGHTWEIGHTRENDERER_MESHCONTROLLER_H
#define LIGHTWEIGHTRENDERER_MESHCONTROLLER_H


#include "../BaseRender/Mesh.h"
#include "../../../../Utils/Head/JsonUtil.h"

class MeshController {
public:
    static void Init();
    static Mesh*GetMesh(std::string name);
    static Mesh*CreateMesh(std::string path);
private:
    static std::unordered_map<std::string,Mesh*> mesh_map;
    static std::unordered_map<std::string,std::string> mesh_path_map;
    static std::string mesh_config_path;
    static bool isReady;
};


#endif //LIGHTWEIGHTRENDERER_MESHCONTROLLER_H
