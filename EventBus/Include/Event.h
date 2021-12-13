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

/*struct UserMovedEventData {
    sf::Vector2f cordinates;
};*/

struct Event {
    Types type;
    sf::Vector2f coordinates[2];
    int player_number;
    int colors[2];
    //UserMovedEventData user_moved;
};

#endif //ISLANDGAME_EVENT_H
