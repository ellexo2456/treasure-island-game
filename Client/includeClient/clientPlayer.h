//
// Created by ser on 27.11.2021.
//

#ifndef ISLANDGAME_CLIENTPLAYER_H
#define ISLANDGAME_CLIENTPLAYER_H
#include <view.h>
class Player : public View {

public:
    Player (const std::string& path_to_file, struct SpriteCoord coord, sf::Vector2f pos) :
            View (path_to_file, coord, pos) {
    };
    //
    void render(struct SpriteCoord update_coord, sf::Vector2f position) {
        hero_sprite.setTextureRect(sf::IntRect(update_coord.begin_x, update_coord.begin_y,
                                                        update_coord.width, update_coord.height));
        hero_sprite.setPosition(position);
    };
};


class State {
public:
    int coord;
};


#endif //ISLANDGAME_CLIENTPLAYER_H
