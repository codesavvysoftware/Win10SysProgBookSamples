cmake_minimum_required(VERSION 3.15)
project(modern_process_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(modern_process_example main.cpp)

target_link_libraries(modern_process_example PRIVATE
    kernel32
    user32
)
