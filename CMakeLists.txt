cmake_minimum_required(VERSION 3.27)
project(LowBudgetSpotify)

set(CMAKE_CXX_STANDARD 17)

add_executable(LowBudgetSpotify main.cpp
        user.h
        playlist.h
        song.h
        user.cpp
        playlist.cpp
        song.cpp
        app.h
        app.cpp
        utils.cpp
        utils.h)
