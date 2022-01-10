//
// Created by khalil on 12/19/21.
//

#ifndef DOODLEJUMP_PLATFORM_H
#define DOODLEJUMP_PLATFORM_H
#include "../entity.h"
#include "../bonus/bonus.h"
#include <iostream>
#include <memory>
namespace DoodleJump{
    class Platform: public Entity{
    private:
        std::shared_ptr<DoodleJump::Bonus> bonus = nullptr;
        bool jumped = false;
        int jumpcounter = 0;
    public:
        void addjump();
        int getJumpcounter() const;

        void setJumped(bool jumped);

        bool isJumped() const;

        const std::shared_ptr<DoodleJump::Bonus> &getBonus() const;

        void setBonus(const std::shared_ptr<DoodleJump::Bonus> &b);

        void updateBonus(COMMAND c);

        /*
         * Constructor with the same inputs as the Entity class
         */
        explicit Platform(std::tuple<float, float> pos);

        virtual bool temporaryJumped() const {return false;};

        virtual void settemporaryJumped(bool b){};

        virtual bool isHorizontal(){return false;};

        virtual bool isVertical(){return false;};

        virtual float getMaxHeight(){return 0;};

        bool hasBonus();

    };
}
#endif //DOODLEJUMP_PLATFORM_H
