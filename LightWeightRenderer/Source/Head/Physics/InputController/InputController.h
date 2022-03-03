//
// Created by MisThe on 2022/2/12.
//

#ifndef LIGHTWEIGHTRENDERER_INPUTCONTROLLER_H
#define LIGHTWEIGHTRENDERER_INPUTCONTROLLER_H


#include "../InputEquip/MouseEquip.h"
#include "../InputEquip/KeyboardEquip.h"

class InputController {
public:
    static void Init();
    static void Update();
    static int AddEquip(BaseEquip::EquipType type,GLFWwindow* window);
    static void DeleteEquip(int index);
public:
    static void UseFunc(BaseEquip::EquipType type,std::function<void(BaseEquip*)> func,int index = -1);
private:
    class PrivateMouse : public MouseEquip
    {
    public:
        void indirectUpdate() override;
    };
    class PrivateKeyboard : public KeyboardEquip
    {
    public:
        void indirectUpdate() override;
    };
    static std::unordered_map<int,BaseEquip*> equip_map;
    static int base_equip_id;
    static int waitingTime;         //等待时间
    static int constWaitingTime;    //响应时间
private:
    InputController();
};


#endif //LIGHTWEIGHTRENDERER_INPUTCONTROLLER_H
