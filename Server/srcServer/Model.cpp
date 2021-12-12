//
// Created by alexey on 08.12.2021.
//

#include "SFML/Graphics.hpp"

#include "Model.h"

void Model::update(Event event) {
    if ((event.type == dir_left || event.type == dir_right || event.type == dir_straight \
    || event.type == dir_back) && event.player_number == event.moved_player.get_player_number()) {
        event.moved_player.set_coordinates(Model::compute_coordinates(event.type, event.moved_player));
    }
}

sf::Vector2f Model::compute_coordinates(int type, Player &player) {
    /*sf::Clock clock;
    float time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time /= 800;*/
    sf::Vector2f player_coordinates = player.get_coordinates();
    float speed = player.get_speed();
    switch(type) {
        case 1: {
            player_coordinates.x -= speed;
            break;
        }
        case 2: {
            player_coordinates.x += speed;
            break;
        }
        case 3: {
            player_coordinates.y -= speed;
            break;
        }
        case 4: {
            player_coordinates.y += speed;
            break;
        }
        default: {
            player_coordinates.x += speed;
            player_coordinates.y += speed;
            break;
        }
    }
    return player_coordinates;
}
