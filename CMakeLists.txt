cmake_minimum_required(VERSION 3.23)
project(M2OEP_wchrisma)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Main
        main.cpp
        Player.h
)
add_executable(Testing
        Testing.cpp
        Player.cpp
        Normal.cpp
        Sniper.cpp
        Playmaker.cpp
        Fighter.cpp
        Veteran.cpp
)