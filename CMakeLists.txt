cmake_minimum_required(VERSION 3.0)

project(Mostima)

set(SRCS
    src/main.cpp
    src/Core.cpp

    src/Parser/FuncParser.cpp
    src/Parser/Func.cpp

    src/Process/Entry.cpp

    src/Utils/JSONParser.cpp
    src/Utils/File.cpp
    )

set(HEADERS
    inc/Core.hpp

    inc/Parser/FuncParser.hpp
    inc/Parser/Func.hpp

    inc/Process/Entry.hpp

    inc/Utils/JSONParser.hpp
    inc/Utils/File.hpp
    )

add_executable(Mostima ${SRCS} ${HEADERS})

target_include_directories(Mostima PUBLIC
    inc/
    inc/Parser/
    inc/Process/
    inc/Utils/
    )
