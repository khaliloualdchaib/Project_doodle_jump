//
// Created by khalil on 12/16/21.
//

#ifndef DOODLEJUMP_ENTITY_H
#define DOODLEJUMP_ENTITY_H
#include <tuple>
#include "observer_pattern/observable.h"
#include <set>
#include "camera.h"

enum COMMAND{LEFT, RIGHT, UP, DOWN, NONE};

namespace DoodleJump{
    class Entity: public Observable{
    private:
        std::tuple<float, float> position = std::make_tuple(0.0, 0.0);
        float width; //width of the entity
        float height; //height of the entity
    public:

        /*
         * getHeight is a getter for the height of the entity.
         */
        float getHeight() const;

        /*
         * update is a function that updates the entity.
         */
        virtual void update(COMMAND c){};

        /*
         * ~Entity is a default destructor.
         */
        virtual ~Entity() = default;

        /*
         * This is a default copy constructor.
         * The input is the entity that will be copied.
         */
        Entity(const Entity& entity) = default;

        /*
         * getWidth is a getter for the width of the entity.
         */
        float getWidth() const;

        /*
         * This is a constructor.
         * The inputs are the width, height and position of the entity.
         */
        Entity(float width, float height, std::tuple<float, float> pos);

        /*
         * setPosition is a setter for the position of the entity.
         * The input is tuple that is the new position.
         */
        void setPosition(const std::tuple<float, float> &pos);

        /*
         * getPosition is a getter for the position of the entity.
         */
        const std::tuple<float, float> &getPosition() const;

    };
}
#endif //DOODLEJUMP_ENTITY_H
