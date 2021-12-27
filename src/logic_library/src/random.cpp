#include "../include/random.h"

DoodleJump::Random& DoodleJump::Random::getInstance() {
    static DoodleJump::Random instance;
    return instance;
}
double DoodleJump::Random::getrandomDouble(double min, double max) {
    double random = ((double) rand())/RAND_MAX;
    double tmp = (max-min)*random;
    return min +tmp;
}
void DoodleJump::Random::initialise_rng() {
    srand(time(nullptr));
}

