cmake_minimum_required(VERSION 3.16)
project(2d_lander CXX)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)

add_executable(2d_lander src/main.cpp)
target_link_libraries(2d_lander PRIVATE raylib)
