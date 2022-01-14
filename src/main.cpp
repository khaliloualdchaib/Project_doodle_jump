#include "SFML_graphics_library/include/game.h"
#include <iostream>
#include <map>

int main()
{
        std::map<std::string, unsigned int> windowconf = {{"Width", 600}, {"Height", 800}};
        SFMLDoodleJump::Game game = SFMLDoodleJump::Game(windowconf);
        game.runGame();
        return 0;
}