//
// Created by khalil on 1/2/22.
//

#include "../../include/platforms/temporaryPlatform.h"

bool DoodleJump::TemporaryPlatform::temporaryJumped() const {
    return temporaryjumped;
}

DoodleJump::TemporaryPlatform::TemporaryPlatform(std::tuple<float, float> pos): Platform(pos) {}

void DoodleJump::TemporaryPlatform::update(INSTRUCTION c, float speed) {
    updateBonus();
    DoodleJump::TemporaryPlatform::notifyObservers(TemporaryPlatform::getPosition(), zero);
}

void DoodleJump::TemporaryPlatform::settemporaryJumped(bool b) {
    temporaryjumped = b;
}