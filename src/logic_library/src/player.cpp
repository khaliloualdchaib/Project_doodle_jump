//
// Created by khalil on 12/16/21.
//
#include <iostream>
#include "../include/player.h"
DoodleJump::Player::Player(float width, float height, std::tuple<float, float> pos): Entity(width, height, pos) {}

void DoodleJump::Player::update(COMMAND c) {
    //std::cout<<"Jumping "<<isJumping<<" Fallinf "<<Falling<<" collision "<<collisionPlatform<<std::endl;
    if((!isJumping and !Falling)){
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
        if(collisionPlatform){
            maxheight = std::get<1>(Player::getPosition()) + 1.f;
            collisionPlatform = false;
            Falling = false;
            isJumping = true;
        }
        else{
            if(c == LEFT){
                std::tuple<float, float> tmp = std::make_tuple(std::get<0>(Player::getPosition())-0.01f, std::get<1>(Player::getPosition())-jumpspeed);
                Player::setPosition(tmp);
                Player::notifyObservers(tmp);
            }
            else if(c == RIGHT){
                std::tuple<float, float> tmp = std::make_tuple(std::get<0>(Player::getPosition())+0.01f, std::get<1>(Player::getPosition())-jumpspeed);
                Player::setPosition(tmp);
                Player::notifyObservers(tmp);
            }
            else{
                std::tuple<float, float> tmp = std::make_tuple(std::get<0>(Player::getPosition()), std::get<1>(Player::getPosition())-jumpspeed);
                Player::setPosition(tmp);
                Player::notifyObservers(tmp);
            }
        }
    }
    if(isJumping){
        if(c == LEFT){
            std::tuple<float, float> tmp = std::make_tuple(std::get<0>(Player::getPosition())-0.01f, std::get<1>(Player::getPosition())+jumpspeed);
            Player::setPosition(tmp);
            Player::notifyObservers(tmp);
        }
        else if(c == RIGHT){
            std::tuple<float, float> tmp = std::make_tuple(std::get<0>(Player::getPosition())+0.01f, std::get<1>(Player::getPosition())+jumpspeed);
            Player::setPosition(tmp);
            Player::notifyObservers(tmp);
        }
        else{
            std::tuple<float, float> tmp = std::make_tuple(std::get<0>(Player::getPosition()), std::get<1>(Player::getPosition())+jumpspeed);
            Player::setPosition(tmp);
            Player::notifyObservers(tmp);
        }
    }
}

void DoodleJump::Player::setCollisionPlatform(bool c) {
    Player::collisionPlatform = c;
}

bool DoodleJump::Player::isFalling() const {
    return Falling;
}