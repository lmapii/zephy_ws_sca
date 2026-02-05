
cmake_minimum_required(VERSION 3.20.0)

set(
    CPPCHECK_VERBATIM_EXTRA_ARGS
    "--suppress=*:*deps/*"
)

include(${CMAKE_CURRENT_LIST_DIR}/codechecker.cmake)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
include(${CMAKE_CURRENT_LIST_DIR}/cppcheck.cmake)

project(
    ScaDemo
    VERSION 0.1
    DESCRIPTION "ScaDemo."
)

target_sources(
    app
    PRIVATE
    src/foo.c
    src/bar.c
    src/baz.c
    src/main.c
)
