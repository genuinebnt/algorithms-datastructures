# set minimum cmake version
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

#Project name
project(tests)

# install libraries for tests target
find_package(GTest 1.14.0 REQUIRED)

set(TESTS_SOURCES
        "main.cpp"
        "skiena/ch3/ch3_tests.cpp"
)

# add tests executables
add_executable(${PROJECT_NAME} ${TESTS_SOURCES})

# compile test target for cpp 20
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# compiler definitionsgit
target_compile_definitions(
        ${PROJECT_NAME}
        PRIVATE
)

# link libraries to target
target_link_libraries(${PROJECT_NAME} PRIVATE sources GTest::GTest)

# used for ctests
add_test(
        NAME ${PROJECT_NAME}
        COMMAND $<TARGET_FILE:tests>
)

# set properties for ctest
set_tests_properties(${PROJECT_NAME} PROPERTIES
        PASS_REGULAR_EXPRESSION ".*No errors detected")