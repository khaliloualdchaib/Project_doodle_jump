//
// Created by khalil on 12/19/21.
//

#ifndef DOODLEJUMP_SFMLPLATFORM_H
#define DOODLEJUMP_SFMLPLATFORM_H
#include "../SFMLentity.h"
namespace SFMLDoodleJump{
    class SFMLPlatform: public SFMLEntity{
    private:
        sf::RectangleShape platform;
    public:

        /*
         * Getter for the platform
         */
        sf::RectangleShape &getPlatform();

        /*
         * Constructor that takes the same input as the SFMLEntity class
         */
        SFMLPlatform(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w);

        /*
         * empty function
         */
        void draw(std::tuple<float, float> pos) override {};
    };
}
#endif //DOODLEJUMP_SFMLPLATFORM_H
