//
// Created by khalil on 1/3/22.
//
#include "../../include/platforms/verticalPlatform.h"

DoodleJump::VerticalPlatform::VerticalPlatform(const std::tuple<float, float> &pos) : Platform(pos) {

}

void DoodleJump::VerticalPlatform::update(COMMAND c) {
    DoodleJump::VerticalPlatform::notifyObservers(getPosition());
}