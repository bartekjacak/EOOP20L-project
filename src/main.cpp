#include <locale.h>
#include <vector>
#include <string>
#include "Rally.hpp"
#include "Driver.hpp"
#include "Game.hpp"

int main() {
    setlocale(LC_CTYPE, "");

    // Config
    const int INITIAL_BALANCE = 500;
    const std::string RALLY_NAME = "Monte Carlo";
    const std::vector<std::string> DRIVER_NAMES = {
        "Bernardi Florian",
        "Tanak Ott",
        "Evans Elfyn",
        "Martin Scott",
        "Suninen Teemu",
        "Lehtinen Jarmo",
        "Lappi Esapekka",
        "Ferm Janne",
        "Loeb Sebastien",
        "Elena Daniel",
        "Greensmith Gus",
        "Edmondson Elliott",
        "Robert Kubica",
        "Katsuta Takamoto",
        "Barritt Daniel",
        "Gryazin Nikolay",
        "Fedorov Yaroslav",
        "Veiby Ole Christian",
        "Andersson Jonas",
        "Yates Rhys"
    };

    auto drivers = std::vector<Driver>();
    drivers.reserve(DRIVER_NAMES.size());
    for (const auto& name: DRIVER_NAMES) {
        drivers.emplace_back(name);
    }

    auto randomizer = Utils::Randomizer();
    auto simulator = Simulator(randomizer);
    auto bookmaker = Bookmaker();
    auto rally = Rally(RALLY_NAME, drivers);
    auto game = Game(rally, simulator, bookmaker, INITIAL_BALANCE);
    game.start();

    return 0;
}
