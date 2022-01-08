//
// Created by khalil on 1/2/22.
//

#include "../../include/platforms/temporaryPlatform.h"

bool DoodleJump::TemporaryPlatform::temporaryJumped() const {
    return temporaryjumped;
}

DoodleJump::TemporaryPlatform::TemporaryPlatform(std::tuple<float, float> pos): Platform(pos) {}

void DoodleJump::TemporaryPlatform::update(COMMAND c, float speed) {
    updateBonus(c);
    DoodleJump::TemporaryPlatform::notifyObservers(TemporaryPlatform::getPosition());
}

void DoodleJump::TemporaryPlatform::settemporaryJumped(bool b) {
    temporaryjumped = b;
}