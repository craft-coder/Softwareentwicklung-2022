#include "Random.h"
#include <random>

namespace raytracer {

double randomDouble(double min, double max) {
    static std::uniform_real_distribution<double> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}

}
