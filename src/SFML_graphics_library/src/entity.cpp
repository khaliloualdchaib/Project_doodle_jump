//
// Created by khalil on 12/13/21.
//

//
// Created by khalil on 12/7/21.
//
#include "../include/entity.h"

#include <utility>

const std::tuple<float, float> &SFMLDoodleJump::Entity::getPosition() const {
    return position;
}

void SFMLDoodleJump::Entity::setPosition(const std::tuple<float, float> &pos) {
    Entity::position = pos;
}


SFMLDoodleJump::Entity::Entity(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w) {
    Entity::position = pos;
    Entity::width = width;
    Entity::height = height;
    Entity::window = std::move(w);
    Entity::camera = std::make_shared<DoodleJump::Camera>(DoodleJump::Camera(window->getSize().x, window->getSize().y));
}

float SFMLDoodleJump::Entity::getWidth() const {
    return width;
}

void SFMLDoodleJump::Entity::setWidth(float w) {
    Entity::width = w;
}

float SFMLDoodleJump::Entity::getHeight() const {
    return height;
}

void SFMLDoodleJump::Entity::setHeight(float h) {
    Entity::height = h;
}

const std::shared_ptr<sf::RenderWindow> &SFMLDoodleJump::Entity::getWindow() const {
    return window;
}

const std::shared_ptr<DoodleJump::Camera> &SFMLDoodleJump::Entity::getCamera() const {
    return camera;
}

