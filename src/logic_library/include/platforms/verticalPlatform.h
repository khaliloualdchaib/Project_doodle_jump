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
    public:
        explicit VerticalPlatform(const std::tuple<float, float> &pos);

        void update(COMMAND c) override;
    };


}
#endif //DOODLEJUMP_VERTICALPLATFORM_H
