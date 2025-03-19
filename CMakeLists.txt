cmake_minimum_required(VERSION 3.16)
project(Flipfinity C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use Ninja and Clang if available
if(NOT CMAKE_GENERATOR)
    set(CMAKE_GENERATOR "Ninja")
endif()

if(NOT CMAKE_C_COMPILER)
    set(CMAKE_C_COMPILER clang)
endif()

if(NOT CMAKE_CXX_COMPILER)
    set(CMAKE_CXX_COMPILER clang++)
endif()

# Source files
file(GLOB SOURCES "src/*.c")
add_executable(Flipfinity ${SOURCES})

# Source include directory
target_include_directories(Flipfinity PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Find and link SDL3
find_package(SDL3 REQUIRED)

if(SDL3_FOUND)
    target_include_directories(Flipfinity PRIVATE ${SDL3_INCLUDE_DIRS})
    target_link_libraries(Flipfinity PRIVATE ${SDL3_LIBRARIES})
else()
    message(FATAL_ERROR "SDL3 not found! Install SDL3 or set SDL3_DIR manually.")
endif()

# Set rpath to current directory so SDL3 is found locally
set_target_properties(Flipfinity PROPERTIES
    CMAKE_INSTALL_RPATH "$ORIGIN"
)
