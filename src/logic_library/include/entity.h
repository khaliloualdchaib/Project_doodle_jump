//
// Created by khalil on 12/7/21.
//

#ifndef DOODLEJUMP_ENTITY_H
#define DOODLEJUMP_ENTITY_H
#include <tuple>

using namespace std;

namespace DoodleJump{
    class Entity{
    private:
        tuple<double, double> position = make_tuple(0.0, 0.0);
        double width = 50.0;
        double height = 50.0;
    public:
        void setHeight(double height);
        double getHeight() const;
        void setWidth(double width);
        virtual void update() = 0;
        virtual ~Entity() = default;
        Entity(const Entity& entity) = default; //copy constructor
        double getWidth() const;
        Entity() = default;
        Entity(double width, double height, tuple<double, double> pos);
        Entity(double width, double height);
        Entity(tuple<double, double> pos);
        void setPosition(const tuple<double, double> &position);
        const tuple<double, double> &getPosition() const;

    };
}
#endif //DOODLEJUMP_ENTITY_H
