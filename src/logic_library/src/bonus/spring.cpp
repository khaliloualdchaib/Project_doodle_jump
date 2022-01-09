//
// Created by khalil on 1/6/22.
//

#include <tuple>
#include "../../include/bonus/spring.h"


DoodleJump::Spring::Spring(const std::tuple<float, float> &pos) : Bonus(0.4, 0.3, pos) {}

void DoodleJump::Spring::update(COMMAND c, float speed) {
    std::tuple<float, float> pos = std::make_tuple(std::get<0>(getPosition()), std::get<1>(getPosition())-0.20);
    notifyObservers(pos, zero);
}