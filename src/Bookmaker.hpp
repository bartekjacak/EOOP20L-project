#pragma once
#include <optional>
#include "Driver.hpp"
#include "RallyEdition.hpp"

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
    static Bet makeBet(int amount, const Driver& driver) ;
    // Get the payoff
    static Payoff getPayoff(const Bet& bet, const RallyEdition& edition);
};