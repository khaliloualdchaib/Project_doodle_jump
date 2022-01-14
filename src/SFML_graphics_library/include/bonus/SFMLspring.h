//
// Created by khalil on 1/6/22.
//

#ifndef DOODLEJUMP_SFMLSPRING_H
#define DOODLEJUMP_SFMLSPRING_H
#include "SFMLbonus.h"

namespace SFMLDoodleJump {
class SFMLSpring : public SFMLBonus
{
public:
        /**
         * Constructor
         * @param width: Width of the spring.
         * @param height: Height of the spring.
         * @param pos: Initial position of the spring.
         * @param w: The window where the spring will be generated.
         * @param texture: Texture of the spring
         */
        SFMLSpring(float width, float height, const std::tuple<float, float>& pos,
                   const std::shared_ptr<sf::RenderWindow>& w, const sf::Texture& texture);
};
} // namespace SFMLDoodleJump
#endif // DOODLEJUMP_SFMLSPRING_H
