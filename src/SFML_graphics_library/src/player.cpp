//
// Created by khalil on 12/13/21.
//

#include "../include/player.h"

#include <utility>

SFMLDoodleJump::Player::Player(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow>& w): Entity(width, height, pos, std::move(w)) {
    if(!texture.loadFromFile("sprites/doodleRight.png")){
        std::cout<<"doodleRight.png not found"<<std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(std::get<0>(SFMLDoodleJump::Entity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos))) , std::get<1>(SFMLDoodleJump::Entity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos)))));
    sf::Vector2f targetSize(width, height);
    sprite.setScale(targetSize.x/sprite.getLocalBounds().width, targetSize.y/sprite.getLocalBounds().height);
}

void SFMLDoodleJump::Player::createPlayer() {
    SFMLDoodleJump::Player::getWindow()->draw(sprite);
}


