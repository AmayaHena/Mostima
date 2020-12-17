cmake_minimum_required(VERSION 3.0)

project(Test)

set(SRCS
    ParserTests.cpp
    ../../src/Core.cpp

    ../../src/Parser/FuncParser.cpp
    ../../src/Parser/Func.cpp

    ../../src/Process/Entry.cpp
    ../../src/Process/Executor.cpp

    ../../src/Utils/JSONParser.cpp
    ../../src/Utils/File.cpp
    )

set(HEADERS
    ../../inc/Core.hpp

    ../../inc/Parser/FuncParser.hpp
    ../../inc/Parser/Func.hpp

    ../../inc/Process/Entry.hpp
    ../../inc/Process/Executor.hpp

    ../../inc/Utils/JSONParser.hpp
    ../../inc/Utils/File.hpp
    )

add_executable(Test ${SRCS} ${HEADERS})

target_include_directories(Test PUBLIC
    ../../inc/
    ../../inc/Parser/
    ../../inc/Process/
    ../../inc/Utils/
    )
