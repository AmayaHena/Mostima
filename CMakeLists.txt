cmake_minimum_required(VERSION 3.0)

project(Mostima)

set(SRCS
    src/main.cpp
    src/Core.cpp

    src/Parser/JSONParser.cpp
    src/Parser/File.cpp
    )

set(HEADERS
    inc/Core.hpp

    inc/Parser/JSONParser.hpp
    inc/Parser/File.hpp
    )

add_executable(Mostima ${SRCS} ${HEADERS})

target_include_directories(Mostima PUBLIC
    inc/
    inc/Parser/
    )
