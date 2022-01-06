//
// Created by khalil on 1/6/22.
//

#ifndef DOODLEJUMP_JETPACK_H
#define DOODLEJUMP_JETPACK_H
#include "bonus.h"

namespace DoodleJump{
    class Jetpack: public Bonus{
    public:
        Jetpack(float width, float height, const std::tuple<float, float> &pos);

    };
}
#endif //DOODLEJUMP_JETPACK_H
