cmake_minimum_required(VERSION 3.22.2)
project(cpu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(R6502_SRC
    R6502/R6502.cpp
    R6502/R6502.h)

add_library(R6502 ${R6502_SRC})
add_library(cpu::R6502 ALIAS R6502) 
target_link_libraries(R6502
    PRIVATE )   

add_subdirectory(test)