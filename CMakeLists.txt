cmake_minimum_required(VERSION 3.17)
project(2020Sem2_Group104)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(2020Sem2_Group104
        "board information.cpp"
        GameFunction.cpp
        GameFunction.h
        main.cpp
        print.cpp
        print.h)
