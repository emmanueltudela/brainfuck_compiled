cmake_minimum_required(VERSION 3.30)

enable_testing()

project(brainfuck_compiled)

include(CTest)

set(SOURCES src/compile.c src/brainfuck.c src/linked_list.c src/linked_list_aux.c)

add_compile_options(-std=c99 -Wall -g)
include_directories(include)

add_executable(main src/main.c ${SOURCES})
