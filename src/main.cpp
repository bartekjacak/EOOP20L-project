#include <vector>
#include "rally.hpp"
#include "driver.hpp"
#include "simulator.hpp"
#include "game.hpp"

int main(int argc, char** argv) {
    std::vector<Driver> drivers = {
        Driver("John Doe"),
        Driver("James Kowalsky"),
        Driver("James White")
    };
    Rally rally("Monte Carlo", drivers);
    Simulator simulator;
    Game game(rally, simulator);

    game.start();

    return 0;
}
