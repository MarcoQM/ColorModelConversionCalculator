cmake_minimum_required(VERSION 3.5)

project(ColorCalculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ColorCalculator RGB.h CMYK.h HSV.h HSL.h XYZ.h LAB.h main.cpp)
