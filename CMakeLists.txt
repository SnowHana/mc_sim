cmake_minimum_required(VERSION 3.10)
project(UFC_Simulator)

# Use C++17 for those nice features!
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Define the include directory once
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

# 2. THE MAIN SIMULATOR
# We combine the logic (fighter.cpp) with the main entry point
add_executable(ufc_sim src/main.cpp src/fighter.cpp)
target_include_directories(ufc_sim PUBLIC ${INCLUDE_DIR})

# 3. THE TEST SUITE
# We combine the SAME logic (fighter.cpp) with the test entry point
add_executable(run_tests tests/test_fight_v1.cpp src/fighter.cpp)
target_include_directories(run_tests PUBLIC ${INCLUDE_DIR})