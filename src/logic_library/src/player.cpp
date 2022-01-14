//
// Created by khalil on 12/16/21.
//
#include "../include/player.h"
#include <iostream>

DoodleJump::Player::Player(std::tuple<float, float> pos) : Entity(0.8f, 0.44f, pos) {}

void DoodleJump::Player::update(INSTRUCTION c, float speed)
{
        float X = 0.0f;
        float Y = 0.0f;
        bool jetpack = false;
        bool spring = false;
        if (!Jumping and !Falling) {
                Jumping = true;
        }
        if (Jumping) {
                Y += velocity;
                velocity -= accelerationY;
                if (velocity < 0) {
                        Falling = true;
                        Jumping = false;
                }
        } else {
                if (collisionSpring) {
                        velocity = 5 * initial_velocity;
                        spring = true;
                        Y = velocity;
                        Falling = false;
                        Jumping = true;
                        collisionSpring = false;
                        highspeed = true;

                } else if (collisionJetpack) {
                        velocity = 10 * initial_velocity;
                        Y = velocity;
                        Falling = false;
                        jetpack = true;
                        Jumping = true;
                        collisionJetpack = false;
                        highspeed = true;
                } else if (collisionPlatform) {
                        velocity = 2 * initial_velocity;
                        Y = velocity;
                        Falling = false;
                        Jumping = true;

                } else {
                        highspeed = false;
                        Y += velocity;
                        velocity -= accelerationY;
                }
        }

        if (c == LEFT) {
                X -= accelerationX;
                if (std::get<0>(getPosition()) + getWidth() < -4.f) {
                        setPosition(std::make_tuple(4.f, std::get<1>(getPosition())));
                }
        }
        if (c == RIGHT) {
                X += accelerationX;
                if (std::get<0>(getPosition()) > 4.f) {
                        setPosition(std::make_tuple(-4.f, std::get<1>(getPosition())));
                }
        }
        setPosition(std::make_tuple(std::get<0>(getPosition()) + X, std::get<1>(getPosition()) + Y));

        if (jetpack) {
                notifyObservers(getPosition(), jetpackcol);
        } else if (spring) {
                notifyObservers(getPosition(), springcol);
        } else if (std::get<1>(getPosition()) > 0) {
                notifyObservers(getPosition(), newHeight);
        } else {
                notifyObservers(getPosition(), zero);
        }
}

void DoodleJump::Player::setCollisionPlatform(bool c) { Player::collisionPlatform = c; }

bool DoodleJump::Player::isFalling() const { return Falling; }

float DoodleJump::Player::getVelocity() const { return velocity; }

float DoodleJump::Player::getInitialVelocity() const { return initial_velocity; }

void DoodleJump::Player::setCollisionSpring(bool c) { Player::collisionSpring = c; }

bool DoodleJump::Player::isHighspeed() const { return highspeed; }

void DoodleJump::Player::setCollisionJetpack(bool c) { Player::collisionJetpack = c; }
