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
        explicit Randomizer(int seed = 0);
        [[nodiscard]] int randomIn(Range<int> range);

    private:
        std::mt19937_64 generator;
    };
};