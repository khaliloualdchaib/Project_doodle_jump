//
// Created by khalil on 12/9/21.
//

#ifndef DOODLEJUMP_ABSTRACTFACTORY_H
#define DOODLEJUMP_ABSTRACTFACTORY_H
#include <iostream>
#include "player.h"
#include "platforms/staticPlatform.h"
#include <memory>
#include <set>
#include "observer_pattern/observer.h"

namespace DoodleJump{
    class AbstractFactory{
    public:

        /*
         * This is a default constructor.
         */
        AbstractFactory() = default;

        /*
         * This is a default destructor
         */
        virtual ~AbstractFactory() = default;

        //The following functions create and return the entities:
        virtual std::shared_ptr<DoodleJump::Observer> createPlayer(std::shared_ptr<DoodleJump::Player> p) = 0;

        virtual std::shared_ptr<DoodleJump::Observer> createStaticPlatform(std::shared_ptr<DoodleJump::staticPlatform> p) = 0;

    };
}
#endif //DOODLEJUMP_ABSTRACTFACTORY_H
