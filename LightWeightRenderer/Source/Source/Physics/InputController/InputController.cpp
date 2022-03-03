//
// Created by MisThe on 2022/2/12.
//

#include "../../../Head/Physics/InputController/InputController.h"

std::unordered_map<int,std::queue<BaseEquip*>*> InputController::equip_map;
int InputController::base_equip_id = 0;
int InputController::waitingTime = 0;
int InputController::constWaitingTime = 0;

void InputController::Init() {
//    equip_queue.push(new PrivateMouse());
}

void InputController::Update() {
    if (waitingTime < constWaitingTime)
        return;
    TraverUtil::TraverUMap<int,std::queue<BaseEquip*>*>(&equip_map,[](int index, std::queue<BaseEquip*>* equip_queue) {
        TraverUtil::TraverQueue<BaseEquip*>(equip_queue,[](BaseEquip*equip) {
            equip->externalUpdate();
        });
    });
    waitingTime = 0;
}
void InputController::AddEquip(BaseEquip::EquipType type, Window* window) {
    if (!window)
        LogUtil::LogError("add equip","error window");
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
    equip->setWindow(window->getWindow());
    if (equip_map.find(window->getWindowID()) == equip_map.end())
        equip_map.insert(std::pair<int,std::queue<BaseEquip*>*>(window->getWindowID(), new std::queue<BaseEquip*>));
    equip_map[window->getWindowID()]->push(equip);
}

void InputController::DeleteEquip(int index) {
    if (equip_map.find(index) != equip_map.end())
        equip_map.erase(index);
    else
        LogUtil::LogWarning("delete equip","error index");
}

InputController::InputController() {

}

//index为-1时调用所有type匹配设备
void InputController::UseFunc(BaseEquip::EquipType type, std::function<void(BaseEquip*)> func, int index) {
    TraverUtil::TraverUMap<int,std::queue<BaseEquip*>*>(&equip_map,[&index, &func, &type](int id, std::queue<BaseEquip*>* equip_queue) {
        if (index < 0 || index == id)
            TraverUtil::TraverQueue<BaseEquip*>(equip_queue,[ &func, &type](BaseEquip*equip) {
                if (equip->getEquipType() == type)
                    func(equip);
            });
    });
}

//定义可用输入设备
void InputController::PrivateMouse::indirectUpdate() {
    this->update();
}

void InputController::PrivateKeyboard::indirectUpdate() {
    this->update();
}
