cmake_minimum_required(VERSION 3.20)
project(IslandGame)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMakeFiles")
find_package(SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

add_executable(IslandGame main.cpp)

target_link_libraries(IslandGame ${SFML_LIBRARIES})
