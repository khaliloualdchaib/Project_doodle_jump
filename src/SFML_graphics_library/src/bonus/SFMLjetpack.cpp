//
// Created by khalil on 1/6/22.
//

#include <tuple>
#include <memory>
#include "../../include/bonus/SFMLjetpack.h"

SFMLDoodleJump::SFMLJetpack::SFMLJetpack(float width, float height, const std::tuple<float, float> &pos,
                                         const std::shared_ptr <sf::RenderWindow> &w, const sf::Texture& texture) : SFMLBonus(width, height, pos,
                                                                                                  w) {
}
