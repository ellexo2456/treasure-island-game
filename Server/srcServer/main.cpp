#include <iostream>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/Packet.hpp>

#include "Model.h"

/*typedef struct {
    float x = -1;
    float y = -1;
    std::string color = "Green";
} data;*/

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
    for (int i = 0; i < 2; ++i) {
        packet >> received_event.coordinates[i].x >> received_event.coordinates[i].y >> received_event.colors[i];
    }
    return packet;
}

sf::Packet operator<< (sf::Packet &packet, Event &received_event) {
    int type_number = received_event.type;
    packet << type_number;
    /*switch(received_event.type) {
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
    }*/

    for (int i = 0; i < 2; ++i) {
        packet << received_event.coordinates[i].x << received_event.coordinates[i].y << received_event.colors[i];
    }
    return packet;
}

int main() {
    EventBus event_bus;

    Player players[2];
    players[0].set_player_number(0);
    players[1].set_player_number(1);

    for (int i = 0; i < 2; ++i) {
        event_bus.subscribe(&players[i], dir_back);
        event_bus.subscribe(&players[i], dir_straight);
        event_bus.subscribe(&players[i], dir_right);
        event_bus.subscribe(&players[i], dir_left);
    }

    Event event_to_send;

    sf::Packet packet;
    sf::TcpListener listener;
    //data clients_data[2];


    if (listener.listen(3001) != sf::Socket::Done) {
        std::cout << "ERROR OF NETWORK" << std::endl;
    }

    sf::TcpSocket clients[2];
    packet.clear();

    if (listener.accept(clients[0]) != sf::Socket::Done) {
        std::cout << "ERROR OF NETWORK" << std::endl;
    }

    event_to_send.type = user_init;
    players[0].set_coordinates({100, 100});
    players[0].color = 0;
    event_to_send.coordinates[0] = players[0].get_coordinates();
    event_to_send.colors[0] = 0;
    /*clients_data[0].x = 100;
    clients_data[0].y = 100;
    clients_data[0].color = "Green";
    packet << clients_data[0].x << clients_data[0].y << clients_data[0].color;

    std::cout << clients[0].getRemoteAddress() << std::endl;*/

    if (listener.accept(clients[1]) != sf::Socket::Done) {
        std::cout << "ERROR OF NETWORK" << std::endl;
    }

    players[1].set_coordinates({300, 300});
    players[1].color = 1;
    event_to_send.coordinates[1] = players[1].get_coordinates();
    event_to_send.colors[1] = 1;
    packet << event_to_send;

    clients[0].send(packet);
    clients[1].send(packet);

    /*clients_data[1].x = 400;
    clients_data[1].y = 100;
    clients_data[1].color = "Red";
    packet << clients_data[1].x << clients_data[1].y << clients_data[1].color;

    std::cout << clients[1].getRemoteAddress() << std::endl;

    clients[0].send(packet);
    clients[1].send(packet);*/

    for (int i = 0; i < 2; ++i) {
        clients[i].setBlocking(false);
    }

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
            received_event.player_number = i;
            event_bus.dispatch(received_event.type, received_event);

            for (int j = 0; j < 2; ++j) {
                event_to_send.coordinates[j] = players[j].get_coordinates();
                event_to_send.colors[j] = players[j].color;
            }
            packet.clear();
            packet << event_to_send;
            clients[0].send(packet);
            clients[1].send(packet);
        }
    }
    return 0;
}