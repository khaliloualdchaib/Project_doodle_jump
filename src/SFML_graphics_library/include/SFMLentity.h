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

        /**
         * Getter for camera.
         * @return camera
         */
        const std::shared_ptr<DoodleJump::Camera> &getCamera() const;

        /**
         * Getter for window.
         * @return window
         */
        const std::shared_ptr<sf::RenderWindow> &getWindow() const;

        /**
         * Getter for height.
         * @return height
         */
        float getHeight() const;

        /**
         * Default destructor.
         */
        ~SFMLEntity() = default;

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
         * @param w: The window where the entity will be generated.
         */
        SFMLEntity(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w);

        /**
         * Setter for position.
         * @param pos: Set position to pos.
         */
        void setPosition(const std::tuple<float, float> &pos);

        /**
         * Getter for position.
         * @return position
         */
        const std::tuple<float, float> &getPosition() const;

    };
}

#endif //DOODLEJUMP_SFMLENTITY_H
