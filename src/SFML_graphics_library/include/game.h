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
        Game() = default;
        Game(int width, int height);
        void runGame();

    };
}
#endif //DOODLEJUMP_GAME_H
