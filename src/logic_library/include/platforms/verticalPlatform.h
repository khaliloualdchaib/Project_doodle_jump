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
        explicit VerticalPlatform(const std::tuple<float, float> &pos);

        void update(COMMAND c, float speed) override;

        bool isVertical() override{return true;};

        float getMaxHeight() override{return maxheight;};
    };


}
#endif //DOODLEJUMP_VERTICALPLATFORM_H
