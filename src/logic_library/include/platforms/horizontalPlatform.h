//
// Created by khalil on 1/2/22.
//

#ifndef DOODLEJUMP_HORIZONTALPLATFORM_H
#define DOODLEJUMP_HORIZONTALPLATFORM_H
#include "platform.h"

namespace DoodleJump{
    class HorizontalPlatform: public Platform{
    private:
        bool goLeft = false;
        bool goRight = false;
    public:

        /**
         * Explicit constructor
         * @param pos: The initial position of the Horizontal Platform.
         */
        explicit HorizontalPlatform(const std::tuple<float, float> &pos);

        /**
         * Updates the Horizontal Platform.
         * @param c: Instruction that the horizontal platform needs to carry out.
         * @param speed: The speed the horizontal platform should move.
         */
        void update(INSTRUCTION c, float speed) override;

        /**
         * @return true
         */
        bool isHorizontal() override {return true;};

    };
}
#endif //DOODLEJUMP_HORIZONTALPLATFORM_H
