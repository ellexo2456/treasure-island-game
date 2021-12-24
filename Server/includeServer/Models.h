//
// Created by alexey on 08.12.2021.
//

#ifndef ISLANDGAME_MODELS_H
#define ISLANDGAME_MODELS_H

#include <SFML/Graphics.hpp>

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
        speed = 4;
        player_number = 0;
        player_sprite_coordinates = {.begin_x = 0, .begin_y = 0, .height = 32, .width = 32};
        ship_resource = 0;
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


    int get_direction() {
        return direction;
    }

    void set_direction(int new_direction) {
        direction = new_direction;
    }

    void set_player_sprite_coordinates(SpriteCoord &new_player_sprite_coordinates) {
        player_sprite_coordinates.begin_x = new_player_sprite_coordinates.begin_x;
        player_sprite_coordinates.begin_y = new_player_sprite_coordinates.begin_y;
        player_sprite_coordinates.height = new_player_sprite_coordinates.height;
        player_sprite_coordinates.width = new_player_sprite_coordinates.width;
    }

    int get_ship_resource() {
        return ship_resource;
    }

    void set_ship_resource(int new_ship_resource) {
        ship_resource = new_ship_resource;
    }

    sf::FloatRect get_sprite_rect() {
        return sf::FloatRect(coordinates, {static_cast<float>(player_sprite_coordinates.width), static_cast<float>(player_sprite_coordinates.height)});
    }
private:
    sf::Vector2f coordinates;
    float speed;
    int direction;
    int player_number;
    int ship_resource;
    Team team;
    SpriteCoord player_sprite_coordinates;

    virtual void update(Event event) override;
};

class Collision : public Model {
public:
    Collision(Player (&players)[2], int player_count) : players(players), player_count(player_count), is_got(false) {
        map.load("../Client/srcClient/main_map.xml");
        objects_res = map.getObjectsByName("res");
        objects_solid = map.getObjectsByName("Solid");
        for(int i = 0; i < objects_res.size(); i++ ) {
            for (int j = 0; j < QUANTITY_RES; j++) { //( rand() % 100 + 1 )) => 1 *32
//                shifts[i][j].x = (rand() % (int)(objects_res.at(i).rect.width/32) + 1) * 32;
//                shifts[i][j].y = (rand() % (int)(objects_res.at(i).rect.height/32) + 1) * 32;
                shifts[i].push_back({(rand() % (int)(objects_res.at(i).rect.width/32) + 1) * 32.f,
                                     (rand() % (int)(objects_res.at(i).rect.height/32) + 1) * 32.f});
            }
        }
    };
    virtual void update(Event event) override;

    bool get_is_got() {
        return is_got;
    }

    void set_is_got(bool is) {
        is_got = is;
    }

    int get_picked_item_index() {
        return picked_item_index;
    }

    void set_picked_item_index(int new_picked_item_index) {
        picked_item_index = new_picked_item_index;
    }

    std::vector<sf::Vector2f>* get_shifts() {
        return shifts;
    }

    std::vector<Object> get_objects_res() {
        return objects_res;
    }

private:
    Player (&players)[2];
    int player_count;
    TileMap map;
    std::vector<sf::Vector2f> shifts[RESOURCE_SPAWN_ZONE_COUNT];
    std::vector<Object> objects_res;
    std::vector<Object> objects_solid;
    int picked_item_index;
    bool is_got;
};

#endif //ISLANDGAME_MODELS_H