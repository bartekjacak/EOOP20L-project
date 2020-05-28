#include "DriverTime.hpp"

DriverTime::DriverTime(const Driver& driver_, std::chrono::duration<int> time_):
    driver(driver_), time(time_) {};

