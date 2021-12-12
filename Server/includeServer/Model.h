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
    virtual void update(Event event) override;
    sf::Vector2f coordinates;
    float speed;
    int player_number;
    Team team;
};

#endif //ISLANDGAME_MODEL_H
