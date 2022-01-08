//
// Created by khalil on 1/7/22.
//
#include "../../include/command_pattern/collisionBonusPlayer.h"
#include <iostream>
#include "../../include/entity.h"
#include <set>
#include <utility>
#include "cmath"
DoodleJump::CollisionBonusPlayer::CollisionBonusPlayer(std::shared_ptr<DoodleJump::Player>  p, std::shared_ptr<DoodleJump::Bonus>  b): player(std::move(p)), bonus(std::move(b)) {}

void DoodleJump::CollisionBonusPlayer::execute() {
    if(player->isFalling()){
        if(std::get<1>(player->getPosition()) - player->getHeight()<=std::get<1>(bonus->getPosition()) and
           std::get<1>(player->getPosition()) - player->getHeight()>=std::get<1>(bonus->getPosition())-bonus->getHeight()){
            if((std::get<0>(player->getPosition())<=std::get<0>(bonus->getPosition())+bonus->getWidth() and
                std::get<0>(player->getPosition())>=std::get<0>(bonus->getPosition())) or
               (std::get<0>(player->getPosition())+player->getWidth()-player->getWidth()/3.2>=std::get<0>(bonus->getPosition()) and
                std::get<0>(player->getPosition())+player->getWidth()-player->getWidth()/3.2<=std::get<0>(bonus->getPosition())+bonus->getWidth())){
                player->setCollisionSpring(true);
            }
        }
    }
}

