//
// Created by khalil on 12/7/21.
//
#include "../include/game.h"
#include "../../logic_library/include/stopwatch.h"
#include "../../logic_library/include/camera.h"

#include "../../logic_library/include/player.h"
#include "../include/SFMLplayer.h"
#include "../include/platforms/SFMLstaticPlatform.h"

SFMLDoodleJump::Game::Game() {
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(get<0>(gameWindow), get<1>(gameWindow)), "DoodleJump");
}

void SFMLDoodleJump::Game::runGame() {
    sf::Texture playerTexture;
    if(!playerTexture.loadFromFile("sprites/doodleRight.png")){
        std::cout<<"doodleRight.png not found"<<std::endl;
    }
    DoodleJump::Player p1 = DoodleJump::Player(60.f, 50.f, make_tuple(0, 0));
    shared_ptr<SFMLDoodleJump::SFMLPlayer> p2 = make_shared<SFMLDoodleJump::SFMLPlayer>(SFMLDoodleJump::SFMLPlayer(60, 59, make_tuple(0, 0), window, playerTexture));
    p1.addObserver(p2);
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
            p2->draw();
            p1.jump();
            //cout<<"p1: "<<get<0>(p1.getPosition())<<", "<<get<1>(p1.getPosition())<<endl;
            //cout<<"p2: "<<get<0>(p2->getPosition())<<", "<<get<1>(p2->getPosition())<<endl;
            SFMLDoodleJump::SFMLstaticPlatform s = SFMLDoodleJump::SFMLstaticPlatform(100, 10, make_tuple(0, 0), window);
            s.draw();
            //cout<<s.getWidth()<<", "<<s.getHeight()<<endl;
            DoodleJump::Stopwatch::getInstance().reset();
            window->display();
        }
    }
}
