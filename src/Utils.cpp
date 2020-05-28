#include "Utils.hpp"

Utils::Randomizer::Randomizer(int seed): generator() {
    if (seed == 0) {
        generator.seed(std::random_device{}());
    } else {
        generator.seed(seed);
    }
};

int Utils::Randomizer::randomIn(Range<int> range) {
    return std::uniform_int_distribution(range.from, range.to)(generator);
}