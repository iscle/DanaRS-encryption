cmake_minimum_required(VERSION 3.21)
project(DanaRS C)

set(CMAKE_C_STANDARD 99)

add_executable(DanaRS main.c crc.c crc.h encrypt.c encrypt.h common.c common.h decrypt.c decrypt.h)
