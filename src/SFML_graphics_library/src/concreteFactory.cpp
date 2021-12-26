//
// Created by khalil on 12/25/21.
//
#include "../include/concreteFactory.h"
#include <utility>
#include "../include/SFMLplayer.h"
#include "../include/platforms/SFMLplatform.h"

SFMLDoodleJump::ConcreteFactory::ConcreteFactory(std::shared_ptr<sf::RenderWindow> w) {
    window = std::move(w);
    sf::Texture texture;
    if(!texture.loadFromFile("sprites/doodleRight.png")){
        std::cout<<"doodleRight.png not found"<<std::endl;
    }
    playerTexture = texture;
}

std::shared_ptr<DoodleJump::Observer> SFMLDoodleJump::ConcreteFactory::createPlayer(const std::shared_ptr<DoodleJump::Player> p) {
    std::shared_ptr<SFMLDoodleJump::SFMLPlayer> player = std::make_shared<SFMLDoodleJump::SFMLPlayer>(p->getWidth(), p->getHeight(), p->getPosition(), window, playerTexture);
    return player;
}

std::shared_ptr<DoodleJump::Observer>SFMLDoodleJump::ConcreteFactory::createPlatform(std::shared_ptr<DoodleJump::Platform> p) {
    std::shared_ptr<SFMLDoodleJump::SFMLPlatform> platform = std::make_shared<SFMLDoodleJump::SFMLPlatform>(SFMLDoodleJump::SFMLPlatform(p->getWidth(), p->getHeight(), p->getPosition(), window));
    return platform;
}