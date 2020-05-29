#include "Game.hpp"

Game::Game(Rally rally, Simulator simulator, const Bookmaker& bookmaker, int balance):
    _rally(rally), _simulator(simulator), _bookmaker(bookmaker), _balance(balance) {}

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

//   for (auto i = 0; i < 10000; i++) {
//        _rally.perform(_simulator);
//    };
//
//     auto homeScreen1 = UI::HomeScreen(_rally, _balance, _bookmaker);
//     homeScreen1.display();

}