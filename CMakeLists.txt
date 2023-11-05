# set minimum cmake version
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# Project name
project(algorithms_datastructures)

# enable testing. should be called before any other target is defined
enable_testing()

# create compile_commands.json file so other tools can refer(example: sonarlint)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable sanitizers

# Enable AddressSanitizer
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libsan")

# Enable LeakSanitizer
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")

# Enable ThreadSanitizer
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")

# Enable UndefinedBehaviorSanitizer
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")

# Enable MemorySanitizer
##set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=memory")

add_subdirectory(src)
add_subdirectory(tests)