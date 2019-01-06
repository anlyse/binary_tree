cmake_minimum_required(VERSION 3.11)
project(binary_tree)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(binary_tree
        binary_tree.hpp
        binary_tree.h
        main.cpp
        tree_node.h)
