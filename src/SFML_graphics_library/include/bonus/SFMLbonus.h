//
// Created by khalil on 1/6/22.
//

#ifndef DOODLEJUMP_SFMLBONUS_H
#define DOODLEJUMP_SFMLBONUS_H
#include "../SFMLentity.h"

namespace SFMLDoodleJump {
class SFMLBonus : public SFMLEntity
{
private:
        sf::Sprite sprite;

public:
        /**
         * Setter for the sprite.
         * @param s: Set sprite to s.
         */
        void setSprite(const sf::Sprite& s);

        /**
         * Constructor
         * @param width: Width of the bonus.
         * @param height: Height of the bonus.
         * @param pos: Initial position of the bonus.
         * @param w: The window where the bonus will be generated.
         */
        SFMLBonus(float width, float height, const std::tuple<float, float>& pos,
                  const std::shared_ptr<sf::RenderWindow>& w);

        /**
         * Handles the event
         * @param pos: Position of the observer.
         * @param s: Gives how the score should be updated.
         */
        void HandleEvent(std::tuple<float, float> nextpos, scoreUpdate s) override;
};
} // namespace SFMLDoodleJump
#endif // DOODLEJUMP_SFMLBONUS_H
