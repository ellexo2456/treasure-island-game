//
// Created by alexey on 08.12.2021.
//

#ifndef ISLANDGAME_MODELS_H
#define ISLANDGAME_MODELS_H

#include <SFML/Graphics.hpp>

#include "EventBus.h"
#include "Lev.h"

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
        speed = 8;
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
    };
    virtual void update(Event event) override;

    bool get_is_got() {
        return is_got;
    }

    int get_map_row_to_change() {
        return map_row_to_change;
    }

    int get_map_column_to_change() {
        return map_column_to_change;
    }

private:
    Player (&players)[2];
    int player_count;
//    static const int HEIGHT_MAP = 20; // Высота карты
//    static const int WIDTH_MAP = 20;  // Ширина карты
//    sf::String TileMap[HEIGHT_MAP] = {
//            "ssssssssssssssssssss",
//            "s000000000000000000s",
//            "s000000000000k00000s",
//            "s00000k000000000000s",
//            "s000000000000000000s",
//            "s000000000000000000s",
//            "s000000000000000000s",
//            "s000000000k00000000s",
//            "s000000000000000000s",
//            "s000000000000000000s",
//            "s000000000000000000s",
//            "s000000000000000000s",
//            "s000000000000000000s",
//            "s000000000000000000s",
//            "s00000k000000000000s",
//            "s000000000000000000s",
//            "s000000000000k00000s",
//            "s000000000000000000s",
//            "s000000000000000000s",
//            "ssssssssssssssssssss",
//    };
    TileMap map;
    std::vector<Object> objects_res;
    std::vector<Object> objects_solid;
    int map_row_to_change;
    int map_column_to_change;
    bool is_got;
};

#endif //ISLANDGAME_MODELS_H