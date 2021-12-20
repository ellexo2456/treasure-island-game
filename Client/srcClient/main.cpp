#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "clientPlayer.h"
//#include "map.h"
#include "camera.h"
#include "Resource.h"
#include "Lev.h"
#include "resources.h"

#define PORT 3001

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
        case 5: {
            received_event.type = is_intersect_with_player;
            break;
        }
        case 6: {
            received_event.type = is_intersect_with_map;
            break;
        }
        case 7: {
            received_event.type = got_ship_resource;
            break;
        }
        default: {
            received_event.type = error;
            break;
        }
    }
    packet >> received_event.client_number;
    packet >> received_event.got_ship_resource.map_row_to_change;
    packet >> received_event.got_ship_resource.map_column_to_change;
    for (int i = 0; i < 2; ++i) {
        packet >> received_event.got_ship_resource.ship_resource_count[i] >> received_event.user_moved.coordinates[i].x >> received_event.user_moved.coordinates[i].y \
        >> received_event.user_moved.sprite_coordinates[i].begin_x >> received_event.user_moved.sprite_coordinates[i].begin_y \
        >> received_event.user_moved.sprite_coordinates[i].height >> received_event.user_moved.sprite_coordinates[i].width;
    }
    return packet;
}

sf::Packet operator<< (sf::Packet &packet, Event &received_event) {
    packet << received_event.type;
    packet << received_event.client_number;
    packet << received_event.got_ship_resource.map_row_to_change;
    packet << received_event.got_ship_resource.map_column_to_change;
    for (int i = 0; i < 2; ++i) {
        packet << received_event.got_ship_resource.ship_resource_count[i] << received_event.user_moved.coordinates[i].x << received_event.user_moved.coordinates[i].y \
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
    Event received_event;
    packet >> received_event;

    sf::Vector2f size_of_screen = {900, 900};

    sf::RenderWindow window(sf::VideoMode(size_of_screen.x, size_of_screen.y), "Treasure island");
    camera.reset(sf::FloatRect(0, 0, 600, 600)); // инициализировали объект камеры

    // Игроки
    std::string path_to_file = "../Client/srcClient/images/one.png";
    struct SpriteCoord coord = {0, 0, 32,  32 };
    struct SpriteCoord coord1 = {0, 128, 32,  32 };
    Player Player1(path_to_file, received_event.user_moved.sprite_coordinates[0],
                   received_event.user_moved.coordinates[0], size_of_screen);
    Player Player2(path_to_file, received_event.user_moved.sprite_coordinates[1],
                   received_event.user_moved.coordinates[1], size_of_screen);

    /*// Карта
    std::string path_to_map = "../Client/srcClient/images/map.png";
    Map MyMap(path_to_map, coord, {0,0});*/
    std::string path_to_level = "../Client/srcClient/main_map.xml";
    TileMap map;
    map.load(path_to_level);

    // Ресы для корабля
    //ShipResource ship_resource("../Client/srcClient/MesloLGS_NF_Bold_Italic.ttf");

    ////Ресурсы///////////////////////////////////////////////////

    std::string name_of_object_one = "res";
    struct SpriteCoord res = {0, 64, 32, 32};  // Это можно не менять

    Object tex = map.getObject(name_of_object_one); //
    /*.getObject - только первый объект с заданным именем, вернёт вектор
     * .getObjectsByName все объекты с заданным именем, вернёт вектор
     * getAllObjects все объекты, вернёт вектор
     */
    sf::Vector2f coord_obj = {tex.rect.left, tex.rect.top}; // откуда начинать отрисовку, внутренние поля Object/rect
    Resources resource_sprite("../Client/srcClient/images/map.png", res, coord_obj);
    resource_sprite.render(res, coord_obj); // обрезает картинку по данным SpriteCoord

    // В основном цикле есть ещё отрисовка
    std::vector<Object> vector_res = map.getObjectsByName(name_of_object_one); // вектор объектов с указанным именем
    std::vector<Resources> sprites_of_object(vector_res.size(), resource_sprite); // вектор спрайтов с длинной вектора объектов
    // Цикл начальной инициализации, хз без него наверное работает, но удалять лучше не надо
    for(int i = 0; i < vector_res.size(); i++) {
        coord_obj = {(vector_res.at(i)).rect.left, (vector_res.at(i)).rect.top};
        (sprites_of_object.at(i)).render(res, coord_obj);
    }

    ////////////////////////////////////////////////////////////////

    Event custom_event;

    socket.setBlocking(false);

    while (window.isOpen()) {
        sf::Event event{};

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
            // std::cout << custom_event.type << std::endl;
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

        give_player_coord_to_camera(received_event.user_moved.coordinates[received_event.client_number]);
        window.setView(camera);

        /*ship_resource.text_render(received_event.got_ship_resource.ship_resource_count[received_event.client_number], camera.getCenter());
        MyMap.TileMap[received_event.got_ship_resource.map_row_to_change][received_event.got_ship_resource.map_column_to_change] = '0';
        window.clear();*/

        //window.draw(ship_resource.text);
        window.draw(map);

        // Проходимся по элементам  вектора спрайтов и
        for(int i = 0; i < vector_res.size(); i++) {
            coord_obj = {(vector_res.at(i)).rect.left, (vector_res.at(i)).rect.top}; // принимаем координаты каждого следующего объекта ресурсов
            (sprites_of_object.at(i)).render(res, coord_obj); // задаём им координаты отрисовки по координатам вектора объектов res
            window.draw(sprites_of_object.at(i).hero_sprite);
        }

//        resource_sprite.render(res, coord_obj);  // обрезаем картинку
//        window.draw(resource_sprite.hero_sprite);
        window.draw(Player2.hero_sprite);
        window.draw(Player1.hero_sprite);
        window.display();
    }
    return 0;
}