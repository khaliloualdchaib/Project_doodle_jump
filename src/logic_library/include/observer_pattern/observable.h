//
// Created by khalil on 12/8/21.
//

#ifndef DOODLEJUMP_OBSERVABLE_H
#define DOODLEJUMP_OBSERVABLE_H
#include "observer.h"
#include <memory>
#include <vector>

namespace DoodleJump {
class Observable
{
private:
        std::vector<std::shared_ptr<Observer>> observers; // this is a list of shared pointers to observers
public:
        /**
         * Adds an observer to the observers list.
         * @param observer: The observer that needs to be added in the list.
         */
        void addObserver(const std::shared_ptr<Observer>& observer);

        /**
         * Removes an observer from the observers list.
         * @param index: The index of the observer that needs to be removed.
         */
        void removeObserver(int index);

        /**
         * Notifies all observers in the list observers.
         * @param pos: The position of the observable.
         * @param s: Gives how the score should be updated.
         */
        void notifyObservers(std::tuple<float, float> pos, scoreUpdate s);

        /**
         * Default constructor.
         */
        Observable() = default;
};
} // namespace DoodleJump
#endif // DOODLEJUMP_OBSERVABLE_H
