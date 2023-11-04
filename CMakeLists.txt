# set minimum cmake version
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

#Project name
project(algorithms_datastructures)

# enable testing. should be called before any other target is defined
enable_testing()

# create compile_commands.json file so other tools can refer(example: sonarlint)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(tests)