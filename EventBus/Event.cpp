//
// Created by alexey on 12.12.2021.
//
#include <SFML/Network/Packet.hpp>

#include "Event.h"

/*sf::Packet operator>> (sf::Packet &packet, Event &received_event) {
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
    for (int i = 0; i < 2; ++i) {
        packet >> received_event.coordinates[i].x >> received_event.coordinates[i].y >> received_event.colors[i];
    }
    return packet;
}

sf::Packet operator<< (sf::Packet &packet, Event &received_event) {
    int type_number = received_event.type;
    packet << type_number;
    switch(received_event.type) {
        case user_init: {
            packet << 0;
        }
        case dir_left: {
            packet << 1;
        }
        case dir_right: {
            packet << 2;
        }
        case dir_straight: {
            packet << 3;
        }
        case dir_back: {
            packet << 4;
        }
    }

    for (int i = 0; i < 2; ++i) {
        packet << received_event.coordinates[i].x << received_event.coordinates[i].y << received_event.colors[i];
    }
    return packet;
}*/