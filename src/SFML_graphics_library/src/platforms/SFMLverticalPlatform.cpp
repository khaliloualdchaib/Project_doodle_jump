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

void SFMLDoodleJump::SFMLVerticalPlatform::draw(std::tuple<float, float> pos) {
    std::tuple<float, float> pixelco = SFMLPlatform::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos));
    SFMLVerticalPlatform::getPlatform().setPosition(std::get<0>(pixelco), std::get<1>(pixelco));
    SFMLVerticalPlatform::getWindow()->draw(SFMLVerticalPlatform::getPlatform());
}

void SFMLDoodleJump::SFMLVerticalPlatform::HandleEvent(std::tuple<float, float> nextpos) {
    draw(nextpos);
}