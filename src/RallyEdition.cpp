#include "RallyEdition.hpp"

RallyEdition::RallyEdition(int number, const std::vector<DriverTime>& results):
    _number(number), _results(results) {};

std::vector<DriverTime> RallyEdition::getOrderedResults() const {
    return _results;
};