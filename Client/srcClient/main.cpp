#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "clientPlayer.h"

int main() {
    sf::TcpSocket socket;
    socket.connect("127.0.0.1", 3000);

    sf::Vector2f A;
    std::string color;

    sf::Packet packet;
    packet.clear();
    socket.receive(packet);

    sf::CircleShape shapeA(90.f);
    sf::CircleShape shapeB(90.f);

    packet >> A.x >> A.y >> color;
    shapeA.setPosition(A);
    if (color == "Red") {
        shapeA.setFillColor(sf::Color::Red);
    } else {
        shapeA.setFillColor(sf::Color::Green);
    }

    packet >> A.x >> A.y >> color;
    shapeB.setPosition(A);
    if (color == "Red") {
        shapeB.setFillColor(sf::Color::Red);
    } else {
        shapeB.setFillColor(sf::Color::Green);
    }


    sf::RenderWindow window(sf::VideoMode(700, 600), "SFML works!");

    // 0 - нет действий
    // 1 - left
    // 2 - right
    // 3 - up
    // 4 - down
    State move;
    move.coord = 0;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        move.coord = 0;
        if (window.hasFocus()) {
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) { move.coord = 1; };
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) { move.coord = 2; };
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) { move.coord = 3; };
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) { move.coord = 4; };
        }
        /*if (argc > 1) {
            move.coord = 2;
            std::cout << move.coord << std::endl;
        }*/
        packet.clear();
        packet << move.coord ;
        socket.send(packet);

        packet.clear();
        socket.receive(packet);

        packet >> A.x >> A.y >> color;

        shapeA.setPosition(A); // Говорит, где отрисовывать объект
        if (color == "Red") {
            shapeA.setFillColor(sf::Color::Red);
        } else {
            shapeA.setFillColor(sf::Color::Green);
        }

        packet >> A.x >> A.y >> color;
        shapeB.setPosition(A); // Говорит, где отрисовывать объект
        if (color == "Red") {
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
