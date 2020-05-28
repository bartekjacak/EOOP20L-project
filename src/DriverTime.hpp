#pragma once
#include <chrono>
#include "Driver.hpp"

class DriverTime {
public:
    const Driver& driver;

    DriverTime(const Driver& driver_, std::chrono::duration<int> time);
    [[nodiscard]] int getTime() const;

    // Overloading the comparison operators
    friend bool operator==(const DriverTime& lhs, const DriverTime& rhs);
    friend bool operator!=(const DriverTime& lhs, const DriverTime& rhs);
    friend bool operator>(const DriverTime& lhs, const DriverTime& rhs);
    friend bool operator>=(const DriverTime& lhs, const DriverTime& rhs);
    friend bool operator<(const DriverTime& lhs, const DriverTime& rhs);
    friend bool operator<=(const DriverTime& lhs, const DriverTime& rhs);

private:
    std::chrono::duration<int> _time;
};