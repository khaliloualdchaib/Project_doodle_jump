//
// Created by khalil on 11/16/21.
//

#ifndef DOODLEJUMP_RANDOM_H
#define DOODLEJUMP_RANDOM_H
#include <memory>

using namespace std;

namespace DoodleJump
{
    class Random{
    private:
        Random()=default;
    public:

        /*
         * Normal singleton getInstance function.
         */
        static Random& getInstance();

        /*
         * Initialise_rng initialises the random number generator
         */
        static void initialise_rng();

        /*
         * If the copy constructor is called the copy is going to get deleted
         */
        Random(const Random&) = delete;

        /*
         * Delete the overloading operator.
         */
        Random& operator = (const Random&) = delete;

        /*
         * This function returns a random number
         */
        static int getrandomnumber();

    };
}
#endif //DOODLEJUMP_RANDOM_H
