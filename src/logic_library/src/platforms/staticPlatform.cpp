//
// Created by khalil on 12/18/21.
//
#include "../../include/platforms/staticPlatform.h"

DoodleJump::staticPlatform::staticPlatform(std::tuple<float, float> pos): Platform(pos){}

void DoodleJump::staticPlatform::update(COMMAND) {
    DoodleJump::staticPlatform::notifyObservers(staticPlatform::getPosition());
}
