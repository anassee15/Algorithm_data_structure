cmake_minimum_required(VERSION 3.20)
project(Nouveau_dossier)

set(CMAKE_CXX_STANDARD 14)

include_directories(GrapheListe)
include_directories(GrapheMatrice)

add_executable(Nouveau_dossier
        GrapheListe/GrapheListe.cpp
        GrapheListe/GrapheListe.h
        GrapheMatrice/GrapheMatrice.cpp
        GrapheMatrice/GrapheMatrice.h
        main.cpp)
