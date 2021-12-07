#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "clientPlayer.h"

typedef struct {
    float x = -1;
    float y = -1;
    std::string color = "Green";
} data;

int main() {

    sf::Packet packet;
    sf::TcpListener listener;
    data clients_data[2];

    if (listener.listen(3000) != sf::Socket::Done) {
        std::cout << "ERROR OF NETWORK" << std::endl;
    }

    sf::TcpSocket clients[2];
    packet.clear();

    if (listener.accept(clients[0]) != sf::Socket::Done) {
        std::cout << "ERROR OF NETWORK" << std::endl;
    }
    clients_data[0].x = 100;
    clients_data[0].y = 100;
    clients_data[0].color = "Green";
    packet << clients_data[0].x << clients_data[0].y << clients_data[0].color;

    std::cout << clients[0].getRemoteAddress() << std::endl;

    if (listener.accept(clients[1]) != sf::Socket::Done) {
        std::cout << "ERROR OF NETWORK" << std::endl;
    }
    clients_data[1].x = 400;
    clients_data[1].y = 100;
    clients_data[1].color = "Red";
    packet << clients_data[1].x << clients_data[1].y << clients_data[1].color;

    std::cout << clients[1].getRemoteAddress() << std::endl;

    clients[0].send(packet);
    clients[1].send(packet);

    while (true) {
        for (int i = 0; i < 2; ++i) {
            int dir = 0;
            packet.clear();
            clients[i].receive(packet);
            packet >> dir;
            /*if (clients_data.dir > 0) {
                std::cout << clients_data.dir << std::endl;
            }*/
            switch (dir) {
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
    }
    return 0;
}
