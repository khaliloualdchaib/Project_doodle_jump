//
// Created by khalil on 1/2/22.
//

#ifndef DOODLEJUMP_TEMPORARYPLATFORM_H
#define DOODLEJUMP_TEMPORARYPLATFORM_H
#include "platform.h"
namespace DoodleJump{
    class temporaryPlatform: public Platform{
    private:
        bool temporaryjumped = false;
    public:
        bool temporaryJumped() const override;
        explicit temporaryPlatform(std::tuple<float, float> pos);
        void update(COMMAND=NONE) override;
        void  settemporaryJumped(bool b) override;
    };
}
#endif //DOODLEJUMP_TEMPORARYPLATFORM_H
