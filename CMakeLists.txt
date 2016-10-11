cmake_minimum_required(VERSION 3.4)
project(damas)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Integer.cpp
    Integer.h
    LinkedList.h
    ListaOrdenable.cpp
    ListaOrdenable.h
    Nodo.h
    Tablero.cpp
    Tablero.h
    README.md Ficha.cpp Ficha.h main.cpp Casilla.cpp Casilla.h Jugador.cpp Jugador.h)

add_executable(damas ${SOURCE_FILES})