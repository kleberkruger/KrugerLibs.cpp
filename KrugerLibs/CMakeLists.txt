cmake_minimum_required(VERSION 3.5)
project(KrugerLibs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES KrugerLibsDemo.cpp ConfigFile/ConfigFile.cpp ConfigFile/Exceptions.h)
add_executable(KrugerLibs ${SOURCE_FILES})