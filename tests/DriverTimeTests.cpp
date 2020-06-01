#include <chrono>
#include "gtest/gtest.h"
#include "../src/DriverTime.hpp"

using namespace std::chrono_literals;

class DriverTimeTests : public ::testing::Test {
protected:
    DriverTimeTests():
        driverA("Mike Scott"),
        driverB("Robert Kubica"),
        resultA(driverA, 100s),
        resultB(driverB, 200s) {}

    Driver driverA;
    Driver driverB;
    DriverTime resultA;
    DriverTime resultB;
};

TEST_F (DriverTimeTests, operators) {
    EXPECT_TRUE(resultA < resultB);
}

TEST_F (DriverTimeTests, getTime) {
    auto resultA = DriverTime(driverA, 1990s);

    EXPECT_EQ(resultA.getTime(), 1990);
}
