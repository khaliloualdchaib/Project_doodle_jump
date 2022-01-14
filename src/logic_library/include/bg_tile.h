//
// Created by khalil on 1/5/22.
//

#ifndef DOODLEJUMP_BG_TILE_H
#define DOODLEJUMP_BG_TILE_H
#include "entity.h"
namespace DoodleJump{
    class bg_Tile: public Entity{
    public:

        /**
         * Explicit constructor
         * @param pos: Initial position of the tile.
         */
        explicit bg_Tile(const std::tuple<float, float> &pos);

        /**
         * Updates the Tile.
         * @param c: Instruction that the tile needs to carry out.
         * @param speed: The speed that the tile needs to move with.
         */
        void update(INSTRUCTION c, float speed) override;
    };
}
#endif //DOODLEJUMP_BG_TILE_H
