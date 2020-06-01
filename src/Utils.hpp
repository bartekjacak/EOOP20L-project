#pragma once
#include <random>

namespace Utils {
    template<typename T>
    struct Range {
        T from;
        T to;
        Range(T from_, T to_): from(from_), to(to_) {};
    };

    class Randomizer {
    public:
        explicit Randomizer(unsigned long long int seed_ = 0);
        [[nodiscard]] int randomIn(Range<int> range);
    private:
        unsigned long long int seed;
        std::mt19937_64 generator;
    };
}