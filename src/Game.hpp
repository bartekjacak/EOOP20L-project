#pragma once
#include <optional>
#include "Rally.hpp"
#include "Simulator.hpp"
#include "Game.hpp"
#include "UI.hpp"

class Game {
public:
    Game(Rally rally, Simulator simulator, const Bookmaker& bookmaker, int balance);
    void start();

private:
    Rally _rally;
    Simulator _simulator;
    const Bookmaker& _bookmaker;
    // Account balance of the player
    int _balance;
};
