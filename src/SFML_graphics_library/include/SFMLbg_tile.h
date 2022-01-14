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

        /**
         * Constructor
         * @param width: Width of the tile.
         * @param height: Height of the tile.
         * @param pos: Initial position of the tile.
         * @param w: The window where the tile will be generated.
         * @param texture: Texture of the tile.
         */
        SFMLbg_Tile(float width, float height, const std::tuple<float, float> &pos, const std::shared_ptr<sf::RenderWindow> &w, const sf::Texture& texture);

        /**
         * Handles the event
         * @param pos: Position of the observer.
         * @param s: Gives how the score should be updated.
         */
        void HandleEvent(std::tuple<float, float> nextpos, scoreUpdate s) override;
    };
}
#endif //DOODLEJUMP_SFMLBG_TILE_H
