cmake_minimum_required(VERSION 3.15)
project(monte_carlo_rally)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "\
    ${CMAKE_CXX_FLAGS} \
    -Wall \
    -Wextra \
    -Wpedantic \
    -pedantic-errors \
    -fsanitize=undefined \
")

#    -fsanitize=address \

#-Werror

include_directories(.)
include_directories(src)
include_directories(tests)

add_executable(monte_carlo_rally
        src/Bookmaker.hpp
        src/Driver.hpp
        src/DriverTime.hpp
        src/Game.cpp
        src/Game.hpp
        src/main.cpp
        src/Rally.cpp
        src/Rally.hpp
        src/Simulator.cpp
        src/Simulator.hpp
        src/Bookmaker.cpp
        src/DriverTime.cpp
        src/UI.cpp
        src/UI.hpp src/Utils.hpp src/Utils.cpp src/Driver.cpp)


# Library for terminal tables
set(FORT_ENABLE_TESTING OFF CACHE INTERNAL "") # Disable building tests and examples
add_subdirectory(third-party/libfort)
target_link_libraries(monte_carlo_rally PRIVATE fort)

