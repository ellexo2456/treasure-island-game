#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "clientPlayer.h"
#include "map.h"
#include "camera.h"

#define PORT 3000

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
        packet >> received_event.user_moved.coordinates[i].x >> received_event.user_moved.coordinates[i].y \
        >> received_event.user_moved.sprite_coordinates[i].begin_x >> received_event.user_moved.sprite_coordinates[i].begin_y \
        >> received_event.user_moved.sprite_coordinates[i].height >> received_event.user_moved.sprite_coordinates[i].width;
    }
    return packet;
}

sf::Packet operator<< (sf::Packet &packet, Event &received_event) {
    packet << received_event.type;
    for (int i = 0; i < 2; ++i) {
        packet << received_event.user_moved.coordinates[i].x << received_event.user_moved.coordinates[i].y \
        << received_event.user_moved.sprite_coordinates[i].begin_x << received_event.user_moved.sprite_coordinates[i].begin_y \
        << received_event.user_moved.sprite_coordinates[i].height << received_event.user_moved.sprite_coordinates[i].width;
    }
    return packet;
}

int main() {
    sf::TcpSocket socket;
    socket.connect("127.0.0.1", PORT);

    sf::Packet packet;
    packet.clear();
    socket.receive(packet);

    sf::RenderWindow window(sf::VideoMode(640, 640), "Treasure island");
    //view.reset(sf::FloatRect(0, 0, 700, 700)); // инициализировали объект камеры

    // Игроки
    std::string path_to_file = "../Client/srcClient/images/one.png";
    struct SpriteCoord coord = {0, 0, 32,  32 };
    struct SpriteCoord coord1 = {0, 128, 32,  32 };
    Event received_event;
    packet >> received_event;
    Player Player1(path_to_file, received_event.user_moved.sprite_coordinates[0], received_event.user_moved.coordinates[0]);
    Player Player2(path_to_file, received_event.user_moved.sprite_coordinates[1], received_event.user_moved.coordinates[1]);

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
            std::cout << "x: " << received_event.user_moved.coordinates[0].x << ' ' << "y: " << received_event.user_moved.coordinates[0].y << std::endl;
            std::cout << "x: " << received_event.user_moved.coordinates[1].x << ' ' << "y: " << received_event.user_moved.coordinates[1].y << std::endl;
            std::cout << "w: " << received_event.user_moved.sprite_coordinates[0].width << ' ' << "h: " << received_event.user_moved.sprite_coordinates[0].height << std::endl;
            std::cout << "w: " << received_event.user_moved.sprite_coordinates[1].width << ' ' << "h: " << received_event.user_moved.sprite_coordinates[1].height << std::endl << std::endl;
        }

        Player1.render(received_event.user_moved.sprite_coordinates[0], received_event.user_moved.coordinates[0]);
        Player2.render(received_event.user_moved.sprite_coordinates[1], received_event.user_moved.coordinates[1]);

        window.clear();
        MyMap.render(window);

        window.draw(Player2.hero_sprite);
        window.draw(Player1.hero_sprite);
        //window.setView(view);
        window.display();
    }
    return 0;
}
