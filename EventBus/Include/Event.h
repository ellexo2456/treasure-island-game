//
// Created by alexey on 07.12.2021.
//

#ifndef ISLANDGAME_EVENT_H
#define ISLANDGAME_EVENT_H

#include <vector>
#include <string>
#include <SFML/System/Vector2.hpp>


enum Types {
    user_init,
    dir_left,
    dir_right,
    dir_straight,
    dir_back,
    is_intersect_with_player,
    is_intersect_with_map,
    got_ship_resource,
    error,
};

// Режем кусочек изображения с помощью этого
struct SpriteCoord {
    int begin_x;
    int begin_y;
    int height;
    int width;
};

struct UserMovedEventData {
    sf::Vector2f coordinates[2];
    SpriteCoord sprite_coordinates[2];
};

struct GotShipResourceData {
    int map_row_to_change;
    int map_column_to_change;
    int ship_resource_count[2];
};

struct Event {
    Types type;
    int moved_player_number;
    int client_number;
    UserMovedEventData user_moved;
    GotShipResourceData got_ship_resource;
};

#endif //ISLANDGAME_EVENT_H