#include "Utils.hpp"

Utils::Randomizer::Randomizer(unsigned long long int seed): generator() { // NOLINT(cert-msc32-c)
    if (seed == 0) {
        generator.seed(std::random_device{}());
    } else {
        generator.seed(seed);
    }
}

int Utils::Randomizer::randomIn(Range<int> range) {
    return std::uniform_int_distribution(range.from, range.to)(generator);
}