#pragma once
#include <string>

class Driver {
public:
    const std::string& name;
    mutable int winsCount;

    explicit Driver(const std::string& name_, int winsCount_ = 0);

    // Overloading the comparison operators
    friend bool operator==(const Driver& lhs, const Driver& rhs);
    friend bool operator!=(const Driver& lhs, const Driver& rhs);
};

