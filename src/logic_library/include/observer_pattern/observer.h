//
// Created by khalil on 12/8/21.
//

#ifndef DOODLEJUMP_OBSERVER_H
#define DOODLEJUMP_OBSERVER_H
namespace DoodleJump{
    class Observer{
    public:

        /*
         * HandleEvent handles the events
         */
        virtual void HandleEvent() = 0;

    };
}
#endif //DOODLEJUMP_OBSERVER_H
