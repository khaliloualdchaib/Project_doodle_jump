//
// Created by khalil on 12/16/21.
//

#ifndef DOODLEJUMP_PLAYER_H
#define DOODLEJUMP_PLAYER_H
#include "entity.h"
namespace DoodleJump{
    class Player: public Entity{
    private:
        float jumpspeed = 0.03f;
        bool isJumping = false; //checks if the player is middle in a jump
        bool Falling = false; //checks if the player is falling
        bool collisionPlatform = false;
        float maxheight = 0; //this is the y coordinate of the max height of the jump
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
         * Moves the player up.
         */
        void jump();

    };
}
#endif //DOODLEJUMP_PLAYER_H
