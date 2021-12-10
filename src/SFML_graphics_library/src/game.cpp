//
// Created by khalil on 12/7/21.
//
#include "../include/game.h"
#include "../../logic_library/include/stopwatch.h"
#include <SFML/Graphics.hpp>
#include "../../logic_library/include/camera.h"

SFMLDoodleJump::Game::Game(int width, int height) {
    gameWindow = make_tuple(width, height);
}

void SFMLDoodleJump::Game::runGame() {
    sf::RenderWindow window(sf::VideoMode(get<0>(gameWindow), get<1>(gameWindow)), "DoodleJump");
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        DoodleJump::Stopwatch::getInstance().tick();
        if(DoodleJump::Stopwatch::getInstance().getTime_difference() >=1/60.0f){
            DoodleJump::Stopwatch::getInstance().reset();
        }
    }
}
