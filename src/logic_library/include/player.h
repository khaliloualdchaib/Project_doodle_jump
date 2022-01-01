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
        float accelerationX = 0.07;
        float accelerationY = 0.001;
        float initial_velocity = 0.03;
    public:
        float getInitialVelocity() const;

    private:
        float velocity = 2*initial_velocity;
    public:
        float getVelocity() const;

    public:

        /*
         * Getter for the Falling boolean.
         */
        bool isFalling() const;

        /*
         * Setter for the collision bool
         */
        void setCollisionPlatform(bool c);

        /*
         * Constructor
         * It has the following inputs:
         * width, height and pos
         */
        Player(float width, float height, std::tuple<float, float> pos);

        /*
         * Updates the player
         */
        void update(COMMAND=NONE) override;

    };
}
#endif //DOODLEJUMP_PLAYER_H
