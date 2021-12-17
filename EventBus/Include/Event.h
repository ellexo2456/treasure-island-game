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
    error,
};

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

struct Event {
    Types type;
    int moved_player_number;
    int client_number;
    UserMovedEventData user_moved;
};

#endif //ISLANDGAME_EVENT_H
