//
// Created by khalil on 12/18/21.
//

#ifndef DOODLEJUMP_SFMLSTATICPLATFORM_H
#define DOODLEJUMP_SFMLSTATICPLATFORM_H
#include "SFMLplatform.h"

namespace SFMLDoodleJump{
    class SFMLstaticPlatform: public SFMLPlatform{
    public:

        /*
         * Constructor that takes the same input as the SFMLPlatform class.
         */
        SFMLstaticPlatform(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w);

        /*
         * draw() is a function that draws the static platform on the window.
         */
        void draw(std::tuple<float, float> pos = std::make_tuple(1000, 1000)) override;

        /*
         * HandleEvent function
         */
        void HandleEvent(std::tuple<float, float> nextpos) override;
    };
}
#endif //DOODLEJUMP_SFMLSTATICPLATFORM_H
