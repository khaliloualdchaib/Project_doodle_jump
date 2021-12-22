//
// Created by khalil on 12/18/21.
//

#ifndef DOODLEJUMP_STATICPLATFORM_H
#define DOODLEJUMP_STATICPLATFORM_H
#include "platform.h"
namespace DoodleJump{
    class staticPlatform: public Platform{
    public:
        /*
         * Constructor with the same inputs as the Platform class.
         */
        staticPlatform(float width, float height, std::tuple<float, float> pos);
    };
}
#endif //DOODLEJUMP_STATICPLATFORM_H
