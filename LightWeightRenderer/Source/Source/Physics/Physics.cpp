//
// Created by MisThe on 2022/2/12.
//

#include "../../Head/Physics/Physics.h"

void Physics::Init() {
    InputController::Init();
}

void Physics::Run() {
    ThreadUtil::Start([](){
        InputController::Update();
    });
}

void Physics::Stop() {

}
