//
// Created by khalil on 12/13/21.
//

#ifndef DOODLEJUMP_PLAYER_H
#define DOODLEJUMP_PLAYER_H
#include "entity.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace SFMLDoodleJump{
    class Player: public SFMLDoodleJump::Entity{
    private:
        sf::Texture texture;
        sf::Sprite sprite;
    public:

        Player(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow>& w);

        ~Player() override = default;

        void createPlayer();

    };
}
#endif //DOODLEJUMP_PLAYER_H
