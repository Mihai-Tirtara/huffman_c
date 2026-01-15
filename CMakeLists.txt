cmake_minimum_required(VERSION 3.10)

project(Huffman C)

set(CMAKE_C_STANDARD 11)

add_executable(huffman main.c
        file_encoding_operations.c
        file_encoding_operations.h)
