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

# Find Python
find_package(Python COMPONENTS Interpreter Development REQUIRED)

# Automatically find and add all solution files
file(GLOB_RECURSE SOLUTION_FILES "src/solutions/**/*.cpp")

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add pybind11 submodule
add_subdirectory(extern/pybind11)

# Add the main executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/registry.cpp
    src/utils.cpp
    ${SOLUTION_FILES}
)

# Link pybind11 and Python with your project
target_link_libraries(${PROJECT_NAME} PRIVATE 
    pybind11::embed
    Python::Python
)
