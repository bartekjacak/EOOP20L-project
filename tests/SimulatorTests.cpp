#include <vector>
#include "gtest/gtest.h"
#include "../src/Utils.hpp"
#include "../src/Simulator.hpp"
#include "../src/Driver.hpp"
#include "../src/DriverTime.hpp"

using namespace std::chrono_literals;

class SimulatorTests : public ::testing::Test {
protected:
    SimulatorTests():
        nameA("Mike Scott"),
        nameB("Robert Kubica"),
        nameC("Diego Asan"),
        drivers({Driver(nameA), Driver(nameB), Driver(nameC)}) {}

    std::string nameA;
    std::string nameB;
    std::string nameC;
    std::vector<Driver> drivers;
};

TEST_F (SimulatorTests, simulateResults) {
    auto seed = 1;
    auto randomizer = Utils::Randomizer(seed);
    auto simulator = Simulator(randomizer);

    auto results = simulator.simulateResults(drivers);
    std::vector<DriverTime> expectedResults = {
        DriverTime(drivers[0], std::chrono::duration<int>(1)),
        DriverTime(drivers[1], std::chrono::duration<int>(2)),
        DriverTime(drivers[2], std::chrono::duration<int>(3))
    };

    auto timesSum = results[0].getTime() + results[1].getTime() + results[2].getTime();

    EXPECT_EQ(results[0].driver, expectedResults[0].driver);
    EXPECT_EQ(results[1].driver, expectedResults[1].driver);
    EXPECT_EQ(results[2].driver, expectedResults[2].driver);
    EXPECT_TRUE(timesSum > 0);
}
