//
// Created by khalil on 12/19/21.
//

#include "../../include/platforms/platform.h"

DoodleJump::Platform::Platform(std::tuple<float, float> pos): Entity(1.33f, 0.12f, pos) {

}

void DoodleJump::Platform::setBonus(const std::shared_ptr<DoodleJump::Bonus> &b) {
    Platform::bonus = b;
}

void DoodleJump::Platform::updateBonus() {
    if(bonus != nullptr){
        bonus->setPosition(std::make_tuple(std::get<0>(getPosition()), std::get<1>(getPosition())+0.5));
        bonus->update(NONE, 0);
    }
}

bool DoodleJump::Platform::hasBonus() {
    if(bonus != nullptr){
        return true;
    }
    return false;
}

const std::shared_ptr<DoodleJump::Bonus> &DoodleJump::Platform::getBonus() const {
    return bonus;
}

bool DoodleJump::Platform::isJumped() const {
    return jumped;
}

void DoodleJump::Platform::setJumped(bool jumped) {
    Platform::jumped = jumped;
}

int DoodleJump::Platform::getJumpcounter() const {
    return jumpcounter;
}

void DoodleJump::Platform::addjump() {
    jumpcounter++;
}