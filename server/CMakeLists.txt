cmake_minimum_required(VERSION 3.21)

project(server)

add_executable(server)

target_sources(server
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/server.cpp
)

target_include_directories(server
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include)