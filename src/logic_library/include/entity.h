//
// Created by khalil on 12/16/21.
//

#ifndef DOODLEJUMP_ENTITY_H
#define DOODLEJUMP_ENTITY_H
#include "camera.h"
#include "observer_pattern/observable.h"
#include <set>
#include <tuple>
enum INSTRUCTION
{
        LEFT,
        RIGHT,
        NONE
};

namespace DoodleJump {
class Entity : public Observable
{
private:
        std::tuple<float, float> position = std::make_tuple(0.0, 0.0);
        float width;  // width of the entity
        float height; // height of the entity
public:
        /**
         * Getter for height.
         * @return height
         */
        float getHeight() const;

        /**
         * Updates the entity.
         * @param c: Instruction that the horizontal platform needs to carry out.
         * @param speed: The speed the horizontal platform should move.
         */
        virtual void update(INSTRUCTION c, float speed){};

        /**
         * Default destructor.
         */
        ~Entity() = default;

        /**
         * Getter for width.
         * @return width
         */
        float getWidth() const;

        /**
         * Constructor
         * @param width: Width of the entity.
         * @param height: Height of the entity.
         * @param pos: Initial position of the entity.
         */
        Entity(float width, float height, std::tuple<float, float> pos);

        /**
         * Setter for position.
         * @param pos: Set the position to pos.
         */
        void setPosition(const std::tuple<float, float>& pos);

        /**
         * Getter for position
         * @return position
         */
        const std::tuple<float, float>& getPosition() const;
};
} // namespace DoodleJump
#endif // DOODLEJUMP_ENTITY_H
