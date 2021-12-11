//
// Created by alexey on 07.12.2021.
//

#ifndef ISLANDGAME_EVENT_H
#define ISLANDGAME_EVENT_H

#include <SFML/Graphics.hpp>

#include "Player.h"

#include <vector>
#include <string>

enum Types {
    user_init,
    dir_left,
    dir_right,
    dir_straight,
    dir_back,
    user_moved,
};

enum Team {
    first,
    second,
};

/*struct UserMovedEventData {
    sf::Vector2f cordinates;
};*/

struct Event {
    Types type;
    sf::Vector2f cordinates;
    Player &moved_player;
    int player_number;
    //UserMovedEventData user_moved;
};

sf::Packet operator>> (sf::Packet &packet, Event &received_event) {
    int type_number;
    packet >> type_number;
    switch(type_number) {
        case 0: {
            received_event.type = user_init;
        }
        case 1: {
            received_event.type = dir_left;
        }
        case 2: {
            received_event.type = dir_right;
        }
        case 3: {
            received_event.type = dir_straight;
        }
        case 4: {
            received_event.type = dir_back;
        }
    }
    packet >> received_event.cordinates.x >> received_event.cordinates.y;
}

#endif //ISLANDGAME_EVENT_H
