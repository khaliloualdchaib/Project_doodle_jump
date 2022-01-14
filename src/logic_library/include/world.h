//
// Created by khalil on 12/7/21.
//

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H
#include "abstractFactory.h"
#include "bg_tile.h"
#include "bonus/bonus.h"
#include "camera.h"
#include "entity.h"
#include "platforms/platform.h"
#include "player.h"
#include "random.h"
#include "score.h"
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>

namespace DoodleJump {
class World
{
private:
        std::shared_ptr<DoodleJump::Player> player;
        std::set<std::shared_ptr<Platform>> platforms;
        std::shared_ptr<DoodleJump::AbstractFactory> factory;
        std::shared_ptr<Observer> staticplatformObserver;
        std::shared_ptr<Observer> temporaryplatformObserver;
        std::shared_ptr<Observer> horizontalplatformObserver;
        std::shared_ptr<Observer> verticalplatformObserver;
        std::shared_ptr<Observer> springObserver;
        std::shared_ptr<Observer> jetpackObserver;
        std::shared_ptr<Observer> bgTileObserver;
        std::shared_ptr<bg_Tile> tiles[2];
        std::shared_ptr<Score> score = std::make_shared<Score>();
        const unsigned int easy = 12;
        const unsigned int medium = 9;
        const unsigned int hard = 6;
        const unsigned int begintypes = floor(DoodleJump::Random::getInstance().getrandomDouble(1000, 2500));
        const unsigned int middletypes = floor(DoodleJump::Random::getInstance().getrandomDouble(2500, 4000));
        const unsigned int endtypes = floor(DoodleJump::Random::getInstance().getrandomDouble(4000, 5000));
        unsigned int currentlvl = 0;

public:
        /**
         * Update the bg tiles
         */
        void updateTiles();

        /**
         * @param f: a float number
         * @return The given float but rounded to 2 decimals.
         */
        inline float round_float2decimals(float f);

        /**
         * Getter for player
         * @return player
         */
        std::shared_ptr<DoodleJump::Player> getPlayer() const;

        /**
         * Generates random amount of platforms between 9 and 12 for the begin state of the game.
         */
        void generate_initPlatforms();

        /**
         * Generate a random platform.
         * @param probStatic: Probability of generating a static platform.
         * @param probTemporary: Probability of generating a temporary platform.
         * @param probHorizontal: Probability of generating a horizontal platform.
         * @param probVertical: Probability of generating a vertical platform.
         * @param difficulty: max number of platforms that are allowed.
         */
        void generatePlatform(unsigned int probStatic, unsigned int probTemporary, unsigned int probHorizontal,
                              unsigned int probVertical, unsigned int difficulty);

        /**
         * Generate static platform.
         * @param difficulty: max number of platforms that are allowed.
         * @param pos: Position for the static platform.
         */
        void generatestaticPlatform(unsigned int difficulty, std::tuple<float, float> pos);

        /**
         * Generate temporary platform.
         * @param difficulty: max number of platforms that are allowed.
         * @param pos: Position for the temporary platform.
         */
        void generatetemporaryPlatform(unsigned int difficulty, std::tuple<float, float> pos);

        /**
         * Generate horizontal platform.
         * @param difficulty: max number of platforms that are allowed.
         * @param pos: Position for the horizontal platform.
         */
        void generatehorizontalPlatform(unsigned int difficulty, std::tuple<float, float> pos);

        /**
         * Generate vertical platform.
         * @param difficulty: max number of platforms that are allowed.
         * @param pos: Position for the vertical platform.
         */
        void generateVerticalPlatform(unsigned int difficulty, std::tuple<float, float> pos);

        /**
         *  @return true if all the logic platform rules are followed, or else false.
         */
        bool doPlatformsCollide(const std::shared_ptr<DoodleJump::Platform>& p);

        /**
         * @return true if platforms are to close, or else false.
         */
        bool arePlatforms2close(const std::shared_ptr<DoodleJump::Platform>& p);

        /**
         * Constructor
         * @param a: Abstract factory class.
         */
        World(std::shared_ptr<DoodleJump::AbstractFactory> a);

        /**
         * @param entity: An entity class
         * @return The positions of the bottom corners of the given entity
         */
        std::tuple<std::tuple<float, float>, std::tuple<float, float>> getBottomCorners(
            const DoodleJump::Entity& entity) const;

        /**
         * @param entity: An entity class
         * @return The positions of the top corners of the given entity
         */
        std::tuple<std::tuple<float, float>, std::tuple<float, float>> getTopCorners(
            const DoodleJump::Entity& entity) const;

        /**
         * checks for collision between player and platform
         */
        void collisionPlayerPlatform();

        /**
         * Update the camera of the world.
         */
        void updateWorldCamera();

        /**
         * @return The Y coordinate of the highest platform.
         */
        float heighestPlatform_Ypos();

        /**
         * Generate a spring.
         * @param platform: The platform on which the spring wil be generated.
         */
        void generatespring(const std::shared_ptr<DoodleJump::Platform>& platform);

        /**
         * Generate a jetpack.
         * @param platform: The platform on which the jetpack wil be generated.
         */
        void generatejetpack(const std::shared_ptr<DoodleJump::Platform>& platform);

        /**
         * Generate a random bonus.
         * @param none: The probability that nothing will be generated.
         * @param springprob: The probability that a spring will be generated.
         * @param jetpackprob: The probability that a jetpack will be generated.
         * @param platform: The platform on which the bonus wil be generated.
         */
        void generateBonus(const std::shared_ptr<DoodleJump::Platform>& platform, unsigned int none,
                           unsigned int springprob, unsigned int jetpackprob);

        /**
         * @return A string that "SCORE: " + score.
         */
        std::string returnScore();

        /**
         * @return A string that will be displayed when the player dies.
         */
        std::string Game_Over_Message();

        /**
         * Updates the platforms and runs the collision checks.
         */
        void runGameLogic();
};
} // namespace DoodleJump
#endif // DOODLEJUMP_WORLD_H
