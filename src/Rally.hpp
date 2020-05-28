#pragma once
#include <vector>
#include "Simulator.hpp"
#include "Driver.hpp"

class Rally {
public:
    const std::string& name;
    const std::vector<Driver>& drivers;

    Rally(const std::string& name_, const std::vector<Driver>& drivers_);

    [[nodiscard]] Driver getDriver(int index) const;

    // Performs a simulation using simulator and returns finished edition
    [[nodiscard]] RallyEdition performNextEdition(const Simulator& simulator) const;
};