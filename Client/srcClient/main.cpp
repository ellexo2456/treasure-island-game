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

    sf::Vector2f A;
    //std::string color;

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
    // Добавление карты
    sf::Image map_image;//объект изображения для карты
    map_image.loadFromFile("../Client/srcClient/images/map.png");//загружаем файл для карты

    sf::Texture map;//текстура карты
    map.loadFromImage(map_image);//заряжаем текстуру картинкой

    sf::Sprite s_map;//создаём спрайт для карты
    s_map.setTexture(map);//заливаем текстуру спрайтом
    //////

    sf::RenderWindow window(sf::VideoMode(700, 700), "Treasure island");
    view.reset(sf::FloatRect(0, 0, 700, 700)); // инициализировали объект камеры


    // Загрузка картинки
   /* std::string str_1 = "../Client/srcClient/images/one";
    sf::Image hero_image;
    hero_image.loadFromFile(str_1);

    sf::Texture hero_texture;
    hero_texture.loadFromImage(hero_image);

    sf::Sprite hero_sprite;
    hero_sprite.setTexture(hero_texture);
    hero_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    hero_sprite.setPosition(50, 25);*/

    std::string path_to_file = "../Client/srcClient/images/one.png";
    struct SpriteCoord coord = {0, 0, 32,  32 };
    Player Player1(path_to_file, coord, A);
   /* sf::Sprite hero_sprite;
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
                coord.begin_y = 96; coord.begin_x = 32;};

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) { custom_event.type = dir_right;
                coord.begin_y = 64; coord.begin_x = 32;};

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) { custom_event.type = dir_straight;
                 coord.begin_y = 96; coord.begin_x = 32;};
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
                 (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) { custom_event.type = dir_back;
                 coord.begin_y = 96; coord.begin_x = 32;};
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

        packet >> A.x >> A.y /*>> color*/;

       // Задаём цвета, по сути только для мячиков/////////////////////////////////////////////////////////
        /*shapeA.setPosition(A); // Говорит, где отрисовывать объект
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
        //hero_sprite.setPosition(A);*/
        Player1.render(coord, A);

        window.clear();



       /* window.draw(shapeA);
        window.draw(shapeB);*/
        window.draw(Player1.hero_sprite);
        window.setView(view);
        window.display();
    }

    return 0;
}
