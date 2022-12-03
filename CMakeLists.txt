cmake_minimum_required(VERSION 3.23)
project(Student)

set(CMAKE_CXX_STANDARD 14)

add_executable(Student main.cpp Student.h Student.cpp Login.h Login.cpp Window.h Window.cpp)
