#!/bin/sh

cmake -Bcmake-build-debug -H.
cmake --build cmake-build-debug --target monte_carlo_bets_tests
./cmake-build-debug/tests/monte_carlo_bets_tests