cmake_minimum_required(VERSION 3.15)
project(monte_carlo_rally)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS)

include_directories(.)
include_directories(src)
include_directories(tests)

add_executable(monte_carlo_rally
        src/bookmaker.hpp
        src/driver.hpp
        src/driver.cpp
        src/driverTime.hpp
        src/game.cpp
        src/game.hpp
        src/main.cpp
        src/rally.cpp
        src/rally.hpp
        src/rallyEdition.cpp
        src/rallyEdition.hpp
        src/simulator.cpp
        src/simulator.hpp
        src/bookmaker.cpp
        src/driverTime.cpp
        src/ui.cpp
        src/ui.hpp)

set(ADDITIONAL_WARNINGS "\
        -Wall \
        -Wextra \
        -Wdouble-promotion \
        -Wshadow \
        -Wformat=2 \
        -Wno-variadic-macros \
        -Wcast-align \
        -Wstrict-aliasing=2 \
        -Wstrict-overflow=5 \
        -Wfloat-equal \
        -Wwrite-strings \ ")

# Disable building tests and examples in libfort project
set(FORT_ENABLE_TESTING OFF CACHE INTERNAL "")

# Library for terminal tables
add_subdirectory(third-party/libfort)
target_link_libraries(monte_carlo_rally PRIVATE fort)