#include "DriverTime.hpp"

DriverTime::DriverTime(const Driver& driver_, std::chrono::duration<int> time):
    driver(driver_), _time(time) {}

int DriverTime::getTime() const {
    return _time.count();
}

bool operator<(const DriverTime& lhs, const DriverTime& rhs) {
    return lhs._time < rhs._time;
}