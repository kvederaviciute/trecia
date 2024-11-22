cmake_minimum_required(VERSION 3.10)

project(StudentProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS_DEBUG "/Zi")
set(CMAKE_CXX_FLAGS_RELEASE "/01")

add_executable(${PROJECT_NAME}
    main.cpp
    studentas.cpp
    studentas.h 
    pagrindas.h
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}
)
