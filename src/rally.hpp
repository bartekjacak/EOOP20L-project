#pragma once
#include <vector>
#include "simulator.hpp"
#include "driver.hpp"

class Rally {
public:
    Rally(const std::string& name, const std::vector<Driver>& drivers);
    ~Rally();

    [[nodiscard]] Driver getDriver(int index) const;

    // Performs a simulation using simulator and returns finished edition
    [[nodiscard]] RallyEdition performNextEdition(Simulator simulator) const;

    [[nodiscard]] std::string getName() const { return _name; }
    [[nodiscard]] std::vector<Driver> getDrivers() const { return _drivers; }

private:
    std::string _name;
    std::vector<Driver> _drivers;
};