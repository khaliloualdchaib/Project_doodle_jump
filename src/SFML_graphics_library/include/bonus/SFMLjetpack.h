//
// Created by khalil on 1/6/22.
//

#ifndef DOODLEJUMP_SFMLJETPACK_H
#define DOODLEJUMP_SFMLJETPACK_H
#include "SFMLbonus.h"

namespace SFMLDoodleJump{
    class SFMLJetpack: public SFMLBonus{
    public:
        SFMLJetpack(float width, float height, const std::tuple<float, float> &pos,
                    const std::shared_ptr<sf::RenderWindow> &w, const sf::Texture& texture);
    };
}
#endif //DOODLEJUMP_SFMLJETPACK_H
