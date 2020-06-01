#pragma once
#include <string>

class Driver {
public:
    std::string name;
    mutable int winsCount;

    explicit Driver(std::string name_, int winsCount_ = 0);

    // Overloading the comparison operator
    friend bool operator==(const Driver& lhs, const Driver& rhs);
};

