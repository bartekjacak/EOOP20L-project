enable_testing()

project(${CMAKE_PROJECT_NAME}_tests)

add_subdirectory("../third-party/googletest" "../third-party/googletest")

set(TEST_SOURCES
    main.cpp
    BookmakerTests.cpp
    DriverTests.cpp
    DriverTimeTests.cpp
    RallyTests.cpp
    SimulatorTests.cpp
    ../src/Bookmaker.hpp
    ../src/Driver.hpp
    ../src/DriverTime.hpp
    ../src/Rally.cpp
    ../src/Rally.hpp
    ../src/Simulator.cpp
    ../src/Simulator.hpp
    ../src/Bookmaker.cpp
    ../src/DriverTime.cpp
    ../src/Utils.hpp
    ../src/Utils.cpp
    ../src/Driver.cpp
)

add_executable(${CMAKE_PROJECT_NAME}_tests ${TEST_SOURCES} ${SOURCES})
add_test(NAME ${CMAKE_PROJECT_NAME}_tests COMMAND ${CMAKE_PROJECT_NAME})
target_link_libraries(${CMAKE_PROJECT_NAME}_tests PUBLIC gtest gmock fort)