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
        std::map<std::string, float> GameConfiguration;
        std::shared_ptr<sf::RenderWindow> window;
    public:

        /*
         * Constructor.
         */
        Game(const std::map<std::string, unsigned int>& windowconf, const std::map<std::string, float>& config);

        /*
         * runGame runs the game, thus it also runs the main game loop.
         */
        void runGame();

    };
}
#endif //DOODLEJUMP_GAME_H
