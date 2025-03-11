cmake_minimum_required(VERSION 3.16)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


project(Flipfinity C)

add_executable(Flipfinity src/main.c)

# Source related addresses
set(SRC_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# SDL3 related addresses
set(SDL3_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SDL3/include")
set(SDL3_LIBRARY "${CMAKE_SOURCE_DIR}/SDL3/lib/libSDL3.dll.a")

# Source linking
target_include_directories(Flipfinity PRIVATE ${SRC_INCLUDE_DIR})

# SDL3 linking
target_include_directories(Flipfinity PRIVATE ${SDL3_INCLUDE_DIR})
target_link_libraries(Flipfinity PRIVATE ${SDL3_LIBRARY})