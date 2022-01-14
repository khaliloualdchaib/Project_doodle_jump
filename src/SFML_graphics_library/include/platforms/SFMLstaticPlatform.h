//
// Created by khalil on 12/18/21.
//

#ifndef DOODLEJUMP_SFMLSTATICPLATFORM_H
#define DOODLEJUMP_SFMLSTATICPLATFORM_H
#include "SFMLplatform.h"

namespace SFMLDoodleJump{
    class SFMLStaticPlatform: public SFMLPlatform{
    public:

        /**
         * Constructor
         * @param width: Width of the static platform.
         * @param height: Height of the static platform.
         * @param pos: Initial position of the static platform.
         * @param w: The window where the static platform will be generated.
         */
        SFMLStaticPlatform(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w);
    };
}
#endif //DOODLEJUMP_SFMLSTATICPLATFORM_H
