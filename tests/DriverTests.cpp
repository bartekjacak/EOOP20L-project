#include <chrono>
#include "gtest/gtest.h"
#include "../src/Driver.hpp"

using namespace std::chrono_literals;

class DriverTests : public ::testing::Test {
protected:
    DriverTests(): nameA("Mike Scott"), driverA(nameA) {}

    std::string nameA;
    Driver driverA;
};

TEST_F (DriverTests, operators) {
    EXPECT_TRUE(driverA == driverA);
}