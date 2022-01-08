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
        explicit HorizontalPlatform(const std::tuple<float, float> &pos);
        void update(COMMAND c, float speed) override;
        bool isHorizontal() override {return true;};
    };
}
#endif //DOODLEJUMP_HORIZONTALPLATFORM_H
