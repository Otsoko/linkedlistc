cmake_minimum_required(VERSION 3.20)

project(linkedlist
    VERSION 1.0
    LANGUAGES C
)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_FLAGS "-O3 -Wall -Wextra -pedantic")

add_library(linkedlist
    STATIC
    lib/linkedlist.c
)

add_executable(app
    app/app.c
)

target_include_directories(app
    PUBLIC lib
)

target_link_libraries(app
    PRIVATE linkedlist
)
