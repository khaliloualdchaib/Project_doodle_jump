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
        sf::Texture tileTexture;
        sf::Texture springTexture;
        sf::Texture jetpackTexture;
    public:

        /*
         * Constructor
         */
        ConcreteFactory(std::shared_ptr<sf::RenderWindow> w);

        /*
         * function that creates the player view
         */
        std::shared_ptr<DoodleJump::Observer> createPlayer(std::shared_ptr<DoodleJump::Player> p) override;

        /*
         *  function that creates the static platform view
         */
        std::shared_ptr<DoodleJump::Observer> createStaticPlatform(std::shared_ptr<DoodleJump::StaticPlatform>p) override;

        std::shared_ptr<DoodleJump::Observer> createTemporaryPlatform(std::shared_ptr<DoodleJump::TemporaryPlatform>p) override;

        std::shared_ptr<DoodleJump::Observer> createHorizontalPlatform(std::shared_ptr<DoodleJump::HorizontalPlatform>p) override;

        std::shared_ptr<DoodleJump::Observer> createVerticalPlatform(std::shared_ptr<DoodleJump::VerticalPlatform> p) override;

        std::shared_ptr<DoodleJump::Observer> createbgTile(std::shared_ptr<DoodleJump::bg_Tile> b) override;

        std::shared_ptr<DoodleJump::Observer> createSpring(std::shared_ptr<DoodleJump::Spring> s) override;

        std::shared_ptr<DoodleJump::Observer> createJetpack(std::shared_ptr<DoodleJump::Jetpack> j) override;

    };
}

#endif //DOODLEJUMP_CONCRETEFACTORY_H
