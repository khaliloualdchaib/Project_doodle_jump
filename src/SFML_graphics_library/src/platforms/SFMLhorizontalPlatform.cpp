//
// Created by khalil on 1/2/22.
//
#include "../../include/platforms/SFMLhorizontalPlatform.h"

SFMLDoodleJump::SFMLHorizontalPlatform::SFMLHorizontalPlatform(float width, float height, const std::tuple<float, float> &pos, const std::shared_ptr<sf::RenderWindow> &w) : SFMLPlatform(width,height,pos, w) {
    SFMLHorizontalPlatform::getPlatform().setFillColor(sf::Color(0, 0, 250));
}

void SFMLDoodleJump::SFMLHorizontalPlatform::HandleEvent(std::tuple<float, float> nextpos) {
    draw(nextpos);
}