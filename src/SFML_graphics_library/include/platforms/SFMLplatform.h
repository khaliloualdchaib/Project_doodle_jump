//
// Created by khalil on 12/19/21.
//

#ifndef DOODLEJUMP_SFMLPLATFORM_H
#define DOODLEJUMP_SFMLPLATFORM_H
#include "../SFMLentity.h"
namespace SFMLDoodleJump {
class SFMLPlatform : public SFMLEntity
{
private:
        sf::RectangleShape platform;

public:
        /**
         * Getter for platform.
         * @return platform
         */
        sf::RectangleShape& getPlatform();

        /**
         * Constructor
         * @param width: Width of the platform.
         * @param height: Height of the platform.
         * @param pos: Initial position of the platform.
         * @param w: The window where the platform will be generated.
         */
        SFMLPlatform(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w);

        /**
         * Handles the event
         * @param pos: Position of the observer.
         * @param s: Gives how the score should be updated.
         */
        void HandleEvent(std::tuple<float, float> nextpos, scoreUpdate s) override;
};
} // namespace SFMLDoodleJump
#endif // DOODLEJUMP_SFMLPLATFORM_H
