#include "Game.hpp"

Game::Game(const Rally& rally, const Simulator& simulator, int balance):
    _rally(rally), _simulator(simulator), _balance(balance) {};

void Game::start() {
    // Main loop
    while (true) {
        auto homeScreen = UI::HomeScreen(_rally, _balance);
        auto bet = homeScreen.display();

        _rally.perform(_simulator);
        auto payoff = Bookmaker::getPayoff(bet, _rally);

        auto resultsScreen = UI::ResultsScreen(_rally, payoff);
        resultsScreen.display();
    };
}