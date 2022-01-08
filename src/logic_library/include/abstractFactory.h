//
// Created by khalil on 12/9/21.
//

#ifndef DOODLEJUMP_ABSTRACTFACTORY_H
#define DOODLEJUMP_ABSTRACTFACTORY_H
#include <iostream>
#include "player.h"
#include "platforms/staticPlatform.h"
#include "platforms/temporaryPlatform.h"
#include "platforms/horizontalPlatform.h"
#include "platforms/verticalPlatform.h"
#include "bonus/spring.h"
#include "bonus/jetpack.h"
#include "bg_tile.h"
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


        virtual std::shared_ptr<DoodleJump::Observer> createPlayer(std::shared_ptr<DoodleJump::Player> p) = 0;

        virtual std::shared_ptr<DoodleJump::Observer> createStaticPlatform(std::shared_ptr<DoodleJump::StaticPlatform> p) = 0;

        virtual std::shared_ptr<DoodleJump::Observer> createTemporaryPlatform(std::shared_ptr<DoodleJump::TemporaryPlatform> p) = 0;

        virtual std::shared_ptr<DoodleJump::Observer> createHorizontalPlatform(std::shared_ptr<DoodleJump::HorizontalPlatform> p) = 0;

        virtual std::shared_ptr<DoodleJump::Observer> createVerticalPlatform(std::shared_ptr<DoodleJump::VerticalPlatform> p) = 0;

        virtual std::shared_ptr<DoodleJump::Observer> createbgTile(std::shared_ptr<DoodleJump::bg_Tile> b) = 0;

        virtual std::shared_ptr<DoodleJump::Observer> createSpring(std::shared_ptr<DoodleJump::Spring> s) = 0;

        virtual std::shared_ptr<DoodleJump::Observer> createJetpack(std::shared_ptr<DoodleJump::Jetpack> j) = 0;

    };
}
#endif //DOODLEJUMP_ABSTRACTFACTORY_H
