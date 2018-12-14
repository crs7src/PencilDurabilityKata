cmake_minimum_required(VERSION 3.12)
project(PencilDurabilityKata)

set(CMAKE_CXX_STANDARD 14)

add_executable(PencilDurabilityKata_run main.cpp Pencil.cpp Pencil.h)
add_subdirectory(tests)