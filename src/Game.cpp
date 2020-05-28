#include "Game.hpp"

Game::Game(const Rally& rally, const Simulator& simulator, int balance):
    _rally(rally), _simulator(simulator), _balance(balance) {};

void Game::start() {
    // Main loop
    while (true) {
        auto homeScreen = UI::HomeScreen(_rally, _balance);
        auto bet = homeScreen.display();

        auto currentEdition = _rally.performNextEdition(_simulator);
        auto results = currentEdition.getOrderedResults();
        auto payoff = Bookmaker::getPayoff(bet, currentEdition);

        auto resultsScreen = UI::ResultsScreen(currentEdition, payoff);
        resultsScreen.display();
    };
}