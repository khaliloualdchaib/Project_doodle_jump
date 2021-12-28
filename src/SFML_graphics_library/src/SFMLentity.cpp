//
// Created by khalil on 12/16/21.
//

#include "../include/SFMLentity.h"

#include <utility>

const std::tuple<float, float> &SFMLDoodleJump::SFMLEntity::getPosition() const {
    return position;
}

void SFMLDoodleJump::SFMLEntity::setPosition(const std::tuple<float, float> &pos) {
    SFMLEntity::position = pos;
}


SFMLDoodleJump::SFMLEntity::SFMLEntity(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w) {
    SFMLEntity::position = pos;
    SFMLEntity::window = std::move(w);
    SFMLEntity::camera = std::make_shared<DoodleJump::Camera>(DoodleJump::Camera(window->getSize().x, window->getSize().y));
    SFMLEntity::width = camera->TransformWidth(width);
    SFMLEntity::height = camera->TransformHeight(height);
}

float SFMLDoodleJump::SFMLEntity::getWidth() const {
    return width;
}

float SFMLDoodleJump::SFMLEntity::getHeight() const {
    return height;
}

const std::shared_ptr<sf::RenderWindow> &SFMLDoodleJump::SFMLEntity::getWindow() const {
    return window;
}

const std::shared_ptr<DoodleJump::Camera> &SFMLDoodleJump::SFMLEntity::getCamera() const {
    return camera;
}





