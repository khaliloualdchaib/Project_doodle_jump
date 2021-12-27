//
// Created by khalil on 12/18/21.
//
#include "../../include/platforms/staticPlatform.h"

DoodleJump::staticPlatform::staticPlatform(float width, float height, std::tuple<float, float> pos): Platform(width, height, pos){}

void DoodleJump::staticPlatform::update(COMMAND) {
    DoodleJump::staticPlatform::notifyObservers(staticPlatform::getPosition());
}

