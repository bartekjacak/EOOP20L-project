#include "driverTime.hpp"

DriverTime::DriverTime(const Driver &driver, float time):
    _driver(driver), _time(time) {};
DriverTime::~DriverTime() = default;

