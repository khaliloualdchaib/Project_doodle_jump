//
// Created by khalil on 1/6/22.
//

#ifndef DOODLEJUMP_SFMLBONUS_H
#define DOODLEJUMP_SFMLBONUS_H
#include "../SFMLentity.h"

namespace SFMLDoodleJump{
    class SFMLBonus: public SFMLEntity{
    public:
        SFMLBonus(float width, float height, const std::tuple<float, float> &pos,
                  const std::shared_ptr<sf::RenderWindow> &w);

    };
}
#endif //DOODLEJUMP_SFMLBONUS_H
