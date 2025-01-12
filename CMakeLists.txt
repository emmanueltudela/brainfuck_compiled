cmake_minimum_required(VERSION 3.30)

enable_testing()

project(brainfuck_compiled)

include(CTest)

set(SOURCES "")

add_executable(main src/main.c ${SOURCES})

add_compile_options(-std=c99 -Wall -g)
include_directories(include)
