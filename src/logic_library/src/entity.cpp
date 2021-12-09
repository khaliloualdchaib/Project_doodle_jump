//
// Created by khalil on 12/7/21.
//
#include "../include/entity.h"
#include <tuple>

const std::tuple<double, double> &DoodleJump::Entity::getPosition() const {
    return position;
}

void DoodleJump::Entity::setPosition(const tuple<double, double> &position) {
    Entity::position = position;
}

DoodleJump::Entity::Entity(double width, double height) {
    Entity::width = width;
    Entity::height = height;
}

DoodleJump::Entity::Entity(tuple<double, double> pos) {
    Entity::position = pos;
}

DoodleJump::Entity::Entity(double width, double height, tuple<double, double> pos) {
    Entity::position = pos;
    Entity::width = width;
    Entity::height = height;
}

double DoodleJump::Entity::getWidth() const {
    return width;
}

void DoodleJump::Entity::setWidth(double width) {
    Entity::width = width;
}

double DoodleJump::Entity::getHeight() const {
    return height;
}

void DoodleJump::Entity::setHeight(double height) {
    Entity::height = height;
}

