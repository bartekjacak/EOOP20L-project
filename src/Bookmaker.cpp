#include "Bookmaker.hpp"

Bet Bookmaker::makeBet(int amount, const Driver& driver) const {
    return Bet(amount, driver);
}

Payoff Bookmaker::getPayoff(const Bet& bet, const Rally& rally) const {
    auto payoff = 0;
    auto xd = rally.getSortedResultsIndices();
    auto lastWinnerIndex = rally.getSortedResultsIndices()[0];
    auto didBetterWin = bet.driver == rally.latestResults[lastWinnerIndex].driver;

    if (didBetterWin) {
        auto allPossibilities = getAllPossibilities(rally.drivers);
        auto winPossibility = 1.0 + bet.driver.winsCount;
        auto ratio = allPossibilities / winPossibility;

        payoff = (bet.amount * ratio) - bet.amount;
    } else {
        payoff = -bet.amount;
    }

    return Payoff(payoff, bet);
}

double Bookmaker::getAllPossibilities(const std::vector<Driver>& drivers) const {
    double possibilities = 0;
    for (const auto& driver: drivers) possibilities += 1.0 + driver.winsCount;

    return possibilities;
}
