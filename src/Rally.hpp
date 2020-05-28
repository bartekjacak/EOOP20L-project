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

    Rally(const std::string& name_, const std::vector<Driver>& drivers_);
    [[nodiscard]] std::vector<int> getSortedResultsIndices() const;
    [[nodiscard]] Driver getDriver(int index) const;

    // Performs a simulation using simulator and returns finished edition
    void perform(const Simulator& simulator);
};