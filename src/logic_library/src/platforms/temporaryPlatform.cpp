//
// Created by khalil on 1/2/22.
//

#include "../../include/platforms/temporaryPlatform.h"

bool DoodleJump::temporaryPlatform::temporaryJumped() const {
    return temporaryjumped;
}

DoodleJump::temporaryPlatform::temporaryPlatform(std::tuple<float, float> pos): Platform(pos) {}

void DoodleJump::temporaryPlatform::update(COMMAND) {
    DoodleJump::temporaryPlatform::notifyObservers(temporaryPlatform::getPosition());
}

void DoodleJump::temporaryPlatform::settemporaryJumped(bool b) {
    temporaryjumped = b;
}