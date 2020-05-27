#include "rallyEdition.hpp"

RallyEdition::RallyEdition(unsigned int number, std::vector<DriverTime> results):
    _number(number), _results(results) {};
RallyEdition::~RallyEdition() = default;

std::vector<DriverTime> RallyEdition::getOrderedResults() const {
    return _results;
};