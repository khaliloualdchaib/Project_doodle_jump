#include <iostream>
#include "SFML_graphics_library/include/game.h"
#include <map>

int main()
{
    std::map<std::string, unsigned int> windowconf = {{"Width", 600}, {"Height", 800}};
    SFMLDoodleJump::Game game = SFMLDoodleJump::Game(windowconf);
    game.runGame();
    return 0;
}