//
// Created by khalil on 12/8/21.
//
#include "../../include/observer_pattern/observable.h"

void DoodleJump::Observable::addObserver(const std::shared_ptr<Observer>& observer) {
    Observable::observers.push_back(observer);
}

void DoodleJump::Observable::removeObserver(int index) {
    Observable::observers.erase(Observable::observers.begin()+index);
}

void DoodleJump::Observable::notifyObservers() {
    for (unsigned int i = 0; i < Observable::observers.size(); ++i) {
        Observable::observers[i]->HandleEvent();
    }
}
