# set minimum cmake version
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

#Project name
project(algorithms_datastructures)

# enable testing. should be called before any other target is defined
enable_testing()

# create compile_commands.json file so other tools can refer(example: sonarlint)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set sources folder path to variable
set(SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/")

# add library source files
set(LIB_SOURCES
        src/library.cpp
)

# add static libraries
add_library(${PROJECT_NAME} STATIC ${LIB_SOURCES})

#add headers to project
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

#set c++ standard to c++20
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# Tests configuration
set(PROJECT_TEST "algorithms-datastructures-tests")

# install libraries for tests target
find_package(GTest 1.14.0 REQUIRED)

set(TESTS_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/tests/library_test.cpp"
)

# add tests executables
add_executable(${PROJECT_TEST} ${TESTS_SOURCES})

# compile test target for cpp 20
target_compile_features(${PROJECT_TEST} PRIVATE cxx_std_20)

# compiler definitions
target_compile_definitions(
        ${PROJECT_TEST}
        PRIVATE
)

# link libraries to target
target_link_libraries(${PROJECT_TEST} PRIVATE ${PROJECT_NAME} GTest::GTest)

# used for ctests
add_test(
        NAME ${PROJECT_TEST}
        COMMAND $<TARGET_FILE:algorithms-datastructures-tests>
)

# set properties for ctest
set_tests_properties(${PROJECT_TEST} PROPERTIES
        PASS_REGULAR_EXPRESSION ".*No errors detected")