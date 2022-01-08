//
// Created by khalil on 12/16/21.
//
#include <iostream>
#include "../include/player.h"

DoodleJump::Player::Player(float width, float height, std::tuple<float, float> pos): Entity(width, height, pos) {}

void DoodleJump::Player::update(COMMAND c, float speed) {
    float X = 0.0f;
    float Y = 0.0f;

    if(!Jumping and !Falling){
        Jumping = true;
    }
    if (Jumping){
        Y+=velocity;
        velocity-=accelerationY;
        if(velocity<0){
            Falling = true;
            Jumping = false;
        }
    }
    else{
        if(collisionSpring){
            velocity = 5*initial_velocity;
            Y = velocity;
            Falling = false;
            Jumping = true;
            collisionSpring = false;
            highspeed = true;

        }
        else if(collisionJetpack){
            velocity = 10*initial_velocity;
            Y = velocity;
            Falling = false;
            Jumping = true;
            collisionJetpack = false;
            highspeed = true;
        }
        else if(collisionPlatform){
            velocity = 2*initial_velocity;
            Y = velocity;
            Falling = false;
            Jumping = true;

        }else{
            highspeed = false;
            Y+=velocity;
            velocity-=accelerationY;
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

float DoodleJump::Player::getVelocity() const {
    return velocity;
}

float DoodleJump::Player::getInitialVelocity() const {
    return initial_velocity;
}

bool DoodleJump::Player::isCollisionSpring() const {
    return collisionSpring;
}

void DoodleJump::Player::setCollisionSpring(bool c) {
    Player::collisionSpring = c;
}

bool DoodleJump::Player::isHighspeed() const {
    return highspeed;
}

void DoodleJump::Player::setCollisionJetpack(bool collisionJetpack) {
    Player::collisionJetpack = collisionJetpack;
}
