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
    std::shared_ptr<DoodleJump::staticPlatform> init_platform = std::make_shared<DoodleJump::staticPlatform>(DoodleJump::staticPlatform(std::make_tuple(GameConfigurations["PlayerX_Position"], GameConfigurations["PlayerY_Position"])));
    staticplatformObserver = factory->createStaticPlatform(init_platform);
    init_platform->addObserver(staticplatformObserver);
    platforms.insert(init_platform);
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

void DoodleJump::World::generate_initPlatforms(unsigned int amount) {
    unsigned int counter = amount;
    float heightcounter = -2.f;
    for (unsigned int i = 0; i < counter; ++i) {
        DoodleJump::staticPlatform dummy_platform = DoodleJump::staticPlatform(make_tuple(0, 0));
        double xpos = DoodleJump::Random::getInstance().getrandomDouble(-4.0, 4.0-dummy_platform.getWidth());
        std::shared_ptr<DoodleJump::staticPlatform> platform = std::make_shared<DoodleJump::staticPlatform>(DoodleJump::staticPlatform(std::make_tuple(xpos, heightcounter)));
        if(doPlatformsCollide(platform)){
            counter++;
        } else{
            platform->addObserver(staticplatformObserver);
            platforms.insert(platform);
        }
        if(heightcounter>3){
            heightcounter = -2.f;
        }
        else{
            heightcounter=heightcounter+0.5f;
        }
    }
}

void DoodleJump::World::generatestaticPlatform() {
    DoodleJump::staticPlatform dummy_platform = DoodleJump::staticPlatform(make_tuple(0, 0));
    double xpos = DoodleJump::Random::getInstance().getrandomDouble(-4.0, 4.0-dummy_platform.getWidth());
    std::shared_ptr<DoodleJump::staticPlatform> platform = std::make_shared<DoodleJump::staticPlatform>(DoodleJump::staticPlatform(std::make_tuple(xpos, 3)));
    if(doPlatformsCollide(platform) or PlatformSameRowCounter()>2){
        return;
    }
    else{
        platform->addObserver(staticplatformObserver);
        platforms.insert(platform);
    }
}

unsigned int DoodleJump::World::PlatformSameRowCounter() {
    unsigned int counter = 0;
    for(const auto& platform: platforms){
        if(std::get<1>(platform->getPosition())>=2.f and std::get<1>(platform->getPosition())<=3.0f){
            counter++;
        }
    }
    return counter;
}

void DoodleJump::World::updateWorldCamera() {
    if(std::get<1>(player->getPosition())>=0){
        for(auto& platform: platforms){
            float xpos = std::get<0>(platform->getPosition());
            float ypos = std::get<1>(platform->getPosition())-0.03f;
            platform->setPosition(make_tuple(xpos, ypos));
        }
        player->setPosition(make_tuple(std::get<0>(player->getPosition()), std::get<1>(player->getPosition())-0.03));
        generatestaticPlatform();
    }
    set<shared_ptr<DoodleJump::Platform>> copy_Platforms = platforms;
    for(auto& platform: copy_Platforms){
        float ypos = std::get<1>(platform->getPosition());
        if(ypos<-3){
            platforms.erase(platform);
        }
    }
}

bool DoodleJump::World::doPlatformsCollide(const std::shared_ptr<DoodleJump::Platform>& p) {
    std::tuple<std::tuple<float, float>, std::tuple<float, float>>  topcornersPlatform = getTopCorners(*p);
    std::tuple<std::tuple<float, float>, std::tuple<float, float>> bottomcornersPlatform = getBottomCorners(*p);
    std::tuple<float, float> topleftcornerp1 = std::get<0>(topcornersPlatform);
    std::tuple<float, float> toprightcornerp1 = std::get<1>(topcornersPlatform);
    std::tuple<float, float> bottomleftcornerp1 = std::get<0>(bottomcornersPlatform);
    std::tuple<float, float> bottomrightcornerp1 = std::get<1>(bottomcornersPlatform);
    set<std::tuple<float, float>> setOFcorners = {topleftcornerp1, toprightcornerp1, bottomleftcornerp1, bottomrightcornerp1};
    for (const auto& platform: platforms) {
        std::tuple<std::tuple<float, float>, std::tuple<float, float>>  topcornersPlatform2 = getTopCorners(*platform);
        std::tuple<std::tuple<float, float>, std::tuple<float, float>> bottomcornersPlatform2 = getBottomCorners(*platform);
        std::tuple<float, float> topleftcornerp2 = std::get<0>(topcornersPlatform2);
        std::tuple<float, float> toprightcornerp2 = std::get<1>(topcornersPlatform2);
        std::tuple<float, float> bottomleftcornerp2 = std::get<0>(bottomcornersPlatform2);
        for(auto corner: setOFcorners){
            if(std::get<0>(topleftcornerp2)<=std::get<0>(corner) and std::get<0>(toprightcornerp2)>=std::get<0>(corner)){
                if(std::get<1>(topleftcornerp2)>=std::get<1>(corner) and std::get<1>(bottomleftcornerp2)<=std::get<1>(corner)){
                    return true;
                }
            }
        }
    }
    return false;
}
std::shared_ptr<DoodleJump::Player> DoodleJump::World::getPlayer() const {
    return player;
}

const std::set<std::shared_ptr<DoodleJump::Platform>> &DoodleJump::World::getPlatforms() const {
    return platforms;
}

