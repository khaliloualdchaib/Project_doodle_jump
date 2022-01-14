//
// Created by khalil on 11/16/21.
//

#ifndef DOODLEJUMP_RANDOM_H
#define DOODLEJUMP_RANDOM_H
#include <memory>
#include <random>

using namespace std;

namespace DoodleJump
{
    class Random{
    private:
        Random()=default;
        std::random_device rng;
        std::mt19937 engine{rng()};

    public:

        /**
         * Singleton getInstance function
         * @return Instance of the Random singleton
         */
        static Random& getInstance();

        /**
         * If the copy constructor is called the copy is going to get deleted
         */
        Random(const Random&) = delete;

        /**
         * Delete the overloading operator if it is called.
         */
        Random& operator = (const Random&) = delete;

        /**
         * @return This function returns a random double
         * @param max: The maximum range that the double can be.
         * @param min: The minimum range that the double can be.
         */
        double getrandomDouble(double min, double max);

    };
}
#endif //DOODLEJUMP_RANDOM_H
