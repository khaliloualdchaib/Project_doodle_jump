//
// Created by khalil on 1/3/22.
//

#include <tuple>
#include <memory>
#include <utility>
#include "../../include/platforms/SFMLverticalPlatform.h"

SFMLDoodleJump::SFMLVerticalPlatform::SFMLVerticalPlatform(float width, float height, const std::tuple<float, float> &pos, std::shared_ptr <sf::RenderWindow> w) : SFMLPlatform(width, height, pos, std::move(w)) {
    SFMLVerticalPlatform::getPlatform().setFillColor(sf::Color(255, 255, 0));
}

void SFMLDoodleJump::SFMLVerticalPlatform::HandleEvent(std::tuple<float, float> nextpos) {
    draw(nextpos);
}