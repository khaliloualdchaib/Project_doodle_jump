//
// Created by khalil on 1/2/22.
//

#include "../../include/platforms/horizontalPlatform.h"
#include <tuple>

DoodleJump::HorizontalPlatform::HorizontalPlatform(const std::tuple<float, float>& pos) : Platform(pos) {}

void DoodleJump::HorizontalPlatform::update(INSTRUCTION c, float speed)
{
        if (!goLeft and !goRight) {
                if (std::get<0>(getPosition()) >= 0) {
                        goRight = true;
                } else {
                        goLeft = true;
                }
        }
        if (std::get<0>(getPosition()) <= -4) {
                goLeft = false;
                goRight = true;
        }
        if (std::get<0>(getPosition()) + getWidth() >= 4) {
                goLeft = true;
                goRight = false;
        }
        if (goRight) {
                HorizontalPlatform::setPosition(
                    std::make_tuple(std::get<0>(getPosition()) + speed, std::get<1>(getPosition())));
        }
        if (goLeft) {
                HorizontalPlatform::setPosition(
                    std::make_tuple(std::get<0>(getPosition()) - speed, std::get<1>(getPosition())));
        }
        updateBonus();
        if (isJumped() and getJumpcounter() > 1) {
                setJumped(false);
                DoodleJump::HorizontalPlatform::notifyObservers(HorizontalPlatform::getPosition(), horizontalcol);
        } else {
                DoodleJump::HorizontalPlatform::notifyObservers(HorizontalPlatform::getPosition(), zero);
        }
}