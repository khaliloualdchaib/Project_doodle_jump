//
// Created by khalil on 12/16/21.
//

#ifndef DOODLEJUMP_SFMLPLAYER_H
#define DOODLEJUMP_SFMLPLAYER_H
#include "SFMLentity.h"
namespace SFMLDoodleJump{
    class SFMLPlayer: public SFMLEntity{
    private:
        sf::Sprite sprite;
        float jumpspeed = 0.03f;
    public:

        /*
         * SFMLPlayer constructor that takes the following inputs:
         * width, height pos and a pointer to the window
         */
        SFMLPlayer(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w, sf::Texture& texture);

        /*
         * Draws the player
         */
        void draw() override;

        /*
         * Handles an event. inherited, form the virtual function in observer.h
         */
        void HandleEvent() override;
    };
}
#endif //DOODLEJUMP_SFMLPLAYER_H
