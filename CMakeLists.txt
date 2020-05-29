cmake_minimum_required(VERSION 3.8)

project(monte_carlo_bets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_FLAGS "\
    ${CMAKE_CXX_FLAGS} \
    -Wall \
    -Wextra \
    -Wpedantic \
    -pedantic-errors \
    -fsanitize=undefined \
    -Werror \
")

add_subdirectory(src)
add_subdirectory(tests)

# Library for terminal tables
set(FORT_ENABLE_TESTING OFF CACHE INTERNAL "") # Disable building tests and examples
add_subdirectory("third-party/libfort")
