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
    //https://stackoverflow.com/questions/288739/generate-random-numbers-uniformly-over-an-entire-range
    class Random{
    private:
        Random()=default;
        std::random_device rng;
        std::mt19937 engine{rng()};

    public:

        /*
         * Normal singleton getInstance function.
         */
        static Random& getInstance();

        /*
         * If the copy constructor is called the copy is going to get deleted
         */
        Random(const Random&) = delete;

        /*
         * Delete the overloading operator.
         */
        Random& operator = (const Random&) = delete;

        /*
         * This function returns a random double
         */
        double getrandomDouble(double min, double max);

    };
}
#endif //DOODLEJUMP_RANDOM_H
