#pragma once
#include <optional>
#include "Rally.hpp"
#include "Simulator.hpp"
#include "Game.hpp"
#include "UI.hpp"

class Game {
public:
    Game(Utils::Randomizer randomizer, Rally& _rally, const Bookmaker& bookmaker, int balance);
    void start();

private:
    Rally& _rally;
    const Bookmaker& _bookmaker;
    // Account balance of the player
    int _balance;
    Simulator _simulator;
};
