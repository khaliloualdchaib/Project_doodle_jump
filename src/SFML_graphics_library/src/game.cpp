//
// Created by khalil on 12/7/21.
//
#include "../include/game.h"
#include "../../logic_library/include/stopwatch.h"
#include "../../logic_library/include/camera.h"
#include "../include/SFMLplayer.h"
#include "../include/platforms/SFMLstaticPlatform.h"
#include "../../logic_library/include/world.h"
#include "../../logic_library/include/camera.h"
#include "../../logic_library/include/platforms/staticPlatform.h"

SFMLDoodleJump::Game::Game() {
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(get<0>(gameWindow), get<1>(gameWindow)), "DoodleJump");
}

void SFMLDoodleJump::Game::runGame() {
    sf::Texture playerTexture;
    if(!playerTexture.loadFromFile("sprites/doodleRight.png")){
        std::cout<<"doodleRight.png not found"<<std::endl;
    }
    shared_ptr<DoodleJump::Camera> camera = make_shared<DoodleJump::Camera>(DoodleJump::Camera(get<0>(gameWindow), get<1>(gameWindow)));
    DoodleJump::World world = DoodleJump::World(camera);
    shared_ptr<DoodleJump::Player> p1 = make_shared<DoodleJump::Player>(DoodleJump::Player(60.f, 50.f, make_tuple(0, 0)));
    shared_ptr<SFMLDoodleJump::SFMLPlayer> p2 = make_shared<SFMLDoodleJump::SFMLPlayer>(SFMLDoodleJump::SFMLPlayer(60, 59, make_tuple(0, 0), window, playerTexture));
    shared_ptr<SFMLDoodleJump::SFMLstaticPlatform> s1 = make_shared<SFMLDoodleJump::SFMLstaticPlatform>(SFMLDoodleJump::SFMLstaticPlatform(100, 10, make_tuple(0, 0), window));
    shared_ptr<DoodleJump::staticPlatform> s2 = make_shared<DoodleJump::staticPlatform>(DoodleJump::staticPlatform(100, 10, make_tuple(0, 0)));
    world.setPlayer(p1);
    world.getPlayer()->addObserver(p2);
    s2->addObserver(s1);
    world.addPlatform(s2);
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
            //cout<<"p2: "<<get<0>(p2->getPosition())<<", "<<get<1>(p2->getPosition())<<endl;
            s1->draw();
            world.getPlayer()->jump();
            //cout<<"p1: "<<get<0>(world.getPlayer()->getPosition())<<", "<<get<1>(world.getPlayer()->getPosition())<<endl;
            world.collisionPlayerPlatform();
            //cout<<s.getWidth()<<", "<<s.getHeight()<<endl;
            DoodleJump::Stopwatch::getInstance().reset();
            window->display();
        }
    }
}
