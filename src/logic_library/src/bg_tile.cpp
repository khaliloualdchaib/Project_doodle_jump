//
// Created by khalil on 1/5/22.
//
#include "../include/bg_tile.h"

DoodleJump::bg_Tile::bg_Tile(const std::tuple<float, float> &pos) : Entity(8, 6,pos) {}

void DoodleJump::bg_Tile::update(COMMAND c, float speed) {
    setPosition(std::make_tuple(std::get<0>(getPosition()), std::get<1>(getPosition())-speed));
    notifyObservers(getPosition());
}
