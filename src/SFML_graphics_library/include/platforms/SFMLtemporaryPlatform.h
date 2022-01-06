//
// Created by khalil on 1/2/22.
//

#ifndef DOODLEJUMP_SFMLTEMPORARYPLATFORM_H
#define DOODLEJUMP_SFMLTEMPORARYPLATFORM_H
#include "SFMLplatform.h"
namespace SFMLDoodleJump{
    class SFMLTemporaryPlatform: public SFMLPlatform{
    public:
        SFMLTemporaryPlatform(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w);
    };
}
#endif //DOODLEJUMP_SFMLTEMPORARYPLATFORM_H
