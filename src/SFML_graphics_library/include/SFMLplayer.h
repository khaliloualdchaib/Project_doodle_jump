//
// Created by khalil on 12/16/21.
//

#ifndef DOODLEJUMP_SFMLPLAYER_H
#define DOODLEJUMP_SFMLPLAYER_H
#include "SFMLentity.h"
namespace SFMLDoodleJump{
    class SFMLPlayer: public SFMLEntity{
    private:
        sf::Texture texture;
        sf::Sprite sprite;
    public:
        SFMLPlayer(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w);
        void createPlayer();
    };
}
#endif //DOODLEJUMP_SFMLPLAYER_H
