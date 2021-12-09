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
        std::vector<std::shared_ptr<Observer>> observers;
    public:
        void addObserver(const std::shared_ptr<Observer>& observer);
        void removeObserver(int index);
        void notifyObservers();
    };
}
#endif //DOODLEJUMP_OBSERVABLE_H
