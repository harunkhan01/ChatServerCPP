cmake_minimum_required(VERSION 3.21)

project(client)

add_executable(client)

target_sources(client
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/client.cpp
)

target_include_directories(client
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include)