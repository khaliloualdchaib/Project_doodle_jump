//
// Created by khalil on 12/19/21.
//

#include "../../include/platforms/platform.h"

DoodleJump::Platform::Platform(std::tuple<float, float> pos): Entity(1.33f, 0.12f, pos) {

}

void DoodleJump::Platform::setBonus(const std::shared_ptr<DoodleJump::Bonus> &b) {
    Platform::bonus = b;
}

void DoodleJump::Platform::updateBonus(COMMAND c) {
    if(bonus != nullptr){
        bonus->setPosition(std::make_tuple(std::get<0>(getPosition()), std::get<1>(getPosition())+0.5));
        bonus->update(c, 0);
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
