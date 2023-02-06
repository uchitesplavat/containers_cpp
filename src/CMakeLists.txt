cmake_minimum_required(VERSION 3.22)
project(containers_cpp C)

set(CMAKE_C_STANDARD 17)

include_directories(..)
include_directories(.)

add_executable(containers_cpp
        vector.h)
