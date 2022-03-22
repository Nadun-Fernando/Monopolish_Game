cmake_minimum_required(VERSION 3.19)
project(CO2402Assignment)

set(CMAKE_CXX_STANDARD 14)

add_executable(CO2402Assignment main.cpp CSquare.cpp CSquare.h Player.cpp Player.h Properties.cpp Properties.h FileOperations.cpp FileOperations.h UserInterface.cpp UserInterface.h rlutil.h)