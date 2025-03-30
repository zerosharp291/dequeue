cmake_minimum_required(VERSION 3.30)
project(dequeue)

set(CMAKE_CXX_STANDARD 20)

add_executable(dequeue main.cpp
        include/dequeue.cpp
        include/dequeue.h)
