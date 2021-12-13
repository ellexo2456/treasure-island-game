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
    error,
    user_moved,
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
    int player_number;
    UserMovedEventData user_moved;
};

#endif //ISLANDGAME_EVENT_H
