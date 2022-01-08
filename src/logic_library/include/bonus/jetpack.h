//
// Created by khalil on 1/6/22.
//

#ifndef DOODLEJUMP_JETPACK_H
#define DOODLEJUMP_JETPACK_H
#include "bonus.h"

namespace DoodleJump{
    class Jetpack: public Bonus{
    public:
        explicit Jetpack(const std::tuple<float, float> &pos);
        void update(COMMAND c, float speed) override;
        bool isJetpack() override {return true;};

    };
}
#endif //DOODLEJUMP_JETPACK_H
