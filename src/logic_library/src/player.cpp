//
// Created by khalil on 12/16/21.
//

#include "../include/player.h"

DoodleJump::Player::Player(float width, float height, std::tuple<float, float> pos): Entity(width, height, pos) {}

void DoodleJump::Player::jump() {
    std::tuple<float, float> tmp = std::make_tuple(std::get<0>(Player::getPosition()), std::get<1>(Player::getPosition())+jumpspeed);
    Player::setPosition(tmp);
    Player::notifyObservers();
}