cmake_minimum_required(VERSION 3.2)
project(amazoom-warehouse-simulation)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

include_directories(lib)

# access to src/ files for tests
include_directories(src)

add_subdirectory(src)
add_subdirectory(test)