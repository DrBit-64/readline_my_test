cmake_minimum_required(VERSION 3.10)

project(Readline)
include_directories(${CMAKE_SOURCE_DIR})


add_executable(example example.cpp readline.cpp)
target_link_libraries(example ${CURSES_LIBRARIES})