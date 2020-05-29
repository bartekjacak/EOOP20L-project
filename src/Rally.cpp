#include <algorithm>
#include "Rally.hpp"

Rally::Rally(const std::string& name_, const std::vector<Driver>& drivers_):
    name(name_), drivers(drivers_), latestResults(), latestEditionNumber(0) {}

const Driver& Rally::getDriver(unsigned long index) const {
    if (index < 1 || index > drivers.size()) {
        throw Rally::InvalidDriverIdError();
    }

    return drivers.at(index - 1);
}

std::vector<int> Rally::getSortedResultsIndices() const {
    int resultsCount = latestResults.size();
    auto indices = std::vector<int>();

    indices.reserve(resultsCount);
    for (int i = 0; i < resultsCount; i++) indices.push_back(i);

    std::sort(indices.begin(), indices.end(), [this](int lhs, int rhs) {
        return latestResults[lhs] < latestResults[rhs];
    });

    return indices;
}

std::vector<int> Rally::getDriversIndicesSortedByWins() const {
    int driversCount = drivers.size();
    auto indices = std::vector<int>();
    indices.reserve(driversCount);

    for (int i = 0; i < driversCount; i++) indices.push_back(i);

    std::sort(indices.begin(), indices.end(), [this](int lhs, int rhs) {
        return drivers[lhs].winsCount > drivers[rhs].winsCount;
    });

    return indices;
}

void Rally::perform(Simulator simulator) {
    latestEditionNumber++;
    latestResults = simulator.simulateResults(drivers);
}
