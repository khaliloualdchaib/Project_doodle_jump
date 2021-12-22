//
// Created by khalil on 12/16/21.
//
#include <iostream>
#include "../include/player.h"
DoodleJump::Player::Player(float width, float height, std::tuple<float, float> pos): Entity(width, height, pos) {}

void DoodleJump::Player::jump() {
    if(!isJumping and !isFalling){
        std::tuple<float, float> tmp = std::make_tuple(std::get<0>(Player::getPosition()), std::get<1>(Player::getPosition())+jumpspeed);
        maxheight = std::get<1>(Player::getPosition()) + 1.f;
        isJumping = true;
        Player::setPosition(tmp);
        Player::notifyObservers(tmp);
    } else{
        if(std::get<1>(Player::getPosition()) >= maxheight and !isFalling){
            std::tuple<float, float> tmp = std::make_tuple(std::get<0>(Player::getPosition()), std::get<1>(Player::getPosition())-jumpspeed);
            Player::setPosition(tmp);
            Player::notifyObservers(tmp);
            isFalling = true;
            collision = false;
        }
        else if (isFalling and !collision){
            std::tuple<float, float> tmp = std::make_tuple(std::get<0>(Player::getPosition()), std::get<1>(Player::getPosition())-jumpspeed);
            Player::setPosition(tmp);
            Player::notifyObservers(tmp);
        }
        else if (isFalling){
            std::tuple<float, float> tmp = std::make_tuple(std::get<0>(Player::getPosition()), std::get<1>(Player::getPosition())+jumpspeed);
            maxheight = std::get<1>(Player::getPosition()) + 1.f;
            isJumping = true;
            Player::setPosition(tmp);
            Player::notifyObservers(tmp);
            isFalling = false;
        }
        else{
            std::tuple<float, float> tmp = std::make_tuple(std::get<0>(Player::getPosition()), std::get<1>(Player::getPosition())+jumpspeed);
            Player::setPosition(tmp);
            Player::notifyObservers(tmp);
        }
    }
}

void DoodleJump::Player::setCollision(bool c) {
    Player::collision = c;
}
