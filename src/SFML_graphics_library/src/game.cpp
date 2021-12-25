//
// Created by khalil on 12/7/21.
//
#include "../include/game.h"
#include "../../logic_library/include/stopwatch.h"
#include "../../logic_library/include/camera.h"
#include "../include/platforms/SFMLstaticPlatform.h"
#include "../../logic_library/include/world.h"
#include "../../logic_library/include/camera.h"
#include "../../logic_library/include/platforms/staticPlatform.h"
#include "../include/concreteFactory.h"

SFMLDoodleJump::Game::Game(const std::map<std::string, unsigned int>& windowconf, const std::map<std::string, float>& config) {
    windowConfiguration = windowconf;
    GameConfiguration = config;
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(windowConfiguration["Width"], windowConfiguration["Height"]), "DoodleJump");
}

void SFMLDoodleJump::Game::runGame() {
    shared_ptr<DoodleJump::Camera> camera = make_shared<DoodleJump::Camera>(DoodleJump::Camera(windowConfiguration["Width"], windowConfiguration["Height"]));
    DoodleJump::World world;
    //SFMLDoodleJump::ConcreteFactory factory = SFMLDoodleJump::ConcreteFactory(GameConfiguration, window);
    //shared_ptr<DoodleJump::Player> p1 = make_shared<DoodleJump::Player>(DoodleJump::Player(GameConfiguration["PlayerWidth"], GameConfiguration["PlayerHeight"],
                                                                                           //make_tuple(GameConfiguration["PlayerX_Position"], GameConfiguration["PlayerY_Position"])));
    shared_ptr<SFMLDoodleJump::SFMLstaticPlatform> s1 = make_shared<SFMLDoodleJump::SFMLstaticPlatform>(SFMLDoodleJump::SFMLstaticPlatform(1.33f, 0.07f, make_tuple(0,-2.5f), window));
    shared_ptr<DoodleJump::staticPlatform> s2 = make_shared<DoodleJump::staticPlatform>(DoodleJump::staticPlatform(1.33f, 0.07f, make_tuple(0, -2.5f)));
    //world.setPlayer(p1);
    //shared_ptr<SFMLDoodleJump::SFMLPlayer> p2 = factory.createPlayer(world.getPlayer());
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

            //cout<<"p2: "<<get<0>(p2->getPosition())<<", "<<get<1>(p2->getPosition())<<endl;
            s1->draw();
            //world.getPlayer()->jump();
            //cout<<"p1: "<<get<0>(world.getPlayer()->getPosition())<<", "<<get<1>(world.getPlayer()->getPosition())<<endl;
            //world.collisionPlayerPlatform();
            //cout<<s.getWidth()<<", "<<s.getHeight()<<endl;
            DoodleJump::Stopwatch::getInstance().reset();
            window->display();
        }
    }
}
