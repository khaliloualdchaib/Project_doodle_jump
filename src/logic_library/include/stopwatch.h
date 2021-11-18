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
    public:
        static Stopwatch& getInstance();
        void reset();
        void tick();
        Stopwatch(const Stopwatch&) = delete;
        Stopwatch& operator = (const Stopwatch&) = delete;
        float getTime_difference();
    private:
        chrono::system_clock::time_point start_time;
        chrono::duration<float> time_difference = chrono::duration<float>(0.0f);
        Stopwatch() = default;
    };
}
#endif //DOODLEJUMP_STOPWATCH_H
