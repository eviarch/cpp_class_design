cmake_minimum_required(VERSION 3.26)
project(C__)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")


add_executable(C__ main.cpp
        Student.h
        Student.cpp
        funclib.cpp
        funclib.h
        corefunc.cpp
        corefunc.h
)
