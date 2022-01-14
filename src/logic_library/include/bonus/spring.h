//
// Created by khalil on 1/6/22.
//

#ifndef DOODLEJUMP_SPRING_H
#define DOODLEJUMP_SPRING_H
#include "bonus.h"

namespace DoodleJump{
    class Spring: public Bonus{
    public:

        /**
         * Explicit constructor
         * @param pos: Initial position of the Jetpack.
         */
        explicit Spring(const std::tuple<float, float> &pos);

        /**
         * Updates the spring.
         * @param c: Instruction that the spring needs to carry out.
         * @param speed: The speed that the spring needs to move with.
         */
        void update(INSTRUCTION c, float speed) override;

        /**
         * @return true.
         */
        bool isSpring() override{return true;};

    };
}
#endif //DOODLEJUMP_SPRING_H
