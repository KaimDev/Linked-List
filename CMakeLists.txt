cmake_minimum_required(VERSION 3.24)

project(LinkedList C)

add_executable(program Main.c)

target_compile_features(program PUBLIC c_std_17)