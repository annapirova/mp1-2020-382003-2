cmake_minimum_required(VERSION 3.17)
project(LinAl_vector__matrix_)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinAl_vector__matrix_ main.cpp Vector.cpp Vector.h Matrix.cpp Matrix.h Solver.cpp Solver.h)