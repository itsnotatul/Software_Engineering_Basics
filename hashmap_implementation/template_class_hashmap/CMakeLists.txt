cmake_minimum_required(VERSION 3.10)  # Specify the minimum CMake version
project(HashMapImplementation)  # Replace with your project name

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# file(GLOB SOURCES "src/Product/*.cpp src/*.cpp")
set(SOURCES
    hashmap.cpp
)

# Add the executable
add_executable(HashMapImplementation
    ${SOURCES}
)