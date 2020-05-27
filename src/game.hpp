#pragma once
#include <optional>
#include "rally.hpp"
#include "simulator.hpp"
#include "game.hpp"
#include "ui.hpp"

const int INITIAL_BALANCE = 500;

class Game {
public:
    Game(const Rally& rally, const Simulator& simulator);
    ~Game();

    void start();

private:
    Rally _rally;
    Simulator _simulator;

    // Account balance of the player
    int _balance;
};
