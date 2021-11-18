#include <SFML/Graphics.hpp>
#include "logic_library/include/random.h"
#include "logic_library/include/stopwatch.h"
#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

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
            cout<<1/DoodleJump::Stopwatch::getInstance().getTime_difference()<<endl;
        }
    }
    DoodleJump::Random::getInstance().initialise_rng();
    cout<<DoodleJump::Random::getInstance().getrandomnumber()<<endl;
    cout<<DoodleJump::Random::getInstance().getrandomnumber()<<endl;
    cout<<DoodleJump::Random::getInstance().getrandomnumber()<<endl;
    cout<<DoodleJump::Random::getInstance().getrandomnumber()<<endl;
    return 0;
}