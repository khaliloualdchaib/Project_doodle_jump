//
// Created by khalil on 1/5/22.
//

#ifndef DOODLEJUMP_SFMLBG_TILE_H
#define DOODLEJUMP_SFMLBG_TILE_H
#include "SFMLentity.h"
namespace SFMLDoodleJump{
    class SFMLbg_Tile: public SFMLEntity{
    private:
        sf::Sprite sprite;
    public:
        SFMLbg_Tile(float width, float height, const std::tuple<float, float> &pos, const std::shared_ptr<sf::RenderWindow> &w, const sf::Texture& texture);

        void draw(std::tuple<float, float> pos) override;

        void HandleEvent(std::tuple<float, float> nextpos, scoreUpdate s) override;
    };
}
#endif //DOODLEJUMP_SFMLBG_TILE_H
