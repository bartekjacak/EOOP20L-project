#pragma once
#include <vector>
#include <random>
#include <chrono>
#include "DriverTime.hpp"
#include "Driver.hpp"
#include "Utils.hpp"

typedef std::chrono::duration<int> duration;
typedef Utils::Range<duration> durationRange;

class Simulator {
public:
    explicit Simulator(Utils::Randomizer& randomizer);

    // Simulates drivers' performance on a single edition
    [[nodiscard]] std::vector<DriverTime> simulateResults(const std::vector<Driver>& drivers) const;

private:
    Utils::Randomizer& _randomizer;
    durationRange _bestPossibleTimeRange;
    durationRange _timeOffsetRange;

    [[nodiscard]] duration randomBestFinishTime() const;
    [[nodiscard]] duration randomTimeOffset() const;
};