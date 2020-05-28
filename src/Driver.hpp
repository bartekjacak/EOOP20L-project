#pragma once
#include <string>

class Driver {
public:
    const std::string& name;

    explicit Driver(const std::string& name_): name(name_) {};

    // Overloading the comparison operators
    friend bool operator==(const Driver& lhs, const Driver& rhs);
    friend bool operator!=(const Driver& lhs, const Driver& rhs);
};