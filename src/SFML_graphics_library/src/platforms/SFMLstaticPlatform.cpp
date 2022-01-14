//
// Created by khalil on 12/18/21.
//

#include "../../include/platforms/SFMLstaticPlatform.h"

#include <utility>

SFMLDoodleJump::SFMLStaticPlatform::SFMLStaticPlatform(float width, float height, std::tuple<float, float> pos,
                                                       std::shared_ptr<sf::RenderWindow> w)
    : SFMLPlatform(width, height, pos, std::move(w))
{
        SFMLStaticPlatform::getPlatform().setFillColor(sf::Color(0, 100, 0));
}