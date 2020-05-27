#!/bin/sh

cmake -Bcmake-build-debug -H. && cmake --build cmake-build-debug --target all