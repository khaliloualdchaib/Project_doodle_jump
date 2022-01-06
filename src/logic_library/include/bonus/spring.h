//
// Created by khalil on 1/6/22.
//

#ifndef DOODLEJUMP_SPRING_H
#define DOODLEJUMP_SPRING_H
#include "bonus.h"

namespace DoodleJump{
    class Spring: public Bonus{
    public:
        explicit Spring(const std::tuple<float, float> &pos);
    };
}
#endif //DOODLEJUMP_SPRING_H
