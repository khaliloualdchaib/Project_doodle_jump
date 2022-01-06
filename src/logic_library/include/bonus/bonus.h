//
// Created by khalil on 1/5/22.
//

#ifndef DOODLEJUMP_BONUS_H
#define DOODLEJUMP_BONUS_H
#include "../entity.h"

namespace DoodleJump{
    class Bonus: public Entity{
    public:
        Bonus(float width, float height, const std::tuple<float, float> &pos);

        void update(COMMAND c) override;
    };
}
#endif //DOODLEJUMP_BONUS_H