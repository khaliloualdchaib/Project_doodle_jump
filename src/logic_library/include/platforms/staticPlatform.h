//
// Created by khalil on 12/18/21.
//

#ifndef DOODLEJUMP_STATICPLATFORM_H
#define DOODLEJUMP_STATICPLATFORM_H
#include "platform.h"
namespace DoodleJump{
    class StaticPlatform: public Platform{
    public:
        /**
         * Explicit constructor
         * @param pos: The initial position of the Static Platform.
         */
        explicit StaticPlatform(std::tuple<float, float> pos);

        /**
         * Updates the Static Platform.
         * @param c: Instruction that the static platform needs to carry out.
         * @param speed: The speed the static platform should move.
         */
        void update(INSTRUCTION c, float speed) override;

    };
}
#endif //DOODLEJUMP_STATICPLATFORM_H
