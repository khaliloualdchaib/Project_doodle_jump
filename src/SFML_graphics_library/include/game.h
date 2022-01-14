//
// Created by khalil on 12/7/21.
//

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H
#include <iostream>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <memory>

namespace SFMLDoodleJump{
    class Game{
    private:
        std::map<std::string, unsigned int> windowConfiguration;
        std::shared_ptr<sf::RenderWindow> window;
    public:

        /**
         * Constructor.
         * @param windowconf: Window configurations
         */
        Game(const std::map<std::string, unsigned int>& windowconf);

        /**
         * Runs the game, thus it also runs the main game loop.
         */
        void runGame();

    };
}
#endif //DOODLEJUMP_GAME_H
