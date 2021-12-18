//
// Created by khalil on 12/16/21.
//

#include "../include/SFMLplayer.h"


SFMLDoodleJump::SFMLPlayer::SFMLPlayer(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w, sf::Texture& texture): SFMLEntity(width, height, pos, std::move(w)) {
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(std::get<0>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos))) , std::get<1>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos)))));
    sf::Vector2f targetSize(width, height);
    sprite.setScale(targetSize.x/sprite.getLocalBounds().width, targetSize.y/sprite.getLocalBounds().height);
}

void SFMLDoodleJump::SFMLPlayer::draw() {
    SFMLDoodleJump::SFMLPlayer::getWindow()->draw(sprite);
}

void SFMLDoodleJump::SFMLPlayer::HandleEvent() {
    SFMLPlayer::setPosition(std::make_tuple(std::get<0>(SFMLPlayer::getPosition()), std::get<1>(SFMLPlayer::getPosition())+jumpspeed));
    std::tuple<float, float> pos = SFMLPlayer::getPosition();
    sprite.setPosition(sf::Vector2f(std::get<0>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos))) , std::get<1>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos)))));
}