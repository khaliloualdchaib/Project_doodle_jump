//
// Created by khalil on 1/3/22.
//

#include "../../include/platforms/SFMLverticalPlatform.h"
#include <memory>
#include <tuple>
#include <utility>

SFMLDoodleJump::SFMLVerticalPlatform::SFMLVerticalPlatform(float width, float height,
                                                           const std::tuple<float, float>& pos,
                                                           std::shared_ptr<sf::RenderWindow> w)
    : SFMLPlatform(width, height, pos, std::move(w))
{
        SFMLVerticalPlatform::getPlatform().setFillColor(sf::Color(255, 255, 0));
}