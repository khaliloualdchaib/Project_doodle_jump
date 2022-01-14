//
// Created by khalil on 1/6/22.
//

#ifndef DOODLEJUMP_SFMLJETPACK_H
#define DOODLEJUMP_SFMLJETPACK_H
#include "SFMLbonus.h"

namespace SFMLDoodleJump {
class SFMLJetpack : public SFMLBonus
{
public:
        /**
         * Constructor
         * @param width: Width of the jetpack.
         * @param height: Height of the jetpack.
         * @param pos: Initial position of the jetpack.
         * @param w: The window where the jetpack will be generated.
         * @param texture: Texture of the jetpack
         */
        SFMLJetpack(float width, float height, const std::tuple<float, float>& pos,
                    const std::shared_ptr<sf::RenderWindow>& w, const sf::Texture& texture);
};
} // namespace SFMLDoodleJump
#endif // DOODLEJUMP_SFMLJETPACK_H
