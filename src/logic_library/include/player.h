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
        unsigned int jetpackcounter = 0;
        float accelerationX = 0.07;
        float accelerationY = 0.001;
        float initial_velocity = 0.03;
        float velocity = 2*initial_velocity;
    public:
        void setCollisionJetpack(bool collisionJetpack);

        bool isHighspeed() const;

        void setCollisionSpring(bool c);

        bool isCollisionSpring() const;

        float getInitialVelocity() const;

        float getVelocity() const;

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
        void update(COMMAND c, float speed) override;

    };
}
#endif //DOODLEJUMP_PLAYER_H
