cmake_minimum_required(VERSION 3.14)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++14")

add_executable(GeneticAlgorithm main.cpp constants.hpp city.cpp city.hpp cities.cpp cities.hpp)