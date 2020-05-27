#include "simulator.hpp"

Simulator::Simulator() {};

RallyEdition Simulator::simulateRallyEdition(unsigned int editionNumber, const std::vector<Driver> &drivers) {
    std::vector<DriverTime> times;

    times.reserve(drivers.size());
    for (auto const &driver: drivers) {
        times.emplace_back(driver, 12);
    }

    return RallyEdition(editionNumber, times);
};
