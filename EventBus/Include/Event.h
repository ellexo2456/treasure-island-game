//
// Created by alexey on 07.12.2021.
//

#ifndef ISLANDGAME_EVENT_H
#define ISLANDGAME_EVENT_H

#include "Player.h"

#include <vector>
#include <string>


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
    Event(Player &movedPlayer) : moved_player(movedPlayer) {};
    Types type;
    sf::Vector2f coordinates[2];
    Player &moved_player;
    int player_number;
    int colors[2];
    //UserMovedEventData user_moved;
};

#endif //ISLANDGAME_EVENT_H
