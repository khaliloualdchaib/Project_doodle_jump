//
// Created by khalil on 1/6/22.
//

#ifndef DOODLEJUMP_JETPACK_H
#define DOODLEJUMP_JETPACK_H
#include "bonus.h"

namespace DoodleJump {
class Jetpack : public Bonus
{
public:
        /**
         * Explicit constructor
         * @param pos: Initial position of the Jetpack.
         */
        explicit Jetpack(const std::tuple<float, float>& pos);

        /**
         * Updates the jetpack.
         * @param c: Instruction that the jetpack needs to carry out.
         * @param speed: The speed that the jetpack needs to move with.
         */
        void update(INSTRUCTION c, float speed) override;

        /**
         * @return true.
         */
        bool isJetpack() override { return true; };
};
} // namespace DoodleJump
#endif // DOODLEJUMP_JETPACK_H
