//
// Created by ser on 11.12.2021.
//

#ifndef ISLANDGAME_CAMERA_H
#define ISLANDGAME_CAMERA_H

#include <SFML/Graphics.hpp>

sf::View camera; // объект камера

void give_player_coord_to_camera(sf::Vector2f player_coordinates) {
    camera.setCenter(player_coordinates); // перерисовывает камеру, в зависимости от положения игрока
}
#endif //ISLANDGAME_CAMERA_H
