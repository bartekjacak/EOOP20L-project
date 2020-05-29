#include "gtest/gtest.h"
#include "../src/Driver.hpp"

using namespace std::chrono_literals;

class DriverTests : public ::testing::Test {
protected:
    DriverTests():
        driverA("Mike Scott"),
        driverB("Robert Kubica") {}

    Driver driverA;
    Driver driverB;
};

TEST_F (DriverTests, operators) {
    EXPECT_TRUE(driverB == driverB);
    EXPECT_TRUE(driverA != driverB);
}