#include "../include/random.h"
#include <random>

DoodleJump::Random& DoodleJump::Random::getInstance() {
    static DoodleJump::Random instance;
    return instance;
}
double DoodleJump::Random::getrandomDouble(double min, double max) {
    std::uniform_real_distribution<> val(min, max);
    return val(engine);
}

