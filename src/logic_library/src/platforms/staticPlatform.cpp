//
// Created by khalil on 12/18/21.
//
#include "../../include/platforms/staticPlatform.h"

DoodleJump::StaticPlatform::StaticPlatform(std::tuple<float, float> pos): Platform(pos){}

void DoodleJump::StaticPlatform::update(COMMAND c, float speed) {
    updateBonus(c);
    if(isJumped() and getJumpcounter()>1){
        setJumped(false);
        DoodleJump::StaticPlatform::notifyObservers(StaticPlatform::getPosition(), staticcol);
    }
    else{
        DoodleJump::StaticPlatform::notifyObservers(StaticPlatform::getPosition(), zero);
    }
}
