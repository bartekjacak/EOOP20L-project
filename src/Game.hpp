#pragma once
#include <optional>
#include "Rally.hpp"
#include "Simulator.hpp"
#include "Game.hpp"
#include "UI.hpp"

class Game {
public:
    Game(const Rally& rally, const Simulator& simulator, int balance);
    void start();

private:
    Rally _rally;
    Simulator _simulator;
    // Account balance of the player
    int _balance;
};
