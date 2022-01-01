//
// Created by khalil on 12/16/21.
//
#include <iostream>
#include "../include/player.h"

DoodleJump::Player::Player(float width, float height, std::tuple<float, float> pos): Entity(width, height, pos) {}

void DoodleJump::Player::update(COMMAND c) {
    float X = 0.0f;
    float Y = 0.0f;
    if(!Jumping and !Falling){
        Jumping = true;
    }
    if(collisionPlatform){
        Falling = false;
        Jumping = true;
        grav = 0;
    }
    if (Jumping){
        Y+=0.05f+grav;
        grav-=0.001f;
        if(Y<0){
            Falling = true;
        }
    }
    if(c==LEFT){
        X -= accelerationX;
        if(std::get<0>(getPosition())+getWidth()<-4.f){
            setPosition(std::make_tuple(4.f, std::get<1>(getPosition())));
        }
    }
    if(c==RIGHT){
        X += accelerationX;
        if(std::get<0>(getPosition())>4.f){
            setPosition(std::make_tuple(-4.f, std::get<1>(getPosition())));
        }
    }
    setPosition(std::make_tuple(std::get<0>(getPosition())+X, std::get<1>(getPosition())+Y));
    notifyObservers(getPosition());
}

void DoodleJump::Player::setCollisionPlatform(bool c) {
    Player::collisionPlatform = c;
}

bool DoodleJump::Player::isFalling() const {
    return Falling;
}