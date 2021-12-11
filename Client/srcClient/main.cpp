#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "clientPlayer.h"
#include "Event.h"
#include "view.h"

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


    sf::RenderWindow window(sf::VideoMode(700, 600), "Treasure island");
    // Загрузка картинки
    std::string str_1 = "../Client/srcClient/images/one";
    sf::Image hero_image;
    hero_image.loadFromFile(str_1);

    sf::Texture hero_texture;
    hero_texture.loadFromImage(hero_image);

    sf::Sprite hero_sprite;
    hero_sprite.setTexture(hero_texture);
    hero_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    hero_sprite.setPosition(50, 25);

    /*std::string path_to_file = "/home/ser/_1_treasure_island_game/Client/srcClient/images/one";
    struct SpriteCoord coord = {0, 0, 32, 32 };
    sf::Sprite hero_sprite = View::draw_and_update(path_to_file, coord, A);

    sf::Sprite hero_sprite;
    hero_sprite.setTexture(hero_texture);
    hero_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    hero_sprite.setPosition(50, 25);*/

    //window.draw(hero_sprite);
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
                hero_sprite.setTextureRect(sf::IntRect (32,32,32,32));};

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) { custom_event.type = dir_right;
                hero_sprite.setTextureRect(sf::IntRect (32,64,32,32));};

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) { custom_event.type = dir_straight;
                hero_sprite.setTextureRect(sf::IntRect (32,96,32,32));};
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) { custom_event.type = dir_back;
                hero_sprite.setTextureRect(sf::IntRect (32,0,32,32));};
        }
        /*if (argc > 1) {
            move.coord = 2;
            std::cout << move.coord << std::endl;
        }*/
        packet.clear();
        packet << custom_event.type;
        socket.send(packet);

        packet.clear();
        socket.receive(packet);

        packet >> A.x >> A.y >> color;

       // Задаём цвета, по сути только для мячиков/////////////////////////////////////////////////////////
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
        hero_sprite.setPosition(A);

        window.clear();
        window.draw(shapeA);
        window.draw(shapeB);
        window.draw(hero_sprite);
        window.display();
    }

    return 0;
}
