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
    shared_ptr<SFMLDoodleJump::ConcreteFactory> factory = make_shared<SFMLDoodleJump::ConcreteFactory>(SFMLDoodleJump::ConcreteFactory(window));
    DoodleJump::World world = DoodleJump::World(factory, GameConfiguration);
    world.generate_initPlatforms();
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
            world.updateWorldCamera();
            for(const auto& platform: world.getPlatforms()){
                platform->update(NONE);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                world.getPlayer()->update(LEFT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                world.getPlayer()->update(RIGHT);
            }
            else{
                world.getPlayer()->update();
            }
            world.collisionPlayerPlatform();
            DoodleJump::Stopwatch::getInstance().reset();
            window->display();
        }
    }
}
