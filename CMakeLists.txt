# CMakeLists.txt - Build configuration for ThreadForge
# This tells the compiler how to build our project

cmake_minimum_required(VERSION 3.10)

# Name our project and set the version
project(ThreadForge VERSION 1.0.0 LANGUAGES CXX)

# Use C++17 standard (modern C++ features)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell the compiler where to find our header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Collect all .cpp files from the src/ folder
file(GLOB SOURCES "src/*.cpp")

# Build an executable called "threadforge" from all source files
add_executable(threadforge ${SOURCES})
