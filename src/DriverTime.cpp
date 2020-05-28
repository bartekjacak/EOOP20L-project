#include "DriverTime.hpp"

DriverTime::DriverTime(const Driver& driver_, std::chrono::duration<int> time_):
    driver(driver_), time(time_) {};

bool operator==(const DriverTime& lhs, const DriverTime& rhs) {
    return lhs.time == rhs.time;
}

bool operator!=(const DriverTime& lhs, const DriverTime& rhs) {
    return lhs.time != rhs.time;
}

bool operator>(const DriverTime& lhs, const DriverTime& rhs) {
    return lhs.time > rhs.time;
}

bool operator>=(const DriverTime& lhs, const DriverTime& rhs) {
    return lhs.time >= rhs.time;
}

bool operator<(const DriverTime& lhs, const DriverTime& rhs) {
    return lhs.time < rhs.time;
}

bool operator<=(const DriverTime& lhs, const DriverTime& rhs) {
    return lhs.time <= rhs.time;
}