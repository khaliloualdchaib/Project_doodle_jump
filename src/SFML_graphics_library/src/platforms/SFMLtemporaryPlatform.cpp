//
// Created by khalil on 1/2/22.
//
#include "../../include/platforms/SFMLtemporaryPlatform.h"

#include <utility>

SFMLDoodleJump::SFMLTemporaryPlatform::SFMLTemporaryPlatform(float width, float height, std::tuple<float, float> pos,
                                                             std::shared_ptr<sf::RenderWindow> w)
    : SFMLPlatform(width, height, pos, std::move(w))
{
        SFMLTemporaryPlatform::getPlatform().setFillColor(sf::Color(255, 255, 255));
}