#include <iostream>
#include "SFML_graphics_library/include/game.h"
#include <map>

int main()
{
    std::map<std::string, unsigned int> windowconf = {{"Width", 600}, {"Height", 800}};
    std::map<std::string, float> configurations = {{"PlayerWidth", 0.8f}, {"PlayerHeight", 0.44f}, {"PlayerX_Position", 0.f}, {"PlayerY_Position", -2.5f},
                                                   {"PlatformWidth", 1.33f}, {"PlatformHeight", 0.07f}};
    SFMLDoodleJump::Game game = SFMLDoodleJump::Game(windowconf, configurations);
    game.runGame();
    return 0;
}