add_subdirectory(lib/googletest)

add_executable(spacemanager_test reality/spacemanager_test.cpp)
target_link_libraries(spacemanager_test gtest gtest_main)
