//
// Created by MisThe on 2022/2/12.
//

#include "../../../Head/Physics/InputController/InputController.h"

std::unordered_map<int,BaseEquip*> InputController::equip_map;
int InputController::base_equip_id = 0;
int InputController::waitingTime = 0;
int InputController::constWaitingTime = 0;

void InputController::Init() {
//    equip_queue.push(new PrivateMouse());
}

void InputController::Update() {
    if (waitingTime < constWaitingTime)
        return;
    TraverUtil::TraverUMap<int,BaseEquip*>(&equip_map,[](int index,BaseEquip* equip) {
        equip->externalUpdate();
    });
    waitingTime = 0;
}
int InputController::AddEquip(BaseEquip::EquipType type, GLFWwindow* window) {
    if (!window)
        LogUtil::LogError("add equip","error window");
    int id = ++base_equip_id;
    BaseEquip* equip = nullptr;
    switch (type) {
        case BaseEquip::MOUSE:
            equip = new PrivateMouse();
            break;
        case BaseEquip::KEYBOARD:
            equip = new PrivateKeyboard();
            break;
        case BaseEquip::ERROR:
            LogUtil::LogError("add equip","error equip type");
        default:
            LogUtil::LogError("add equip","invalid equip type");
    }
    equip->setEquipType(type);
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

void InputController::GetMouseMove() {

}

InputController::InputController() {

}

//index为-1时调用所有type匹配设备
void InputController::UseFunc(BaseEquip::EquipType type, std::function<void(BaseEquip*)> func, int index) {
    TraverUtil::TraverUMap<int,BaseEquip*>(&equip_map,[&type, &index, &func](int id,BaseEquip* equip) {
        if (equip->getEquipType() == type)
            if (index < 0 || index == id) {
                func(equip);
            }
    });
}

//定义可用输入设备
void InputController::PrivateMouse::indirectUpdate() {
    this->update();
}

void InputController::PrivateKeyboard::indirectUpdate() {
    this->update();
}
