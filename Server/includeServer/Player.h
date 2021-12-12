//
// Created by alexey on 07.12.2021.
//

#ifndef ISLANDGAME_PLAYER_H
#define ISLANDGAME_PLAYER_H

#include <SFML/Graphics.hpp>



enum Team {
    first,
    second,
};

class Player :  {
public:
    Player() {
        coordinates = {0,0};
        speed = 50;
        player_number = 0;
    }

    int color;

    sf::Vector2f get_coordinates() {
        return coordinates;
    }

    void set_coordinates(sf::Vector2f new_coordinates) {
        coordinates = new_coordinates;
    }

    int get_player_number() const {
        return player_number;
    }

    void set_player_number(int number) {
        player_number = number;
    }

    float get_speed() const {
        return speed;
    }
private:
    sf::Vector2f coordinates;
    float speed;
    int player_number;
    Team team;
};

#endif //ISLANDGAME_PLAYER_H
