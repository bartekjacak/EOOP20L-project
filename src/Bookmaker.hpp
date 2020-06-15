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
    // Create new bet
    [[nodiscard]] Bet makeBet(int amount, const Driver& driver) const;
    // Get the payoff
    [[nodiscard]] Payoff getPayoff(const Bet& bet, const Rally& rally) const;

private:
    // Used to calculate the payoff, all possibilities based on drivers wins
    [[nodiscard]] double getAllPossibilities(const std::vector<Driver>& drivers) const;
};