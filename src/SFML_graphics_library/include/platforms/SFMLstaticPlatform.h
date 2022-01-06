//
// Created by khalil on 12/18/21.
//

#ifndef DOODLEJUMP_SFMLSTATICPLATFORM_H
#define DOODLEJUMP_SFMLSTATICPLATFORM_H
#include "SFMLplatform.h"

namespace SFMLDoodleJump{
    class SFMLStaticPlatform: public SFMLPlatform{
    public:

        /*
         * Constructor that takes the same input as the SFMLPlatform class.
         */
        SFMLStaticPlatform(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w);
    };
}
#endif //DOODLEJUMP_SFMLSTATICPLATFORM_H
