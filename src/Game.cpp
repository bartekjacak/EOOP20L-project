#include "Game.hpp"

Game::Game(Utils::Randomizer randomizer, Rally& rally, const Bookmaker& bookmaker, int balance):
    _rally(rally), _bookmaker(bookmaker), _balance(balance), _simulator{randomizer} {}

void Game::start() {
    // Main loop
    while (true) {
        auto homeScreen = UI::HomeScreen(_rally, _balance, _bookmaker);
        auto bet = homeScreen.display();

        _rally.perform(_simulator);
        auto payoff = _bookmaker.getPayoff(bet, _rally);

        _balance += payoff.value;

        auto resultsScreen = UI::ResultsScreen(_rally, payoff);
        resultsScreen.display();
    }
}