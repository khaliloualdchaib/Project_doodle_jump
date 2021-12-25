//
// Created by khalil on 12/7/21.
//

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H
#include "camera.h"
#include <memory>
#include <set>
#include <iostream>
#include "entity.h"
#include "player.h"
#include "platforms/platform.h"
#include <math.h>
namespace DoodleJump{
    class World{
    private:
        std::shared_ptr<DoodleJump::Player> player;
        std::set<std::shared_ptr<Platform>> platforms;
    public:

        /*
         * Getter for the set of platforms
         */
        const std::set<std::shared_ptr<Platform>> &getPlatforms() const;

        /*
         * Getter for the player
         */
        std::shared_ptr<DoodleJump::Player> getPlayer() const;

        /*
         * Setter for the player
         */
        void setPlayer(std::shared_ptr<DoodleJump::Player> p);

        /*
         * Adds a platform to the set of platforms
         */
        void addPlatform(const std::shared_ptr<Platform>& p);

        /*
         * Default constructor
         */
        World() = default;

        /*
         * Returns the positions of the bottom corners of the given entity
         */
        std::tuple<std::tuple<float, float>, std::tuple<float, float>> getBottomCorners(DoodleJump::Entity entity) const;

        /*
         * Returns the positions of the top corners of the given entity
         */
        std::tuple<std::tuple<float, float>, std::tuple<float, float>> getTopCorners(DoodleJump::Entity entity) const;

        /*
         * checks for collision between player and platform
         */
        void collisionPlayerPlatform();

    };
}
#endif //DOODLEJUMP_WORLD_H
