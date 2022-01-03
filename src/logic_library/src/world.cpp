//
// Created by khalil on 12/7/21.
//

#include "../include/world.h"
#include "../include/random.h"
#include <utility>
#include "cmath"
#include <cassert>
#include <vector>
#include <algorithm>

DoodleJump::World::World(std::shared_ptr<DoodleJump::AbstractFactory> a, std::map<std::string, float> config) {
    factory = std::move(a);
    GameConfigurations = std::move(config);
    std::shared_ptr<DoodleJump::StaticPlatform> init_platform = std::make_shared<DoodleJump::StaticPlatform>(DoodleJump::StaticPlatform(std::make_tuple(GameConfigurations["PlayerX_Position"], GameConfigurations["PlayerY_Position"])));
    staticplatformObserver = factory->createStaticPlatform(init_platform);
    init_platform->addObserver(staticplatformObserver);
    platforms.insert(init_platform);

    std::shared_ptr<DoodleJump::TemporaryPlatform> temp_platform = std::make_shared<DoodleJump::TemporaryPlatform>(DoodleJump::TemporaryPlatform(make_tuple(0, 0)));
    temporaryplatformObserver = factory->createTemporaryPlatform(temp_platform);

    std::shared_ptr<DoodleJump::HorizontalPlatform> horizontal_platform = std::make_shared<DoodleJump::HorizontalPlatform>(DoodleJump::HorizontalPlatform(std::make_tuple(0, 0)));
    horizontalplatformObserver = factory->createHorizontalPlatform(horizontal_platform);
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
                    platform->settemporaryJumped(true);
                    if(platform->temporaryJumped()){
                        platforms.erase(platform);
                    }
                    return;
                }
            }
            if((round_float2decimals(std::get<1>(topleftcorner))>round_float2decimals(std::get<1>(bottomleftcorner))) and (round_float2decimals(std::get<1>(bottomleftcornersplatform))<round_float2decimals(std::get<1>(bottomleftcorner)))){
                if ((std::get<0>(topleftcorner)<=std::get<0>(bottomleftcorner)+0.04f and std::get<0>(toprightcorner)>=std::get<0>(bottomleftcorner)+0.04f) or
                    (std::get<0>(topleftcorner)<=std::get<0>(bottomrightcorner)-(player->getWidth()/3.2) and std::get<0>(toprightcorner)>=std::get<0>(bottomrightcorner)-(player->getWidth()/3.2) )){
                    player->setCollisionPlatform(true);
                    platform->settemporaryJumped(true);
                    if(platform->temporaryJumped()){
                        platforms.erase(platform);
                    }
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
        DoodleJump::StaticPlatform dummy_platform = DoodleJump::StaticPlatform(make_tuple(0, 0));
        double xpos = DoodleJump::Random::getInstance().getrandomDouble(-4.0, 4.0-dummy_platform.getWidth());
        std::shared_ptr<DoodleJump::StaticPlatform> platform = std::make_shared<DoodleJump::StaticPlatform>(DoodleJump::StaticPlatform(std::make_tuple(xpos, heightcounter)));
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

void DoodleJump::World::generatePlatform(const unsigned int probStatic, const unsigned int probTemporary, const unsigned int probHorizontal, const unsigned int probVertical, unsigned int difficulty) {
    const unsigned int total = probStatic + probTemporary + probHorizontal + probVertical;
    assert(total == 100);
    DoodleJump::StaticPlatform dummy_platform = DoodleJump::StaticPlatform(make_tuple(0, 0));
    double xpos = DoodleJump::Random::getInstance().getrandomDouble(-4.0, 4.0-dummy_platform.getWidth());
    float maxheight = heighestPlatform_Ypos()+1.2f;
    double ypos = DoodleJump::Random::getInstance().getrandomDouble(3.0, maxheight);
    unsigned int platformProb = floor(DoodleJump::Random::getInstance().getrandomDouble(1, 100));
    //put all probabilities in list
    vector<pair<unsigned int, std::string>> probabilities = {{probStatic, "static"}, {probTemporary, "temporary"}, {probHorizontal, "Horizontal"}, {probVertical, "Vertical"}};
    //sort probabilities
    std::sort(probabilities.begin(), probabilities.end());
    //erase all probabilities equal to 0
    unsigned int index = 0;
    while(index<probabilities.size()){
        if(probabilities[index].first == 0){
            probabilities.erase(probabilities.begin()+index);
        } else{
            index++;
        }
    }
    vector<pair<unsigned int, std::string>>  copy_prob = probabilities;
    //calculate cumulative probability
    for (unsigned int i = 1; i < probabilities.size(); ++i) {
        if(probabilities[i].second != probabilities[probabilities.size()-1].second){
            if(probabilities[i].first != probabilities[i+1].first){
                probabilities[i+1].first += probabilities[i].first;
            }
        }
        else if(probabilities.size()>1){
            if(copy_prob[i].first != copy_prob[i-1].first){
                probabilities[i].first += probabilities[i-1].first;
            }
        }
    }
    //determine wich platform to generate
    std::string platformtype;
    if(probabilities.size() == 1){
        platformtype = probabilities[0].second;
    }
    else{
        for (unsigned int i = 0; i < probabilities.size(); ++i) {
            if(platformProb<=probabilities[i].first){
                //determine wich platform belongs to the prob
                if(probabilities[i].first!=probabilities[i+1].first){
                    platformtype = probabilities[i].second;
                    break;
                }
                else{
                    if(i==probabilities.size()-1){
                        platformtype = probabilities[i].second;
                    }
                    else{
                        double choosplatform = DoodleJump::Random::getInstance().getrandomDouble(1, 3);
                        if(choosplatform<=2){
                            platformtype = probabilities[i].second;
                            break;
                        }
                        else{
                            platformtype = probabilities[i+1].second;
                            break;
                        }
                    }
                }
            }
        }
    }
    //generate the platform dertimined by the type of platform.
    if(platformtype == "static"){
        generatestaticPlatform(difficulty, std::make_tuple(xpos, ypos));
    }
    else if(platformtype == "temporary"){
        generatetemporaryPlatform(difficulty, std::make_tuple(xpos, ypos));
    }
    else if(platformtype == "Horizontal"){
        generatehorizontalPlatform(difficulty, std::make_tuple(xpos, ypos));
    }
    else if(platformtype == "Vertical"){
    }
}

void DoodleJump::World::generatestaticPlatform(unsigned int difficulty, std::tuple<float, float> pos) {
    std::shared_ptr<DoodleJump::StaticPlatform> platform = std::make_shared<DoodleJump::StaticPlatform>(DoodleJump::StaticPlatform(pos));
    if(doPlatformsCollide(platform) or platforms.size()>difficulty){
        return;
    }
    else{
        cout<<std::get<0>(platform->getPosition())<<" "<<std::get<1>(platform->getPosition())<<endl;
        platform->addObserver(staticplatformObserver);
        platforms.insert(platform);
    }
}

void DoodleJump::World::generatetemporaryPlatform(unsigned int difficulty, std::tuple<float, float> pos) {
    std::shared_ptr<DoodleJump::TemporaryPlatform> platform = std::make_shared<DoodleJump::TemporaryPlatform>(DoodleJump::TemporaryPlatform(pos));
    if(doPlatformsCollide(platform) or platforms.size()>difficulty){
        return;
    }
    else{
        platform->addObserver(temporaryplatformObserver);
        platforms.insert(platform);
    }
}

void DoodleJump::World::generatehorizontalPlatform(unsigned int difficulty, std::tuple<float, float> pos) {
    std::shared_ptr<DoodleJump::HorizontalPlatform> platform = std::make_shared<DoodleJump::HorizontalPlatform>(DoodleJump::HorizontalPlatform(pos));
    if(doPlatformsCollide(platform) or platforms.size()>difficulty){
        return;
    }
    else{
        platform->addObserver(horizontalplatformObserver);
        platforms.insert(platform);
    }
}


void DoodleJump::World::updateWorldCamera() {
    if(currentlvl>500){
        spreadPlatforms();
    }
    if(std::get<1>(player->getPosition())>=0){
        if(currentlvl<=500){
            generatePlatform(100, 0, 0, 0, easy);
        }
        else if(currentlvl<=1000){
            generatePlatform(60, 10, 30, 0, medium);
        }
        else{
            generatePlatform(60, 10, 30, 0, hard);
        }
        for(auto& platform: platforms){
            float xpos = std::get<0>(platform->getPosition());
            float ypos = std::get<1>(platform->getPosition())-player->getInitialVelocity();
            platform->setPosition(make_tuple(xpos, ypos));
        }

        player->setPosition(make_tuple(std::get<0>(player->getPosition()), std::get<1>(player->getPosition())-player->getInitialVelocity()));
        //currentlvl++;
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

void DoodleJump::World::spreadPlatforms() {
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

