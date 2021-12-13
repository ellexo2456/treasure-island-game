#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "clientPlayer.h"
#include "Event.h"
#include "view.h"
#include "map.h"
#include "camera.h"

int main() {
    sf::TcpSocket socket;
    socket.connect("127.0.0.1", 3001);

    sf::Vector2f A, B;
    //std::string color;
    B = {300, 400};
    sf::Packet packet;
    packet.clear();
    socket.receive(packet);

    /*sf::CircleShape shapeA(90.f);
    sf::CircleShape shapeB(90.f);
    */
    packet >> A.x >> A.y /*>> color*/;
   /* shapeA.setPosition(A);
    if (color == "Red") {
        shapeA.setFillColor(sf::Color::Red);
    } else {
        shapeA.setFillColor(sf::Color::Green);
    }*/

    packet >> A.x >> A.y /*>> color*/;
    /*shapeB.setPosition(A);
    if (color == "Red") {
        shapeB.setFillColor(sf::Color::Red);
    } else {
        shapeB.setFillColor(sf::Color::Green);
    }
    */


    sf::RenderWindow window(sf::VideoMode(700, 700), "Treasure island");
    //view.reset(sf::FloatRect(0, 0, 700, 700)); // инициализировали объект камеры


    // Игроки
    std::string path_to_file = "../Client/srcClient/images/one.png";
    struct SpriteCoord coord = {0, 0, 32,  32 };
    struct SpriteCoord coord1 = {0, 128, 32,  32 };
    Player Player1(path_to_file, coord, A);
    Player Player2(path_to_file, coord1, B);

    // Карта
    std::string path_to_map = "../Client/srcClient/images/map.png";
    Map MyMap(path_to_map, coord, A);
    // 0 - нет действий
    // 1 - left
    // 2 - right
    // 3 - up
    // 4 - down
    Event custom_event;
    custom_event.type = user_init;

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
                coord.begin_y = 32; coord.begin_x = 32;};

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) { custom_event.type = dir_right;
                coord.begin_y = 64; coord.begin_x = 32;};

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) { custom_event.type = dir_straight;
                 coord.begin_y = 96; coord.begin_x = 32;};
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) { custom_event.type = dir_back;
                 coord.begin_y = 0; coord.begin_x = 32;};
        }

        packet.clear();
        packet << custom_event.type;
        socket.send(packet);

        packet.clear();
        socket.receive(packet);

        packet >> A.x >> A.y /*>> color*/;
        Player1.render(coord, A);
       // Задаём цвета, по сути только для мячиков/////////////////////////////////////////////////////////
        /*shapeA.setPosition(A); // Говорит, где отрисовывать объект
        if (color == "Red") {
            shapeA.setFillColor(sf::Color::Red);
        } else {
            shapeA.setFillColor(sf::Color::Green);
        }*/

        packet >> A.x >> A.y ;/*>> color;
        shapeB.setPosition(A); // Говорит, где отрисовывать объект
        if (color == "Red") {
            shapeB.setFillColor(sf::Color::Red);
        } else {
            shapeB.setFillColor(sf::Color::Green);
        }
        //hero_sprite.setPosition(A);*/
        Player2.render(coord1, A);


        window.clear();
        MyMap.render(window);


       /* window.draw(shapeA);
        window.draw(shapeB);*/
        window.draw(Player2.hero_sprite);
        window.draw(Player1.hero_sprite);
        //window.setView(view);
        window.display();
    }

    return 0;
}
