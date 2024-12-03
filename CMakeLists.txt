cmake_minimum_required(VERSION 3.27)
project(COP3530_Project3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(COP3530_Project3
        csvreader.cpp
        csvreader.h
        location.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        sorter.cpp
        sorter.h
        sortingbuttons.cpp
        sortingbuttons.h
        table.cpp
        table.h)
