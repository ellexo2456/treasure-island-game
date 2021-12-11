#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "Model.h"
#include "Player.h"
#include "clientPlayer.h"
#include "Event.h"
#include "EventBus.h"

/*typedef struct {
    float x = -1;
    float y = -1;
    std::string color = "Green";
} data;*/


int main() {
    EventBus event_bus;
    Model model;
    event_bus.subscribe(&model, dir_back);
    event_bus.subscribe(&model, dir_straight);
    event_bus.subscribe(&model, dir_right);
    event_bus.subscribe(&model, dir_left);

    Player players[2];
    players[0].set_player_number(0);
    players[0].set_player_number(1);

    Event event_to_send = {.moved_player = players[0]};

    sf::Packet packet;
    sf::TcpListener listener;
    //data clients_data[2];


    if (listener.listen(3000) != sf::Socket::Done) {
        std::cout << "ERROR OF NETWORK" << std::endl;
    }

    sf::TcpSocket clients[2];
    packet.clear();

    if (listener.accept(clients[0]) != sf::Socket::Done) {
        std::cout << "ERROR OF NETWORK" << std::endl;
    }
    /*clients_data[0].x = 100;
    clients_data[0].y = 100;
    clients_data[0].color = "Green";
    packet << clients_data[0].x << clients_data[0].y << clients_data[0].color;

    std::cout << clients[0].getRemoteAddress() << std::endl;*/

    if (listener.accept(clients[1]) != sf::Socket::Done) {
        std::cout << "ERROR OF NETWORK" << std::endl;
    }
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

    Event received_event = {.moved_player = players[0]};

    while (true) {
        for (int i = 0; i < 2; ++i) {
            packet.clear();
            if (clients[i].receive(packet) == sf::Socket::NotReady) {
                break;
            }
            packet >> received_event;
            received_event.player_number= i;
            event_bus.dispatch(received_event.type, received_event);

            /*switch (dir) {
                case 0: {
                    break;
                }
                case 1: {
                    --clients_data[i].x;
                    break;
                }
                case 2: {
                    ++clients_data[i].x;
                    break;
                }
                case 3: {
                    --clients_data[i].y;
                    break;
                }
                case 4: {
                    ++clients_data[i].y;
                    break;
                }
            }
        }
        packet.clear();
        packet << clients_data[0].x << clients_data[0].y << clients_data[0].color\
        << clients_data[1].x << clients_data[1].y << clients_data[1].color;
        clients[0].send(packet);
        clients[1].send(packet);
    }*/
    return 0;
}
