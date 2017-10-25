cmake_minimum_required(VERSION 3.2)
project(amazoom-warehouse-simulation)

include_directories(library/include)

# access to src/ files for tests
include_directories(src)

add_executable(helloworld src/helloworld.cpp)