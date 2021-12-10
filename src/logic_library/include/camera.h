//
// Created by khalil on 12/10/21.
//

#ifndef DOODLEJUMP_CAMERA_H
#define DOODLEJUMP_CAMERA_H
#include <tuple>
namespace DoodleJump{
    class Camera{
    private:
        unsigned int width;
        unsigned int height;
    public:

        /*
         * This is a constructor.
         * The inputs are the width and the height of the window
         */
        Camera(unsigned int width, unsigned int height);

        /*
         * Later commenten.
         */
        std::tuple<int, int> Transformation(double xpos, double ypos);

        /*
         *Later commenten
         */
        void update();
        
    };
}
#endif //DOODLEJUMP_CAMERA_H
