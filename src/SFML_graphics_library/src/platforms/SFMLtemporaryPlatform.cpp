//
// Created by khalil on 1/2/22.
//
#include "../../include/platforms/SFMLtemporaryPlatform.h"

#include <utility>

SFMLDoodleJump::SFMLTemporaryPlatform::SFMLTemporaryPlatform(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w): SFMLPlatform(width, height, pos, std::move(w)) {
    SFMLTemporaryPlatform::getPlatform().setFillColor(sf::Color(255, 255, 255));
}

void SFMLDoodleJump::SFMLTemporaryPlatform::draw(std::tuple<float, float> pos) {
    std::tuple<float, float> pixelco = SFMLPlatform::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos));
    SFMLTemporaryPlatform::getPlatform().setPosition(std::get<0>(pixelco), std::get<1>(pixelco));
    SFMLTemporaryPlatform::getWindow()->draw(SFMLTemporaryPlatform::getPlatform());
}

void SFMLDoodleJump::SFMLTemporaryPlatform::HandleEvent(std::tuple<float, float> nextpos) {
    draw(nextpos);
}