//
// Created by MisThe on 2022/2/10.
//

#include "../../../Head/Graph/GraphController/RenderObjectController.h"

std::string RenderObjectController::object_config_path = "LightWeightRenderer/Config/ObjectConfig.json";
bool RenderObjectController::isReady = false;
std::unordered_map<std::string, RenderObject *> RenderObjectController::object_map;
std::unordered_map<std::string, std::string> RenderObjectController::object_path_map;

RenderObjectController::RenderObjectController() {

}

void RenderObjectController::Init() {
    if (!isReady) {
        isReady = true;
        InitAsset(object_config_path, [](std::string name, JValue *value) {
            std::string path = value->asString();
            Json::Value object = JsonUtil::ReadJson(path);
            std::vector<int> index_vec = JsonUtil::JsonToArray<float>(object["transform"]);
            std::vector<float> vec = DataSaveUtil::UseData<float>(index_vec);
            RenderObject *ro = new RenderObject(
                    ShaderController::GetShader(object["shader"].asString()),
                    MaterialController::GetMaterial(object["material"].asString()),
                    MeshController::GetMesh(object["mesh"].asString()),
                    new Transform(vec)
            );
            object_map.insert(std::pair<std::string, RenderObject *>(name, ro));
            object_path_map.insert(std::pair<std::string, std::string>(name, path));
        }, [](std::string name, JValue *value) {
            std::string path = value->asString();
            object_path_map.insert(std::pair<std::string, std::string>(name, path));
        });
    }
}

void RenderObjectController::GetObject(std::string name) {

}

void RenderObjectController::TraverObject(std::function<void(RenderObject *)> func) {
    TraverUtil::TraverUMap<std::string,RenderObject*>(&object_map,[&func](std::string name,RenderObject*ro){
        func(ro);
    });
}
