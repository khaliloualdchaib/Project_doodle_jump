//
// Created by khalil on 1/3/22.
//

#ifndef DOODLEJUMP_VERTICALPLATFORM_H
#define DOODLEJUMP_VERTICALPLATFORM_H
#include "platform.h"
namespace DoodleJump{
    class VerticalPlatform: public Platform{
    private:
        const float maxheight = 1.f;
        const float speed = 0.02f;
        bool goUP = false;
        bool goDOWN = false;
        float heightcounter = 0;
    public:

        /**
         * Explicit constructor
         * @param pos: The initial position of the Vertical Platform
         */
        explicit VerticalPlatform(const std::tuple<float, float> &pos);

        /**
         * Updates the Vertical Platform.
         * @param c: Instruction that the vertical platform needs to carry out.
         * @param speed: The speed the vertical platform should move.
         */
        void update(INSTRUCTION c, float speed) override;

        /**
         * @return true
         */
        bool isVertical() override{return true;};

        /**
         * Getter for maxheight
         * @return maxheight
         */
        float getMaxHeight() override{return maxheight;};
    };


}
#endif //DOODLEJUMP_VERTICALPLATFORM_H
