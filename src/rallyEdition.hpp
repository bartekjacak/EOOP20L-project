#pragma once
#include <vector>
#include "driverTime.hpp"

class RallyEdition {
public:
    RallyEdition(unsigned int number, std::vector<DriverTime> results);
    ~RallyEdition();

    // Returns drivers' times in ascending order
    std::vector<DriverTime> getOrderedResults() const;

private:
    // Unique edition number
    unsigned int _number;

    // Drivers' times used to calculate each player's place on the scoreboard
    std::vector<DriverTime> _results;
};