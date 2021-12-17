//
// Created by alexey on 17.12.2021.
//

//
// Created by alexey on 08.12.2021.
//

#include "Models.h"

void Collision::update(Event event) {
    if (event.type == is_intersect_with_player) {
        for (int i = 0; i < player_count; ++i) {
            if (event.moved_player_number != players[i].get_player_number()) {
                continue;
            }
            for (int j = 0; j < player_count; ++j) {
                if (j != players[i].get_player_number()) {
                    if (players[i].get_sprite_rect().intersects(sf::FloatRect(event.user_moved.coordinates[j], \
                {static_cast<float>(event.user_moved.sprite_coordinates[j].width),
                 static_cast<float>(event.user_moved.sprite_coordinates[j].height)}))) {
                        switch (players[i].get_direction()) {
                            case 1: {
                                players[i].set_coordinates({event.user_moved.coordinates[j].x + \
                                event.user_moved.sprite_coordinates[j].width, players[i].get_coordinates().y});
                                //event.user_moved.coordinates[j].x + event.user_moved.sprite_coordinates[j].width;
                                break;
                            }
                            case 2: {
                                players[i].set_coordinates({event.user_moved.coordinates[j].x - players[i].get_player_sprite_coordinates().width, \
                                players[i].get_coordinates().y});
                                //coordinates.x = event.user_moved.coordinates[j].x - player_sprite_coordinates.width;
                                break;
                            }
                            case 3: {
                                players[i].set_coordinates({players[i].get_coordinates().x, \
                                event.user_moved.coordinates[j].y + event.user_moved.sprite_coordinates[j].height});
                                //coordinates.y = event.user_moved.coordinates[j].y +
                                //              event.user_moved.sprite_coordinates[j].height;
                                break;
                            }
                            case 4: {
                                players[i].set_coordinates({players[i].get_coordinates().x, \
                                event.user_moved.coordinates[j].y - players[i].get_player_sprite_coordinates().height});
                                //coordinates.y = event.user_moved.coordinates[j].y - player_sprite_coordinates.height;
                                break;
                            }
                            default: {
                                players[i].set_coordinates({players[i].get_coordinates().x + players[i].get_speed(), \
                                players[i].get_coordinates().y + players[i].get_speed()});
                                //coordinates.x += speed;
                                //coordinates.y += speed;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if (event.type == is_intersect_with_map) {
        for (int i = 0; i < player_count; ++i) {
            if (event.moved_player_number != players[i].get_player_number()) {
                continue;
            }
            for (int k = players[i].get_coordinates().y / 32;
                 k < (players[i].get_coordinates().y + players[i].get_player_sprite_coordinates().height) / 32; ++k) {
                for (int l = players[i].get_coordinates().x / 32; l < (players[i].get_coordinates().x +
                                                                       players[i].get_player_sprite_coordinates().width) /
                                                                      32; ++l) {
                    if (TileMap[k][l] == 's') {
                        switch (players[i].get_direction()) {
                            case 1: {
                                players[i].set_coordinates({static_cast<float>(32*l + \
                                    players[i].get_player_sprite_coordinates().width), players[i].get_coordinates().y});
                                //event.user_moved.coordinates[j].x + event.user_moved.sprite_coordinates[j].width;
                                break;
                            }
                            case 2: {
                                players[i].set_coordinates({static_cast<float>(32*l -
                                                            players[i].get_player_sprite_coordinates().width), \
                                players[i].get_coordinates().y});
                                //coordinates.x = event.user_moved.coordinates[j].x - player_sprite_coordinates.width;
                                break;
                            }
                            case 3: {
                                players[i].set_coordinates({players[i].get_coordinates().x, \
                                static_cast<float>(32*k + players[i].get_player_sprite_coordinates().height)});
                                //coordinates.y = event.user_moved.coordinates[j].y +
                                //              event.user_moved.sprite_coordinates[j].height;
                                break;
                            }
                            case 4: {
                                players[i].set_coordinates({players[i].get_coordinates().x, \
                                static_cast<float>(32*k - players[i].get_player_sprite_coordinates().height)});
                                //coordinates.y = event.user_moved.coordinates[j].y - player_sprite_coordinates.height;
                                break;
                            }
                            default: {
                                players[i].set_coordinates({players[i].get_coordinates().x + players[i].get_speed(), \
                                players[i].get_coordinates().y + players[i].get_speed()});
                                //coordinates.x += speed;
                                //coordinates.y += speed;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

