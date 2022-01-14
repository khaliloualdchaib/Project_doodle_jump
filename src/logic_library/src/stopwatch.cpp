//
// Created by khalil on 11/17/21.
//

#include "../include/stopwatch.h"
DoodleJump::Stopwatch& DoodleJump::Stopwatch::getInstance()
{
        static DoodleJump::Stopwatch instance;
        return instance;
}

void DoodleJump::Stopwatch::reset()
{
        start_time = chrono::system_clock::now(); // update start time
}

void DoodleJump::Stopwatch::tick()
{
        time_difference = chrono::system_clock::now() -
                          start_time; // difference in time between the current update step and the previous one
}

float DoodleJump::Stopwatch::getTime_difference()
{
        return time_difference.count(); // returns the number of ticks in the duration
}