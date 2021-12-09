//
// Created by khalil on 12/7/21.
//

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H
#include <iostream>
#include <tuple>

using namespace std;

namespace SFMLDoodleJump{
    class Game{
    private:
        tuple <int, int> gameWindow = make_tuple(800, 600); //this the default width and height of the window
    public:

        /*
         * This a default constructor.
         */
        Game() = default;

        /*
         * This is a constructor.
         * The inputs are the width and height of the window.
         */
        Game(int width, int height);

        /*
         * runGame runs the game, thus it also runs the main game loop.
         */
        void runGame();

    };
}
#endif //DOODLEJUMP_GAME_H
