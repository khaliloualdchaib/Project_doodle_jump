//
// Created by khalil on 12/25/21.
//
#include "../include/concreteFactory.h"
#include <utility>
#include "../include/SFMLplayer.h"

SFMLDoodleJump::ConcreteFactory::ConcreteFactory(std::map<std::string, float> config, std::shared_ptr<sf::RenderWindow> w) {
    GameConfiguration = config;
    window = w;
}

std::shared_ptr<SFMLDoodleJump::SFMLPlayer> SFMLDoodleJump::ConcreteFactory::createPlayer(const std::shared_ptr<DoodleJump::Player> p) {
    sf::Texture playerTexture;
    if(!playerTexture.loadFromFile("sprites/doodleRight.png")){
        std::cout<<"doodleRight.png not found"<<std::endl;
    }
    std::shared_ptr<SFMLDoodleJump::SFMLPlayer> player = std::make_shared<SFMLDoodleJump::SFMLPlayer>(SFMLDoodleJump::SFMLPlayer(GameConfiguration["PlayerWidth"], GameConfiguration["PlayerHeight"],
                                                                                                                                 std::make_tuple(GameConfiguration["PlayerX_Position"], GameConfiguration["PlayerY_Position"]),
                                                                                                                                 window, playerTexture));
    p->addObserver(player);
    return player;
}
