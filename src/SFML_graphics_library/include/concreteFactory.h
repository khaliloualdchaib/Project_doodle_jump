//
// Created by khalil on 12/25/21.
//

#ifndef DOODLEJUMP_CONCRETEFACTORY_H
#define DOODLEJUMP_CONCRETEFACTORY_H
#include "../../logic_library/include/abstractFactory.h"
#include <map>
#include <SFML/Graphics.hpp>

namespace SFMLDoodleJump{
    class ConcreteFactory: public DoodleJump::AbstractFactory{
    private:
        std::shared_ptr<sf::RenderWindow> window;
        sf::Texture playerTexture;
    public:
        ConcreteFactory(std::shared_ptr<sf::RenderWindow> w);
        std::shared_ptr<DoodleJump::Observer> createPlayer(std::shared_ptr<DoodleJump::Player> p) override;
        std::shared_ptr<DoodleJump::Observer> createStaticPlatform(std::shared_ptr<DoodleJump::staticPlatform>p) override;
    };
}

#endif //DOODLEJUMP_CONCRETEFACTORY_H
