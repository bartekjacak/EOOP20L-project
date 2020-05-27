#pragma once
#include "driver.hpp"

class DriverTime {
public:
    DriverTime(const Driver &driver, float time);
    ~DriverTime();

    Driver getDriver() const { return _driver; }
    float getTime() const { return _time; }

    // Overloading the comparison operators
    friend bool operator==(const DriverTime& lhs, const DriverTime& rhs);
    friend bool operator!=(const DriverTime& lhs, const DriverTime& rhs);
    friend bool operator>(const DriverTime& lhs, const DriverTime& rhs);
    friend bool operator>=(const DriverTime& lhs, const DriverTime& rhs);
    friend bool operator<(const DriverTime& lhs, const DriverTime& rhs);
    friend bool operator<=(const DriverTime& lhs, const DriverTime& rhs);

private:
    const Driver &_driver;

    // Time in seconds
    float _time;
};