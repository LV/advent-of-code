set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE)
cmake_minimum_required(VERSION 3.15)
project(AdventOfCode VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_compile_options(-Wall -Wextra -Wpedantic -Werror -fdiagnostics-color=always)

find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_program(ZIG_EXECUTABLE zig REQUIRED)

file(GLOB_RECURSE SOLUTION_FILES "src/solutions/**/*.cpp")

# Create a shared library for C++ solutions
add_library(cpp_solutions SHARED
    src/solutions.cpp
    src/utils.cpp
    ${SOLUTION_FILES}
)

target_include_directories(cpp_solutions PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Add Zig executable build
add_custom_target(aoc ALL
    COMMAND ${ZIG_EXECUTABLE} build
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_dependencies(aoc cpp_solutions)
