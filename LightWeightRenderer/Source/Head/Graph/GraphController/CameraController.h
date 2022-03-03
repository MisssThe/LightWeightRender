//
// Created by MisThe on 2022/2/9.
//

#ifndef LIGHTWEIGHTRENDERER_CAMERACONTROLLER_H
#define LIGHTWEIGHTRENDERER_CAMERACONTROLLER_H

#include "../BaseRender/Camera.h"

class CameraController {
public:
    static void AddCamera(Transform*transform,std::string name = "main");
    static void DeleteCamera(std::string name);
    static Camera *GetCamera();
    static void ChangeCamera(std::string name);
//    static glm::mat4* GetPMatrix();
//    static glm::mat4* GetVMatrix();
private:
    static std::unordered_map<std::string,Camera*> camera_map;
    static Camera* usingCamera;
};


#endif //LIGHTWEIGHTRENDERER_CAMERACONTROLLER_H
