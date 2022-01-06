//
// Created by khalil on 1/3/22.
//

#ifndef DOODLEJUMP_SFMLVERTICALPLATFORM_H
#define DOODLEJUMP_SFMLVERTICALPLATFORM_H
#include "SFMLplatform.h"

namespace SFMLDoodleJump{
    class SFMLVerticalPlatform: public SFMLPlatform{
    public:
        SFMLVerticalPlatform(float width, float height, const std::tuple<float, float> &pos, std::shared_ptr<sf::RenderWindow> w);
    };
}
#endif //DOODLEJUMP_SFMLVERTICALPLATFORM_H
