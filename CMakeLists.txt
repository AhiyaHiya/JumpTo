cmake_minimum_required(VERSION 3.28)
project(HyperDrive)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Conan setup
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

##
# Project setup
##
# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Executable
add_executable(HyperDrive ${SOURCES})

# Link libraries
target_link_libraries(HyperDrive ${CONAN_LIBS})

# Tests
add_subdirectory(tests)
