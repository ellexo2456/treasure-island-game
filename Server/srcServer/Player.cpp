//
// Created by alexey on 08.12.2021.
//

#include "Model.h"

void Player::update(Event event) {
    if ((event.type == dir_left || event.type == dir_right || event.type == dir_straight \
    || event.type == dir_back) && event.player_number == player_number) {
        switch (event.type) {
            case 1: {
                coordinates.x -= speed;
                break;
            }
            case 2: {
                coordinates.x += speed;
                break;
            }
            case 3: {
                coordinates.y -= speed;
                break;
            }
            case 4: {
                coordinates.y += speed;
                break;
            }
            default: {
                coordinates.x += speed;
                coordinates.y += speed;
                break;
            }
        }
    }
}
