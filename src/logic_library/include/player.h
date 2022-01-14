//
// Created by khalil on 12/16/21.
//

#ifndef DOODLEJUMP_PLAYER_H
#define DOODLEJUMP_PLAYER_H
#include "entity.h"
namespace DoodleJump{
    class Player: public Entity{
    private:
        bool Jumping = false; //checks if the player is middle in a jump
        bool Falling = false; //checks if the player is falling
        bool collisionPlatform = false;
        bool collisionSpring = false;
        bool highspeed = false;
        bool collisionJetpack = false;
        float accelerationX = 0.07;
        float accelerationY = 0.001;
        float initial_velocity = 0.03;
        float velocity = 2*initial_velocity;
    public:

        /**
         * Setter for collisionJetpack
         * @param c: Set collisionJetpack to c
         */
        void setCollisionJetpack(bool c);

        /**
         * Getter for highspeed.
         * @return highspeed
         */
        bool isHighspeed() const;

        /**
         * Setter for collisionSpring.
         * @param c: Set collisionSpring to c.
         */
        void setCollisionSpring(bool c);

        /**
         * Getter for initial_velocity.
         * @return initial_velocity
         */
        float getInitialVelocity() const;


        /**
         * Getter for velocity.
         * @return velocity
         */
        float getVelocity() const;

        /**
         * Getter for Falling
         * @return Falling
         */
        bool isFalling() const;

        /**
         * Setter for collisionPlatform.
         * @param c: Set collisionPlatform to c.
         */
        void setCollisionPlatform(bool c);

        /**
         * Constructor
         * @param pos: Initial position of the player.
         */
        explicit Player(std::tuple<float, float> pos);

        /**
         * Updates the jetpack.
         * @param c: Instruction that the player needs to carry out.
         * @param speed: This input does not affect player.
         */
        void update(INSTRUCTION c, float speed) override;

    };
}
#endif //DOODLEJUMP_PLAYER_H
