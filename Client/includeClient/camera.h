//
// Created by ser on 11.12.2021.
//

#ifndef ISLANDGAME_CAMERA_H
#define ISLANDGAME_CAMERA_H

#include <SFML/Graphics.hpp>

sf::View view; // объект камера

sf::View getPlayercoordcamera(float x, float y) {
    view.setCenter(x, y); // перерисовывает камеру, в зависимости от положения игрока
    return view;  // возвращаем камеру, что бы обновлять её
}
#endif //ISLANDGAME_CAMERA_H
