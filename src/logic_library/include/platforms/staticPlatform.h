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
        explicit staticPlatform(std::tuple<float, float> pos);

        /*
         * update the platform
         */
        void update(COMMAND=NONE) override;
    };
}
#endif //DOODLEJUMP_STATICPLATFORM_H
