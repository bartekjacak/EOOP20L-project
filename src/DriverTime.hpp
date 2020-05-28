#pragma once
#include <chrono>
#include "Driver.hpp"

class DriverTime {
public:
    const Driver& driver;
    std::chrono::duration<int> time;

    DriverTime(const Driver& driver_, std::chrono::duration<int> time_);

    // Overloading the comparison operators
    friend bool operator==(const DriverTime& lhs, const DriverTime& rhs);
    friend bool operator!=(const DriverTime& lhs, const DriverTime& rhs);
    friend bool operator>(const DriverTime& lhs, const DriverTime& rhs);
    friend bool operator>=(const DriverTime& lhs, const DriverTime& rhs);
    friend bool operator<(const DriverTime& lhs, const DriverTime& rhs);
    friend bool operator<=(const DriverTime& lhs, const DriverTime& rhs);
};