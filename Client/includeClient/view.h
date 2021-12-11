//
// Created by ser on 08.12.2021.
//

#ifndef ISLANDGAME_VIEW_H
#define ISLANDGAME_VIEW_H
struct SpriteCoord {
    int begin_x;
    int begin_y;
    int height;
    int width;
};
/*struct SpritePosition {
    int x;
    int y;
};*/
class View {
public:
    static sf::Sprite draw_and_update(const std::string& path_to_file, struct SpriteCoord coord, sf::Vector2f pos) { // static - позволяет вызывать методы без объектов

        // Создание изображения
        sf::Image hero_image;
        hero_image.loadFromFile(path_to_file);
        if (!hero_image.loadFromFile(path_to_file)) {
            std::cout << "ERROR OF PATH FILE" << std::endl;
        }

        //Создание текстуры
        sf::Texture hero_texture;
        hero_texture.loadFromImage(hero_image);

        //Создание спрайта игрока
        sf::Sprite hero_sprite;
        hero_sprite.setTexture(hero_texture);
        hero_sprite.setTextureRect(sf::IntRect(coord.begin_x, coord.begin_y,
                                                                        coord.width, coord.height));

        hero_sprite.setPosition(pos);
        return hero_sprite;
    }

};

#endif //ISLANDGAME_VIEW_H
