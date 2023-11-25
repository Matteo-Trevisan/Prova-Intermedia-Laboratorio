cmake_minimum_required(VERSION 2.8)
project(Prova_Intermedia)

set(CMAKE_CXX_STANDARD 11)

add_executable(Prova_Intermedia
        src/main.cpp
        src/BookShelf.cpp
        include/BookShelf.h
        src/Book.cpp
        include/Book.h
        src/Date.cpp
        include/Date.h
)
