cmake_minimum_required(VERSION 3.4)
project(damas)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    LinkedList.h
    ListaOrdenable.cpp
    ListaOrdenable.h
    Nodo.h
    README.md)

add_executable(damas ${SOURCE_FILES})