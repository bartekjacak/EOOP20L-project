#include <vector>
#include <string>
#include "Rally.hpp"
#include "Driver.hpp"
#include "Game.hpp"

int main() {
    // Config
    const int INITIAL_BALANCE = 500;
    const std::string RALLY_NAME = "Monte Carlo";
    const std::vector<Driver> DRIVERS = {
        Driver("Bernardi Florian"),
        Driver("Tanak Ott"),
        Driver("Evans Elfyn"),
        Driver("Martin Scott"),
        Driver("Suninen Teemu"),
        Driver("Lehtinen Jarmo"),
        Driver("Lappi Esapekka"),
        Driver("Ferm Janne"),
        Driver("Loeb Sebastien"),
        Driver("Elena Daniel"),
        Driver("Greensmith Gus"),
        Driver("Edmondson Elliott"),
        Driver("Robert Kubica"),
        Driver("Katsuta Takamoto"),
        Driver("Barritt Daniel"),
        Driver("Gryazin Nikolay"),
        Driver("Fedorov Yaroslav"),
        Driver("Veiby Ole Christian"),
        Driver("Andersson Jonas"),
        Driver("Yates Rhys")
    };

    auto randomizer = Utils::Randomizer();
    auto simulator = Simulator(randomizer);
    auto rally = Rally(RALLY_NAME, DRIVERS);
    auto game = Game(rally, simulator, INITIAL_BALANCE);
    game.start();

    return 0;
};
