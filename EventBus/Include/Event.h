//
// Created by alexey on 07.12.2021.
//

#ifndef ISLANDGAME_EVENT_H
#define ISLANDGAME_EVENT_H

#define RESOURCE_SPAWN_ZONE_COUNT 2
#define QUANTITY_RES 10
#define PORT 3003


#include <vector>
#include <string>

#include <SFML/System/Vector2.hpp>

#include "Lev.h"


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
    int picked_item_index;
    int ship_resource_count[2];
};

struct ResourcesData {
    std::vector<sf::Vector2f> *shifts_to_send;
    std::vector<sf::Vector2f> received_shifts[RESOURCE_SPAWN_ZONE_COUNT];
    std::vector<Object> objects_res;
};

struct Event {
    Event() {
        Object a = Object();
        resource_data.objects_res = {a, a};
        for (auto & received_shift : resource_data.received_shifts) {
            for (int j = 0; j < 10; ++j) {
                received_shift.emplace_back(0, 0);
            }
        }
    }

    Types type;
    int moved_player_number;
    int client_number;
    UserMovedEventData user_moved;
    GotShipResourceData got_ship_resource;
    ResourcesData resource_data;
};

#endif //ISLANDGAME_EVENT_H