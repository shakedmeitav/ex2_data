cmake_minimum_required(VERSION 3.0)
project(ex2_data)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex2_data
        Exception.h
        library.cpp
        library.h
        main.cpp
        Map.cpp
        Map.h)
