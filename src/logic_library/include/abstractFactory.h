//
// Created by khalil on 12/9/21.
//

#ifndef DOODLEJUMP_ABSTRACTFACTORY_H
#define DOODLEJUMP_ABSTRACTFACTORY_H
#include <iostream>
#include "player.h"
#include <memory>
#include <set>

namespace SFMLDoodleJump{
    class SFMLPlayer;
    class SFMLPlatform;
}

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
        virtual std::shared_ptr<SFMLDoodleJump::SFMLPlayer> createPlayer(std::shared_ptr<DoodleJump::Player> p) = 0;

        //virtual std::set<std::shared_ptr<SFMLDoodleJump::SFMLPlatform>> createPlatforms(){};

    };
}
#endif //DOODLEJUMP_ABSTRACTFACTORY_H
