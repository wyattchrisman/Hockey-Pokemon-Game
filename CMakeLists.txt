cmake_minimum_required(VERSION 3.23)
project(M2OEP_wchrisma)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(M2OEP_wchrisma
        main.cpp
        Player.h
)
