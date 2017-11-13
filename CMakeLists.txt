cmake_minimum_required(VERSION 3.8)
project(pr5_eedd)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Diccionario.cpp Diccionario.h Palabra.cpp Palabra.h Sucesor.h Sucesor.cpp VDinamico.h ListaEnlazada.h AVL.cpp AVL.h)
add_executable(pr5_eedd ${SOURCE_FILES})