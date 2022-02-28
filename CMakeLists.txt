cmake_minimum_required(VERSION 3.20)
project(algorithme_structure_donnee)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(algorithme_structure_donnee
        GrapheMatrice/GrapheMatrice.cpp
        GrapheMatrice/GrapheMatrice.h
        main.cpp GrapheListe/GrapheListe.cpp GrapheListe/GrapheListe.h)
