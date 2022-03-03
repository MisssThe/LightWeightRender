//
// Created by MisThe on 2022/2/9.
//

#include "../../../Head/Graph/GraphController/CameraController.h"

std::unordered_map<std::string,Camera*> CameraController::camera_map;
Camera* CameraController::usingCamera;

void CameraController::AddCamera(Transform*transform,std::string name) {
//    camera_map.insert(std::pair<std::string,Camera*>(name,new Camera()))
}

void CameraController::DeleteCamera(std::string name) {
    camera_map.erase(name);
}

//glm::mat4 *CameraController::GetPMatrix() {
//    if (usingCamera)
//        return usingCamera->getPMatrix();
//}
//
//glm::mat4 *CameraController::GetVMatrix() {
//    return nullptr;
//}

void CameraController::ChangeCamera(std::string name) {
    if (camera_map.find(name) != camera_map.end())
        usingCamera = camera_map[name];
    else
        LogUtil::LogWarning("change camera","error camera name");
}

Camera *CameraController::GetCamera() {
    if (!usingCamera)
        LogUtil::LogError("get camera","null camera");
    return usingCamera;
}
