//
// Created by khalil on 12/8/21.
//

#ifndef DOODLEJUMP_OBSERVABLE_H
#define DOODLEJUMP_OBSERVABLE_H
#include <memory>
#include <vector>
#include "observer.h"

namespace DoodleJump{
    class Observable{
    private:
        std::vector<std::shared_ptr<Observer>> observers; //this is a list of shared pointers to observers
    public:

        /*
         * addObserver adds an observer to the observers list given the observer that needs to be added.
         */
        void addObserver(std::shared_ptr<Observer> observer);

        /*
         * removeObserver removes an observer from the observers list given the index of the observer that needs to be removed.
         */
        void removeObserver(int index);

        /*
         * notifyObservers notifies all observers in the list observers.
         */
        void notifyObservers(std::tuple<float, float> pos);

        /*
         * This is a default constructor.
         */
        Observable() = default;

    };
}
#endif //DOODLEJUMP_OBSERVABLE_H
