#pragma once
#include <vector>
#include "Simulator.hpp"
#include "DriverTime.hpp"
#include "Driver.hpp"

class Rally {
public:
    const std::string& name;
    const std::vector<Driver>& drivers;
    std::vector<DriverTime> latestResults;
    int latestEditionNumber;

    class InvalidDriverIdError: public std::exception {};

    Rally(const std::string& name_, const std::vector<Driver>& drivers_);
    [[nodiscard]] std::vector<int> getSortedResultsIndices() const;
    [[nodiscard]] std::vector<int> getDriversIndicesSortedByWins() const;
    [[nodiscard]] const Driver& getDriver(unsigned long index) const;

    // Performs a simulation using simulator and returns finished edition
    void perform(Simulator simulator);
};