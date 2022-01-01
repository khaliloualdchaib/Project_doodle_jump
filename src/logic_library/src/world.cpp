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

void DoodleJump::World::generate_initPlatforms() {
    unsigned int amount = floor(DoodleJump::Random::getInstance().getrandomDouble(10, 15));
    float heightcounter = -2.f;
    while (amount!=platforms.size()) {
        DoodleJump::staticPlatform dummy_platform = DoodleJump::staticPlatform(make_tuple(0, 0));
        double xpos = DoodleJump::Random::getInstance().getrandomDouble(-4.0, 4.0-dummy_platform.getWidth());
        std::shared_ptr<DoodleJump::staticPlatform> platform = std::make_shared<DoodleJump::staticPlatform>(DoodleJump::staticPlatform(std::make_tuple(xpos, heightcounter)));
        if(doPlatformsCollide(platform)){
            continue;
        } else{
            platform->addObserver(staticplatformObserver);
            platforms.insert(platform);
        }
        if(heightcounter>=3){
            heightcounter = -2.f;
        }
        else{
            heightcounter=heightcounter+0.5f;
        }
    }
}


float DoodleJump::World::heighestPlatform_Ypos() {
    float ypos = -1;
    for(const auto& platform: platforms){
        if(ypos<0){
            ypos = std::get<1>(platform->getPosition());
        }
        else if(std::get<1>(platform->getPosition())>ypos){
            ypos = std::get<1>(platform->getPosition());
        }
    }
    return ypos;
}


void DoodleJump::World::generatestaticPlatform(unsigned int difficulty) {
    DoodleJump::staticPlatform dummy_platform = DoodleJump::staticPlatform(make_tuple(0, 0));
    double xpos = DoodleJump::Random::getInstance().getrandomDouble(-4.0, 4.0-dummy_platform.getWidth());
    float maxheight = heighestPlatform_Ypos()+1.f;
    double ypos = DoodleJump::Random::getInstance().getrandomDouble(3.0, maxheight);
    //cout<<"max: "<<ypos<<endl;
    std::shared_ptr<DoodleJump::staticPlatform> platform = std::make_shared<DoodleJump::staticPlatform>(DoodleJump::staticPlatform(std::make_tuple(xpos, ypos)));
    if(doPlatformsCollide(platform) or platforms.size()>difficulty){
        return;
    }
    else{
        platform->addObserver(staticplatformObserver);
        platforms.insert(platform);
    }
    //platform placement
    if(difficulty == medium or difficulty == hard){
        for(auto& p1: platforms){
            for(auto& p2: platforms){
                if(std::get<1>(p1->getPosition())>3 and std::get<1>(p2->getPosition())>3){
                    float distance = sqrt(pow(std::get<1>(p1->getPosition()), 2.f)-pow(std::get<1>(p2->getPosition()), 2.f));
                    if(distance != 0){
                        if(distance>1.f or distance<0.5f){
                            if(std::get<1>(p1->getPosition())>std::get<1>(p2->getPosition())){
                                p1->setPosition(make_tuple(std::get<0>(p1->getPosition()), std::get<1>(p2->getPosition())+1.f));
                            }
                            else{
                                p2->setPosition(make_tuple(std::get<0>(p2->getPosition()), std::get<1>(p1->getPosition())+1.f));
                            }
                        }
                    }
                }
                if(std::get<1>(p1->getPosition())== std::get<1>(p2->getPosition()) and std::get<0>(p1->getPosition())!= std::get<0>(p2->getPosition())){
                    p1->setPosition(make_tuple(std::get<0>(p1->getPosition()), std::get<1>(p1->getPosition())+1.f));
                }
            }
        }
    }
}


void DoodleJump::World::updateWorldCamera() {
    if(std::get<1>(player->getPosition())>=0){
        if(currentlvl<=500){
            generatestaticPlatform(easy);
        }
        else if(currentlvl<=1000){
            generatestaticPlatform(medium);
        }
        else{
            generatestaticPlatform(hard);
        }
        for(auto& platform: platforms){
            float xpos = std::get<0>(platform->getPosition());
            float ypos = std::get<1>(platform->getPosition())-player->getInitialVelocity();
            platform->setPosition(make_tuple(xpos, ypos));
        }

        player->setPosition(make_tuple(std::get<0>(player->getPosition()), std::get<1>(player->getPosition())-player->getInitialVelocity()));
        currentlvl++;
        //cout<<currentlvl<<endl;
        //cout<<std::get<1>(player->getPosition())<<std::endl;


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

