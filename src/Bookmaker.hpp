#pragma once
#include <optional>
#include "Driver.hpp"
#include "Rally.hpp"

struct Bet {
    const int amount;
    const Driver& driver;

    Bet(int amount_, const Driver &driver_): amount(amount_), driver(driver_) {};
};

struct Payoff {
    int value;
    const Bet& bet;

    Payoff(int value_, const Bet& bet_): value(value_), bet(bet_) {};
};

class Bookmaker {
public:
    Bookmaker() = default;

    // Create new bet
    Bet makeBet(int amount, const Driver& driver) const;
    // Get the payoff
    Payoff getPayoff(const Bet& bet, const Rally& rally) const;

private:
    double getAllPossibilities(const std::vector<Driver>& drivers) const;
};