#include "Rally.hpp"

Rally::Rally(const std::string& name_, const std::vector<Driver>& drivers_):
    name(name_), drivers(drivers_), latestResults(), latestEditionNumber(0) {};

Driver Rally::getDriver(int index) const {
//    if (index < 1 || index > _drivers.size()) {
//        return std::nullopt;
//        throw
//    }

    return drivers.at(index - 1);
};

std::vector<int> Rally::getSortedResultsIndices() const {
    int resultsSize = latestResults.size();
    auto indices = std::vector<int>();

    indices.reserve(resultsSize);
    for (int i = 0; i < resultsSize; i++) indices.push_back(i);

    std::sort(indices.begin(), indices.end(), [this](int lhs, int rhs) {
        return latestResults[lhs] < latestResults[rhs];
    });

    return indices;
};


void Rally::perform(const Simulator& simulator) {
    latestEditionNumber++;
    latestResults = simulator.simulateResults(drivers);
}
