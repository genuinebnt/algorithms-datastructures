# set minimum cmake version
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

#Project name
project(sources)

# add library source files
set(LIB_SOURCES
        skiena/ch3/3.1.cpp
        skiena/ch3/3.2.cpp
        skiena/ch3/3.3.cpp
        include/skiena/ch3/3.4.h
)

# add static libraries
add_library(${PROJECT_NAME} STATIC ${LIB_SOURCES})

#add headers to project
target_include_directories(${PROJECT_NAME} PUBLIC include/)

#set c++ standard to c++20
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)