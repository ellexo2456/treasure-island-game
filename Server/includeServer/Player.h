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
    };
    void set_coordinates(sf::Vector2f new_coordinates) {
        coordinates = new_coordinates;
    }
private:
    sf::Vector2f coordinates = {0, 0};
    float speed = 0;
    Team team;
};

#endif //ISLANDGAME_PLAYER_H
