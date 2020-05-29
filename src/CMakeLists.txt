project(${CMAKE_PROJECT_NAME})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#set(Files
#    main.cpp
#    Bookmaker.hpp
#    Driver.hpp
#    DriverTime.hpp
#    Game.cpp
#    Game.hpp
#    Rally.cpp
#    Rally.hpp
#    Simulator.cpp
#    Simulator.hpp
#    Bookmaker.cpp
#    DriverTime.cpp
#    UI.cpp
#    UI.hpp
#    Utils.hpp
#    Utils.cpp
#    Driver.cpp
#)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.hpp *.cpp)
set(SOURCES ${SOURCES})
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE fort)