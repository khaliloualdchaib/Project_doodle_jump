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
        if(std::get<1>(player->getPosition()) - player->getHeight()<= std::get<1>(bonus->getPosition())-0.2f and
           std::get<1>(player->getPosition())>= std::get<1>(bonus->getPosition())-0.2f){
            float playerleftcornerx = std::get<0>(player->getPosition());
            float playerrightcornerx = std::get<0>(player->getPosition()) + player->getWidth();
            float bonusleftcornerx = std::get<0>(bonus->getPosition());
            float bonusrightcornerx = std::get<0>(bonus->getPosition()) + bonus->getWidth();
            if((bonusleftcornerx<=playerrightcornerx and bonusleftcornerx>=playerleftcornerx) or
               (bonusrightcornerx>=playerleftcornerx and bonusrightcornerx<=playerrightcornerx)){
                if(bonus->isSpring()){
                    player->setCollisionSpring(true);
                    return;
                }
                if(bonus->isJetpack()){
                    player->setCollisionJetpack(true);
                    return;
                }

            }
        }
    }
}

