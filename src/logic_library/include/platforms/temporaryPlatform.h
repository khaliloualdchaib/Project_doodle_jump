//
// Created by khalil on 1/2/22.
//

#ifndef DOODLEJUMP_TEMPORARYPLATFORM_H
#define DOODLEJUMP_TEMPORARYPLATFORM_H
#include "platform.h"
namespace DoodleJump{
    class TemporaryPlatform: public Platform{
    private:
        bool temporaryjumped = false;
    public:
        bool temporaryJumped() const override;
        explicit TemporaryPlatform(std::tuple<float, float> pos);
        void update(COMMAND c, float speed) override;
        void  settemporaryJumped(bool b) override;
    };
}
#endif //DOODLEJUMP_TEMPORARYPLATFORM_H
