#pragma once
#include <string>

class Driver {
public:
    Driver(std::string name);
    ~Driver();

    std::string getName() const { return _name; };

    // Overloading the comparison operators
    friend bool operator==(const Driver& lhs, const Driver& rhs);
    friend bool operator!=(const Driver& lhs, const Driver& rhs);

private:
    const std::string _name;
};