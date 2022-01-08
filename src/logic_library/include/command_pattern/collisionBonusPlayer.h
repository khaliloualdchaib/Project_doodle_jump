//
// Created by khalil on 1/7/22.
//

#ifndef DOODLEJUMP_COLLISIONBONUSPLAYER_H
#define DOODLEJUMP_COLLISIONBONUSPLAYER_H
#include "command.h"
#include "../player.h"
#include "../bonus/bonus.h"

namespace DoodleJump{
    class CollisionBonusPlayer: public Command{
        std::shared_ptr<DoodleJump::Player> player;
        std::shared_ptr<DoodleJump::Bonus> bonus;
    public:
        void execute() override;
        CollisionBonusPlayer(std::shared_ptr<DoodleJump::Player>  p, std::shared_ptr<DoodleJump::Bonus>  b);
    };
}
#endif //DOODLEJUMP_COLLISIONBONUSPLAYER_H
