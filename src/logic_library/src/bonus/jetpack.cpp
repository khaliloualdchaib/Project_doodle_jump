//
// Created by khalil on 1/6/22.
//

#include "../../include/bonus/jetpack.h"
#include <tuple>

DoodleJump::Jetpack::Jetpack(const std::tuple<float, float>& pos) : Bonus(0.4, 0.4, pos) {}

void DoodleJump::Jetpack::update(INSTRUCTION c, float speed)
{
        std::tuple<float, float> pos = std::make_tuple(std::get<0>(getPosition()), std::get<1>(getPosition()) - 0.10);
        notifyObservers(pos, zero);
}