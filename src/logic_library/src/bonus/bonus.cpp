//
// Created by khalil on 1/5/22.
//

#include <tuple>
#include "../../include/bonus/bonus.h"
#include <iostream>

DoodleJump::Bonus::Bonus(float width, float height, const std::tuple<float, float> &pos) : Entity(width, height, pos) {}

void DoodleJump::Bonus::update(COMMAND c, float speed) {
    notifyObservers(getPosition());
}