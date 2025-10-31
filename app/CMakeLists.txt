cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(
    ScaDemo
    VERSION 0.1
    DESCRIPTION "ScaDemo."
)

target_sources(
    app
    PRIVATE
    src/dummy.c
    src/main.c
)
