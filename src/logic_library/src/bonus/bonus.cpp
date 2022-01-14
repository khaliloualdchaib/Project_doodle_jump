//
// Created by khalil on 1/5/22.
//

#include "../../include/bonus/bonus.h"
#include <tuple>
DoodleJump::Bonus::Bonus(float width, float height, const std::tuple<float, float>& pos) : Entity(width, height, pos) {}

void DoodleJump::Bonus::checkCollision(const std::shared_ptr<Player>& player)
{
        if (player->isFalling()) {
                if (std::get<1>(player->getPosition()) - player->getHeight() <= std::get<1>(getPosition()) - 0.2f and
                    std::get<1>(player->getPosition()) >= std::get<1>(getPosition()) - 0.2f) {
                        float playerleftcornerx = std::get<0>(player->getPosition());
                        float playerrightcornerx = std::get<0>(player->getPosition()) + player->getWidth();
                        float bonusleftcornerx = std::get<0>(getPosition());
                        float bonusrightcornerx = std::get<0>(getPosition()) + getWidth();
                        if ((bonusleftcornerx <= playerrightcornerx and bonusleftcornerx >= playerleftcornerx) or
                            (bonusrightcornerx >= playerleftcornerx and bonusrightcornerx <= playerrightcornerx)) {
                                if (isSpring()) {
                                        player->setCollisionSpring(true);
                                        return;
                                }
                                if (isJetpack()) {
                                        player->setCollisionJetpack(true);
                                        return;
                                }
                        }
                }
        }
}