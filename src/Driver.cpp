#include "Driver.hpp"

Driver::Driver(std::string name_, int winsCount_): name(name_), winsCount(winsCount_) {}

bool operator==(const Driver& lhs, const Driver& rhs) {
    return lhs.name == rhs.name;
}