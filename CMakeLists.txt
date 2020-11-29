cmake_minimum_required(VERSION 3.0)

project(Mostima)

set(SRCS
    src/main.cpp
    src/Core.cpp
    )

set(HEADERS
    inc/Core.hpp
    )

add_executable(Mostima ${SRCS} ${HEADERS})

target_include_directories(Mostima PUBLIC
    inc/
    )
