cmake_minimum_required(VERSION 3.22.2)
project(6502_test)

include(GoogleTest)

find_package(GTest)
find_package(benchmark)

set(R6502_TEST_SRC
    R6502/basic.cpp)

add_executable(R6502_test ${R6502_TEST_SRC})

target_link_libraries(R6502_test
    GTest::GTest
    cpu::R6502)

gtest_discover_tests(R6502_test)