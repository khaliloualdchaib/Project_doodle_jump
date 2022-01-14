//
// Created by khalil on 12/16/21.
//

#include "../include/entity.h"
#include <tuple>

const std::tuple<float, float>& DoodleJump::Entity::getPosition() const { return position; }

void DoodleJump::Entity::setPosition(const std::tuple<float, float>& pos) { Entity::position = pos; }

DoodleJump::Entity::Entity(float width, float height, std::tuple<float, float> pos)
{
        Entity::position = pos;
        Entity::width = width;
        Entity::height = height;
}

float DoodleJump::Entity::getWidth() const { return width; }

float DoodleJump::Entity::getHeight() const { return height; }
