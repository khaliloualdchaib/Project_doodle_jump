//
// Created by khalil on 1/3/22.
//

#ifndef DOODLEJUMP_SFMLVERTICALPLATFORM_H
#define DOODLEJUMP_SFMLVERTICALPLATFORM_H
#include "SFMLplatform.h"

namespace SFMLDoodleJump {
class SFMLVerticalPlatform : public SFMLPlatform
{
public:
        /**
         * Constructor
         * @param width: Width of the vertical platform.
         * @param height: Height of the vertical platform.
         * @param pos: Initial position of the vertical platform.
         * @param w: The window where the vertical platform will be generated.
         */
        SFMLVerticalPlatform(float width, float height, const std::tuple<float, float>& pos,
                             std::shared_ptr<sf::RenderWindow> w);
};
} // namespace SFMLDoodleJump
#endif // DOODLEJUMP_SFMLVERTICALPLATFORM_H
