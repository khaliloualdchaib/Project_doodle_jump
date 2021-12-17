//
// Created by khalil on 12/16/21.
//

#ifndef DOODLEJUMP_PLAYER_H
#define DOODLEJUMP_PLAYER_H
#include "entity.h"
namespace DoodleJump{
    class Player: public Entity{
    public:

        /*
         * Constructor
         * It has the following inputs:
         * width, height and pos
         */
        Player(float width, float height, std::tuple<float, float> pos);
    };
}
#endif //DOODLEJUMP_PLAYER_H
