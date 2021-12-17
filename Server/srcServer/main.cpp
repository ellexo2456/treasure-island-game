#include <iostream>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/Packet.hpp>

#include "Collision.h"

#define PORT 3002

sf::Packet operator>> (sf::Packet &packet, Event &received_event) {
    int type_number;
    packet >> type_number;
    switch(type_number) {
        case 0: {
            received_event.type = user_init;
            break;
        }
        case 1: {
            received_event.type = dir_left;
            break;
        }
        case 2: {
            received_event.type = dir_right;
            break;
        }
        case 3: {
            received_event.type = dir_straight;
            break;
        }
        case 4: {
            received_event.type = dir_back;
            break;
        }
        default: {
            received_event.type = error;
            break;
        }
    }
    packet >> received_event.client_number;
    for (int i = 0; i < 2; ++i) {
        packet >> received_event.user_moved.coordinates[i].x >> received_event.user_moved.coordinates[i].y \
        >> received_event.user_moved.sprite_coordinates[i].begin_x >> received_event.user_moved.sprite_coordinates[i].begin_y \
        >> received_event.user_moved.sprite_coordinates[i].height >> received_event.user_moved.sprite_coordinates[i].width;
    }
    return packet;
}

sf::Packet operator<< (sf::Packet &packet, Event &received_event) {
    packet << received_event.type;
    packet << received_event.client_number;
    for (int i = 0; i < 2; ++i) {
        packet << received_event.user_moved.coordinates[i].x << received_event.user_moved.coordinates[i].y \
        << received_event.user_moved.sprite_coordinates[i].begin_x << received_event.user_moved.sprite_coordinates[i].begin_y \
        << received_event.user_moved.sprite_coordinates[i].height << received_event.user_moved.sprite_coordinates[i].width;
    }
    return packet;
}

int main() {
    EventBus event_bus;

    Player players[2];
    players[0].set_player_number(0);
    players[1].set_player_number(1);

    Collision collision(players, 2);
    event_bus.subscribe(&collision, is_intersect);

    for (auto & player : players) {
        event_bus.subscribe(&player, dir_back);
        event_bus.subscribe(&player, dir_straight);
        event_bus.subscribe(&player, dir_right);
        event_bus.subscribe(&player, dir_left);
    }

    Event event_to_send;

    sf::Packet packet;
    sf::TcpListener listener;
    //data clients_data[2];


    if (listener.listen(PORT) != sf::Socket::Done) {
        std::cout << "ERROR OF NETWORK" << std::endl;
    }

    sf::TcpSocket clients[2];

    if (listener.accept(clients[0]) != sf::Socket::Done) {
        std::cout << "ERROR OF NETWORK" << std::endl;
    }

    event_to_send.type = user_init;
    players[0].set_coordinates({100, 100});
    event_to_send.user_moved.coordinates[0] = players[0].get_coordinates();
    event_to_send.user_moved.sprite_coordinates[0] = {0, 0, 32,  32 };

    if (listener.accept(clients[1]) != sf::Socket::Done) {
        std::cout << "ERROR OF NETWORK" << std::endl;
    }

    players[1].set_coordinates({300, 300});
    event_to_send.user_moved.coordinates[1] = players[1].get_coordinates();
    event_to_send.user_moved.sprite_coordinates[1] = {0, 0, 32,  32 };

    packet.clear();
    packet << event_to_send;
    clients[0].send(packet);
    clients[1].send(packet);

    for (auto & client : clients) {
        client.setBlocking(false);
    }

    /*for (auto & player : players) {
        event_bus.subscribe(&player, is_intersect);
    }*/

    Event received_event;

    while (true) {
        for (int i = 0; i < 2; ++i) {
            packet.clear();
            if (clients[i].receive(packet) == sf::Socket::NotReady) {
                continue;
            }
            packet >> received_event;
            if (received_event.type != user_init) {
                std::cout << received_event.type << std::endl;
            }
            received_event.moved_player_number = i;
            event_bus.dispatch(received_event.type, received_event);

            for (int j = 0; j < 2; ++j) {
                event_to_send.user_moved.coordinates[j] = players[j].get_coordinates();
                event_to_send.user_moved.sprite_coordinates[j] = players[j].get_player_sprite_coordinates();
            }
            players[i].set_direction(received_event.type);
            event_to_send.moved_player_number = i;
            event_to_send.type = is_intersect;
            event_bus.dispatch(is_intersect, event_to_send);
            for (int i = 0; i < 2; ++i) {
                event_to_send.user_moved.coordinates[i] = players[i].get_coordinates();
            }
            packet.clear();
            event_to_send.client_number = 0;
            packet << event_to_send;
            clients[0].send(packet);

            packet.clear();
            event_to_send.client_number = 1;
            packet << event_to_send;
            clients[1].send(packet);
        }
    }
    return 0;
}