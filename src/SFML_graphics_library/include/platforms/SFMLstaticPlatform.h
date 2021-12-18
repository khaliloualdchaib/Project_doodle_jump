//
// Created by khalil on 12/18/21.
//

#ifndef DOODLEJUMP_SFMLSTATICPLATFORM_H
#define DOODLEJUMP_SFMLSTATICPLATFORM_H
#include "../SFMLentity.h"

namespace SFMLDoodleJump{
    class SFMLstaticPlatform: public SFMLEntity{
    private:
        sf::RectangleShape platform;
    public:
        SFMLstaticPlatform(float width, float height, std::tuple<float, float> pos, std::shared_ptr<sf::RenderWindow> w);

        void draw() override;

        //void void HandleEvent() override;
    };
}
#endif //DOODLEJUMP_SFMLSTATICPLATFORM_H
