//
// Created by khalil on 1/5/22.
//

#include <tuple>
#include <memory>
#include "../include/SFMLbg_tile.h"

SFMLDoodleJump::SFMLbg_Tile::SFMLbg_Tile(float width, float height, const std::tuple<float, float> &pos,const std::shared_ptr <sf::RenderWindow> &w, const sf::Texture& texture) : SFMLEntity(width, height, pos,w){
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(std::get<0>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos))) , std::get<1>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos)))));
    sf::Vector2f targetSize(getCamera()->TransformWidth(width), getCamera()->TransformHeight(height));
    sprite.setScale(targetSize.x/sprite.getLocalBounds().width, targetSize.y/sprite.getLocalBounds().height);
}

void SFMLDoodleJump::SFMLbg_Tile::HandleEvent(std::tuple<float, float> nextpos, scoreUpdate s) {
    SFMLbg_Tile::setPosition(nextpos);
    sprite.setPosition(sf::Vector2f(std::get<0>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(nextpos), std::get<1>(nextpos))) , std::get<1>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(nextpos), std::get<1>(nextpos)))));
    SFMLbg_Tile::getWindow()->draw(sprite);
}
