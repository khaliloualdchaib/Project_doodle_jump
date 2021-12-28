//
// Created by khalil on 12/19/21.
//

#ifndef DOODLEJUMP_PLATFORM_H
#define DOODLEJUMP_PLATFORM_H
#include "../entity.h"
namespace DoodleJump{
    class Platform: public Entity{
    public:

        /*
         * Constructor with the same inputs as the Entity class
         */
        Platform(float width, float height, std::tuple<float, float> pos);

    };
}
#endif //DOODLEJUMP_PLATFORM_H
