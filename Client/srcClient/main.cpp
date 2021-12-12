#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "EventBus.h"

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
    Player a;
    Event received_event(a);

    sf::TcpSocket socket;
    socket.connect("127.0.0.1", 3000);

    sf::Packet packet;
    packet.clear();
    socket.receive(packet);

    sf::CircleShape shapeA(90.f);
    sf::CircleShape shapeB(90.f);

    packet >> received_event;

    shapeA.setPosition(received_event.coordinates[0]);
    if (received_event.colors[0] == 0) {
        shapeA.setFillColor(sf::Color::Red);
    } else {
        shapeA.setFillColor(sf::Color::Green);
    }

    shapeB.setPosition(received_event.coordinates[1]);
    if (received_event.colors[1] == 0) {
        shapeB.setFillColor(sf::Color::Red);
    } else {
        shapeB.setFillColor(sf::Color::Green);
    }

    sf::RenderWindow window(sf::VideoMode(700, 600), "Treasure Island");

    Event custom_event(a);

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
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) { custom_event.type = dir_left;
                /*hero_sprite.setTextureRect(sf::IntRect (32,32,32,32));*/};

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) { custom_event.type = dir_right;
                /*hero_sprite.setTextureRect(sf::IntRect (32,64,32,32));*/};

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) { custom_event.type = dir_straight;
                /*hero_sprite.setTextureRect(sf::IntRect (32,96,32,32));*/};
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) { custom_event.type = dir_back;
                /*hero_sprite.setTextureRect(sf::IntRect (32,0,32,32));*/};
        }
        /*if (argc > 1) {
            move.coord = 2;
            std::cout << move.coord << std::endl;
        }*/
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

        shapeA.setPosition(received_event.coordinates[0]);
        if (received_event.colors[0] == 0) {
            shapeA.setFillColor(sf::Color::Red);
        } else {
            shapeA.setFillColor(sf::Color::Green);
        }

        shapeB.setPosition(received_event.coordinates[1]);
        if (received_event.colors[1] == 0) {
            shapeB.setFillColor(sf::Color::Red);
        } else {
            shapeB.setFillColor(sf::Color::Green);
        }

        window.clear();
        window.draw(shapeA);
        window.draw(shapeB);
        window.display();
    }
    return 0;
}
