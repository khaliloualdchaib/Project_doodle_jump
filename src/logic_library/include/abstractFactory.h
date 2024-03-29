//
// Created by khalil on 12/9/21.
//

#ifndef DOODLEJUMP_ABSTRACTFACTORY_H
#define DOODLEJUMP_ABSTRACTFACTORY_H
#include "bg_tile.h"
#include "bonus/jetpack.h"
#include "bonus/spring.h"
#include "observer_pattern/observer.h"
#include "platforms/horizontalPlatform.h"
#include "platforms/staticPlatform.h"
#include "platforms/temporaryPlatform.h"
#include "platforms/verticalPlatform.h"
#include "player.h"
#include <iostream>
#include <memory>
#include <set>

namespace DoodleJump {
class AbstractFactory
{
public:
        /**
         * Default constructor.
         */
        AbstractFactory() = default;

        /**
         * Default destructor
         */
        ~AbstractFactory() = default;

        // The following functions create an observer and return it
        virtual std::shared_ptr<DoodleJump::Observer> createPlayer(std::shared_ptr<DoodleJump::Player> p) = 0;

        virtual std::shared_ptr<DoodleJump::Observer> createStaticPlatform(
            std::shared_ptr<DoodleJump::StaticPlatform> p) = 0;

        virtual std::shared_ptr<DoodleJump::Observer> createTemporaryPlatform(
            std::shared_ptr<DoodleJump::TemporaryPlatform> p) = 0;

        virtual std::shared_ptr<DoodleJump::Observer> createHorizontalPlatform(
            std::shared_ptr<DoodleJump::HorizontalPlatform> p) = 0;

        virtual std::shared_ptr<DoodleJump::Observer> createVerticalPlatform(
            std::shared_ptr<DoodleJump::VerticalPlatform> p) = 0;

        virtual std::shared_ptr<DoodleJump::Observer> createbgTile(std::shared_ptr<DoodleJump::bg_Tile> b) = 0;

        virtual std::shared_ptr<DoodleJump::Observer> createSpring(std::shared_ptr<DoodleJump::Spring> s) = 0;

        virtual std::shared_ptr<DoodleJump::Observer> createJetpack(std::shared_ptr<DoodleJump::Jetpack> j) = 0;
};
} // namespace DoodleJump
#endif // DOODLEJUMP_ABSTRACTFACTORY_H
