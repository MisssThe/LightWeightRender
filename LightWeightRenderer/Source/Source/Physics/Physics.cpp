//
// Created by MisThe on 2022/2/12.
//

#include "../../Head/Physics/Physics.h"
#include "../../Head/Physics/InputController/ShortcutController.h"

bool Physics::isReady = false;

void Physics::Init(std::vector<GLFWwindow *> windowVec) {
    if (isReady)
        return;
    if (windowVec.size() < 1)
        return;
    isReady = true;
    //自动检测已连接输入设备
    InputController::Init();
    TraverUtil::TraverVector<GLFWwindow*>(&windowVec,[](GLFWwindow* window){
        InputController::AddEquip(BaseEquip::EquipType::MOUSE,window);
        InputController::AddEquip(BaseEquip::EquipType::KEYBOARD,window);
    });
    ShortcutController::Init();
}


void Physics::Run() {
    ThreadUtil::Start([](){
        InputController::Update();
        ShortcutController::Update();
    });
}

void Physics::Stop() {

}
