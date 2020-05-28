#include "Bookmaker.hpp"

Bet Bookmaker::makeBet(int amount, const Driver &driver) {
    return Bet(amount, driver);
}

Payoff Bookmaker::getPayoff(const Bet& _bet, const Rally& rally) {
    return Payoff(_bet.amount, _bet);
};