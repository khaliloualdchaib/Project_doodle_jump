//
// Created by khalil on 1/5/22.
//

#ifndef DOODLEJUMP_BONUS_H
#define DOODLEJUMP_BONUS_H
#include "../entity.h"
#include "../player.h"
namespace DoodleJump {
class Bonus : public Entity
{
public:
        /**
         * Constructor
         * @param width: Width of the bonus.
         * @param height: Height of the bonus.
         * @param pos: Initial position of the bonus.
         */
        Bonus(float width, float height, const std::tuple<float, float>& pos);

        /**
         * @return true if the bonus is a jetpack, false if not.
         */
        virtual bool isJetpack() { return false; };

        /**
         * @return true if the bonus is a spring, false if not.
         */
        virtual bool isSpring() { return false; };

        /**
         * Checks for collision between the bonus and the player.
         */
        void checkCollision(const std::shared_ptr<Player>& player);
};
} // namespace DoodleJump
#endif // DOODLEJUMP_BONUS_H
