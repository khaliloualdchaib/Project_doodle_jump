//
// Created by khalil on 12/18/21.
//

#ifndef DOODLEJUMP_STATICPLATFORM_H
#define DOODLEJUMP_STATICPLATFORM_H
#include "../entity.h"
namespace DoodleJump{
    class staticPlatform: public Entity{
    public:
        staticPlatform(float width, float height, std::tuple<float, float> pos);
    };
}
#endif //DOODLEJUMP_STATICPLATFORM_H
