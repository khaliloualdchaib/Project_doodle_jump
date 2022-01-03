//
// Created by khalil on 1/2/22.
//
#include "../../include/platforms/SFMLhorizontalPlatform.h"

SFMLDoodleJump::SFMLHorizontalPlatform::SFMLHorizontalPlatform(float width, float height, const std::tuple<float, float> &pos, const std::shared_ptr<sf::RenderWindow> &w) : SFMLPlatform(width,height,pos, w) {
    SFMLHorizontalPlatform::getPlatform().setFillColor(sf::Color(0, 0, 250));
}

void SFMLDoodleJump::SFMLHorizontalPlatform::draw(std::tuple<float, float> pos) {
    std::tuple<float, float> pixelco = SFMLPlatform::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos));
    SFMLHorizontalPlatform::getPlatform().setPosition(std::get<0>(pixelco), std::get<1>(pixelco));
    SFMLHorizontalPlatform::getWindow()->draw(SFMLHorizontalPlatform::getPlatform());
}

void SFMLDoodleJump::SFMLHorizontalPlatform::HandleEvent(std::tuple<float, float> nextpos) {
    draw(nextpos);
}