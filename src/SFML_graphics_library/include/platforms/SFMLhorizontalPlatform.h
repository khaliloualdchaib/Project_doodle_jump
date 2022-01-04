//
// Created by khalil on 1/2/22.
//

#ifndef DOODLEJUMP_SFMLHORIZONTALPLATFORM_H
#define DOODLEJUMP_SFMLHORIZONTALPLATFORM_H
#include "SFMLplatform.h"
namespace SFMLDoodleJump{
    class SFMLHorizontalPlatform: public SFMLPlatform{
    public:
        SFMLHorizontalPlatform(float width, float height, const std::tuple<float, float> &pos,const std::shared_ptr<sf::RenderWindow> &w);
        void HandleEvent(std::tuple<float, float> nextpos) override;
    };
}
#endif //DOODLEJUMP_SFMLHORIZONTALPLATFORM_H
