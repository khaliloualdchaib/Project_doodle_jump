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
#include "abstractFactory.h"
#include <map>

namespace DoodleJump{
    class World{
    private:
        std::shared_ptr<DoodleJump::Player> player;
        std::set<std::shared_ptr<Platform>> platforms;
        std::shared_ptr<DoodleJump::AbstractFactory> factory;
        std::map<std::string, float> GameConfigurations;
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
         * Generates the player
         */
        void generatePlayer();

        /*
         * Generates given amount of platforms
         */
        void generatePlatforms(unsigned int amount);

        /*
         * Constructor
         */
        World(std::shared_ptr<DoodleJump::AbstractFactory> a, std::map<std::string, float> config);

        /*
         * Returns the positions of the bottom corners of the given entity
         */
        std::tuple<std::tuple<float, float>, std::tuple<float, float>> getBottomCorners(const DoodleJump::Entity& entity) const;

        /*
         * Returns the positions of the top corners of the given entity
         */
        std::tuple<std::tuple<float, float>, std::tuple<float, float>> getTopCorners(const DoodleJump::Entity& entity) const;

        /*
         * checks for collision between player and platform
         */
        void collisionPlayerPlatform();

    };
}
#endif //DOODLEJUMP_WORLD_H
