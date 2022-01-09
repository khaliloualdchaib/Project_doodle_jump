//
// Created by khalil on 1/6/22.
//

#ifndef DOODLEJUMP_SFMLBONUS_H
#define DOODLEJUMP_SFMLBONUS_H
#include "../SFMLentity.h"

namespace SFMLDoodleJump{
    class SFMLBonus: public SFMLEntity{
    private:
        sf::Sprite sprite;
    public:
        void setSprite(const sf::Sprite &s);

        SFMLBonus(float width, float height, const std::tuple<float, float> &pos,
                  const std::shared_ptr<sf::RenderWindow> &w);
        void draw(std::tuple<float, float> pos) override;

        void HandleEvent(std::tuple<float, float> nextpos, scoreUpdate s) override;

    };
}
#endif //DOODLEJUMP_SFMLBONUS_H
