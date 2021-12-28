//
// Created by khalil on 12/7/21.
//

#include "../include/world.h"
#include "../include/random.h"
#include <utility>
#include "cmath"

DoodleJump::World::World(std::shared_ptr<DoodleJump::AbstractFactory> a, std::map<std::string, float> config) {
    factory = std::move(a);
    GameConfigurations = std::move(config);
    std::shared_ptr<DoodleJump::staticPlatform> dummy_staticplatform = std::make_shared<DoodleJump::staticPlatform>(DoodleJump::staticPlatform(std::make_tuple(0, 0)));
    staticplatformObserver = factory->createStaticPlatform(dummy_staticplatform);
}

std::tuple<std::tuple<float, float>, std::tuple<float, float>>  DoodleJump::World::getBottomCorners(const DoodleJump::Entity& entity) const {
    std::tuple<float, float> corner1 = {std::get<0>(entity.getPosition()), std::get<1>(entity.getPosition()) - entity.getHeight()};
    std::tuple<float, float> corner2 = {std::get<0>(entity.getPosition()) + entity.getWidth(), std::get<1>(entity.getPosition()) - entity.getHeight()};
    return {corner1, corner2};
}

std::tuple<std::tuple<float, float>, std::tuple<float, float>> DoodleJump::World::getTopCorners(const DoodleJump::Entity& entity) const {
    std::tuple<float, float> corner1 = entity.getPosition();
    std::tuple<float, float> corner2 = {std::get<0>(entity.getPosition()) + entity.getWidth(), std::get<1>(entity.getPosition())};
    return {corner1, corner2};
}

float DoodleJump::World::round_float2decimals(float f) {
    float value = (int)(f * 100 + .5);
    return (float)value / 100;
}

void DoodleJump::World::collisionPlayerPlatform() {
    player->setCollisionPlatform(false);
    std::tuple<std::tuple<float, float>, std::tuple<float, float>> bottomcornersPlayer = getBottomCorners(*player);
    for (auto& platform: platforms) {
        std::tuple<std::tuple<float, float>, std::tuple<float, float>>  topcornersPlatform = getTopCorners(*platform);
        std::tuple<float, float> bottomleftcornersplatform = std::get<0>(getBottomCorners(*platform));
        std::tuple<float, float> topleftcorner = std::get<0>(topcornersPlatform);
        std::tuple<float, float> toprightcorner = std::get<1>(topcornersPlatform);
        std::tuple<float, float> bottomleftcorner = std::get<0>(bottomcornersPlayer);
        std::tuple<float, float> bottomrightcorner = std::get<1>(bottomcornersPlayer);
        if(player->isFalling()){
            if (round_float2decimals(std::get<1>(topleftcorner))== round_float2decimals(std::get<1>(bottomleftcorner))){
                if ((std::get<0>(topleftcorner)<=std::get<0>(bottomleftcorner)+0.04f and std::get<0>(toprightcorner)>=std::get<0>(bottomleftcorner)+0.04f) or
                    (std::get<0>(topleftcorner)<=std::get<0>(bottomrightcorner)-(player->getWidth()/3.2) and std::get<0>(toprightcorner)>=std::get<0>(bottomrightcorner)-(player->getWidth()/3.2) )){
                    player->setCollisionPlatform(true);
                    return;
                }
            }
            if((round_float2decimals(std::get<1>(topleftcorner))>round_float2decimals(std::get<1>(bottomleftcorner))) and (round_float2decimals(std::get<1>(bottomleftcornersplatform))<round_float2decimals(std::get<1>(bottomleftcorner)))){
                if ((std::get<0>(topleftcorner)<=std::get<0>(bottomleftcorner)+0.04f and std::get<0>(toprightcorner)>=std::get<0>(bottomleftcorner)+0.04f) or
                    (std::get<0>(topleftcorner)<=std::get<0>(bottomrightcorner)-(player->getWidth()/3.2) and std::get<0>(toprightcorner)>=std::get<0>(bottomrightcorner)-(player->getWidth()/3.2) )){
                    player->setCollisionPlatform(true);
                    return;
                }
            }
        }
    }

}

void DoodleJump::World::generatePlayer() {
    player = std::make_shared<DoodleJump::Player>(DoodleJump::Player(GameConfigurations["PlayerWidth"], GameConfigurations["PlayerHeight"],
                                                                     std::make_tuple(GameConfigurations["PlayerX_Position"], GameConfigurations["PlayerY_Position"])));
    player->addObserver(factory->createPlayer(player));
}

void DoodleJump::World::generatePlatforms(unsigned int amount) {
    unsigned int counter = amount;
    for (unsigned int i = 0; i < counter; ++i) {
        double xpos = DoodleJump::Random::getInstance().getrandomDouble(-4.0, 4.0);
        double ypos = DoodleJump::Random::getInstance().getrandomDouble(-3.0, 3.0);
        std::shared_ptr<DoodleJump::staticPlatform> platform = std::make_shared<DoodleJump::staticPlatform>(DoodleJump::staticPlatform(std::make_tuple(xpos, ypos)));
        if(doPlatformsCollide(platform)){
            counter++;
        } else{
            platform->addObserver(staticplatformObserver);
            platforms.insert(platform);
        }

    }


}

bool DoodleJump::World::doPlatformsCollide(const std::shared_ptr<DoodleJump::Platform>& p) {
    bool check = false;
    for (const auto& platform: platforms) {
        if(std::get<0>(p->getPosition()) == std::get<0>(platform->getPosition()) and std::get<1>(p->getPosition()) == std::get<1>(platform->getPosition())){
            check = true;
        }
    }
    return check;
}
std::shared_ptr<DoodleJump::Player> DoodleJump::World::getPlayer() const {
    return player;
}

const std::set<std::shared_ptr<DoodleJump::Platform>> &DoodleJump::World::getPlatforms() const {
    return platforms;
}

