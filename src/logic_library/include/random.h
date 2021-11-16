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
    public:
        static shared_ptr<Random>& getInstance();
        static void initialise_rng();
        Random(const Random&) = delete; //if the copy constructor is called the copy is going to get deleted
        Random& operator = (const Random&) = delete;
        static int getrandomnumber(); //This function returns a random number
    private:
        Random()=default;
    };
}
#endif //DOODLEJUMP_RANDOM_H
