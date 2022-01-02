//
// Created by khalil on 1/2/22.
//
#include "../../include/platforms/SFMLtemporaryPlatform.h"

#include <utility>

SFMLDoodleJump::SFMLtemporaryPlatform::SFMLtemporaryPlatform(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w): SFMLPlatform(width, height, pos, std::move(w)) {
    SFMLtemporaryPlatform::getPlatform().setFillColor(sf::Color(255, 255, 255));
}

void SFMLDoodleJump::SFMLtemporaryPlatform::draw(std::tuple<float, float> pos) {
    std::tuple<float, float> pixelco = SFMLPlatform::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos));
    SFMLtemporaryPlatform::getPlatform().setPosition(std::get<0>(pixelco), std::get<1>(pixelco));
    SFMLtemporaryPlatform::getWindow()->draw(SFMLtemporaryPlatform::getPlatform());
}

void SFMLDoodleJump::SFMLtemporaryPlatform::HandleEvent(std::tuple<float, float> nextpos) {
    draw(nextpos);
}