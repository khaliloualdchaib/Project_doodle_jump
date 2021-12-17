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
        std::tuple <int, int> gameWindow = std::make_tuple(600, 800); //this the default width and height of the window
        std::shared_ptr<sf::RenderWindow> window;
    public:

        /*
         * This a default constructor.
         */
        Game();

        /*
         * runGame runs the game, thus it also runs the main game loop.
         */
        void runGame();

    };
}
#endif //DOODLEJUMP_GAME_H
