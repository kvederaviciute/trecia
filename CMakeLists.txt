cmake_minimum_required(VERSION 3.10)

project(v1.0vector)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(v1.0 ${SOURCES})

target_include_directories(v1.0 PRIVATE "${CMAKE_SOURCE_DIR}/include")
