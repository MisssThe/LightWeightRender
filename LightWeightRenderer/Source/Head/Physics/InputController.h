//
// Created by MisThe on 2022/2/12.
//

#ifndef LIGHTWEIGHTRENDERER_INPUTCONTROLLER_H
#define LIGHTWEIGHTRENDERER_INPUTCONTROLLER_H


#include "InputEquip/MouseEquip.h"

class InputController {
public:
    enum EquipType
    {
        MOUSE
    };
public:
    static void Init();
    static void Update();
    static int AddEquip(EquipType type,GLFWwindow* window);
    static void DeleteEquip(int index);
private:
    class PrivateMouse : public MouseEquip
    {
    public:
        void indirectUpdate() override;
    };
    static PrivateMouse privateMouse;
    static std::unordered_map<int,BaseEquip*> equip_map;
    static int base_equip_id;
private:
    InputController();
};


#endif //LIGHTWEIGHTRENDERER_INPUTCONTROLLER_H
