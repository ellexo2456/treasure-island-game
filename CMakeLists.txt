cmake_minimum_required(VERSION 3.20)
project(IslandGame)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeFiles")
find_package(SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
include_directories(Client/includeClient)

add_executable(Client Client/srcClient/main.cpp Client/includeClient/menu.h)
add_executable(Server  Server/srcServer/main.cpp)


target_link_libraries(Client ${SFML_LIBRARIES})
target_link_libraries(Server ${SFML_LIBRARIES})
