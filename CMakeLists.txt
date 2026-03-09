cmake_minimum_required(VERSION 3.10)
project(UFC_Simulator)

set(CMAKE_CXX_STANDARD 17)

# List all your .cpp files here
# This tells the compiler to add the 'include' directory to its search path
add_executable(ufc_sim src/main.cpp src/fighter.cpp)

# 2. Link the include directory using the absolute path variable
target_include_directories(ufc_sim PUBLIC ${PROJECT_SOURCE_DIR}/include)
