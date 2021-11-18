#include "../include/random.h"
#include "time.h"

DoodleJump::Random& DoodleJump::Random::getInstance() {
    static DoodleJump::Random instance;
    return instance;
}
int DoodleJump::Random::getrandomnumber() {
    return rand();
}
void DoodleJump::Random::initialise_rng() {
    srand(time(0));
}

