//
// Created by khalil on 12/19/21.
//

#ifndef DOODLEJUMP_PLATFORM_H
#define DOODLEJUMP_PLATFORM_H
#include "../bonus/bonus.h"
#include "../entity.h"
#include <iostream>
#include <memory>
namespace DoodleJump {
class Platform : public Entity
{
private:
        std::shared_ptr<DoodleJump::Bonus> bonus = nullptr;
        bool jumped = false;
        int jumpcounter = 0;

public:
        /**
         * Adds 1 to the jumpcounter.
         */
        void addjump();

        /**
         * Getter for jumpcounter.
         * @return jumpcounter
         */
        int getJumpcounter() const;

        /**
         * Setter for jumped.
         * @param jumped: set the member jumped to this value.
         */
        void setJumped(bool jumped);

        /**
         * Getter for jumped.
         * @return jumped;
         */
        bool isJumped() const;

        /**
         * Getter for bonus.
         * @return bonus
         */
        const std::shared_ptr<DoodleJump::Bonus>& getBonus() const;

        /**
         * Setter for bonus.
         * @param b: The bonus that will be on the platform.
         */
        void setBonus(const std::shared_ptr<DoodleJump::Bonus>& b);

        /**
         * Updates the bonus on the platform.
         */
        void updateBonus();

        /**
         * Explicit constructor
         * @param pos: Initial Position of the platform.
         */
        explicit Platform(std::tuple<float, float> pos);

        /**
         * @return true if the temporary platform has been jumped on, or else it returns false.
         */
        virtual bool temporaryJumped() const { return false; };

        /**
         * Setter for boolean in temporary platform class
         * @param b: Set temporyjumped to b.
         */
        virtual void settemporaryJumped(bool b){};

        /**
         * @return true if the platform is a horizontal platform, or else return false.
         */
        virtual bool isHorizontal() { return false; };

        /**
         * @return true if the platform is a vertical platform, or else return false.
         */
        virtual bool isVertical() { return false; };

        /**
         * Getter for the MaxHeight value in the vertical platform class
         * @return 0 if the platform is not a vertical platform, or else the maxheight.
         */
        virtual float getMaxHeight() { return 0; };

        /**
         * @return true if there is a bonus on the platform, or else false.
         */
        bool hasBonus();
};
} // namespace DoodleJump
#endif // DOODLEJUMP_PLATFORM_H
