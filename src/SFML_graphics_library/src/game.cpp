//
// Created by khalil on 12/7/21.
//
#include "../include/game.h"
#include "../../logic_library/include/stopwatch.h"
#include "../../logic_library/include/camera.h"
SFMLDoodleJump::Game::Game() {
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(get<0>(gameWindow), get<1>(gameWindow)), "DoodleJump");
}
void SFMLDoodleJump::Game::runGame() {
    // run the program as long as the window is open
    while (window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
        }
        DoodleJump::Stopwatch::getInstance().tick();
        if(DoodleJump::Stopwatch::getInstance().getTime_difference() >=1/60.0f){
            window->clear(sf::Color::Black);
            DoodleJump::Stopwatch::getInstance().reset();
            window->display();
        }
    }
}
