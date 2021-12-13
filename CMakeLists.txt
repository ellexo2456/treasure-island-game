cmake_minimum_required(VERSION 3.19)
project(IslandGame)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeFiles")
find_package(SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
include_directories(Client/includeClient)
include_directories(Server/includeServer)
include_directories(EventBus/Include)

add_executable(Client Client/srcClient/main.cpp EventBus/EventBus.cpp Client/includeClient/view.h Client/includeClient/map.h Client/includeClient/camera.h)
add_executable(Server Server/srcServer/main.cpp EventBus/EventBus.cpp Server/srcServer/Player.cpp Server/srcServer/Model.cpp EventBus/Event.cpp)

target_link_libraries(Client ${SFML_LIBRARIES})
target_link_libraries(Server ${SFML_LIBRARIES})
