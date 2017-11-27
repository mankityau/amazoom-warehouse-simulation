cmake_minimum_required(VERSION 3.2)
project(amazoom-warehouse-simulation)

include_directories(lib)

# access to src/ files for tests
include_directories(src)

add_subdirectory(src)
add_subdirectory(test)