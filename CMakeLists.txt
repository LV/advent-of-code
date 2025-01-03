set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE)
cmake_minimum_required(VERSION 3.15)
project(AdventOfCode VERSION 1.0)

# C++20 settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GCC specific compiler flags
add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
    -Werror
    -fdiagnostics-color=always
)

# Optional: Enable Link Time Optimization in Release mode
include(CheckIPOSupported)
check_ipo_supported(RESULT supported OUTPUT error)
if(supported)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)
endif()

# Find Python and Zig
find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_program(ZIG_EXECUTABLE zig REQUIRED)

# Automatically find and add all solution files
file(GLOB_RECURSE SOLUTION_FILES "src/solutions/**/*.cpp")

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add Zig build target
add_custom_target(zig_build ALL
    COMMAND ${ZIG_EXECUTABLE} build
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# Add the main executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/registry.cpp
    src/utils.cpp
    ${SOLUTION_FILES}
)

# Make main executable depend on Zig build
add_dependencies(${PROJECT_NAME} zig_build)
