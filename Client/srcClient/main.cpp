#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "clientPlayer.h"
//#include "map.h"
#include "camera.h"
#include "ResourceText.h"
#include "Lev.h"
#include "resources.h"
#include "unistd.h"

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
    packet >> received_event.resources_data.picked_item_area;
    packet >> received_event.resources_data.picked_item_index;
    for (int i = 0; i < 2; ++i) {
        packet >> received_event.resources_data.ship_resource_count[i] >> received_event.user_moved.coordinates[i].x >> received_event.user_moved.coordinates[i].y \
 >> received_event.user_moved.sprite_coordinates[i].begin_x >> received_event.user_moved.sprite_coordinates[i].begin_y \
        >> received_event.user_moved.sprite_coordinates[i].height >> received_event.user_moved.sprite_coordinates[i].width;
    }
    for (int i = 0; i < RESOURCE_SPAWN_ZONE_COUNT; ++i) {
        packet >> received_event.resources_data.resource_spawn_areas[i].rect.left >> received_event.resources_data.resource_spawn_areas[i].rect.top;
        if (!received_event.resources_data.resource_positions_to_send) {
            continue;
        }
        received_event.resources_data.received_resource_positions[i].clear();
        int size;
        packet >> size;
        for (int j = 0; j < size; ++j) {
            //packet >> received_event.resources_data.received_resource_positions[i][j].x >> received_event.resources_data.received_resource_positions[i][j].y;
            float x, y;
            packet >> x >> y;
            received_event.resources_data.received_resource_positions[i].push_back({x,y});
        }
    }
    return packet;
}

sf::Packet operator<< (sf::Packet &packet, Event &received_event) {
    packet << received_event.type;
    packet << received_event.client_number;
    packet << received_event.resources_data.picked_item_area;
    packet << received_event.resources_data.picked_item_index;
    for (int i = 0; i < 2; ++i) {
        packet << received_event.resources_data.ship_resource_count[i] << received_event.user_moved.coordinates[i].x << received_event.user_moved.coordinates[i].y \
 << received_event.user_moved.sprite_coordinates[i].begin_x << received_event.user_moved.sprite_coordinates[i].begin_y \
        << received_event.user_moved.sprite_coordinates[i].height << received_event.user_moved.sprite_coordinates[i].width;
    }
    for (int i = 0; i < RESOURCE_SPAWN_ZONE_COUNT; ++i) {
        packet << received_event.resources_data.resource_spawn_areas[i].rect.left << received_event.resources_data.resource_spawn_areas[i].rect.top;
        if (!received_event.resources_data.resource_positions_to_send) {
            continue;
        }
        packet << (int)received_event.resources_data.resource_positions_to_send[i].size();
        for (int j = 0; j < received_event.resources_data.resource_positions_to_send[i].size(); ++j) {
            packet << received_event.resources_data.resource_positions_to_send[i][j].x << received_event.resources_data.resource_positions_to_send[i][j].y;
        }
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

    sf::Vector2f size_of_screen = {600, 600};

    sf::RenderWindow window(sf::VideoMode(size_of_screen.x, size_of_screen.y), "Treasure island");
    camera.reset(sf::FloatRect(0, 0, 600, 600)); // инициализировали объект камеры

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // Игроки
    std::string path_to_file = "../Client/srcClient/images/one.png";
    struct SpriteCoord coord = {0, 0, 32,  32 };
    struct SpriteCoord coord1 = {0, 128, 32,  32 };
    Player Player1(path_to_file, received_event.user_moved.sprite_coordinates[0],
                   received_event.user_moved.coordinates[0], size_of_screen);
    Player Player2(path_to_file, received_event.user_moved.sprite_coordinates[1],
                   received_event.user_moved.coordinates[1], size_of_screen);

    /*// Карта
    std::string path_to_map = "../Client/srcClient/images/map.adwpng";
    Map MyMap(path_to_map, coord, {0,0});*/
    std::string path_to_level = "../Client/srcClient/main_map_two.xml";
    TileMap map;
    map.load(path_to_level);



    ////Ресурсы///////////////////////////////////////////////////

    ShipResourceText ship_resource_text("../Client/srcClient/MesloLGS_NF_Bold_Italic.ttf");

    std::vector<Object> new_objects = {};
    std::vector<Resources> new_sprites = {};

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
//    std::vector<Object> vector_res = received_event.resources_data.resource_spawn_areas; // вектор объектов с указанным именем
    std::vector<Resources> sprites_of_object(QUANTITY_RES, resource_sprite); // вектор спрайтов с длинной вектора объектов

    // Рандомизация появления ресурсов
//    std::vector<sf::Vector2f> shifts[RESOURCE_SPAWN_ZONE_COUNT];

//    for(int i = 0; i < vector_res.size(); i++ ) {
//        for (int j = 0; j < QUANTITY_RES; j++) { //( rand() % 100 + 1 )) => 1 *32
//            shift[j].x = (rand() % (int)(vector_res.at(i).rect.width/32) + 1) * 32;
//            shift[j].y = (rand() % (int)(vector_res.at(i).rect.height/32) + 1) * 32;
//        }
//    }
    ////////////////////////////////////////////////////////////////                          << std::endl;

    WinText won("../Client/srcClient/MesloLGS_NF_Bold_Italic.ttf");

    Event custom_event;
    custom_event.resources_data.resource_positions_to_send = nullptr;

    socket.setBlocking(false);

    while (window.isOpen()) {
        sf::Event event{};
        received_event.resources_data.picked_item_index = -1;
        received_event.type = user_init;

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
//            std::cout << "x: " << received_event.user_moved.coordinates[0].x << ' ' << "y: " << received_event.user_moved.coordinates[0].y << std::endl;
//            std::cout << "x: " << received_event.user_moved.coordinates[1].x << ' ' << "y: " << received_event.user_moved.coordinates[1].y << std::endl;
//            std::cout << "w: " << received_event.user_moved.sprite_coordinates[0].width << ' ' << "h: " << received_event.user_moved.sprite_coordinates[0].height << std::endl;
//            std::cout << "w: " << received_event.user_moved.sprite_coordinates[1].width << ' ' << "h: " << received_event.user_moved.sprite_coordinates[1].height << std::endl << std::endl;
        }

        Player1.render(received_event.user_moved.sprite_coordinates[0], received_event.user_moved.coordinates[0]);
        Player2.render(received_event.user_moved.sprite_coordinates[1], received_event.user_moved.coordinates[1]);

        give_player_coord_to_camera(received_event.user_moved.coordinates[received_event.client_number]);
        window.setView(camera);

        ship_resource_text.text_render(received_event.resources_data.ship_resource_count[received_event.client_number], camera.getCenter());

        sf::RectangleShape frontend_rectangle(sf::Vector2f(180, 25));
        frontend_rectangle.setFillColor(sf::Color(0, 0, 0,120));
        frontend_rectangle.move(camera.getCenter().x + 103, camera.getCenter().y - 293);


        window.clear();

        window.draw(map);
        window.draw(frontend_rectangle);
        window.draw(ship_resource_text.text);
//        new_objects = {};
//        if (received_event.type == got_ship_resource) {
//        for (int k = 0; k < vector_res.size(); ++k) {
//            vector_res.erase(vector_res.begin() + received_event.resources_data.picked_item_index);
//            if (k != received_event.got_ship_resource.picked_item_index) {
//                new_objects.push_back(vector_res[k]);
//            }
//        }
//            if (received_event.got_ship_resource.picked_item_index != -1) {
//                std::cout << "Y: " << vector_res[received_event.got_ship_resource.picked_item_index].rect.top
//                          << " X: " << vector_res[received_event.got_ship_resource.picked_item_index].rect.left << '\t' << "pckd itm ind: "
//                          << received_event.got_ship_resource.picked_item_index << std::endl;
//            }
//            vector_res = new_objects;

//        }
        // Проходимся по элементам  вектора спрайтов и
        for (int i = 0; i < received_event.resources_data.resource_spawn_areas.size(); i++) {
//            if (received_event.resources_data.picked_item_area != -1)
//                std::cout << '\t' << "pckd itm area: " << received_event.resources_data.picked_item_area
//                        << '\t' << "pckd itm ind: " << received_event.resources_data.picked_item_index
//                        << "\t X: " << received_event.resources_data.ship_resource_count[i][received_event.<< std::endl;
//                coord_obj = {(vector_res.at(i)).rect.left, (vector_res.at(i)).rect.top}; // принимаем координаты каждого следующего объекта ресурсов

            for (int j = 0; j < received_event.resources_data.received_resource_positions[i].size(); j++) {
                if (received_event.resources_data.picked_item_index != -1) {
                    std::cout << "el nmbr: " << j << "\t X: "
                              << received_event.resources_data.received_resource_positions[i][j].x
                              << "\t X: " << received_event.resources_data.received_resource_positions[i][j].y
                              << std::endl;
                }
//                    coord_obj = {(vector_res.at(i)).rect.left + received_event.resources_data.received_resource_positions[i][j].x,
//                                 (vector_res.at(i)).rect.top + received_event.resources_data.received_resource_positions[i][j].y};
                (sprites_of_object.at(j)).render(res,received_event.resources_data.received_resource_positions[i][j]);
                window.draw(sprites_of_object.at(j).hero_sprite);
            }
        }

//        resource_sprite.render(res, coord_obj);  // обрезаем картинку
//        window.draw(resource_sprite.hero_sprite);
        window.draw(Player2.hero_sprite);
        window.draw(Player1.hero_sprite);
        if (received_event.resources_data.ship_resource_count[0] >= 6) {
            if (received_event.client_number == 0) {
                won.text_render(0, camera.getCenter());
                window.draw(won.text);
                window.display();
                sleep(3);
                break;
            } else {
                won.text_render(1, camera.getCenter());
                window.draw(won.text);
                window.display();
                sleep(3);
                break;
            }
        } else if (received_event.resources_data.ship_resource_count[1] >= 6) {
            if (received_event.client_number == 1) {
                won.text_render(0, camera.getCenter());
                window.draw(won.text);
                window.display();
                sleep(3);
                break;
            } else {
                won.text_render(1, camera.getCenter());
                window.draw(won.text);
                window.display();
                sleep(3);
                break;
            }
        }
        window.display();

    }
    return 0;
}