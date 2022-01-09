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
#include "bg_tile.h"
#include "platforms/platform.h"
#include "bonus/bonus.h"
#include "abstractFactory.h"
#include "score.h"
#include <map>
#include <string>

namespace DoodleJump{
    class World{
    private:
        std::shared_ptr<DoodleJump::Player> player;
        std::set<std::shared_ptr<Platform>> platforms;
        std::set<std::shared_ptr<Bonus>> bonusList;
        std::shared_ptr<DoodleJump::AbstractFactory> factory;
        std::map<std::string, float> GameConfigurations;
        std::shared_ptr<Observer> staticplatformObserver;
        std::shared_ptr<Observer> temporaryplatformObserver;
        std::shared_ptr<Observer> horizontalplatformObserver;
        std::shared_ptr<Observer> verticalplatformObserver;
        std::shared_ptr<Observer> springObserver;
        std::shared_ptr<Observer> jetpackObserver;
        std::shared_ptr<Observer> bgTileObserver;
        std::shared_ptr<bg_Tile> tiles[2];
        std::shared_ptr<Score> score = std::make_shared<Score>();
        unsigned int easy = 12;
        unsigned int medium = 9;
        unsigned int hard = 6;
        unsigned int currentlvl = 0;
    public:

        void updateTiles();

        /*
         * rounds a float 2 decimals
         * got the function from the following site:
         * https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/
         */
        inline float round_float2decimals(float f);

        /*
         * Getter for the set of platforms
         */
        const std::set<std::shared_ptr<Platform>> &getPlatforms() const;

        /*
         * Getter for the player
         */
        std::shared_ptr<DoodleJump::Player> getPlayer() const;

        /*
         * Generates random amount of platforms for the begin state of the game.
         */
        void generate_initPlatforms();

        void generatePlatform(unsigned int probStatic, unsigned int probTemporary, unsigned int probHorizontal, unsigned int probVertical, unsigned int difficulty);

        void generatestaticPlatform(unsigned int difficulty, std::tuple<float, float> pos);

        void generatetemporaryPlatform(unsigned int difficulty, std::tuple<float, float> pos);

        void generatehorizontalPlatform(unsigned int difficulty, std::tuple<float, float> pos);

        void generateVerticalPlatform(unsigned int difficulty, std::tuple<float, float> pos);

        /*
         *  returns true if all the logic platform rules are followed.
         */
        bool doPlatformsCollide(const std::shared_ptr<DoodleJump::Platform>& p);

        bool arePlatforms2close(const std::shared_ptr<DoodleJump::Platform>& p);

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

        void updateWorldCamera();

        float heighestPlatform_Ypos();

        void generatespring(const std::shared_ptr<DoodleJump::Platform>& platform);

        void generatejetpack(const std::shared_ptr<DoodleJump::Platform>& platform);

        void generateBonus(const std::shared_ptr<DoodleJump::Platform>& platform, unsigned int none, unsigned int springprob, unsigned int jetpackprob);

        std::string returnScore();
    };
}
#endif //DOODLEJUMP_WORLD_H
