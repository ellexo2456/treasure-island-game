//
// Created by alexey on 07.12.2021.
//

#ifndef ISLANDGAME_PLAYER_H
#define ISLANDGAME_PLAYER_H

#include <SFML/Graphics.hpp>

#include "IObservable.h"
#include "Event.h"

class Player {
public:
    sf::Vector2f get_coordinates() {
        return coordinates;
    }

    void set_coordinates(sf::Vector2f new_coordinates) {
        coordinates = new_coordinates;
    }

    Player() {
        coordinates = {0,0};
        speed = 0;
        player_number = 0;
    }

    int get_player_number() {
        return player_number;
    }

    void set_player_number(int number) {
        number = player_number;
    }

    float get_speed() {
        return speed;
    }
private:
    sf::Vector2f coordinates;
    float speed;
    int player_number;
    Team team;
};

#endif //ISLANDGAME_PLAYER_H
