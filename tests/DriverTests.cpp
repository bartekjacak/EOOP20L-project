#include <chrono>
#include "gtest/gtest.h"
#include "../src/Driver.hpp"

using namespace std::chrono_literals;

class DriverTests : public ::testing::Test {
protected:
    DriverTests():
        nameA("Mike Scott"),
        nameB("Robert Kubica"),
        driverA(nameA),
        driverB(nameB) {}

    std::string nameA;
    std::string nameB;
    Driver driverA;
    Driver driverB;
};

TEST_F (DriverTests, operators) {
    EXPECT_TRUE(driverB == driverB);
    EXPECT_TRUE(driverA != driverB);
}