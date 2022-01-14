//
// Created by khalil on 12/10/21.
//

#ifndef DOODLEJUMP_CAMERA_H
#define DOODLEJUMP_CAMERA_H
#include <tuple>
namespace DoodleJump {
class Camera
{
private:
        unsigned int width;
        unsigned int height;

public:
        /**
         * Constructor.
         * @param height: Window Height
         * @param width: Window Width
         */
        Camera(unsigned int width, unsigned int height);

        /**
         * Transform own 2D coordinate system coordinates to pixel coordinates.
         * @param xpos: X coordinate of own 2D coordinate system coordinates.
         * @param ypos: Y coordinate of own 2D coordinate system coordinates.
         * @return pixel coordinate.
         */
        std::tuple<float, float> Transformation(float xpos, float ypos) const;

        /**
         * Transforms the width of my own coordinate system to width in pixels.
         * @param w: Width of my own coordinate system.
         * @return Width in pixels.
         */
        float TransformWidth(float w) const;

        /**
         * Transforms the height of my own coordinate system to height in pixels.
         * @param h: Height of my own coordinate system.
         * @return Height in pixels
         */
        float TransformHeight(float h) const;
};
} // namespace DoodleJump
#endif // DOODLEJUMP_CAMERA_H
