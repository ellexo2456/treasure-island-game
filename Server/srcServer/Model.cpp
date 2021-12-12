//
// Created by alexey on 08.12.2021.
//

#include "SFML/Graphics.hpp"

#include "Model.h"
#include "Player.h"
#include "Event.h"

void Model::update(Event event) {
    if ((event.type == dir_left || event.type == dir_right || event.type == dir_straight \
    || event.type == dir_back) && event.player_number != event.moved_player.get_player_number()) {
        event.moved_player.set_coordinates(compute_coordinates(event.type, event.moved_player));
    }
}

sf::Vector2f compute_coordinates(int type, Player &player) {
    /*sf::Clock clock;
    float time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time /= 800;*/
    sf::Vector2f calculated_coordinates;
    switch(type) {
        case 1: {
            calculated_coordinates.x = -player.get_speed();
            calculated_coordinates.y = 0;
        }
        case 2: {
            calculated_coordinates.x = player.get_speed();
            calculated_coordinates.y = 0;
        }
        case 3: {
            calculated_coordinates.x = 0;
            calculated_coordinates.y = -player.get_speed();
        }
        case 4: {
            calculated_coordinates.x = 0;
            calculated_coordinates.y = player.get_speed();
        }
    }
    return calculated_coordinates;
}

