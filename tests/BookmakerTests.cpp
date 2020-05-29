#include <vector>
#include <chrono>
#include "gtest/gtest.h"
#include "../src/Driver.hpp"
#include "../src/DriverTime.hpp"
#include "../src/Bookmaker.hpp"

using namespace std::chrono_literals;

class BookmakerTests : public ::testing::Test {
protected:
    BookmakerTests():
        bookmaker(),
        betAmount(100),
        driverA("Mike Scott"),
        driverB("Robert Kubica"),
        resultA(driverA, 100s),
        resultB(driverB, 200s) {}

    Bookmaker bookmaker;
    int betAmount;
    Driver driverA;
    Driver driverB;
    DriverTime resultA;
    DriverTime resultB;
};

TEST_F (BookmakerTests, makeBet) {
    auto bet = bookmaker.makeBet(betAmount, driverA);

    ASSERT_EQ(bet.amount, betAmount);
    ASSERT_EQ(bet.driver.name, driverA.name);
}

TEST_F (BookmakerTests, getPayoff_WhenWinning) {
    std::vector<Driver> drivers = { driverA, driverB };
    auto rally = Rally("A", drivers);
    rally.latestResults.push_back(resultA);
    rally.latestResults.push_back(resultB);

    auto bet = bookmaker.makeBet(betAmount, driverA);
    auto payoff = bookmaker.getPayoff(bet, rally);

    EXPECT_TRUE(payoff.value >= betAmount);
}

TEST_F (BookmakerTests, getPayoff_WhenLosing) {
    std::vector<Driver> drivers = { driverA, driverB };
    auto rally = Rally("A", drivers);
    rally.latestResults.push_back(resultA);
    rally.latestResults.push_back(resultB);

    auto bet = bookmaker.makeBet(betAmount, driverB);
    auto payoff = bookmaker.getPayoff(bet, rally);

    EXPECT_EQ(payoff.value, -betAmount);
}
