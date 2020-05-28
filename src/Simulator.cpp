#include <algorithm>
#include "Simulator.hpp"

using namespace std::chrono_literals;

Simulator::Simulator(Utils::Randomizer& randomizer):
    _randomizer(randomizer),
    _bestPossibleTimeRange(durationRange(30min, 300min)),
    _timeOffsetRange(durationRange(0s, 3600s)) {};

std::vector<DriverTime> Simulator::simulateResults(const std::vector<Driver>& drivers) const {
    auto bestPossibleTime = randomBestFinishTime();
    auto results = std::vector<DriverTime>();

    results.reserve(drivers.size());
    for (auto const &driver: drivers) {
        auto time = bestPossibleTime + randomTimeOffset();
        results.emplace_back(driver, time);
    }

    return results;
};

duration Simulator::randomBestFinishTime() const {
    auto from = std::chrono::duration_cast<std::chrono::seconds>(_bestPossibleTimeRange.from).count();
    auto to = std::chrono::duration_cast<std::chrono::seconds>(_bestPossibleTimeRange.to).count();
    int bestTime = _randomizer.randomIn(Utils::Range<int>(from, to));

    return std::chrono::seconds(bestTime);
};

duration Simulator::randomTimeOffset() const {
    auto from = std::chrono::duration_cast<std::chrono::seconds>(_timeOffsetRange.from).count();
    auto to = std::chrono::duration_cast<std::chrono::seconds>(_timeOffsetRange.to).count();
    int timeOffset = _randomizer.randomIn(Utils::Range<int>(from, to));

    return std::chrono::seconds(timeOffset);
};