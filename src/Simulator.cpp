#include <algorithm>
#include "Simulator.hpp"

using namespace std::chrono_literals;

Simulator::Simulator(Utils::Randomizer randomizer):
    _randomizer(randomizer),
    _bestPossibleTimeRange(durationRange(30min, 300min)),
    _timeOffsetRange(durationRange(0s, 900s)) {};

std::vector<DriverTime> Simulator::simulateResults(const std::vector<Driver>& drivers) {
    auto driversCount = drivers.size();
    auto bestPossibleTime = randomBestFinishTime();
    auto indices = std::vector<int>();
    auto weights = std::vector<double>();
    indices.reserve(driversCount);
    weights.reserve(driversCount);

    for (auto i = 0; i < driversCount; i++) {
        indices.push_back(i);
        weights.push_back(1.0 + (drivers[i].winsCount / 2.0) + (drivers[i].winsCount / 10.0));
    }

    auto distribution = std::discrete_distribution<int>(weights.begin(), weights.end());
    auto generator = std::mt19937_64(std::random_device{}());
    auto winnerIndex = distribution(generator);
    drivers[winnerIndex].winsCount++;

    auto results = std::vector<DriverTime>();
    results.reserve(driversCount);
    for (auto i = 0; i < driversCount; i++) {
        auto time = (i == winnerIndex) ? bestPossibleTime : bestPossibleTime + randomTimeOffset();
        results.emplace_back(drivers[i], time);
    }

    return results;
};

duration Simulator::randomBestFinishTime() {
    auto from = std::chrono::duration_cast<std::chrono::seconds>(_bestPossibleTimeRange.from).count();
    auto to = std::chrono::duration_cast<std::chrono::seconds>(_bestPossibleTimeRange.to).count();
    int bestTime = _randomizer.randomIn(Utils::Range<int>(from, to));

    return std::chrono::seconds(bestTime);
};

duration Simulator::randomTimeOffset() {
    auto from = std::chrono::duration_cast<std::chrono::seconds>(_timeOffsetRange.from).count();
    auto to = std::chrono::duration_cast<std::chrono::seconds>(_timeOffsetRange.to).count();
    int timeOffset = _randomizer.randomIn(Utils::Range<int>(from, to));

    return std::chrono::seconds(timeOffset);
};