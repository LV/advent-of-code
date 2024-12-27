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

# Automatically find and add all solution files
file(GLOB_RECURSE SOLUTION_FILES "src/solutions/**/*.cpp")

include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/registry.cpp
    ${SOLUTION_FILES}  # Automatically include all solution files
)
