//
// Created by khalil on 12/19/21.
//

#include "../../include/platforms/SFMLplatform.h"

SFMLDoodleJump::SFMLPlatform::SFMLPlatform(float width, float height, std::tuple<float, float> pos,
                                           std::shared_ptr<sf::RenderWindow> w)
    : SFMLEntity(width, height, pos, std::move(w))
{
        sf::RectangleShape tmp(sf::Vector2f(getCamera()->TransformWidth(width), getCamera()->TransformHeight(height)));
        platform = tmp;
}

sf::RectangleShape& SFMLDoodleJump::SFMLPlatform::getPlatform() { return platform; }

void SFMLDoodleJump::SFMLPlatform::HandleEvent(std::tuple<float, float> nextpos, scoreUpdate s)
{
        std::tuple<float, float> pixelco =
            SFMLPlatform::getCamera()->Transformation(std::get<0>(nextpos), std::get<1>(nextpos));
        SFMLPlatform::getPlatform().setPosition(std::get<0>(pixelco), std::get<1>(pixelco));
        SFMLPlatform::getWindow()->draw(SFMLPlatform::getPlatform());
}