//
// Created by khalil on 12/7/21.
//

#include "../include/world.h"

#include <utility>

DoodleJump::World::World(std::shared_ptr<DoodleJump::Camera> c) {
    World::camera = std::move(c);
}

std::tuple<std::tuple<float, float>, std::tuple<float, float>>  DoodleJump::World::getBottomCorners(const DoodleJump::Entity entity) const {
    std::tuple<float, float> pixelco = camera->Transformation(std::get<0>(entity.getPosition()),std::get<1>(entity.getPosition()));
    std::tuple<float, float> corner1 = {std::get<0>(pixelco), std::get<1>(pixelco) + entity.getHeight()};
    std::tuple<float, float> corner2 = {std::get<0>(pixelco) + entity.getWidth(), std::get<1>(pixelco) + entity.getHeight()};
    return {corner1, corner2};
}

std::tuple<std::tuple<float, float>, std::tuple<float, float>> DoodleJump::World::getTopCorners(const DoodleJump::Entity entity) const {
    std::tuple<float, float> pixelco = camera->Transformation(std::get<0>(entity.getPosition()),std::get<1>(entity.getPosition()));
    std::tuple<float, float> corner1 = pixelco;
    std::tuple<float, float> corner2 = {std::get<0>(pixelco) + entity.getWidth(), std::get<1>(pixelco)};
    return {corner1, corner2};
}

void DoodleJump::World::collisionPlayerPlatform() {
    std::tuple<std::tuple<float, float>, std::tuple<float, float>> bottomcornersPlayer = getBottomCorners(*player);
    for (auto& platform: platforms) {
        std::tuple<std::tuple<float, float>, std::tuple<float, float>>  topcornersPlatform = getTopCorners(*platform);
        std::tuple<float, float> topleftcorner = std::get<0>(topcornersPlatform);
        std::tuple<float, float> toprightcorner = std::get<1>(topcornersPlatform);
        std::tuple<float, float> bottomleftcorner = std::get<0>(bottomcornersPlayer);
        std::tuple<float, float> bottomrightcorner = std::get<1>(bottomcornersPlayer);
        if (std::get<1>(topleftcorner)== std::get<1>(bottomleftcorner)+2){
            if (std::get<0>(topleftcorner)<=std::get<0>(bottomleftcorner) or std::get<0>(toprightcorner)>=std::get<0>(bottomrightcorner)){
                player->setCollision(true);
            }
        }
    }
}

void DoodleJump::World::setPlayer(std::shared_ptr<DoodleJump::Player> p) {
    World::player = std::move(p);
}

void DoodleJump::World::addPlatform(const std::shared_ptr<Platform>& p) {
    platforms.insert(p);
}

std::shared_ptr<DoodleJump::Player> DoodleJump::World::getPlayer() const {
    return player;
}

const std::set<std::shared_ptr<DoodleJump::Platform>> &DoodleJump::World::getPlatforms() const {
    return platforms;
}

