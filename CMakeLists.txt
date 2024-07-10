cmake_minimum_required(VERSION 3.28)
project(HyperDrive)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Conan setup
include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)

enable_testing()
find_package(Boost CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

##
# Project setup
##
# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Executable
add_executable(HyperDrive
    "include/HyperDrive/DataSet.h"
    "src/DataSet.cpp"
    "src/main.cpp"
)

message(STATUS "CONAN_LIBS ${CONAN_LIBS}")

# Link libraries
target_link_libraries(HyperDrive
    PRIVATE
    boost::boost
    nlohmann_json::nlohmann_json
)

# Tests
#add_subdirectory(tests)
