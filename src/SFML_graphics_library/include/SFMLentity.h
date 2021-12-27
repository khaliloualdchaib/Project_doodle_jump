//
// Created by khalil on 12/16/21.
//

#ifndef DOODLEJUMP_SFMLENTITY_H
#define DOODLEJUMP_SFMLENTITY_H

#include <iostream>
#include <tuple>
#include "../../logic_library/include/observer_pattern/observer.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include "../../logic_library/include/camera.h"

namespace SFMLDoodleJump{
    class SFMLEntity: public DoodleJump::Observer{
    private:
        std::tuple<float, float> position = std::make_tuple(0.0, 0.0);
        float width; //width of the entity
        float height; //height of the entity
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<DoodleJump::Camera> camera;
    public:

        /*
         * This is a getter for the Camera
         */
        const std::shared_ptr<DoodleJump::Camera> &getCamera() const;

        /*
         * This is a getter for the window
         */
        const std::shared_ptr<sf::RenderWindow> &getWindow() const;

        /*
         * setHeight is a setter for the height of the entity.
         * The input is the new height
         */
        void setHeight(float h);

        /*
         * getHeight is a getter for the height of the entity.
         */
        float getHeight() const;

        /*
         * setWidth is a setter for the width of the entity.
         * The input is the new width.
         */
        void setWidth(float w);

        /*
         * update is a function that updates the entity.
         */
        virtual void update(){};

        /*
         * ~SFMLEntity is a default destructor.
         */
        virtual ~SFMLEntity() = default;

        /*
         * This is a default copy constructor.
         * The input is the entity that will be copied.
         */
        SFMLEntity(const SFMLEntity& entity) = default;

        /*
         * getWidth is a getter for the width of the entity.
         */
        float getWidth() const;

        /*
         * This is a constructor.
         * The inputs are the width, height and position of the entity.
         * It also has a window input
         */
        SFMLEntity(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w);

        /*
         * setPosition is a setter for the position of the entity.
         * The input is a tuple that is the new position.
         */
        void setPosition(const std::tuple<float, float> &pos);

        /*
         * getPosition is a getter for the position of the entity.
         */
        const std::tuple<float, float> &getPosition() const;

        /*
         * virtual draw function that draws the entity on the window.
         */
        virtual void draw(std::tuple<float, float> pos = std::make_tuple(1000, 1000)) = 0;

    };
}

#endif //DOODLEJUMP_SFMLENTITY_H
