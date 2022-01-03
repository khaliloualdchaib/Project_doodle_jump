//
// Created by khalil on 12/18/21.
//

#include "../../include/platforms/SFMLstaticPlatform.h"

#include <utility>

SFMLDoodleJump::SFMLStaticPlatform::SFMLStaticPlatform(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w): SFMLPlatform(width, height, pos, std::move(w)) {
    SFMLStaticPlatform::getPlatform().setFillColor(sf::Color(0, 250, 0));
}

void SFMLDoodleJump::SFMLStaticPlatform::draw(std::tuple<float, float> pos) {
    std::tuple<float, float> pixelco = SFMLPlatform::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos));
    SFMLStaticPlatform::getPlatform().setPosition(std::get<0>(pixelco), std::get<1>(pixelco));
    SFMLStaticPlatform::getWindow()->draw(SFMLStaticPlatform::getPlatform());
}

void SFMLDoodleJump::SFMLStaticPlatform::HandleEvent(std::tuple<float, float> nextpos) {
    draw(nextpos);
}