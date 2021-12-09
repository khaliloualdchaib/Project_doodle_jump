//
// Created by khalil on 11/17/21.
//

#ifndef DOODLEJUMP_STOPWATCH_H
#define DOODLEJUMP_STOPWATCH_H
#include <iostream>
#include <memory>
#include <chrono>

using namespace std;

namespace DoodleJump{
    class Stopwatch{
    private:
        chrono::system_clock::time_point start_time;
        chrono::duration<float> time_difference = chrono::duration<float>(0.0f);
        Stopwatch() = default;
    public:

        /*
         * Normal singleton getInstance function.
         */
        static Stopwatch& getInstance();

        /*
         * Changes the start time to now
         */
        void reset();

        /*
         * Sets the time_difference to the time now minus the start time.
         */
        void tick();

        /*
         * If the copy constructor is called the copy is going to get deleted.
         */
        Stopwatch(const Stopwatch&) = delete;

        /*
         * Delete the overloading operator.
         */
        Stopwatch& operator = (const Stopwatch&) = delete;

        /*
         * getTime_difference is a getter for time_difference.
         */
        float getTime_difference();

    };
}
#endif //DOODLEJUMP_STOPWATCH_H
