//
// Created by alexey on 08.12.2021.
//

#include "Model.h"

void Player::update(Event event) {
    if ((event.type == dir_left || event.type == dir_right || event.type == dir_straight \
 || event.type == dir_back) && event.moved_player_number == player_number) {

        switch (event.type) {
            case 1: {
                coordinates.x -= speed;
                player_sprite_coordinates = {.begin_x = 32, .begin_y = 32, .height = 32, .width = 32};
                break;
            }
            case 2: {
                coordinates.x += speed;
                player_sprite_coordinates = {.begin_x = 32, .begin_y = 64, .height = 32, .width = 32};
                break;
            }
            case 3: {
                coordinates.y -= speed;
                player_sprite_coordinates = {.begin_x = 32, .begin_y = 96, .height = 32, .width = 32};
                break;
            }
            case 4: {
                coordinates.y += speed;
                player_sprite_coordinates = {.begin_x = 32, .begin_y = 0, .height = 32, .width = 32};
                break;
            }
            default: {
                coordinates.x += speed;
                coordinates.y += speed;
                player_sprite_coordinates = {.begin_x = 32, .begin_y = 32, .height = 32, .width = 32};
                break;
            }
        }
    }
    if (event.type == is_intersect && event.moved_player_number == player_number) {
        for (int i = 0; i < 2; ++i) {
            if (i != player_number) {
                if(get_sprite_rect().intersects(sf::FloatRect(event.user_moved.coordinates[i], \
                {static_cast<float>(event.user_moved.sprite_coordinates[i].width),
                 static_cast<float>(event.user_moved.sprite_coordinates[i].height)}))) {
                    switch(direction) {
                        case 1: {
                            coordinates.x = event.user_moved.coordinates[i].x + event.user_moved.sprite_coordinates[i].width;
                            //event.user_moved.coordinates[i].x = coordinates.x - event.user_moved.sprite_coordinates[i].width;
                            break;
                        }
                        case 2: {
                            coordinates.x = event.user_moved.coordinates[i].x - player_sprite_coordinates.width;
                            break;
                        }
                        case 3: {
                            coordinates.y = event.user_moved.coordinates[i].y + event.user_moved.sprite_coordinates[i].height;
                            break;
                        }
                        case 4: {
                            coordinates.y = event.user_moved.coordinates[i].y - player_sprite_coordinates.height;
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
        }
    }
}
