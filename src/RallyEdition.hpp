#pragma once
#include <vector>
#include "DriverTime.hpp"

class RallyEdition {
public:
    RallyEdition(int number, const std::vector<DriverTime>& results);

    // Returns drivers' times in ascending order
    [[nodiscard]] std::vector<DriverTime> getOrderedResults() const;

private:
    // Unique edition number
    unsigned int _number;

    // Drivers' times used to calculate each player's place on the scoreboard
    std::vector<DriverTime> _results;
};