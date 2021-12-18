//
// Created by khalil on 12/18/21.
//

#include "../../include/platforms/SFMLstaticPlatform.h"

#include <utility>

SFMLDoodleJump::SFMLstaticPlatform::SFMLstaticPlatform(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w): SFMLEntity(width, height, pos, std::move(w)) {
    std::tuple<float, float> pixelco = SFMLstaticPlatform::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos));
    sf::RectangleShape tmp(sf::Vector2f(width, height));
    platform = tmp;
    platform.setFillColor(sf::Color(100, 250, 50));
    platform.setPosition(std::get<0>(pixelco), std::get<1>(pixelco));
}

void SFMLDoodleJump::SFMLstaticPlatform::draw() {
    SFMLstaticPlatform::getWindow()->draw(platform);
}