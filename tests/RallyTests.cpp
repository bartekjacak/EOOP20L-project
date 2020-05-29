#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/Driver.hpp"
#include "../src/DriverTime.hpp"
#include "../src/Rally.hpp"

using namespace std::chrono_literals;

class RallyTests : public ::testing::Test {
protected:
    RallyTests():
        nameA("Mike Scott"),
        nameB("Robert Kubica"),
        nameC("Diego Asan"),
        drivers({Driver(nameA), Driver(nameB), Driver(nameC)}),
        rally("A", drivers)
    {
        rally.latestResults.push_back({drivers[0], 100s});
        rally.latestResults.push_back({drivers[1], 200s});
        rally.latestResults.push_back({drivers[2], 50s});
    }

    std::string nameA;
    std::string nameB;
    std::string nameC;
    std::vector<Driver> drivers;
    Rally rally;
};

TEST_F (RallyTests, getSortedResultsIndices) {
    auto sortedResults = rally.getSortedResultsIndices();
    std::vector<int> expectedResults = { 2, 0, 1 };

    EXPECT_EQ(sortedResults, expectedResults);
}

TEST_F (RallyTests, getDriver_withValidId) {
    auto index = 1;
    auto driver = rally.getDriver(index);

    EXPECT_EQ(driver.name, drivers[index - 1].name);
}

TEST_F (RallyTests, getDriver_withInvalidId) {
    try {
        auto driver = rally.getDriver(4);
        FAIL() << "Expected some error " << driver.name;
    } catch(Rally::InvalidDriverIdError const &_) {
        EXPECT_TRUE(1);
    } catch(...) {
        FAIL() << "Expected Rally::InvalidDriverIdError ";
    }
}

TEST_F (RallyTests, perform) {
    auto seed = 1;
    auto randomizer = Utils::Randomizer(seed);
    auto simulator = Simulator(randomizer);
    rally.perform(simulator);

    EXPECT_EQ(rally.latestEditionNumber, 1);
}