//
// Created by khalil on 1/6/22.
//

#include <tuple>
#include <memory>
#include "../../include/bonus/SFMLbonus.h"

SFMLDoodleJump::SFMLBonus::SFMLBonus(float width, float height, const std::tuple<float, float> &pos,const std::shared_ptr <sf::RenderWindow> &w) : SFMLEntity(width, height, pos, w) {}

void SFMLDoodleJump::SFMLBonus::draw(std::tuple<float, float> pos) {
    getWindow()->draw(sprite);
}

void SFMLDoodleJump::SFMLBonus::HandleEvent(std::tuple<float, float> nextpos) {
    sprite.setPosition(sf::Vector2f(std::get<0>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(nextpos), std::get<1>(nextpos))) , std::get<1>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(nextpos), std::get<1>(nextpos)))));
    SFMLBonus::setPosition(nextpos);
    draw(getPosition());

}

void SFMLDoodleJump::SFMLBonus::setSprite(const sf::Sprite &s) {
    SFMLBonus::sprite = s;
}
