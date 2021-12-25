//
// Created by khalil on 12/16/21.
//
#include <iostream>
#include "../include/player.h"
DoodleJump::Player::Player(float width, float height, std::tuple<float, float> pos): Entity(width, height, pos) {}

void DoodleJump::Player::jump() {
    if((!isJumping and !Falling) or collisionPlatform){
        maxheight = std::get<1>(Player::getPosition()) + 1.f;
        isJumping = true;
        collisionPlatform = false;
        Falling = false;
    }
    if(maxheight<=std::get<1>(getPosition())){
        Falling = true;
        isJumping = false;
    }
    if(Falling){
        std::tuple<float, float> tmp = std::make_tuple(std::get<0>(Player::getPosition()), std::get<1>(Player::getPosition())-jumpspeed);
        Player::setPosition(tmp);
        Player::notifyObservers(tmp);
    }
    if(isJumping){
        std::tuple<float, float> tmp = std::make_tuple(std::get<0>(Player::getPosition()), std::get<1>(Player::getPosition())+jumpspeed);
        Player::setPosition(tmp);
        Player::notifyObservers(tmp);
    }
}

void DoodleJump::Player::setCollisionPlatform(bool c) {
    Player::collisionPlatform = c;
}

bool DoodleJump::Player::isFalling() const {
    return Falling;
}
