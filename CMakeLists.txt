cmake_minimum_required(VERSION 3.17)
project(SudokuCPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(SudokuCPP main.cpp SudokuSolver.cpp Sudoku.cpp)