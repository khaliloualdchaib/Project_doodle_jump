//
// Created by khalil on 12/8/21.
//

#ifndef DOODLEJUMP_OBSERVER_H
#define DOODLEJUMP_OBSERVER_H
#include <tuple>
#include <limits>

namespace DoodleJump{
    class Observer{
    public:

        /*
         * HandleEvent handles the events
         */
        virtual void HandleEvent(std::tuple<float, float> nextpos){};

        /*
         * This is a default constructor.
         */
        Observer() = default;

    };
}

#endif //DOODLEJUMP_OBSERVER_H
