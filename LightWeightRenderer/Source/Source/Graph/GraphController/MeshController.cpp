//
// Created by MisThe on 2022/1/27.
//

#include "../../../Head/Graph/GraphController/MeshController.h"

std::unordered_map<std::string,Mesh*> MeshController::mesh_map;
std::unordered_map<std::string,std::string> MeshController::mesh_path_map;
std::string MeshController::mesh_config_path = "LightWeightRenderer/Config/MeshConfig.json";
bool MeshController::isReady = false;
//-------------- 基础网格默认路径 ----------------
std::string MeshController::square_mesh_name = "square";
std::string MeshController::cube_mesh_name = "cube";
//-------------- 基础网格默认路径 ----------------

void MeshController::Init() {
    if (!isReady)
    {
        isReady = true;
        InitAsset(mesh_config_path,[](std::string name,JValue* value) {
                std::string path = value->asString();
                path = FileUtil::CheckPath(path);
                path = FileUtil::CheckPath(path);
                mesh_path_map.insert(std::pair<std::string,std::string>(name,path));
                Mesh*mesh = new Mesh(path);
                mesh_map.insert(std::pair<std::string,Mesh*>(name,mesh));
        },[](std::string name,JValue* value){
                std::string path = FileUtil::CheckPath(value->asString());
                mesh_path_map.insert(std::pair<std::string,std::string>(name,path));
        });
    }
}

Mesh *MeshController::GetMesh(std::string name) {
    Mesh* mesh = nullptr;
    if (mesh_map.find(name) != mesh_map.end())
        mesh = mesh_map[name];
    else
    {
        std::string path = mesh_path_map[name];
        path = FileUtil::CheckPath(path);
        mesh = new Mesh(path);
        if (mesh_path_map.find(name) == mesh_path_map.end())
            LogUtil::LogError("get mesh","mesh name error");
        mesh_map.insert(std::pair<std::string,Mesh*>(name,mesh));
    }
    return mesh;
}

Mesh *MeshController::GetSquareMesh() {
    return GetMesh(square_mesh_name);
}

Mesh *MeshController::GetCubeMesh() {
    return GetMesh(cube_mesh_name);
}
