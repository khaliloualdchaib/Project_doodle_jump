//
// Created by khalil on 12/10/21.
//
#include "../include/camera.h"

DoodleJump::Camera::Camera(unsigned int width, unsigned int height) {
    Camera::width = width;
    Camera::height = height;
}

std::tuple<float, float> DoodleJump::Camera::Transformation(float xpos, float ypos) const {
    return std::make_tuple(((xpos + 4.0) * (Camera::width/8.0)), ((-ypos + 3.0) * (Camera::height/6.0)));
}

float DoodleJump::Camera::TransformWidth(float w) const {
    return w * float(Camera::width / 8.0);
}

float DoodleJump::Camera::TransformHeight(float h) const {
    return h * float(Camera::height / 6.0);
}