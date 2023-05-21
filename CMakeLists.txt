cmake_minimum_required(VERSION 3.0)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_definitions(-DUNICODE -D_UNICODE)

project(tcp_friend)
include_directories(src)

message("----------------------------------------------")
message("-- CMake       ${CMAKE_VERSION}")
message("-- Build       ${CMAKE_SYSTEM_NAME}")
message("----------------------------------------------")

set(TARGET_NAME ${PROJECT_NAME})

add_executable(
    example_client
    
    examples/example_client.cpp
    
    src/tcp_friend.hpp
    src/tcp_friend.cpp
)

add_executable(
    example_server
    
    examples/example_server.cpp
    
    src/tcp_friend.hpp
    src/tcp_friend.cpp
)
