//
// Created by khalil on 1/3/22.
//
#include "../../include/platforms/verticalPlatform.h"

DoodleJump::VerticalPlatform::VerticalPlatform(const std::tuple<float, float> &pos) : Platform(pos){}

void DoodleJump::VerticalPlatform::update(COMMAND c) {
    if(heightcounter >= maxheight){
        goDOWN = true;
        goUP = false;
    }
    if(heightcounter <= 0 ){
        goDOWN = false;
        goUP = true;
    }
    if(goUP){
        setPosition(std::make_tuple(std::get<0>(getPosition()), std::get<1>(getPosition())+speed));
        heightcounter += speed;
    }
    if(goDOWN){
        setPosition(std::make_tuple(std::get<0>(getPosition()), std::get<1>(getPosition())-speed));
        heightcounter -= speed;
    }
    DoodleJump::VerticalPlatform::notifyObservers(getPosition());
}