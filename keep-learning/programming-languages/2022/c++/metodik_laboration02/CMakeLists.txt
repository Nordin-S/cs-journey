cmake_minimum_required(VERSION 3.23)
project(metodik_laboration02)

set(CMAKE_CXX_STANDARD 17)

add_executable(metodik_laboration02 main.cpp Shape.cpp Shape.h Rectangle.cpp Rectangle.h Parallelepiped.cpp Parallelepiped.h RoundedRect.cpp RoundedRect.h Circle.cpp Circle.h Cylinder.cpp Cylinder.h)
