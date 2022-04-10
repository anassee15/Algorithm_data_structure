cmake_minimum_required(VERSION 3.20)
project(algorithme_structure_donnee)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(algorithme_structure_donnee
        GrapheListe/GrapheListe.cpp
        GrapheListe/GrapheListe.h
        GrapheMatrice/GrapheMatrice.cpp
        GrapheMatrice/GrapheMatrice.h
        File_priorite/PriorityQueue.cpp
        File_priorite/PriorityQueue.h
        Tools/Conversion.h
        main.cpp Tools/Conversion.h)
