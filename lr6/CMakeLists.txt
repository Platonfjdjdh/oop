cmake_minimum_required(VERSION 3.27)
project(lr6)

set(CMAKE_CXX_STANDARD 17)

add_executable(lr6
        MazeSolver.cpp
        MazeSolver.h
        main.cpp
        T_cell.h
        T_cell.cpp)
