//
// Created by khalil on 12/16/21.
//

#include "../include/SFMLplayer.h"
#include <limits>

SFMLDoodleJump::SFMLPlayer::SFMLPlayer(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w, const sf::Texture& texture): SFMLEntity(width, height, pos, std::move(w)) {
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(std::get<0>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos))) , std::get<1>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(pos), std::get<1>(pos)))));
        sf::Vector2f targetSize(getCamera()->TransformWidth(width), getCamera()->TransformHeight(height));
    sprite.setScale(targetSize.x/sprite.getLocalBounds().width, targetSize.y/sprite.getLocalBounds().height);
}

void SFMLDoodleJump::SFMLPlayer::draw(std::tuple<float, float> pos) {
    SFMLDoodleJump::SFMLPlayer::getWindow()->draw(sprite);
}

void SFMLDoodleJump::SFMLPlayer::HandleEvent(std::tuple<float, float> nextpos) {
    draw();
    SFMLPlayer::setPosition(nextpos);
    sprite.setPosition(sf::Vector2f(std::get<0>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(nextpos), std::get<1>(nextpos))) , std::get<1>(SFMLDoodleJump::SFMLEntity::getCamera()->Transformation(std::get<0>(nextpos), std::get<1>(nextpos)))));
}