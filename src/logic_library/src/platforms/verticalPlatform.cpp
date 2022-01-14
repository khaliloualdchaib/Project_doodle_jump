//
// Created by khalil on 1/3/22.
//
#include "../../include/platforms/verticalPlatform.h"
#include "../../include/random.h"

DoodleJump::VerticalPlatform::VerticalPlatform(const std::tuple<float, float> &pos) : Platform(pos){}

void DoodleJump::VerticalPlatform::update(INSTRUCTION c, float speed) {
    if(!goUP and !goDOWN){
        double rng = DoodleJump::Random::getInstance().getrandomDouble(0, 2);
        if(rng>=1){
            goDOWN = true;
        }
        else{
            goUP = true;
        }
    }
    else if(heightcounter >= maxheight){
        goDOWN = true;
        goUP = false;
    }
    else if(heightcounter <= 0 ){
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
    updateBonus();
    if(isJumped() and getJumpcounter()>1){
        setJumped(false);
        DoodleJump::VerticalPlatform::notifyObservers(getPosition(), verticalcol);
    }
    else{
        DoodleJump::VerticalPlatform::notifyObservers(getPosition(), zero);
    }

}