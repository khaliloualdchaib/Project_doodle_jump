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
    public:

        /*
         * SFMLPlayer constructor that takes the following inputs:
         * width, height pos and a pointer to the window
         */
        SFMLPlayer(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w, const sf::Texture& texture);

        /*
         * Draws the player
         */
        void draw(std::tuple<float, float> pos) override;

        /*
         * Handles an event. inherited, form the virtual function in observer.h
         */
        void HandleEvent(std::tuple<float, float> nextpos, scoreUpdate s) override;
        
    };
}
#endif //DOODLEJUMP_SFMLPLAYER_H
