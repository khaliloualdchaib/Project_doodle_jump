//
// Created by khalil on 1/6/22.
//

#include <tuple>
#include <memory>
#include "../../include/bonus/SFMLspring.h"

SFMLDoodleJump::SFMLSpring::SFMLSpring(float width, float height, const std::tuple<float, float> &pos,const std::shared_ptr <sf::RenderWindow> &w, const sf::Texture& texture) : SFMLBonus(width, height, pos,w) {
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(std::get<0>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos))) , std::get<1>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos)))));
    sf::Vector2f targetSize(getCamera()->TransformWidth(width), getCamera()->TransformHeight(height));
    sprite.setScale(targetSize.x/sprite.getLocalBounds().width, targetSize.y/sprite.getLocalBounds().height);
}

void SFMLDoodleJump::SFMLSpring::draw(std::tuple<float, float> pos) {
    getWindow()->draw(sprite);
}

void SFMLDoodleJump::SFMLSpring::HandleEvent(std::tuple<float, float> nextpos) {
    draw(getPosition());
    SFMLSpring::setPosition(nextpos);
    sprite.setPosition(sf::Vector2f(std::get<0>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(nextpos), std::get<1>(nextpos))) , std::get<1>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(nextpos), std::get<1>(nextpos)))));
}