//
// Created by khalil on 1/2/22.
//

#ifndef DOODLEJUMP_TEMPORARYPLATFORM_H
#define DOODLEJUMP_TEMPORARYPLATFORM_H
#include "platform.h"
namespace DoodleJump {
class TemporaryPlatform : public Platform
{
private:
        bool temporaryjumped = false;

public:
        /**
         * Getter for temporaryjumped boolean.
         * @return temporaryjumped
         */
        bool temporaryJumped() const override;

        /**
         * Explicit constructor
         * @param pos: The initial position of the Temporary Platform
         */
        explicit TemporaryPlatform(std::tuple<float, float> pos);

        /**
         * Updates the Temporary Platform.
         * @param c: Instruction that the temporary platform needs to carry out.
         * @param speed: The speed the temporary platform should move.
         */
        void update(INSTRUCTION c, float speed) override;

        /**
         * Setter for tempraryjumped.
         * @param b: Set temporaryjumped to b.
         */
        void settemporaryJumped(bool b) override;
};
} // namespace DoodleJump
#endif // DOODLEJUMP_TEMPORARYPLATFORM_H
