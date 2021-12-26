//
// Created by khalil on 12/18/21.
//

#include "../../include/platforms/SFMLstaticPlatform.h"

#include <utility>

SFMLDoodleJump::SFMLstaticPlatform::SFMLstaticPlatform(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w): SFMLPlatform(width, height, pos, std::move(w)) {
    SFMLstaticPlatform::getPlatform().setFillColor(sf::Color(100, 250, 50));
    std::tuple<float, float> pixelco = SFMLPlatform::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos));
    SFMLstaticPlatform::getPlatform().setPosition(std::get<0>(pixelco), std::get<1>(pixelco));
}

void SFMLDoodleJump::SFMLstaticPlatform::draw() {
    SFMLstaticPlatform::getWindow()->draw(SFMLstaticPlatform::getPlatform());
}

void SFMLDoodleJump::SFMLstaticPlatform::HandleEvent(std::tuple<float, float> nextpos) {
    draw();
}