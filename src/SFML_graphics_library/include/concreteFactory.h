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
        std::map<std::string, float> GameConfiguration;
        std::shared_ptr<sf::RenderWindow> window;
    public:
        explicit ConcreteFactory(std::map<std::string, float> config, std::shared_ptr<sf::RenderWindow> w);
        std::shared_ptr<SFMLDoodleJump::SFMLPlayer> createPlayer(std::shared_ptr<DoodleJump::Player> p) override;
    };
}

#endif //DOODLEJUMP_CONCRETEFACTORY_H
