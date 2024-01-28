cmake_minimum_required(VERSION 3.1...3.27)
project(
        pain3
)
set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES decode.cpp)
include_directories(.)
add_executable(pain3/decode.cpp
        pain3/encode.cpp
       )
#Include(FetchContent)
#FetchContent_Declare(
#        Catch2
#        GIT_REPOSITORY https://github.com/catchorg/Catch2
#        GIT_TAG        v3.4.0 # or a later release
#)
