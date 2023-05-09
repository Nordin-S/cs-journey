cmake_minimum_required(VERSION 3.21)
project(laboration01)

set(CMAKE_CXX_STANDARD 14)

add_executable(laboration01 main.cpp reader.cpp reader.h adjToMatrix.cpp adjToMatrix.h dfs.cpp dfs.h findNotVisited.cpp findNotVisited.h bfs.cpp bfs.h dijkstras.cpp dijkstras.h CONSTANTS.h)
