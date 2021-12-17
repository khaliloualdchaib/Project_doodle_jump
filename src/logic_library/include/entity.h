//
// Created by khalil on 12/16/21.
//

#ifndef DOODLEJUMP_ENTITY_H
#define DOODLEJUMP_ENTITY_H
#include <tuple>

using namespace std;

namespace DoodleJump{
    class Entity{
    private:
        tuple<double, double> position = make_tuple(0.0, 0.0);
        unsigned int width = 50; //width of the entity
        unsigned int height = 50; //height of the entity
    public:

        /*
         * setHeight is a setter for the height of the entity.
         * The input is the new height
         */
        void setHeight(unsigned int h);

        /*
         * getHeight is a getter for the height of the entity.
         */
        unsigned int getHeight() const;

        /*
         * setWidth is a setter for the width of the entity.
         * The input is the new width.
         */
        void setWidth(unsigned int w);

        /*
         * update is a function that updates the entity.
         */
        virtual void update(){};

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
        double getWidth() const;

        /*
         * This is a default constructor.
         */
        Entity() = default;

        /*
         * This is a constructor.
         * The inputs are the width, height and position of the entity.
         */
        Entity(unsigned int width, unsigned int height, tuple<double, double> pos);

        /*
         * This is a constructor.
         * The inputs are the width and height of the entity.
         */
        Entity(unsigned int width, unsigned int height);

        /*
         * This is a constructor.
         * The input is the position of the entity.
         */
        Entity(tuple<double, double> pos);

        /*
         * setPosition is a setter for the position of the entity.
         * The input is tuple that is the new position.
         */
        void setPosition(const tuple<double, double> &pos);

        /*
         * getPosition is a getter for the position of the entity.
         */
        const tuple<double, double> &getPosition() const;

    };
}
#endif //DOODLEJUMP_ENTITY_H
