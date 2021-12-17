//
// Created by khalil on 12/16/21.
//

#include "../include/SFMLplayer.h"


SFMLDoodleJump::SFMLPlayer::SFMLPlayer(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w): SFMLEntity(width, height, pos, std::move(w)) {
    if(!texture.loadFromFile("sprites/doodleRight.png")){
        std::cout<<"doodleRight.png not found"<<std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(std::get<0>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos))) , std::get<1>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos)))));
    sf::Vector2f targetSize(width, height);
    sprite.setScale(targetSize.x/sprite.getLocalBounds().width, targetSize.y/sprite.getLocalBounds().height);
}

void SFMLDoodleJump::SFMLPlayer::createPlayer() {
    SFMLDoodleJump::SFMLPlayer::getWindow()->draw(sprite);
}

