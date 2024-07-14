cmake_minimum_required(VERSION 3.28)
project(HyperDrive VERSION 0.1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Conan setup
include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)

enable_testing()
find_package(Boost CONFIG REQUIRED COMPONENTS program_options)
find_package(GTest CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(tests)

##
# App setup
##
add_executable(HyperDrive "src/main.cpp")

target_compile_definitions(HyperDrive
    PRIVATE
        VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
        VERSION_MINOR=${PROJECT_VERSION_MINOR}
        VERSION_PATCH=${PROJECT_VERSION_PATCH}
)

# Link libraries
target_link_libraries(HyperDrive
    PRIVATE
        HyperDriveLib
)
