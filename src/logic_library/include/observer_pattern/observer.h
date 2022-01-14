//
// Created by khalil on 12/8/21.
//

#ifndef DOODLEJUMP_OBSERVER_H
#define DOODLEJUMP_OBSERVER_H
#include <tuple>
#include <limits>
enum scoreUpdate{newHeight, staticcol, horizontalcol, verticalcol, springcol, jetpackcol, zero};
namespace DoodleJump{
    class Observer{
    public:

        /**
         * Handles the events
         * @param pos: Position of the observer.
         * @param s: Gives how the score should be updated.
         */
        virtual void HandleEvent(std::tuple<float, float> pos, scoreUpdate s){};

        /**
         * Default constructor.
         */
        Observer() = default;

    };
}

#endif //DOODLEJUMP_OBSERVER_H
