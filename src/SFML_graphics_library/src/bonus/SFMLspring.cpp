//
// Created by khalil on 1/6/22.
//

#include "../../include/bonus/SFMLspring.h"
#include <memory>
#include <tuple>

SFMLDoodleJump::SFMLSpring::SFMLSpring(float width, float height, const std::tuple<float, float>& pos,
                                       const std::shared_ptr<sf::RenderWindow>& w, const sf::Texture& texture)
    : SFMLBonus(width, height, pos, w)
{
        sf::Sprite tmp;
        tmp.setTexture(texture);
        tmp.setPosition(sf::Vector2f(
            std::get<0>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos))),
            std::get<1>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos)))));
        sf::Vector2f targetSize(getCamera()->TransformWidth(width), getCamera()->TransformHeight(height));
        tmp.setScale(targetSize.x / tmp.getLocalBounds().width, targetSize.y / tmp.getLocalBounds().height);
        setSprite(tmp);
}