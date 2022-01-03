//
// Created by khalil on 12/19/21.
//

#ifndef DOODLEJUMP_PLATFORM_H
#define DOODLEJUMP_PLATFORM_H
#include "../entity.h"
#include <iostream>
namespace DoodleJump{
    class Platform: public Entity{
    public:

        /*
         * Constructor with the same inputs as the Entity class
         */
        explicit Platform(std::tuple<float, float> pos);

        virtual bool temporaryJumped() const {return false;};

        virtual void settemporaryJumped(bool b){};

    };
}
#endif //DOODLEJUMP_PLATFORM_H
