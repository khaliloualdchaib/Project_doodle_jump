//
// Created by khalil on 12/25/21.
//
#include "../include/concreteFactory.h"
#include <utility>
#include "../include/SFMLplayer.h"
#include "../include/platforms/SFMLstaticPlatform.h"
#include "../include/platforms/SFMLtemporaryPlatform.h"

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

std::shared_ptr<DoodleJump::Observer>SFMLDoodleJump::ConcreteFactory::createStaticPlatform(std::shared_ptr<DoodleJump::staticPlatform> p) {
    std::shared_ptr<SFMLDoodleJump::SFMLstaticPlatform> platform = std::make_shared<SFMLDoodleJump::SFMLstaticPlatform>(SFMLDoodleJump::SFMLstaticPlatform(p->getWidth(), p->getHeight(), p->getPosition(), window));
    return platform;
}

std::shared_ptr<DoodleJump::Observer> SFMLDoodleJump::ConcreteFactory::createTemporaryPlatform(std::shared_ptr<DoodleJump::temporaryPlatform> p) {
    std::shared_ptr<SFMLDoodleJump::SFMLtemporaryPlatform> platform = std::make_shared<SFMLDoodleJump::SFMLtemporaryPlatform>(SFMLDoodleJump::SFMLtemporaryPlatform(p->getWidth(), p->getHeight(), p->getPosition(), window));
    return platform;
}