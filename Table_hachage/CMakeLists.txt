cmake_minimum_required(VERSION 3.20)
project(Table_hachage)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Table_hachage
        TableH.cpp
        TableH.h)
