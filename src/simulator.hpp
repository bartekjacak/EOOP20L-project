#pragma once
#include <vector>
#include "rallyEdition.hpp"
#include "driver.hpp"

class Simulator {
public:
    Simulator();

    // Simulates drivers' performance on a single edition
    RallyEdition simulateRallyEdition(unsigned int editionNumber, const std::vector<Driver> &drivers);
};