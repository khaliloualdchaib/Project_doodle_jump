//
// Created by khalil on 1/5/22.
//

#ifndef DOODLEJUMP_BG_TILE_H
#define DOODLEJUMP_BG_TILE_H
#include "entity.h"
namespace DoodleJump{
    class bg_Tile: public Entity{
    public:
        explicit bg_Tile(const std::tuple<float, float> &pos);

        void update(COMMAND c) override;
    };
}
#endif //DOODLEJUMP_BG_TILE_H
