project(src)

add_executable(helloworld helloworld.cpp)
add_executable(centrolcontroller warehouse/centralcontrollermain.cpp)
add_executable(customerclient customerclient.cpp)

# link with unix realtime library
if(UNIX AND NOT APPLE)
    target_link_libraries(centrolcontroller rt)
    target_link_libraries(customerclient rt)
endif()

if(WIN32)
    target_link_libraries(centrolcontroller wsock32 ws2_32)
    target_link_libraries(customerclient wsock32 ws2_32)

endif()