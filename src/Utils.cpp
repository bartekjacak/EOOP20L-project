#include <chrono>
#include "Utils.hpp"

Utils::Randomizer::Randomizer(unsigned long long int seed_): seed(seed_), generator() {
    if (seed != 0) {
        generator.seed(seed);
    }
}

int Utils::Randomizer::randomIn(Range<int> range) {
    if (seed == 0) generator.seed(std::chrono::steady_clock::now().time_since_epoch().count());
    return std::uniform_int_distribution(range.from, range.to)(generator);
}