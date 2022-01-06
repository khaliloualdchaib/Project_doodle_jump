//
// Created by khalil on 12/25/21.
//
#include "../include/concreteFactory.h"
#include <utility>
#include "../include/SFMLplayer.h"
#include "../include/platforms/SFMLstaticPlatform.h"
#include "../include/platforms/SFMLtemporaryPlatform.h"
#include "../include/platforms/SFMLhorizontalPlatform.h"
#include "../include/platforms/SFMLverticalPlatform.h"
#include "../include/SFMLbg_tile.h"

SFMLDoodleJump::ConcreteFactory::ConcreteFactory(std::shared_ptr<sf::RenderWindow> w) {
    window = std::move(w);
    sf::Texture ptexture;
    sf::Texture tileText;
    if(!ptexture.loadFromFile("sprites/doodleRight.png")){
        std::cout<<"doodleRight.png not found"<<std::endl;
    }
    if(!tileText.loadFromFile("sprites/background.png")){
        std::cout<<"background.png not found"<<std::endl;
    }
    playerTexture = ptexture;
    tileTexture = tileText;
}

std::shared_ptr<DoodleJump::Observer> SFMLDoodleJump::ConcreteFactory::createPlayer(const std::shared_ptr<DoodleJump::Player> p) {
    std::shared_ptr<SFMLDoodleJump::SFMLPlayer> player = std::make_shared<SFMLDoodleJump::SFMLPlayer>(p->getWidth(), p->getHeight(), p->getPosition(), window, playerTexture);
    return player;
}

std::shared_ptr<DoodleJump::Observer>SFMLDoodleJump::ConcreteFactory::createStaticPlatform(std::shared_ptr<DoodleJump::StaticPlatform> p) {
    std::shared_ptr<SFMLDoodleJump::SFMLStaticPlatform> platform = std::make_shared<SFMLDoodleJump::SFMLStaticPlatform>(SFMLDoodleJump::SFMLStaticPlatform(p->getWidth(), p->getHeight(), p->getPosition(), window));
    return platform;
}

std::shared_ptr<DoodleJump::Observer> SFMLDoodleJump::ConcreteFactory::createTemporaryPlatform(std::shared_ptr<DoodleJump::TemporaryPlatform> p) {
    std::shared_ptr<SFMLDoodleJump::SFMLTemporaryPlatform> platform = std::make_shared<SFMLDoodleJump::SFMLTemporaryPlatform>(SFMLDoodleJump::SFMLTemporaryPlatform(p->getWidth(), p->getHeight(), p->getPosition(), window));
    return platform;
}

std::shared_ptr<DoodleJump::Observer>SFMLDoodleJump::ConcreteFactory::createHorizontalPlatform(std::shared_ptr<DoodleJump::HorizontalPlatform> p) {
    std::shared_ptr<SFMLDoodleJump::SFMLHorizontalPlatform> platform = std::make_shared<SFMLDoodleJump::SFMLHorizontalPlatform>(SFMLDoodleJump::SFMLHorizontalPlatform(p->getWidth(), p->getHeight(), p->getPosition(), window));
    return platform;
}

std::shared_ptr<DoodleJump::Observer> SFMLDoodleJump::ConcreteFactory::createVerticalPlatform(std::shared_ptr<DoodleJump::VerticalPlatform> p) {
    std::shared_ptr<SFMLDoodleJump::SFMLVerticalPlatform> platform = std::make_shared<SFMLDoodleJump::SFMLVerticalPlatform>(SFMLDoodleJump::SFMLVerticalPlatform(p->getWidth(), p->getHeight(), p->getPosition(), window));
    return platform;
}

std::shared_ptr<DoodleJump::Observer>SFMLDoodleJump::ConcreteFactory::createbgTile(std::shared_ptr<DoodleJump::bg_Tile> b) {
    std::shared_ptr<SFMLDoodleJump::SFMLbg_Tile> tile = std::make_shared<SFMLDoodleJump::SFMLbg_Tile>(SFMLDoodleJump::SFMLbg_Tile(b->getWidth(), b->getWidth(), b->getPosition(), window, tileTexture));
    return tile;
}