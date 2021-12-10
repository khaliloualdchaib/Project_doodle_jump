//
// Created by khalil on 12/7/21.
//
#include "../include/entity.h"
#include <tuple>

const std::tuple<double, double> &DoodleJump::Entity::getPosition() const {
    return position;
}

void DoodleJump::Entity::setPosition(const tuple<double, double> &pos) {
    Entity::position = pos;
}

DoodleJump::Entity::Entity(unsigned int width, unsigned int height) {
    Entity::width = width;
    Entity::height = height;
}

DoodleJump::Entity::Entity(tuple<double, double> pos) {
    Entity::position = pos;
}

DoodleJump::Entity::Entity(unsigned int width, unsigned int height, tuple<double, double> pos) {
    Entity::position = pos;
    Entity::width = width;
    Entity::height = height;
}

double DoodleJump::Entity::getWidth() const {
    return width;
}

void DoodleJump::Entity::setWidth(unsigned int w) {
    Entity::width = w;
}

unsigned int DoodleJump::Entity::getHeight() const {
    return height;
}

void DoodleJump::Entity::setHeight(unsigned int h) {
    Entity::height = h;
}

