//
// Created by khalil on 1/6/22.
//

#include <tuple>
#include <memory>
#include "../../include/bonus/SFMLbonus.h"

SFMLDoodleJump::SFMLBonus::SFMLBonus(float width, float height, const std::tuple<float, float> &pos,const std::shared_ptr <sf::RenderWindow> &w) : SFMLEntity(width, height, pos, w) {}