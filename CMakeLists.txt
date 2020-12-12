cmake_minimum_required(VERSION 3.17)
project(GA_Folding)

set(CMAKE_CXX_STANDARD 14)

add_executable(GA_Folding main.cpp Solution.cpp Solution.h Population.cpp Population.h)