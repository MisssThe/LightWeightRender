//
// Created by MisThe on 2022/2/12.
//

#include "../../Head/Physics/InputController.h"

InputController::PrivateMouse InputController::privateMouse;
std::unordered_map<int,BaseEquip*> InputController::equip_map;
int InputController::base_equip_id = 0;

void InputController::Init() {
//    equip_queue.push(new PrivateMouse());
}

void InputController::Update() {
    TraverUtil::TraverUMap<int,BaseEquip*>(&equip_map,[](int index,BaseEquip* equip) {
        equip->externalUpdate();
    });
}
int InputController::AddEquip(InputController::EquipType type, GLFWwindow* window) {
    if (!window)
        LogUtil::LogError("add equip","error window");
    int id = ++base_equip_id;
    BaseEquip* equip = nullptr;
    switch (type) {
        case EquipType::MOUSE:
            equip = new PrivateMouse();
            break;
        default:
            LogUtil::LogError("add equip","error equip type");
    }
    equip->setWindow(window);
    equip_map.insert(std::pair<int,BaseEquip*>(id,equip));
    return id;
}

void InputController::DeleteEquip(int index) {
    if (equip_map.find(index) != equip_map.end())
        equip_map.erase(index);
    else
        LogUtil::LogWarning("delete equip","error index");
}

InputController::InputController() {

}

//定义可用输入设备
void InputController::PrivateMouse::indirectUpdate() {
    this->update();
}