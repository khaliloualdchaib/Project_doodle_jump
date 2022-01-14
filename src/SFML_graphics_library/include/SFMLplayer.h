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

        /**
         * Constructor
         * @param width: Width of the player.
         * @param height: Height of the player.
         * @param pos: Initial position of the player.
         * @param w: The window where the player will be generated.
         * @param texture: The texture of the player.
         */
        SFMLPlayer(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w, const sf::Texture& texture);

        /**
         * Handles the event
         * @param pos: Position of the observer.
         * @param s: Gives how the score should be updated.
         */
        void HandleEvent(std::tuple<float, float> nextpos, scoreUpdate s) override;
        
    };
}
#endif //DOODLEJUMP_SFMLPLAYER_H
