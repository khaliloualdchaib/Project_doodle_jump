//
// Created by khalil on 12/7/21.
//
#include "../include/game.h"
#include "../../logic_library/include/stopwatch.h"
#include "../../logic_library/include/camera.h"
#include "../include/platforms/SFMLstaticPlatform.h"
#include "../../logic_library/include/world.h"
#include "../include/concreteFactory.h"
SFMLDoodleJump::Game::Game(const std::map<std::string, unsigned int>& windowconf) {
    windowConfiguration = windowconf;
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(windowConfiguration["Width"], windowConfiguration["Height"]), "DoodleJump");
}

void SFMLDoodleJump::Game::runGame() {
    shared_ptr<DoodleJump::Camera> camera = make_shared<DoodleJump::Camera>(DoodleJump::Camera(windowConfiguration["Width"], windowConfiguration["Height"]));
    shared_ptr<SFMLDoodleJump::ConcreteFactory> factory = make_shared<SFMLDoodleJump::ConcreteFactory>(SFMLDoodleJump::ConcreteFactory(window));
    DoodleJump::World world = DoodleJump::World(factory);
    world.generate_initPlatforms();
    sf::Font font;
    if (!font.loadFromFile("font/Academy.ttf"))
    {
        std::cout<<"Can not find Academy.ttf"<<std::endl;
    }
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
            if(std::get<1>(world.getPlayer()->getPosition())>=-3){
                world.updateWorldCamera();
                world.updateTiles();
                sf::Text text;
                text.setFont(font);
                text.setString(world.returnScore());
                text.setCharacterSize(24);
                text.setFillColor(sf::Color::White);
                window->draw(text);
                world.runGameLogic();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    world.getPlayer()->update(LEFT, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    world.getPlayer()->update(RIGHT, 0);
                }
                else{
                    world.getPlayer()->update(NONE, 0);
                }
            }
            else{
                sf::Text game_over;
                game_over.setFont(font);
                game_over.setString(world.Game_Over_Message());
                game_over.setCharacterSize(50);
                game_over.setFillColor(sf::Color::Red);
                game_over.setPosition(sf::Vector2f(std::get<0>(camera->Transformation(-2, 0.5)), std::get<1>(camera->Transformation(-2, 0.5))));
                window->draw(game_over);
            }
            DoodleJump::Stopwatch::getInstance().reset();
            window->display();
        }
    }
}
