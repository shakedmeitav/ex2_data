cmake_minimum_required(VERSION 3.10.3)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_library(untitled library.cpp library.h Map.cpp Map.h)