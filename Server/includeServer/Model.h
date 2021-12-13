//
// Created by alexey on 08.12.2021.
//

#ifndef ISLANDGAME_MODEL_H
#define ISLANDGAME_MODEL_H

#include "EventBus.h"

enum Team {
    first,
    second,
};

class Model : public IObservable {
public:
    virtual void update(Event event) override = 0;
};

class Player : public Model {
public:
    Player() {
        coordinates = {0,0};
        speed = 2;
        player_number = 0;
        player_sprite_coordinates = {.begin_x = 0, .begin_y = 0, .height = 32, .width = 32};
    }

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


    SpriteCoord get_player_sprite_coordinates() {
        return player_sprite_coordinates;
    }

    void set_player_sprite_coordinates(SpriteCoord &new_player_sprite_coordinates) {
        player_sprite_coordinates.begin_x = new_player_sprite_coordinates.begin_x;
        player_sprite_coordinates.begin_y = new_player_sprite_coordinates.begin_y;
        player_sprite_coordinates.height = new_player_sprite_coordinates.height;
        player_sprite_coordinates.width = new_player_sprite_coordinates.width;
    }
private:
    sf::Vector2f coordinates;
    float speed;
    int player_number;
    Team team;
    SpriteCoord player_sprite_coordinates;

    virtual void update(Event event) override;
};

#endif //ISLANDGAME_MODEL_H
