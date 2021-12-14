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
         * Transform own 2D coordinate system coordinates to pixel coordinates.
         * Takes own 2D coordinate system coordinates as input.
         * Returns pixel coordinates.
         */
        std::tuple<float, float> Transformation(float xpos, float ypos) const;

        /*
         *Later commenten
         */
        void update();

    };
}
#endif //DOODLEJUMP_CAMERA_H
