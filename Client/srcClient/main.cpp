#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "clientPlayer.h"
#include "EventBus.h"
#include "map.h"
#include "camera.h"

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
    packet << received_event.type;
    for (int i = 0; i < 2; ++i) {
        packet << received_event.coordinates[i].x << received_event.coordinates[i].y << received_event.colors[i];
    }
    return packet;
}

int main() {
    Event received_event;

    sf::TcpSocket socket;
    socket.connect("127.0.0.1", 3001);

    sf::Packet packet;
    packet.clear();
    socket.receive(packet);
    packet >> received_event;

    sf::RenderWindow window(sf::VideoMode(700, 700), "Treasure island");
    //view.reset(sf::FloatRect(0, 0, 700, 700)); // инициализировали объект камеры

    // Игроки
    std::string path_to_file = "../Client/srcClient/images/one.png";
    struct SpriteCoord coord = {0, 0, 32,  32 };
    struct SpriteCoord coord1 = {0, 128, 32,  32 };
    std::string color;
    //packet >> A.x >> A.y >> color;
    Player Player1(path_to_file, coord, A);
    //packet >> A.x >> A.y >> color;
    Player Player2(path_to_file, coord1, A);

    // Карта
    std::string path_to_map = "../Client/srcClient/images/map.png";
    Map MyMap(path_to_map, coord, {0,0});

    Event custom_event;

    socket.setBlocking(false);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        custom_event.type = user_init;
        if (window.hasFocus()) {
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
                custom_event.type = dir_left;
            }
                //coord.begin_y = 32; coord.begin_x = 32;};

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) {
                custom_event.type = dir_right;
            }
                //coord.begin_y = 64; coord.begin_x = 32;};

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) {
                custom_event.type = dir_straight;
            }
                 //coord.begin_y = 96; coord.begin_x = 32;};
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) {
                custom_event.type = dir_back;
            }
                 //coord.begin_y = 0; coord.begin_x = 32;};
        }

        if (custom_event.type != user_init) {
            packet.clear();
            packet << custom_event;
            socket.send(packet);
        }

        packet.clear();
        if (socket.receive(packet) != sf::Socket::NotReady) {
            packet >> received_event;
            std::cout << received_event.coordinates[0].x << ' ' << received_event.coordinates[0].y << std::endl;
            std::cout << received_event.coordinates[1].x << ' ' << received_event.coordinates[1].y << std::endl << std::endl;
        }

        //packet >> A.x >> A.y >> color;
        Player1.render(coord, A);
        //packet >> A.x >> A.y >> color;
        Player2.render(coord1, A);

        window.clear();
        MyMap.render(window);

        window.draw(Player2.hero_sprite);
        window.draw(Player1.hero_sprite);
        //window.setView(view);
        window.display();
    }
    return 0;
}
