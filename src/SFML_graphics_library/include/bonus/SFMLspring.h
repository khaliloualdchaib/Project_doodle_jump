//
// Created by khalil on 1/6/22.
//

#ifndef DOODLEJUMP_SFMLSPRING_H
#define DOODLEJUMP_SFMLSPRING_H
#include "SFMLbonus.h"

namespace SFMLDoodleJump{
    class SFMLSpring: public SFMLBonus{
    public:
        SFMLSpring(float width, float height, const std::tuple<float, float> &pos,
                   const std::shared_ptr<sf::RenderWindow> &w, const sf::Texture& texture);
    };
}
#endif //DOODLEJUMP_SFMLSPRING_H
