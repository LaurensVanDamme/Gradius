cmake_minimum_required(VERSION 3.7)
project(Gradius)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(Gradius ${SOURCE_FILES})

target_link_libraries(Gradius sfml-graphics sfml-window sfml-system)