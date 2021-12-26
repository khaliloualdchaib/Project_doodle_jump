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
}

std::tuple<std::tuple<float, float>, std::tuple<float, float>>  DoodleJump::World::getBottomCorners(const DoodleJump::Entity& entity) const {
    std::tuple<float, float> corner1 = {std::get<0>(entity.getPosition()), std::get<1>(entity.getPosition()) + entity.getHeight()};
    std::tuple<float, float> corner2 = {std::get<0>(entity.getPosition()) + entity.getWidth(), std::get<1>(entity.getPosition()) + entity.getHeight()};
    return {corner1, corner2};
}

std::tuple<std::tuple<float, float>, std::tuple<float, float>> DoodleJump::World::getTopCorners(const DoodleJump::Entity& entity) const {
    std::tuple<float, float> corner1 = entity.getPosition();
    std::tuple<float, float> corner2 = {std::get<0>(entity.getPosition()) + entity.getWidth(), std::get<1>(entity.getPosition())};
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
        if(player->isFalling()){
            float distance = std::abs(std::abs(std::get<1>(bottomleftcorner))-std::abs(std::get<1>(topleftcorner)));
            if (distance<=0.05f){
                if (std::get<0>(topleftcorner)<=std::get<0>(bottomleftcorner) or std::get<0>(toprightcorner)>=std::get<0>(bottomrightcorner)){
                    player->setCollisionPlatform(true);
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
        /*DoodleJump::Random::getInstance().initialise_rng();

        int isnegavtiveX = DoodleJump::Random::getInstance().getrandomnumber()%2;
        DoodleJump::Random::getInstance().initialise_rng();
        int isnegavtiveY = DoodleJump::Random::getInstance().getrandomnumber()%2;
        DoodleJump::Random::getInstance().initialise_rng();
        int randomX = DoodleJump::Random::getInstance().getrandomnumber();
        DoodleJump::Random::getInstance().initialise_rng();
        int randomY = DoodleJump::Random::getInstance().getrandomnumber();
        float xpos = randomX/((double ) RAND_MAX*4);
        float ypos = randomY/((double ) RAND_MAX*3);
        if(isnegavtiveX == 1){
            xpos = xpos*-1;
        }
        if(isnegavtiveY == 1){
            ypos = ypos*-1;
        }*/
    }
    std::shared_ptr<DoodleJump::Platform> platform = std::make_shared<DoodleJump::Platform>(DoodleJump::Platform(GameConfigurations["PlatformWidth"], GameConfigurations["PlatformHeight"],std::make_tuple(0, 0)));
    std::shared_ptr<DoodleJump::Platform> platform1 = std::make_shared<DoodleJump::Platform>(DoodleJump::Platform(GameConfigurations["PlatformWidth"], GameConfigurations["PlatformHeight"],std::make_tuple(1, 1)));
    platform->addObserver(factory->createPlatform(platform));
    platform1->addObserver(factory->createPlatform(platform));
    platforms.insert(platform);
    platforms.insert(platform1);
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

