//
// Created by khalil on 1/2/22.
//

#ifndef DOODLEJUMP_SFMLTEMPORARYPLATFORM_H
#define DOODLEJUMP_SFMLTEMPORARYPLATFORM_H
#include "SFMLplatform.h"
namespace SFMLDoodleJump{
    class SFMLtemporaryPlatform: public SFMLPlatform{
    public:
        SFMLtemporaryPlatform(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w);
        void draw(std::tuple<float, float> pos) override;
        void HandleEvent(std::tuple<float, float> nextpos) override;
    };
}
#endif //DOODLEJUMP_SFMLTEMPORARYPLATFORM_H
